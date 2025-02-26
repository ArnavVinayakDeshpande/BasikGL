#include <glad/glad.h>

#include <gfx/texture/texture2d.h>
#include <core/convert_values.h>

namespace bskgl {

    Texture2D::Texture2D(
        UUID uuid, const std::filesystem::path& texfile,
        TextureBase::MinFilter min_filter,
        TextureBase::MagFilter mag_filter,
        TextureBase::WrapMode wrap_mode_s,
        TextureBase::WrapMode wrap_mode_t
    )
        :
        m_uuid(uuid),
        m_sprite(texfile),
        m_min_filter(min_filter),
        m_mag_filter(mag_filter),
        m_wrap_mode_s(wrap_mode_s),
        m_wrap_mode_t(wrap_mode_t) {
        glGenTextures(1, &m_glid);
        this->sync();
    }

    Texture2D::Texture2D(
        UUID uuid, const Sprite& sprite,
        TextureBase::MinFilter min_filter,
        TextureBase::MagFilter mag_filter,
        TextureBase::WrapMode wrap_mode_s,
        TextureBase::WrapMode wrap_mode_t
    )
        :
        m_uuid(uuid),
        m_sprite(sprite),
        m_min_filter(min_filter),
        m_mag_filter(mag_filter),
        m_wrap_mode_s(wrap_mode_s),
        m_wrap_mode_t(wrap_mode_t) {
        glGenTextures(1, &m_glid);
        this->sync();
    }

    Texture2D::Texture2D(Texture2D&& other) noexcept {
        m_glid = other.m_glid;
        other.m_glid = 0;
        m_sprite = std::move(other.m_sprite);
        this->sync();
    }

    Texture2D& Texture2D::operator=(Texture2D&& other) noexcept {
        m_glid = other.m_glid;
        other.m_glid = 0;
        m_sprite = std::move(other.m_sprite);
        this->sync();

        return *this;   
    }

    Texture2D::~Texture2D() {
        glDeleteTextures(1, &m_glid);
    }

    uint32_t Texture2D::gl_id() const {
        return m_glid;
    }

    uint32_t Texture2D::width() const {
        return m_sprite.width();
    }

    uint32_t Texture2D::height() const {
        return m_sprite.height();
    }

    TextureBase::Type Texture2D::type() const {
        return Texture2D::texture_type;
    }

    TextureBase::InternalFormat Texture2D::internal_format() const {
        return m_internal_format;
    }

    TextureBase::Format Texture2D::format() const {
        return m_format;
    }

    TextureBase::DataType Texture2D::data_type() const {
        return Texture2D::tex_data_type;
    }

    TextureBase::MinFilter Texture2D::min_filter() const {
        return m_min_filter;
    }

    TextureBase::MagFilter Texture2D::mag_filter() const {
        return m_mag_filter;
    }

    TextureBase::WrapMode Texture2D::wrap_mode_s() const {
        return m_wrap_mode_s;
    }

    TextureBase::WrapMode Texture2D::wrap_mode_t() const {
        return m_wrap_mode_t;
    }

    const Sprite& Texture2D::sprite() const {
        return m_sprite;
    }

    Texture2D& Texture2D::set_min_filter(TextureBase::MinFilter min_filter) {
        m_min_filter = min_filter;
        
        this->bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, opengl::convert(min_filter));
        
        return *this;
    }

    Texture2D& Texture2D::set_mag_filter(TextureBase::MagFilter mag_filter) {
        m_mag_filter = mag_filter;
        
        this->bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, opengl::convert(mag_filter));
        
        return *this;
    }

    Texture2D& Texture2D::set_wrap_mode_s(TextureBase::WrapMode wrap_mode) {
        m_wrap_mode_s = wrap_mode;
        
        this->bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, opengl::convert(wrap_mode));	
        
        return *this;
    }

    Texture2D& Texture2D::set_wrap_mode_t(TextureBase::WrapMode wrap_mode) {
        m_wrap_mode_t = wrap_mode;
        
        this->bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, opengl::convert(wrap_mode));
        
        return *this;
    }

    Texture2D& Texture2D::read_from(const std::filesystem::path& _texfile) {
        m_sprite.read_from(_texfile);
        this->sync();
        return *this;
    }

    void Texture2D::bind(int32_t _tex_unit) const {
        if (_tex_unit == -1)
            glBindTextureUnit(this->default_texture_unit, m_glid);
        else
            glBindTextureUnit(_tex_unit, m_glid);
    }

    Texture2D& Texture2D::sync() {
        switch (m_sprite.channels()) {
            case 1:
                m_internal_format = TextureBase::InternalFormat::Red;
                m_format = TextureBase::Format::Red;
                break;
            case 3:
                m_internal_format = TextureBase::InternalFormat::RGB;
                m_format = TextureBase::Format::RGB;
                break;
            case 4:
                m_internal_format = TextureBase::InternalFormat::RGBA;
                m_format = TextureBase::Format::RGBA;
                break;
            default:
                throw std::runtime_error("Unsupported number of channels in texture.");
        }

        glBindTexture(GL_TEXTURE_2D, m_glid);

        glTexImage2D(
            GL_TEXTURE_2D, 
            0, 
            opengl::convert(m_internal_format), 
            m_sprite.width(), m_sprite.height(), 0, 
            opengl::convert(m_format), 
            opengl::convert(Texture2D::tex_data_type), 
            m_sprite.data());
        glGenerateMipmap(GL_TEXTURE_2D);

        this->set_min_filter(m_min_filter)
            .set_mag_filter(m_mag_filter)
            .set_wrap_mode_s(m_wrap_mode_s)
            .set_wrap_mode_t(m_wrap_mode_t);

        return *this;
    }

}