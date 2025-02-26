#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#include <gfx/shader.h>
#include <core/error_handler.h>
#include <utils/utils.h>

namespace bskgl {

    Shader::Shader(UUID uuid, const std::string& vertex_source, const std::string& pixel_source)
        :
        m_uuid(uuid),
        m_glid(glCreateProgram()),
        m_vert_glid(glCreateShader(GL_VERTEX_SHADER)),
        m_pixel_glid(glCreateShader(GL_FRAGMENT_SHADER)),
        m_uniforms() {
        m_compile(vertex_source, pixel_source);
    }

    Shader::Shader(UUID uuid, const std::filesystem::path& vertex_path, const std::filesystem::path& pixel_path)
        :
        m_uuid(uuid),
        m_glid(glCreateProgram()),
        m_vert_glid(glCreateShader(GL_VERTEX_SHADER)),
        m_pixel_glid(glCreateShader(GL_FRAGMENT_SHADER)),
        m_uniforms() {
        m_compile(utils::read_file(vertex_path), utils::read_file(pixel_path));
    }

    Shader::Shader(Shader&& other) noexcept
        :
        m_uuid(other.m_uuid),
        m_glid(other.m_glid),
        m_vert_glid(other.m_vert_glid),
        m_pixel_glid(other.m_pixel_glid),
        m_uniforms(std::move(other.m_uniforms)) {
        other.m_glid = other.m_vert_glid = other.m_pixel_glid = 0;
    }

    Shader& Shader::operator=(Shader&& other) noexcept {
        if (this == &other)
            return *this;

        m_uuid = other.m_uuid;
        m_glid = other.m_glid;
        m_vert_glid = other.m_vert_glid;
        m_pixel_glid = other.m_pixel_glid;
        m_uniforms = std::move(other.m_uniforms);
        other.m_glid = other.m_vert_glid = other.m_pixel_glid = 0;

        return *this;
    }

    Shader::~Shader() {
        glDeleteShader(m_vert_glid);
        glDeleteShader(m_pixel_glid);
        glDeleteProgram(m_glid);
    }

    UUID Shader::uuid() const {
        return m_uuid;
    }

    uint32_t Shader::gl_id() const {
        return m_glid;
    }

    uint32_t Shader::vertex_shdr_gl_id() const {
        return m_vert_glid;
    }
    
    uint32_t Shader::pixel_shdr_gl_id() const {
        return m_pixel_glid;
    }

    Shader& Shader::set_vertex_shader_source(const std::string& source_code) {
        m_compile(source_code, "");

        return *this;
    }
    
    Shader& Shader::set_pixel_shader_source(const std::string& source_code) {
        m_compile("", source_code);

        return *this;
    }

    Shader& Shader::set_vertex_shader_source(const std::filesystem::path& source_path) {
        m_compile(utils::read_file(source_path), "");

        return *this;
    }

    Shader& Shader::set_pixel_shader_source(const std::filesystem::path& source_path) {
        m_compile("", utils::read_file(source_path));

        return *this;
    }

    Shader& Shader::set_uniform(const std::string& name, const UniformValue& value) {
        m_uniforms[name] = value;

        return *this;
    }

    Shader& Shader::remove_uniform(const std::string& name) {
        auto it = m_uniforms.find(name);
        if (it != m_uniforms.end())
            m_uniforms.erase(it);

        return *this;
    }

    std::optional<Shader::UniformValue> Shader::uniform_value(const std::string& name) const {
        auto it = m_uniforms.find(name);
        if (it != m_uniforms.end())
            return it->second;
        
        return std::nullopt;
    }

    void Shader::bind() const {
        glUseProgram(m_glid);
        m_apply_uniforms();
    }

    void Shader::unbind() {
        glUseProgram(0);
    }

