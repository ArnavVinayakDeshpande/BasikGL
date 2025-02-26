#include <stb_image.h>

#include <sprite/sprite.h>

namespace bskgl {

    Sprite::Sprite() 
        :
        m_width(0),
        m_height(0),
        m_channels(0),
        m_data(nullptr) { }

    Sprite::Sprite(const std::filesystem::path& path) {
        this->read_from(path);
    }

    Sprite::Sprite(const Sprite& other) {
        m_width = other.m_width;
        m_height = other.m_height;
        m_channels = other.m_channels;
        
        if (other.m_data) {
            m_data = std::make_unique<uint8_t[]>(m_width * m_height * m_channels);
            std::copy(other.m_data.get(), other.m_data.get() + (m_width * m_height * m_channels), m_data.get());
        } else {
            m_data = nullptr;
        }
    }
    
    Sprite& Sprite::operator=(const Sprite& other) {
        if (this == &other) 
            return *this; 
    
        m_width = other.m_width;
        m_height = other.m_height;
        m_channels = other.m_channels;
    
        if (other.m_data) {
            m_data = std::make_unique<uint8_t[]>(m_width * m_height * m_channels);
            std::copy(other.m_data.get(), other.m_data.get() + (m_width * m_height * m_channels), m_data.get());
        } else {
            m_data = nullptr;
        }
    
        return *this;
    }

    Sprite::~Sprite() {
        if (m_data) {
            stbi_image_free(m_data.release());
        }
    }

    int32_t Sprite::width() const {
        return m_width;
    }

    int32_t Sprite::height() const {
        return m_height;
    }

    int32_t Sprite::channels() const {
        return m_channels;
    }

    const unsigned char* Sprite::data() const {
        return m_data.get();
    }

    Sprite& Sprite::read_from(const std::filesystem::path& path) {
        if (m_data) {
            stbi_image_free(m_data.release());
        }

        const char* filepath = path.string().c_str();

        m_data.reset(stbi_load(filepath, &m_width, &m_height, &m_channels, 0));
        
        if (!m_data) {
            throw std::runtime_error("Couldn't load file " + path.string());
        }

        return *this;
    }

    bool Sprite::is_valid() const {
        return m_data != nullptr;
    }

}