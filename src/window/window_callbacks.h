/**
 * @file window/window_callbacks.h
 * @brief Provides functionality for window callbacks.
 * @author Arnav Deshpande
 */

#pragma once

#include <functional>

#include <glm/vec2.hpp>

#include <core/core.h>
#include <input/keyinput.h>
#include <input/mouseinput.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration for Window class.
    class Window;

    /**
     * @struct WindowCallbacks
     * @brief Contains callback functions for window.
     */
    struct BSK_API WindowCallbacks final {
        /**
         * @property Callback function for key pressed.
         * @note CURRENTLY UNAVAIABLE.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] keycode Keycode of the key pressed.
         */
        /*std::function<void(Window&, KeyCode)> key_pressed_callback =
            [](Window&, KeyCode) { }; */

        /**
         * @property Callback function for key held.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] keycode Keycode of the key held.
         */
        std::function<void(Window&, KeyCode)> key_held_callback  =
            [](Window&, KeyCode) { };

        /**
         * @property Callback function for mouse button pressed.
         * @note CURRENTLY UNAVAIABLE
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] mousebuttoncode Mouse button code of button pressed.
         */
        // std::function<void(Window&, MouseButtonCode)> mouse_button_pressed_callback =
        //     [](Window&, MouseButtonCode) { };

        /**
         * @property Callback function for mouse button held.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] mousebuttoncode Mouse button code of button pressed.
         */
        std::function<void(Window&, MouseButtonCode)> mouse_button_held_callback  =
            [](Window&, MouseButtonCode) { };


        /**
         * @property Callback function for character pressed.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] char Character pressed as a uint32_t.
         */
        std::function<void(Window&, uint32_t)> char_callback =
            [](Window&, uint32_t) { };

        /**
         * @property Callback function for cursor position update.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] pos New position of the cursor as a glm::dvec2.
         */
        std::function<void(Window&, glm::dvec2)> cursor_pos_callback =
            [](Window&, glm::dvec2) { };

        /**
         * @property Callback function for cursor enter update.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] entered Has the cursor has entered.
         */
        std::function<void(Window&, bool)> cursor_enter_callback =
            [](Window&, bool) { };

        /**
         * @property Callback function for mouse scrolled.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] offset Offset as a glm::dvec2.
         */
        std::function<void(Window&, glm::dvec2)> scroll_callback =
            [](Window&, glm::dvec2) { };

        /**
         * @property Callback function for framebuffer size update.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] newsize New framebuffer size as a glm::uvec2.
         */
        std::function<void(Window&, glm::uvec2)> framebuffer_resize_callback =
            [](Window&, glm::uvec2) { };

        /**
         * @property Callback function for window closing.
         * 
         * @param[inout] window Reference to window where callback is registered.
         */
        std::function<void(Window&)> window_close_callback =
            [](Window&) { };

        /**
         * @property Callback function for window focus.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] focused Is the window focused.
         */
        std::function<void(Window&, bool)> window_focus_callback =
            [](Window&, bool) { };

        /**
         * @property Callback function for window iconification (minimizing).
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] iconified Is the window minimized.
         */
        std::function<void(Window&, bool)> window_iconify_callback =
            [](Window&, bool) { };

        /**
         * @property Callback function for window maximize.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] maxmimize Is the window maximized.
         */
        std::function<void(Window&, bool)> window_maximize_callback =
            [](Window&, bool) { };

        /**
         * @property Callback function for window refresh.
         * 
         * @param[inout] window Reference to window where callback is registered.
         */
        std::function<void(Window&)> window_refresh_callback =
            [](Window&) { };

        /**
         * @property Callback function for windiw pos change.
         * 
         * @param[inout] window Reference to window where callback is registered.
         * @param[in] pos New window pos as a glm::ivec2.
         */
        std::function<void(Window&, glm::ivec2)> window_pos_callback =
            [](Window&, glm::ivec2) { };

    public:
        /**
         * @brief Constructor
         */
        WindowCallbacks() = default;

        /**
         * @brief Copy Constructor
         */
        WindowCallbacks(const WindowCallbacks& other) = default;

        /**
         * @brief Move Constructor
         */
        WindowCallbacks(WindowCallbacks&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        WindowCallbacks& operator=(const WindowCallbacks& other) = default;

        /**
         * @brief Move Assignment Operator
         */
        WindowCallbacks& operator=(WindowCallbacks&& other) noexcept = default;
        
        /**
         * @brief Destructor
         */
        ~WindowCallbacks() = default;
    };

}