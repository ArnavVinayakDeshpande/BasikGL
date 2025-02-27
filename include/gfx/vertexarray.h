/**
 * @file gfx/vertexarray.h
 * @brief Contains definitions for vertex arrays.
 * @author Arnav Deshpande
 */

#pragma once

#include <memory>

#include <core/core.h>
#include <gfx/asset.h>
#include <gfx/vertexbuffer.h>
#include <gfx/indexbuffer.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration for AssetManager class.
    class AssetManager;

    /**
     * @class VertexArray
     * @brief Represents an opengl vertex array.
     * This class follows RAII.
     */
    class BSK_API VertexArray final : public Asset {
        friend AssetManager;
    private:
        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] vbuffer Shared ptr of the vertex buffer.
         * @param[in] ibuffer Shared ptr of the index buffer.
         */
        VertexArray(UUID uuid, std::shared_ptr<VertexBuffer> vbuffer, std::shared_ptr<IndexBuffer> ibuffer);

    public:
        /**
         * @brief Move Constructor
         */
        VertexArray(VertexArray&& other) noexcept;
        
        /**
         * @brief Move Assignment Operator
         */
        VertexArray& operator=(VertexArray&& other) noexcept;

        /**
         * @brief Destructor
         */
        ~VertexArray();

        VertexArray(const VertexArray& other) = delete;
        VertexArray& operator=(const VertexArray& other) = delete;

        /**
         * @implements Asset::uuid()
         */
        [[nodiscard]]
        UUID uuid() const override;
        
        /**
         * @brief Returns the OpenGL ID of the buffer.
         * 
         * @retval uint32_t
         * @returns OpenGL ID of the buffer
         */
        [[nodiscard]]
        uint32_t gl_id() const;

        /**
         * @brief Returns vector of vertices.
         * 
         * @retval const std::vector<Vertex>&
         * @returns Vector of vertices.
         */
        [[nodiscard]]
        const std::vector<Vertex>& vertices() const;

        /**
         * @brief Returns vector of indices.
         * 
         * @retval const std::vector<uint32_t>&
         * @returns Vector of indices.
         */
        [[nodiscard]]
        const std::vector<uint32_t>& indices() const;

        /**
         * @brief Returns number of vertices.
         * 
         * @retval size_t
         * @returns Number of vertices stored in the buffer.
         */
        [[nodiscard]]
        size_t num_vertices() const;

        /**
         * @brief Returns number of indices.
         * 
         * @retval size_t
         * @returns Number of indices stored in the buffer.
         */
        [[nodiscard]]
        size_t num_indices() const;

        /**
         * @brief Returns uuid vertex buffer associated in the array.
         * 
         * @retval UUID
         * @returns Vertex buffer
         */
        [[nodiscard]]
        UUID vbuffer() const;
        
        /** 
         * @brief Returns index buffer associated in the array.
         * 
         * @retval UUID
         * @returns Index Buffer
         */
        [[nodiscard]]
        UUID ibuffer() const;

        /**
         * @brief Sets the vertices.
         * Setting the vertices does not update the buffer stored in the GPU, call @fn VertexArray::sync() to update the GPU side array.
         * 
         * @param[in] vertices Vector of vertices.
         * 
         * @retval VertexArray&
         * @returns Reference to the updated variable.
         */
        VertexArray& set_vertices(const std::vector<Vertex>& vertices);

        /**
         * @brief Sets the indices.
         * Setting the indices does not update the buffer stored in the GPU, call @fn VertexArray::sync() to update the GPU side array.
         * 
         * @param[in] indices Vector of indices.
         * 
         * @retval VertexArray&
         * @returns Reference to the updated variable.
         */
        VertexArray& set_indices(const std::vector<uint32_t>& indices);

        /**
         * @brief Binds the vertex buffer.
         */
        void bind() const;
        
        /**
         * @brief Updates the GPU side array.
         * This function binds the array, updates the array and then unbinds the array.
         * 
         * @retval VertexArray&
         * @returns Reference to the updated variable.
         */
        VertexArray& sync();

        /**
         * @brief Unbinds the currently bound vertex array.
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
         * @property Vertex buffer associated with the array.
         */
        std::shared_ptr<VertexBuffer> m_vbuffer;

        /**
         * @property Index buffer associated with the array.
         */
        std::shared_ptr<IndexBuffer> m_ibuffer;
    };

}