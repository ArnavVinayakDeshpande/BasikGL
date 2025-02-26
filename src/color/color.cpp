#include <color/color.h>

namespace bskgl {

    Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        m_rgba =
            (red   << 24) |
            (green << 16) |
            (blue  << 8)  |
            (alpha << 0);
    }

    Color::Color(uint8_t rgb, uint8_t alpha) {
        m_rgba =
            (rgb   << 24) |
            (rgb << 16) |
            (rgb  << 8)  |
            (alpha << 0);
    }

    Color::Color(uint32_t rgba) {
        m_rgba = rgba;
    }

    Color::Color(const glm::vec4& rgba) {
        glm::vec4 nn_rgba = rgba * 255.0f;
        m_rgba =
            ((uint8_t) nn_rgba.r   << 24)  |
            ((uint8_t) nn_rgba.g   << 16)  |
            ((uint8_t) nn_rgba.b   << 8)   |
            ((uint8_t) nn_rgba.a   << 0);
    }

    uint8_t Color::red_component() const {
        return m_rgba >> 24;
    }

    uint8_t Color::green_component() const {
        return m_rgba >> 16;
    }

    uint8_t Color::blue_component() const {
        return m_rgba >> 8;
    }

    uint8_t Color::alpha_component() const {
        return m_rgba >> 0;
    }

    uint32_t Color::rgba() const {
        return m_rgba;
    }

    glm::vec4 Color::normalized() const {
        return 
            glm::vec4(
                this->red_component(),
                this->green_component(),
                this->blue_component(),
                this->alpha_component()) / 255.0f;
    }

    Color& Color::set_red(uint8_t r) {
        m_rgba = (m_rgba & 0x00FFFFFF) | (r << 24);

        return *this;
    }

    Color& Color::set_green(uint8_t g) {
        m_rgba = (m_rgba & 0xFF00FFFF) | (g << 16);

        return *this;
    }

    Color& Color::set_blue(uint8_t b) {
        m_rgba = (m_rgba & 0xFFFF00FF) | (b << 8);

        return *this;
    }

    Color& Color::set_alpha(uint8_t a) {
        m_rgba = (m_rgba & 0xFFFFFF00) | (a << 0);

        return *this;
    }

    Color& Color::set_rgba(uint32_t rgba) {
        m_rgba = rgba;

        return *this;
    }

    Color& Color::set_rgba(const glm::vec4& rgba) {
        glm::vec4 nn_rgba = rgba * 255.0f;
        m_rgba =
            ((uint8_t) nn_rgba.r   << 24)  |
            ((uint8_t) nn_rgba.g   << 16)  |
            ((uint8_t) nn_rgba.b   << 8)   |
            ((uint8_t) nn_rgba.a   << 0);

        return *this;
    }

    Color& Color::reset_red() {
        m_rgba = m_rgba & 0x00FFFFFF;

        return *this;
    }

    Color& Color::reset_green() {
        m_rgba = m_rgba & 0xFF00FFFF;

        return *this;
    }

    Color& Color::reset_blue() {
        m_rgba = m_rgba & 0xFFFF00FF;

        return *this;
    }

    Color& Color::reset_alpha() {
        m_rgba = m_rgba & 0xFFFFFF00;

        return *this;
    }

    Color& Color::reset() {
        m_rgba = m_rgba & 0x00000000;

        return *this;
    }

    Color Color::complementary() const {
        return Color(255 - red_component(), 255 - green_component(), 255 - blue_component(), alpha_component());
    }
    
    Color Color::adjust_brightness(float factor) const {
        auto clamp = [](int value) { return static_cast<uint8_t>(glm::clamp(value, 0, 255)); };
    
        int r = static_cast<int>(red_component() * (1.0f + factor));
        int g = static_cast<int>(green_component() * (1.0f + factor));
        int b = static_cast<int>(blue_component() * (1.0f + factor));
    
        return Color(clamp(r), clamp(g), clamp(b), alpha_component());
    }
    
    Color Color::to_grayscale() const {
        uint8_t gray = static_cast<uint8_t>(0.299f * red_component() + 0.587f * green_component() + 0.114f * blue_component());
        return Color(gray, gray, gray, alpha_component());
    }
    
    glm::vec3 Color::to_hsv() const {
        glm::vec4 normalized = this->normalized();
        glm::vec3 hsv;
        float min = glm::min(glm::min(normalized.r, normalized.g), normalized.b);
        float max = glm::max(glm::max(normalized.r, normalized.g), normalized.b);
        float delta = max - min;
    
        if (delta < 0.00001f) {
            hsv.x = 0.0f;
        } else if (max == normalized.r) {
            hsv.x = 60.0f * fmod(((normalized.g - normalized.b) / delta), 6.0f);
        } else if (max == normalized.g) {
            hsv.x = 60.0f * (((normalized.b - normalized.r) / delta) + 2.0f);
        } else {
            hsv.x = 60.0f * (((normalized.r - normalized.g) / delta) + 4.0f);
        }
    
        if (max > 0.0f) {
            hsv.y = delta / max;
        } else {
            hsv.y = 0.0f;
        }
    
        hsv.z = max;
        return hsv;
    }

    Color Color::mix(const Color& lhs, const Color& rhs, float t) {
        return Color(
            t * rhs.red_component()   + (1.0f - t) * lhs.red_component(),
            t * rhs.green_component() + (1.0f - t) * lhs.green_component(),
            t * rhs.blue_component()  + (1.0f - t) * lhs.blue_component(),
            t * rhs.alpha_component() + (1.0f - t) * lhs.alpha_component()
        );
    }

    Color Color::from_hsv(const glm::vec3& hsv) {
        float c = hsv.z * hsv.y;
        float x = c * (1.0f - fabs(fmod(hsv.x / 60.0f, 2.0f) - 1.0f));
        float m = hsv.z - c;
    
        glm::vec3 rgb;
        if (hsv.x < 60)         rgb = {c, x, 0};
        else if (hsv.x < 120)   rgb = {x, c, 0};
        else if (hsv.x < 180)   rgb = {0, c, x};
        else if (hsv.x < 240)   rgb = {0, x, c};
        else if (hsv.x < 300)   rgb = {x, 0, c};
        else                    rgb = {c, 0, x};
    
        return Color(
            static_cast<uint8_t>((rgb.r + m) * 255),
            static_cast<uint8_t>((rgb.g + m) * 255),
            static_cast<uint8_t>((rgb.b + m) * 255)
        );
    }
    
    Color Color::blend(const Color& src, const Color& dest) {
        float srcA = src.alpha_component() / 255.0f;
        float destA = dest.alpha_component() / 255.0f;
        float outA = srcA + destA * (1.0f - srcA);
    
        auto blend_component = [&](uint8_t srcC, uint8_t destC) -> uint8_t {
            return static_cast<uint8_t>((srcC * srcA + destC * destA * (1.0f - srcA)) / outA);
        };
    
        return Color(
            blend_component(src.red_component(), dest.red_component()),
            blend_component(src.green_component(), dest.green_component()),
            blend_component(src.blue_component(), dest.blue_component()),
            static_cast<uint8_t>(outA * 255)
        );
    }

    Color Color::white() {
        return Color(255, 255);
    }

    Color Color::black() {
        return Color(0);
    }

    Color Color::red() {
        return Color(255, 0, 0);
    }

    Color Color::green() {
        return Color(0, 255, 0);
    }

    Color Color::blue() {
        return Color(0, 0, 255);
    }

}