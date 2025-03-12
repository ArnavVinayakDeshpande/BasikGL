/**
 * @file gfx/vertexbuffer.h
 * @brief Contains the vertex buffer.
 * @author Arnav Deshpande
 */

#pragma once

#include <vector>

#include <basikgl/core/core.h>
#include <basikgl/gfx/vertex.h>
#include <basikgl/gfx/asset.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration of AssetManager class.
    class AssetManager;

    /**
     * @class VertexBuffer
     * @brief Represents a opengl vertex buffer object
     * This class follows RAII.
     */
    class BSK_API VertexBuffer final : public Asset {
        friend AssetManager;
    private:
        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] num_vertices Number of vertices.
         */
        VertexBuffer(UUID uuid, size_t num_vertices);

        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] vertices Vector of vertices.
         */
        VertexBuffer(UUID uuid, const std::vector<Vertex>& vertices);

    public:
        /**
         * @brief Move Constructor
         */
        VertexBuffer(VertexBuffer&& other) noexcept;

        /**
         * @brief Move Assignment Operator
         */
        VertexBuffer& operator=(const VertexBuffer& other) = delete;
        
        /**
         * @brief Destructor
         */
        ~VertexBuffer();

        VertexBuffer(const VertexBuffer& other) = delete;
        VertexBuffer& operator=(VertexBuffer&& other) noexcept;

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
         * @brief Returns vector of vertices.
         * 
         * @retval const std::vector<Vertex>&
         * @returns Vector of vertices.
         */
        [[nodiscard]] 
        const std::vector<Vertex>& vertices() const;

        /**
         * @brief Returns number of vertices.
         * 
         * @retval size_t
         * @returns Number of vertices stored in the buffer.
         */
        [[nodiscard]]
        size_t num_vertices() const;

        /**
         * @brief Sets the vertices.
         * Setting the vertices does not update the buffer stored in the GPU, call @fn VertexBuffer::sync() to update the GPU side buffer.
         * 
         * @param[in] vertices Vector of vertices.
         * 
         * @retval VertexBuffer&
         * @returns Reference to the updated variable.
         */
        VertexBuffer& set_vertices(const std::vector<Vertex>& vertices);

        /**
         * @brief Binds the vertex buffer.
         */
        void bind() const;

        /**
         * @brief Updates the GPU side buffer.
         * This function binds the buffer, updates the buffer and then unbinds the buffer.
         * 
         * @retval VertexBuffer&
         * @returns Reference to the updated variable.
         */
        VertexBuffer& sync();
        
        /**
         * @brief Unbinds the currently bound vertex buffer.
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
         * @property Vector of vertices stored in the buffer.
         */
        std::vector<Vertex> m_vertices;
    };

}