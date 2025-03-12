/**
 * @file gfx/shader.h
 * @brief Contains definitions for Shader program containing vertex shader and pixel (fragment) shader.
 * @author Arnav Deshpande
 */
#pragma once

#include <filesystem>
#include <string>
#include <variant>
#include <unordered_map>
#include <optional>

#include <glm/glm.hpp>

#include <basikgl/core/core.h>
#include <basikgl/gfx/asset.h>
#include <basikgl/color/color.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration for AssetManager class.
    class AssetManager;

    /**
     * @class Shader
     * @brief Contains implementation for handling shader program with a vertex and pixel (fragment) shader.
     */
    class BSK_API Shader final : public Asset {
        friend AssetManager;
    public:
        /**
         * @property Possible values for uniforms.
         */
        using UniformValue = std::variant<
            /// @brief Primitives
            float,
            double,
            uint32_t,
            int32_t,
            
            /// @brief Vectors
            glm::vec2,
            glm::dvec2,
            glm::uvec2,
            glm::ivec2,
            glm::vec3,
            glm::dvec3,
            glm::uvec3,
            glm::ivec3,
            glm::vec4,
            glm::dvec4,
            glm::uvec4,
            glm::ivec4,

            /// @brief Matrices
            glm::mat2,
            glm::dmat2,
            glm::mat3,
            glm::dmat3,
            glm::mat4,
            glm::dmat4,
            glm::mat2x3,
            glm::dmat2x3,
            glm::mat2x4,
            glm::dmat2x4,
            glm::mat3x2,
            glm::dmat3x2,
            glm::mat3x4,
            glm::dmat3x4,
            glm::mat4x2,
            glm::dmat4x2,
            glm::mat4x3,
            glm::dmat4x3,

            /// @brief BasikGL types
            Color
        >;
    
    private:
        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] vertex_source Vertex source code.
         * @param[in] pixel_source Pixel source code.
         */
        Shader(UUID uuid, const std::string& vertex_source, const std::string& pixel_source);

        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] vertex_path Vertex source file path.
         * @param[in] pixel_path Pixel source file path
         */
        Shader(UUID uuid, const std::filesystem::path& vertex_path, const std::filesystem::path& pixel_path);

        Shader(const Shader& other) = delete;
        Shader& operator=(const Shader& other) = delete;

    public:
        /**
         * @brief Move Constructor
         */
        Shader(Shader&& other) noexcept;

        /**
         * @brief Move Assignment Operator
         */
        Shader& operator=(Shader&& other) noexcept;

        /**
         * @brief Destructor
         */
        ~Shader();

        /**
         * @implements Asset::uuid()
         */
        [[nodiscard]]
        UUID uuid() const override;

        /**
         * @brief Returns OpenGL ID of the shader program.
         * 
         * @retval uint32_t
         * @returns OpenGL ID of the shader program.
         */
        [[nodiscard]]
        uint32_t gl_id() const;

        /**
         * @brief Returns OpenGL ID of the vertex shader.
         * 
         * @retval uint32_t
         * @returns OpenGL ID of the vertex shader.
         */
        [[nodiscard]]
        uint32_t vertex_shdr_gl_id() const;

        /**
         * @brief Returns OpenGL ID of the pixel (fragment) shader.
         * 
         * @retval uint32_t
         * @returns OpenGL ID of the pixel (fragment) shader.
         */
        [[nodiscard]]
        uint32_t pixel_shdr_gl_id() const;

        /**
         * @brief Sets the vertex shader source.
         * This function updates GPU side program immediately after execution.
         * 
         * @param[in] source_code Vertex shader source code.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& set_vertex_shader_source(const std::string& source_code);

        /**
         * @brief Sets the pixel (fragment) shader source.
         * This function updates GPU side program immediately after execution.
         * 
         * @param[in] source_code Pixel (fragment) shader source code.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& set_pixel_shader_source(const std::string& source_code);

        /**
         * @brief Sets the vertex shader source.
         * This function updates GPU side program immediately after execution.
         * 
         * @param[in] source_path File path to vertex shader source.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& set_vertex_shader_source(const std::filesystem::path& source_path);

        /**
         * @brief Sets the pixel (fragment) shader source.
         * This function updates GPU side program immediately after execution.
         * 
         * @param[in] source_path File path to pixel (fragment) shader source.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& set_pixel_shader_source(const std::filesystem::path& source_path);

        /**
         * @brief Sets the uniform value.
         * 
         * @param[in] name Uniform name.
         * @param[in] value Uniform value.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& set_uniform(const std::string& name, const UniformValue& value);

        /**
         * @brief Removes the uniform.
         * 
         * @param[in] name Uniform name.
         * 
         * @retval Shader&
         * @returns Reference to the updated variable.
         */
        Shader& remove_uniform(const std::string& name);

        /**
         * @brief Gets the uniform value.
         * 
         * @param[in] name Uniform name.
         * 
         * @retval std::optional<UniformValue>
         * @returns Value of the uniform if exists, else std::nullopt.
         */
        std::optional<UniformValue> uniform_value(const std::string& name) const;

        /**
         * @brief Binds the shader program, also updates the shader with all the stored uniform values.
         */
        void bind() const;

        /**
         * @brief Unbinds currently bound shader program.
         */
        static void unbind();

    private:
        /**
         * @brief Compiles, attaches and links the program.
         * 
         * @param[in] vert_source Vertex shader source.
         * @param[in] pixel_source Pixel (fragment) shader source.
         */
        void m_compile(const std::string& vert_source, const std::string& pixel_source);

        /**
         * @brief Sets all the uniform values.
         */
        void m_apply_uniforms() const;

    private:
        /**
         * @property UUID of this instance.
         */
        UUID m_uuid;

        /**
         * @property OpenGL side ID of this program.
         */
        uint32_t m_glid;

        /**
         * @property OpenGL side ID of the vertex shader.
         */
        uint32_t m_vert_glid;

        /**
         * @property OpenGL side ID of the pixel (fragment) shader.
         */
        uint32_t m_pixel_glid;

        /**
         * @property Uniform values stored in the shader.
         */
        std::unordered_map<std::string, UniformValue> m_uniforms;
    };

}

/**
 * @todo Implement quering shader source.
 */