/**
 * @file gfx/IndexBuffer.h
 * @brief Contains the index buffer.
 * @author Arnav Deshpande
 */

#pragma once

#include <vector>

#include <core/core.h>
#include <gfx/asset.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration of AssetManager class.
    class AssetManager;

    /**
     * @class IndexBuffer
     * @brief Represents a opengl index buffer object
     * This class follows RAII..
     */
    class BSK_API IndexBuffer final : public Asset {
        friend AssetManager;
    private:
        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] num_indices Number of indices.
         */
        IndexBuffer(UUID uuid, size_t num_indices);

        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] indices Vector of indices.
         */
        IndexBuffer(UUID uuid, const std::vector<uint32_t>& indices);

    public:
        /**
         * @brief Move Constructor
         */
        IndexBuffer(IndexBuffer&& other) noexcept;

        /**
         * @brief Move Assignment Operator
         */
        IndexBuffer& operator=(const IndexBuffer& other) = delete;
        
        /**
         * @brief Destructor
         */
        ~IndexBuffer();

        IndexBuffer(const IndexBuffer& other) = delete;
        IndexBuffer& operator=(IndexBuffer&& other) noexcept;

        /**
         * @implements Asset::uuid()
         */
        [[nodiscard]]
        UUID uuid() const override;

        /**
         * @brief Returns the OpenGL ID of the buffer.
         * 
         * @retval uint32_t
         * @returns OpenGL ID of the buffer.
         */
        [[nodiscard]]
        uint32_t gl_id() const;

        /**
         * @brief Returns vector of indices.
         * 
         * @retval const std::vector<uint32_t>&
         * @returns Vector of indices.
         */
        [[nodiscard]] 
        const std::vector<uint32_t>& indices() const;

        /**
         * @brief Returns number of indices.
         * 
         * @retval size_t
         * @returns Number of indices stored in the buffer.
         */
        [[nodiscard]]
        size_t num_indices() const;

        /**
         * @brief Sets the indices.
         * Setting the indices does not update the buffer stored in the GPU, call @fn IndexBuffer::sync() to update the GPU side buffer.
         * 
         * @param[in] indices Vector of indices.
         * 
         * @retval IndexBuffer&
         * @returns Reference to the updated variable.
         */
        IndexBuffer& set_indices(const std::vector<uint32_t>& indices);

        /**
         * @brief Binds the index buffer.
         */
        void bind() const;

        /**
         * @brief Updates the GPU side buffer.
         * This function binds the buffer, updates the buffer and then unbinds the buffer.
         * 
         * @retval IndexBuffer&
         * @returns Reference to the updated variable.
         */
        IndexBuffer& sync();
        
        /**
         * @brief Unbinds the currently bound index buffer.
         */
        static void unbind();

    private:
        /**
         * @property Unique Universal Identifier of this instance.
         */
        UUID m_uuid;

        /**
         * @property GPU side id of this instance.
         */
        uint32_t m_glid;

        /**
         * @property Vector of indices stored in the buffer.
         */
        std::vector<uint32_t> m_indices;
    };

}