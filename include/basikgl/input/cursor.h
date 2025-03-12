/**
 * @file input/cursor.h
 * Defines cursor modes and provides functionality for converting between internal and GLFW cursor modes.
 * @author Arnav Deshpande
 */

#pragma once

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum CursorMode
     * @brief Represents different modes for the cursor's visibility and behavior.
     */
    enum class CursorMode {
        None,
        Normal,   
        Disabled, 
        Hidden,   
        Captured  
    };

} 