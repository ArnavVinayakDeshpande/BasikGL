/**
 * @file window/window_attributes.h
 * @brief Provides functionality for window attributes.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/vec2.hpp>

#include <basikgl/core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum WindowAttribute
     * @brief Represents various attributes that can be set for a window.
     */
    enum class WindowAttribute : uint16_t {
        None                     = 0     ,
        Resizable                = 1 << 0, 
        Visible                  = 1 << 1, 
        Decorated                = 1 << 2, 
        Focused                  = 1 << 3, 
        AutoIconify              = 1 << 4, 
        Floating                 = 1 << 5, 
        Maximized                = 1 << 6, 
        CenterCursor             = 1 << 7, 
        TransparentFramebuffer   = 1 << 8, 
        FocusOnShow              = 1 << 9, 
        ScaleToMonitor           = 1 << 10,
        ScaleFramebuffer         = 1 << 11,
        MousePassthrough         = 1 << 12 
    };

    /**
     * @brief Performs a bitwise OR operation on two WindowAttribute values.
     * 
     * @param[in] lhs The left-hand side WindowAttribute.
     * @param[in] rhs The right-hand side WindowAttribute.
     * 
     * @retval WindowAttribute 
     * @returns The resulting attribute set.
     */
    WindowAttribute BSK_API operator|(WindowAttribute lhs, WindowAttribute rhs);

    /**
     * @brief Performs a bitwise XOR operation on two WindowAttribute values.
     * @param[in] lhs The left-hand side WindowAttribute.
     * @param[in] rhs The right-hand side WindowAttribute.
     * 
     * @retval WindowAttribute 
     * @returns The resulting attribute set.
     */
    WindowAttribute BSK_API operator^(WindowAttribute lhs, WindowAttribute rhs);

    /**
     * @brief Checks if a given attribute is set.
     * @param[in] lhs The attribute set.
     * @param[in] rhs The attribute to check.
     * 
     * @retval bool 
     * @returns True if the attribute is set, false otherwise.
     */
    bool BSK_API operator&(WindowAttribute lhs, WindowAttribute rhs);

    /**
     * @brief Gets the default window attributes.
     * 
     * @retval WindowAttribute 
     * @returns The default attribute set.
     */
    WindowAttribute BSK_API default_window_attributes();

    /**
     * @brief Gets the default window position.
     * 
     * @retval glm::uvec2 
     * @returns The default window position.
     */
    glm::ivec2 BSK_API default_window_position();

}