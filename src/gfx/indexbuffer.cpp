#include <glad/glad.h>

#include <gfx/indexbuffer.h>

namespace bskgl {

    IndexBuffer::IndexBuffer(UUID uuid, size_t num_indices)
        :
        m_uuid(uuid),
        m_indices(num_indices, 0u) {
        glGenBuffers(1, &m_glid);
    }

    IndexBuffer::IndexBuffer(UUID uuid, const std::vector<uint32_t>& indices)
        :
        m_uuid(uuid),
        m_indices(indices) {
        glGenBuffers(1, &m_glid);
    }

    IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept 
        :
        m_uuid(other.m_uuid),
        m_glid(other.m_glid),
        m_indices(std::move(other.m_indices)) {
        other.m_glid = 0;
    }

    IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept {
        if (this == &other)
            return *this;

        m_uuid = other.m_uuid;
        m_glid = other.m_glid;
        m_indices = std::move(other.m_indices);

        other.m_glid = 0;

        return *this;
    }

    IndexBuffer::~IndexBuffer() {
        if (m_glid != 0)
            glDeleteBuffers(1, &m_glid);
    }

    UUID IndexBuffer::uuid() const {
        return m_uuid;
    }

    uint32_t IndexBuffer::gl_id() const {
        return m_glid;
    }

    const std::vector<uint32_t>& IndexBuffer::indices() const {
        return m_indices;
    }

    size_t IndexBuffer::num_indices() const {
        return m_indices.size();
    }

    IndexBuffer& IndexBuffer::set_indices(const std::vector<uint32_t>& indices) {
        m_indices = indices;

        return *this;
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glid);
    }

    IndexBuffer& IndexBuffer::sync() {
        // bind the buffer
        this->bind();

        // update the buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(uint32_t), m_indices.data(), GL_DYNAMIC_DRAW);

        // unbind the buffer
        IndexBuffer::unbind();

        return *this;
    }

    void IndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}