    void Shader::m_compile(const std::string& vert_source, const std::string& pixel_source) {
        static auto compile_shader =
            [](uint32_t id, const char* src) -> bool {
                if (id == 0 || src == NULL) {
                    BSK_ERROR("Shader compilation failed due to invalid id or null source.");
                    return false;
                }

                // Set the shader source
                glShaderSource(id, 1, &src, nullptr);

                // Compile the shader
                glCompileShader(id);

                // Error handling
                int32_t compile_result;
                glGetShaderiv(id, GL_COMPILE_STATUS, &compile_result);

                if (compile_result != GL_TRUE) {
                    int32_t info_log_length;
                    glGetShaderiv(id, GL_COMPILE_STATUS, &info_log_length);
                    char* info_log = new char[info_log_length + 1];
                    info_log[info_log_length] = '\0';
                    glGetShaderInfoLog(id, info_log_length, &info_log_length, info_log);
                    BSK_ERROR(info_log);
                    delete[] info_log;
                    return false;
                }

                return true;
            };

        // Compile vertex shader
        if (vert_source != "") {
            bool compiled = compile_shader(m_vert_glid, vert_source.c_str());
            if (!compiled)
                return;
        }

        // Compile pixel shader
        if (pixel_source != "") {
            bool compiled = compile_shader(m_pixel_glid, pixel_source.c_str());
            if (!compiled)
                return;
        }

        // Attach the shaders
        glAttachShader(m_glid, m_vert_glid);
        glAttachShader(m_glid, m_pixel_glid);

        // Link the program
        glLinkProgram(m_glid);

        // Error handling for linking
        int32_t link_result;
        glGetProgramiv(m_glid, GL_LINK_STATUS, &link_result);

        if (link_result != GL_TRUE) {
            int32_t info_log_length;
            glGetProgramiv(m_glid, GL_LINK_STATUS, &info_log_length);
            char* info_log = new char[info_log_length + 1];
            info_log[info_log_length] = '\0';
            glGetProgramInfoLog(m_glid, info_log_length, &info_log_length, info_log);
            BSK_ERROR(info_log);
            delete[] info_log;
            return;
        }

        // Valide the program
        glValidateProgram(m_glid);

        // Error handling for validation
        int32_t validate_result;
        glGetProgramiv(m_glid, GL_VALIDATE_STATUS, &validate_result);

        if (validate_result != GL_TRUE) {
            int32_t info_log_length;
            glGetProgramiv(m_glid, GL_LINK_STATUS, &info_log_length);
            char* info_log = new char[info_log_length + 1];
            info_log[info_log_length] = '\0';
            glGetProgramInfoLog(m_glid, info_log_length, &info_log_length, info_log);
            BSK_ERROR(info_log);
            delete[] info_log;
            return;
        }
    }

    void Shader::m_apply_uniforms() const {
        static constexpr auto apply_uniform =
            [](uint32_t id, const std::string& name, const UniformValue& value) {
                GLint location = glGetUniformLocation(id, name.c_str());
                if (location == -1) {
                    BSK_WARNING("Warning: Uniform '" + name + "' not found in shader.");
                    return;
                }
            
                std::visit([location](auto&& v) {
                    using T = std::decay_t<decltype(v)>;
            
                    if constexpr (std::is_same_v<T, float>) 
                        glUniform1f(location, v);
                    else if constexpr (std::is_same_v<T, double>) 
                        glUniform1d(location, v);
                    else if constexpr (std::is_same_v<T, uint32_t>) 
                        glUniform1ui(location, v);
                    else if constexpr (std::is_same_v<T, int32_t>) 
                        glUniform1i(location, v);
            
                    else if constexpr (std::is_same_v<T, glm::vec2>) 
                        glUniform2fv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dvec2>) 
                        glUniform2dv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::uvec2>) 
                        glUniform2uiv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::ivec2>) 
                        glUniform2iv(location, 1, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::vec3>) 
                        glUniform3fv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dvec3>) 
                        glUniform3dv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::uvec3>) 
                        glUniform3uiv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::ivec3>) 
                        glUniform3iv(location, 1, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::vec4>) 
                        glUniform4fv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dvec4>) 
                        glUniform4dv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::uvec4>) 
                        glUniform4uiv(location, 1, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::ivec4>) 
                        glUniform4iv(location, 1, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat2>) 
                        glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat2>) 
                        glUniformMatrix2dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat3>) 
                        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat3>) 
                        glUniformMatrix3dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat4>) 
                        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat4>) 
                        glUniformMatrix4dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat2x3>) 
                        glUniformMatrix2x3fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat2x3>) 
                        glUniformMatrix2x3dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat2x4>) 
                        glUniformMatrix2x4fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat2x4>) 
                        glUniformMatrix2x4dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat3x2>) 
                        glUniformMatrix3x2fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat3x2>) 
                        glUniformMatrix3x2dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat3x4>) 
                        glUniformMatrix3x4fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat3x4>) 
                        glUniformMatrix3x4dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat4x2>) 
                        glUniformMatrix4x2fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat4x2>) 
                        glUniformMatrix4x2dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, glm::mat4x3>) 
                        glUniformMatrix4x3fv(location, 1, GL_FALSE, glm::value_ptr(v));
                    else if constexpr (std::is_same_v<T, glm::dmat4x3>) 
                        glUniformMatrix4x3dv(location, 1, GL_FALSE, glm::value_ptr(v));
            
                    else if constexpr (std::is_same_v<T, Color>) {
                        glm::vec4 normalized = v.normalized();
                        glUniform4fv(location, 1, glm::value_ptr(normalized));
                    }
                }, 
                value
            );
        };

        for (const auto& [name, value] : m_uniforms)
            apply_uniform(m_glid, name, value);
    }
    

}