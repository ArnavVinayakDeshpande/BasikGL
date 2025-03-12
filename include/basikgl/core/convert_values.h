/**
 * @file core/convert_values.h
 * @brief Provides functionality to convert basikgl enum values to OpenGL / GLFW values and vice versa.
 * @author Arnav Deshpande
 */

#pragma once

#include <core/core.h>
#include <gfx/texture/texture.h>
#include <context/gl_tests.h>
#include <input/keyinput.h>
#include <input/mouseinput.h>
#include <input/cursor.h>
#include <window/window_attributes.h>

/**
 * @namespace bskgl::opengl
 * @brief Namespace for direct conversion from basikgl enum values to OpenGL values and vice cersa.
 */
namespace bskgl::opengl {

    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] type TextureBase::Type
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::Type type);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] int_format TextureBase::InternalFormat
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::InternalFormat int_format);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] format TextureBase::Format
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::Format format);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] data_type TextureBase::DataType
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::DataType data_type);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] min_filter TextureBase::MinFilter
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::MinFilter min_filter);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] mag_filter TextureBase::MagFilter
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::MagFilter mag_filter);
    
    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] wrap_mode OpenGL value.
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]] 
    int32_t BSK_API convert(TextureBase::WrapMode wrap_mode);

    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] test OpenGL value.
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(GLTest test);

    /**
     * @brief Converts given enums to OpenGL appropriate values.
     * 
     * @param[in] clearbit GLCLearbit
     * 
     * @retval int32_t
     * @returns OpenGL compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(GLClearBit clearbit);

    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] type OpenGL value.
     * 
     * @retval TextureBase::Type
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::Type BSK_API convert_to_basikgl_texture_type(int32_t type);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] int_format OpenGL value.
     * 
     * @retval TextureBase::    TextureBase::InternalFormat BSK_API convert_to_texture_internal_format(int32_t int_format);
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::InternalFormat BSK_API convert_to_basikgl_texture_internal_format(int32_t int_format);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] format OpenGL value.
     * 
     * @retval TextureBase::Format
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::Format BSK_API convert_to_basikgl_texture_format(int32_t format);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] data_type OpenGL value.
     * 
     * @retval TextureBase::DataType
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::DataType BSK_API convert_to_basikgl_texture_data_type(int32_t data_type);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] min_filter OpenGL value.
     * 
     * @retval TextureBase::MinFilter
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::MinFilter BSK_API convert_to_basikgl_texture_min_filter(int32_t min_filter);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * 
     * @param[in] mag_filter OpenGL value.
     * 
     * @retval TextureBase::MagFilter
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::MagFilter BSK_API convert_to_basikgl_texture_mag_filter(int32_t mag_filter);
    
    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * @param[in] wrap_mode OpenGL value.
     * 
     * @retval TextureBase::WrapMode
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]] 
    TextureBase::WrapMode BSK_API convert_to_basikgL_texture_wrap_mode(int32_t wrap_mode);

    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * @param[in] test OpenGL value.
     * 
     * @retval GLTest
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]]
    GLTest BSK_API convert_to_basikgl_gltest(int32_t test);

    /**
     * @brief Converts given OpenGL values to BasikGL appropriate enums.
     * 
     * @param[in] clearbit OpenGL value.
     * 
     * @retval GLClearBit
     * @returns BasikGL compatible enums.
     */
    [[nodiscard]]
    GLClearBit BSK_API convert_to_basikgl_gl_clear_bit(int32_t clearbit);

}

/**
 * @namespace bskgl::glfw
 * @brief Namespace for direct conversion from basikgl enum values to GLFW values and vice cersa.
 */
namespace bskgl::glfw {

    /**
     * @brief Converts given enums to GLFW appropriate values.
     * 
     * @param[in] key_code KeyCode
     * 
     * @retval int32_t
     * @returns GLFW compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(KeyCode key_code);

    /**
     * @brief Converts given enums to GLFW appropriate values.
     * 
     * @param[in] key_mode KeyMode
     * 
     * @retval int32_t
     * @returns GLFW compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(KeyMode key_mode);

    /**
     * @brief Converts given enums to GLFW appropriate values.
     * 
     * @param[in] mouse_button MouseButtonCode
     * 
     * @retval int32_t
     * @returns GLFW compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(MouseButtonCode mouse_button);

    /**
     * @brief Converts given enums to GLFW appropriate values.
     * 
     * @param[in] cursor_mode CursorMode
     * 
     * @retval int32_t
     * @returns GLFW compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(CursorMode cursor_mode);

    /**
     * @brief Converts  given enums to GLFW appropriate values.
     * 
     * @param[in] window_attibute WindowAttribute
     * 
     * @retval int32_t
     * @returns GLFW compatible values.
     */
    [[nodiscard]]
    int32_t BSK_API convert(WindowAttribute window_attibute);

    /**
     * @brief Convers given GLFW values to basikgl enums.
     * 
     * @param[in] key_code GLFW value for key code
     * 
     * @retval KeyCode
     * @returns Basikgl compatible enums.
     */
    [[nodiscard]]
    KeyCode BSK_API convert_to_basikgl_key_code(int32_t key_code);

    /**
     * @brief Convers given GLFW values to basikgl enums.
     * This function throws a fatal error on getting a value not matchable to basigl enum.
     * 
     * @param[in] key_mode GLFW value for key mode
     * 
     * @retval KeyMode
     * @returns Basikgl compatible enums.
     */
    [[nodiscard]]
    KeyMode BSK_API convert_to_basikgl_key_mode(int32_t key_mode);

    /**
     * @brief Convers given GLFW values to basikgl enums.
     * This function throws a fatal error on getting a value not matchable to basigl enum.
     * 
     * @param[in] mouse_button GLFW value for mouse button
     * 
     * @retval MouseButtonCode
     * @returns Basikgl compatible enums.
     */
    [[nodiscard]]
    MouseButtonCode BSK_API convert_to_basikgl_mouse_button_code(int32_t mouse_button);

    /**
     * @brief Convers given GLFW values to basikgl enums.
     * This function throws a fatal error on getting a value not matchable to basigl enum.
     * 
     * @param[in] cursor_mode GLFW value for cursor mode
     * 
     * @retval CursorMode
     * @returns Basikgl compatible enums.
     */
    [[nodiscard]]
    CursorMode BSK_API convert_to_basikgl_cursor_mode(int32_t cursor_mode);

}