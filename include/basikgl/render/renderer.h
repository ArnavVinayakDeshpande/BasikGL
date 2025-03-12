#pragma once

#include <basikgl/core/core.h>
#include <basikgl/context/asset_manager.h>

namespace bskgl {

    class RenderContext;
    class Shader;

    class BSK_API Renderer final {
        friend RenderContext;
    private:
        Renderer(const RenderContext& parent_context);

    public:
        Renderer(Renderer&& other) noexcept;
        ~Renderer();
        
        Renderer(const Renderer& other) = delete;
        Renderer& operator=(const Renderer& other) = delete;
        Renderer& operator=(Renderer&& other) noexcept = delete;

        void render(UUID vertexarray, UUID shader);

    private:
        const RenderContext& m_parent_ctx;
        AssetManager::AssetHandle<VertexArray> m_cached_va;
        AssetManager::AssetHandle<Shader> m_cached_shader;
    };

}