#include <glad/glad.h>
#include <iostream>

#include <gfx/vertexarray.h>
#include <context/asset_manager.h>

namespace bskgl {

    VertexArray::VertexArray(UUID uuid, std::shared_ptr<VertexBuffer> vbuffer, std::shared_ptr<IndexBuffer> ibuffer)
        :
        m_uuid(uuid),
        m_vbuffer(std::move(vbuffer)),
        m_ibuffer(std::move(ibuffer)) {
        glGenVertexArrays(1, &m_glid);
        this->sync();
    }

    VertexArray::VertexArray(VertexArray&& other) noexcept 
        :
        m_uuid(other.m_uuid),
        m_glid(other.m_glid),
        m_vbuffer(std::move(other.m_vbuffer)),
        m_ibuffer(std::move(other.m_ibuffer)) {
        other.m_glid = 0;
    }

    VertexArray& VertexArray::operator=(VertexArray&& other) noexcept {
        if (this == &other)
            return *this;

        m_uuid = other.m_uuid;
        m_glid = other.m_glid;
        m_vbuffer = std::move(other.m_vbuffer);
        m_ibuffer = std::move(other.m_ibuffer);
        other.m_glid = 0;
    
        return *this;
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_glid);
    }

    UUID VertexArray::uuid() const {
        return m_uuid;
    }

    uint32_t VertexArray::gl_id() const {
        return m_glid;
    }

    const std::vector<Vertex>& VertexArray::vertices() const {
        return m_vbuffer->vertices();
    }

    const std::vector<uint32_t>& VertexArray::indices() const {
        return m_ibuffer->indices();
    }

    size_t VertexArray::num_vertices() const {
        return m_vbuffer->num_vertices();
    }
    
    size_t VertexArray::num_indices() const {
        return m_ibuffer? m_ibuffer->num_indices() : 0;
    }

    UUID VertexArray::vbuffer() const {
        return m_vbuffer->uuid();
    }

    UUID VertexArray::ibuffer() const {
        if (m_ibuffer)
            return m_ibuffer->uuid();
        return BSK_INVALID_UUID;
    }

    VertexArray& VertexArray::set_vertices(const std::vector<Vertex>& vertices) {
        m_vbuffer->set_vertices(vertices);
        return *this;
    }

    VertexArray& VertexArray::set_indices(const std::vector<uint32_t>& indices) {
        if (m_ibuffer)
            m_ibuffer->set_indices(indices);

        return *this;
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_glid);
        m_vbuffer->bind();

        if (m_ibuffer)
            m_ibuffer->bind();
    }

    VertexArray& VertexArray::sync() {
        // bind this vertex array
        this->bind();

        // sync the vertex buffer
        m_vbuffer->sync();

        // sync the index buffer
        if (m_ibuffer)
            m_ibuffer->sync();
        
        // reattach the buffers to this vertex array (rebind them)
        m_vbuffer->bind();

        if (m_ibuffer)
            m_ibuffer->bind();

        // set vertex attributes
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, tex_coords));

        // unbind this vertex array
        VertexArray::unbind();

        return *this;
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
        VertexBuffer::unbind();
        IndexBuffer::unbind();
    }

}