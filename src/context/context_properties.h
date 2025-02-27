/**
 * @file context/context_properties.h
 */

#pragma once

#include <core/core.h>
#include <window/window_properties.h>
#include <color/color.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class ContextProperties
     * @brief Properties used by a context at creation.
     */
    struct BSK_API ContextProperties final {
        /**
         * @property Window properties for the context.
         */
        WindowProperties window_properties;

        /**
         * @property Clear color for the context.
         */
        Color clear_color;

        /**
         * @brief Constructor
         * 
         * @param[in] win_prop Window properties.
         * @param[in] clr_color Clear color.
         */
        ContextProperties(WindowProperties win_prop, Color clr_col = Color(255, 255, 255));
    };

}