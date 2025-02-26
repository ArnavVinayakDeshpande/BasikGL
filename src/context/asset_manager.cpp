#include <context/asset_manager.h>
#include <context/render_context.h>
#include <gfx/vertexarray.h>

namespace bskgl {

    AssetManager::AssetManager(const RenderContext& parent_context)
        :
        m_parent_ctx(parent_context),
        m_assets() { }

    AssetManager::AssetManager(AssetManager&& other) noexcept
        :
        m_parent_ctx(other.m_parent_ctx),
        m_assets(std::move(other.m_assets)) {
    }

    AssetManager::~AssetManager() {
        for (auto& asset : m_assets) {
            asset.second.reset();
        }
    }

    void AssetManager::delete_asset(UUID uuid) {
        auto it = m_assets.find(uuid);

        if (it != m_assets.end())
            m_assets.erase(it);
    }

    void AssetManager::m_bind_ctx() {
        m_parent_ctx.bind();
    }

    template <>
    UUID AssetManager::create_asset<VertexArray>(const std::vector<Vertex>& vertices) {
        return this->create_asset<VertexArray>(vertices, std::vector<uint32_t>({}));
    }

    template <>
    UUID AssetManager::create_asset<VertexArray>(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices) {
        UUID vb_uuid = this->create_asset<VertexBuffer>(vertices);
        UUID ib_uuid = this->create_asset<IndexBuffer>(indices);
        UUID va_uuid = this->create_asset<VertexArray>(this->get_asset<VertexBuffer>(vb_uuid), this->get_asset<IndexBuffer>(ib_uuid));

        return va_uuid;
    }

}