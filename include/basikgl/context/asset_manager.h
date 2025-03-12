/**
 * @file context/asset_manager.h
 * @brief Provides functionality for creation and destruction of assets.
 * @author Arnav Deshpande
 */

#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include <core/core.h>
#include <gfx/asset.h>
#include <utils/uuid_generator.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL Library.
 */
namespace bskgl {

    /// @brief Forward declaration of RenderContext class.
    class RenderContext;

    /// @brief Forward declaration of Vertex struct.
    struct Vertex;

    /// @brief Forward declaration of VertexArray class.
    class VertexArray;

    /**
     * @class AssetManager
     * @brief Creates, manages and destroys assets.
     */
    class BSK_API AssetManager final {
        friend RenderContext;
    public:       
        /**
         * @typedef AssetHandle
         * @brief Return handle for all assets, currently typedefed to std::shared_ptr.
         */
        template <typename T>
        using AssetHandle = std::shared_ptr<T>;

    private:
        /**
         * @brief Constructor
         * 
         * @param[in] parent_context Render context responsible for the asset manager.
         */
        AssetManager(const RenderContext& parent_context);
        
    public:
        /**
         * @brief Move Constructor
         */
        AssetManager(AssetManager&& other) noexcept;

        /**
         * @brief Destructor
         */
        ~AssetManager();
        
        AssetManager(const AssetManager& other) = delete;
        AssetManager& operator=(const AssetManager& other) = delete;
        AssetManager& operator=(AssetManager&& other) noexcept = delete;

        /**
         * @brief Creates an asset, see @class Asset in @headerfile gfx/asset.
         * 
         * @tparam Ast Asset type, @example Shader, VertexArray etc.
         * @tparam ...Args Arguments to be passed to constructor of the asset.
         * 
         * @param[in] args Arguments to be passed to constructor of the asset.
         * 
         * @retval UUID
         * @returns UUID of the newly created asset.
         */
        template <typename Ast, typename... Args>
        UUID create_asset(const Args& ...args) {
            m_bind_ctx();
    
            UUID uuid = utils::UUIDGenerator::generate();
    
            m_assets[uuid] = AssetHandle<Asset>(new Ast(uuid, args...));
    
            return uuid;
        }

        /**
         * @brief Returns a handle to the asset.
         * 
         * @tparam Ast Asset type, @example Shader, VertexArray etc.
         * 
         * @param[in] uuid UUID of the asset.
         * 
         * @retval AssetHandle<Ast>
         * @returns AssetHandle if the asset is found, nullptr else wise.
         */
        template <typename Ast>
        AssetHandle<Ast> get_asset(UUID uuid) const {
            auto it = m_assets.find(uuid);
    
            if (it != m_assets.end())
                return std::static_pointer_cast<Ast>(it->second);
    
            return nullptr;
        }

        /**
         * @brief Deletes the given asset.
         * 
         * @param[in] uuid UUID of the asset to delete.
         */
        void delete_asset(UUID uuid);

    private:
        /**
         * @brief Binds the parent context to make sure assets are correct context wise.
         */
        void m_bind_ctx();

    private:
        /**
         * @property Parent context.
         */
        const RenderContext& m_parent_ctx;

        /**
         * @property Created assets.
         */
        std::unordered_map<UUID, AssetHandle<Asset>> m_assets;
    };

    /**
     * @brief Template specialization for @class VertexArray.
     * 
     * @param[in] vertices Vector of @struct Vertex.
     * 
     * @retval UUID
     * @returns UUID of the created vertex array.
     */
    template <>
    UUID AssetManager::create_asset<VertexArray>(const std::vector<Vertex>& vertices);
    
    /**
     * @brief Template specialization for @class VertexArray.
     * 
     * @param[in] vertices Vector of @struct Vertex vertices.
     * @param[in] indices Vector of uint32_t indices.
     * 
     * @retval UUID
     * @returns UUID of the created vertex array.
     */
    template <>
    UUID AssetManager::create_asset<VertexArray>(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);

}