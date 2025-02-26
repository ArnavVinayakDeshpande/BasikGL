#include <glad/glad.h>

#include <gfx/vertexbuffer.h>

namespace bskgl {

    VertexBuffer::VertexBuffer(UUID uuid, size_t num_vertices)
        :
        m_uuid(uuid),
        m_vertices(num_vertices, bskgl::Vertex()) {
        glGenBuffers(1, &m_glid);
    }

    VertexBuffer::VertexBuffer(UUID uuid, const std::vector<Vertex>& vertices)
        :
        m_uuid(uuid),
        m_vertices(vertices) {
        glGenBuffers(1, &m_glid);
    }

    VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept 
        :
        m_uuid(other.m_uuid),
        m_glid(other.m_glid),
        m_vertices(std::move(other.m_vertices)) {
        other.m_glid = 0;
    }

    VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
        if (this == &other)
            return *this;

        m_uuid = other.m_uuid;
        m_glid = other.m_glid;
        m_vertices = std::move(other.m_vertices);

        other.m_glid = 0;

        return *this;
    }

    VertexBuffer::~VertexBuffer() {
        if (m_glid != 0)
            glDeleteBuffers(1, &m_glid);
    }

    UUID VertexBuffer::uuid() const {
        return m_uuid;
    }

    uint32_t VertexBuffer::gl_id() const {
        return m_glid;
    }

    const std::vector<Vertex>& VertexBuffer::vertices() const {
        return m_vertices;
    }

    size_t VertexBuffer::num_vertices() const {
        return m_vertices.size();
    }

    VertexBuffer& VertexBuffer::set_vertices(const std::vector<Vertex>& vertices) {
        m_vertices = vertices;

        return *this;
    }

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_glid);
    }

    VertexBuffer& VertexBuffer::sync() {
        // bind the buffer
        this->bind();

        // update the buffer
        glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_DYNAMIC_DRAW);

        // unbind the buffer
        VertexBuffer::unbind();

        return *this;
    }

    void VertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}