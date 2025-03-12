#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <context/render_context.h>
#include <core/convert_values.h>

namespace bskgl {

    static GLbitfield clear_bits(GLClearBit clr_bits) {
        GLbitfield bitfield = 0;

        for (GLClearBit bit : { GLClearBit::Color, GLClearBit::Depth, GLClearBit::Stencil, GLClearBit::Accum }) {
            if (clr_bits & bit) {
                bitfield |= opengl::convert(bit);
            }
        }

        return bitfield;
    }

    RenderContext::RenderContext(UUID uuid, const ContextProperties& properties)
        :
        window(properties.window_properties),
        asset_manager(*this),
        renderer(*this),
        m_uuid(uuid) {
        this->bind();
        this->set_clear_color(properties.clear_color);
    }

    RenderContext::RenderContext(RenderContext&& other) noexcept
        :
        window(std::move(other.window)),
        asset_manager(std::move(other.asset_manager)),
        renderer(std::move(other.renderer)) {
        this->bind();
        this->set_clear_color(other.clear_color());
    }

    RenderContext::~RenderContext() {

    }

    UUID RenderContext::uuid() const {
        return m_uuid;
    }
    
    Color RenderContext::clear_color() const {
        glm::vec4 color;
        glGetFloatv(GL_COLOR_CLEAR_VALUE, glm::value_ptr(color));
        return Color(color);
    }

    void RenderContext::clear() const {
        glClear(clear_bits(m_clearbits));
    }

    RenderContext& RenderContext::enable(GLTest test) {
        glEnable(opengl::convert(test));
        m_enabled_tests = m_enabled_tests | test;

        return *this;
    }

    RenderContext& RenderContext::disable(GLTest test) {
        glDisable(opengl::convert(test));
        m_enabled_tests = m_enabled_tests ^ test;

        return *this;
    }

    RenderContext& RenderContext::set_clear_bits(GLClearBit clear_bits) {
        m_clearbits = m_clearbits | clear_bits;

        return *this;
    }

    RenderContext& RenderContext::set_clear_color(const Color& color) {
        glm::vec4 normalized = color.normalized();
        glClearColor(normalized.r, normalized.g, normalized.b, normalized.a);

        return *this;
    }

    void RenderContext::bind() const {
        this->window.make_ctx_current();
    }

}