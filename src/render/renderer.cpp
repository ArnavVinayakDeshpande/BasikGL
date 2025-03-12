#include <glad/glad.h>

#include <render/renderer.h>
#include <gfx/vertexarray.h>
#include <gfx/shader.h>
#include <core/error_handler.h>
#include <context/render_context.h>
#include <core/logger.h>

namespace bskgl {

    Renderer::Renderer(const RenderContext& parent_context)
        :
        m_parent_ctx(parent_context),
        m_cached_va(nullptr),
        m_cached_shader(nullptr) { }

    Renderer::Renderer(Renderer&& other) noexcept 
        :
        m_parent_ctx(other.m_parent_ctx),
        m_cached_va(other.m_cached_va),
        m_cached_shader(other.m_cached_shader) { }

    Renderer::~Renderer() {

    }

    void Renderer::render(UUID va, UUID shdr) {
        if (!(m_cached_va) || va != m_cached_va->uuid()) {
            m_cached_va = m_parent_ctx.asset_manager.get_asset<VertexArray>(va);
        }
        if (!(m_cached_shader) || shdr != m_cached_shader->uuid()) {
            m_cached_shader = m_parent_ctx.asset_manager.get_asset<Shader>(shdr);
        }

        if (!(m_cached_va) || !(m_cached_shader)) {
            BSK_ERROR("Invalid asset UUID given.")
            return;
        }

        m_parent_ctx.bind();

        m_cached_shader->bind();
        m_cached_va->bind();

        if (m_cached_va->does_ibuffer_exist()) {
            glDrawElements(GL_TRIANGLES, m_cached_va->num_vertices(), GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, m_cached_va->num_vertices());
        }

        m_cached_shader->unbind();
        m_cached_va->unbind();
    }


}