/**
 * @file window/window.h
 * @brief Provides functionality for window creation and usage.
 * @author Arnav Deshpande
 */

#pragma once

#include <unordered_map>

#include <core/core.h>
#include <window/window_attributes.h>
#include <window/window_properties.h>
#include <window/window_callbacks.h>
#include <input/keyinput.h>
#include <input/mouseinput.h>
#include <input/cursor.h>

/// @brief Forward declaration of GLFWwindow struct.
struct GLFWwindow;

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration of RenderContext class.
    class RenderContext;

    /**
     * @class Window
     * @brief Represents a graphical window.
     */
    class BSK_API Window {
        friend RenderContext;
    public:
        /**
         * @property Callback functions for window.
         */
        WindowCallbacks callbacks;

    private:
        /**
         * @brief Constructor
         * 
         * @param[in] properties Window properties.
         */
        Window(const WindowProperties& properties);

    public:
        /**
         * @brief Move Constructor
         */
        Window(Window&& other) noexcept;
        
        /**
         * @brief Move Assignment Operator
         */
        Window& operator=(Window&& other) noexcept;

        /**
         * @brief Destructor
         */
        ~Window();
        
        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;

        /**
         * @retval uint32_t
         * @returns Width of the window.
         */
        [[nodiscard]]
        uint32_t width() const;

        /**
         * @retval uint32_t
         * @returns Height of the window.
         */
        [[nodiscard]]
        uint32_t height() const;

        /**
         * @retval std::string_view
         * @returns Title of the window.
         */
        [[nodiscard]]
        std::string_view title() const;

        /**
         * @retval CursorMode
         * @returns Cursor mode of the window.
         */
        [[nodiscard]]
        CursorMode cursor_mode() const;

        /**
         * @brief Sets the properties the window.
         * 
         * @param[in] properties Window properties.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_properties(const WindowProperties& properties);

        /**
         * @brief Sets the window width.
         * 
         * @param[in] width Window width.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_width(uint32_t width);
        
        /**
         * @brief Set the window height.
         * 
         * @param[in] height Window height.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_height(uint32_t height);

        /**
         * @brief Sets the window title.
         * 
         * @param[in] title Window title.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_title(const std::string& title);

        /**
         * @brief Sets the cursor mode of the window.
         * 
         * @param[in] mode Cursor mode to be set.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_cursor_mode(CursorMode mode);

        /**
         * @brief Sets the window postion.
         * 
         * @param[in] postion Window position to be set as a glm::ivec2.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_window_position(glm::ivec2 position);

        /**
         * @brief Sets the cursor position.
         * 
         * @param[in] position Cursor position to be set as a glm::dvec2.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& set_cursor_position(glm::dvec2 position);

        /**
         * @brief Makes the context current.
         */
        void make_ctx_current() const;

        /**
         * @retval bool
         * @returns Is the window the current context.
         */
        [[nodiscard]]
        bool is_current_ctx() const;

        /**
         * @retval bool
         * @returns Is the window open.
         */
        [[nodiscard]]
        bool is_open() const;

        /**
         * @retval bool
         * @returns Is the window closed.
         */
        [[nodiscard]]
        bool is_closed() const;

        /**
         * This function returns true only if the key was pressed in the single current frame, else returns false.
         * 
         * @param[in] keycode Key code to check.
         * 
         * @retval bool
         * @returns Is the key pressed.
         */
        [[nodiscard]]
        bool is_key_pressed(KeyCode keycode) const;

        /**
         * This function returns true only if the key was released in the single current frame and was pressed in the immediate previous frame, else returns false.
         * 
         * @param[in] keycode Key code to check.
         * 
         * @retval bool
         * @returns Is the key released.
         */
        [[nodiscard]]
        bool is_key_released(KeyCode keycode) const;

        /**
         * @param[in] keycode Key code to check.
         * 
         * @retval bool
         * @returns Is key held.
         */
        [[nodiscard]]
        bool is_key_held(KeyCode keycode) const;

        /**
         * This function returns true only if the mouse button was pressed in the single current frame, else returns false.
         * 
         * @param[in] button Mouse button code to check.
         * 
         * @retval bool
         * @returns Is the mouse button pressed.
         */
        [[nodiscard]]
        bool is_mouse_button_pressed(MouseButtonCode button) const;

        /**
         * This function returns true only if the mouse button was released in the single current frame and was pressed in the immediate previous frame, else returns false.
         * 
         * @param[in] button Mouse button code to check.
         * 
         * @retval bool
         * @returns Is the mouse button released.
         */
        [[nodiscard]]
        bool is_mouse_button_held(MouseButtonCode button) const;
        
        /**
         * @param[in] button Mouse button code to check.
         * 
         * @retval bool
         * @returns Is mouse button held.
         */
        [[nodiscard]]
        bool is_mouse_button_released(MouseButtonCode button) const;

        /**
         * @retval glm::dvec2
         * @returns Position of the cursor.
         */
        [[nodiscard]]
        glm::dvec2 cursor_position() const;

        /**
         * @retval glm::ivec2
         * @returns Position of the window.
         */
        [[nodiscard]]
        glm::ivec2 window_position() const;

        /**
         * @brief Swaps front and back buffer.
         */
        void swap_buffers() const;

        /**
         * @brief Opens the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& open();

        /**
         * @brief Closes the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& close();

        /**
         * @brief Minimizes (iconifies) the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& minimize();

        /**
         * @brief Maximizes the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& maximize();

        /**
         * @brief Restores the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& restore();

        /**
         * @brief Focuses the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& focus();

        /**
         * @brief Requests window attention.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& request_attention();

        /**
         * @brief Centers window on the monitor.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& center_window_on_monitor();

        /**
         * @brief Centers cursor on the window.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& center_cursor_on_window();

        /**
         * @brief Enables the given attribute.
         * Ensure that only a single attribute is passed as a parameter, in case of an invalid input,
         * the function returns safely.
         * Supported attributes are  
         *      WindowAttribute::Decorated, 
         *      WindowAttribute::Resizable, 
         *      WindowAttribute::Floating, 
         *      WindowAttribute::AutoIconify,
         *      WindowAttribute::FocusOnShow, 
         *      WindowAttribute::MousePassthrough
         * Some of these attributes are ignored for full screen windows. The new value will take effect if the window is later made windowed.
         * Some of these attributes are ignored for windowed mode windows. The new value will take effect if the window is later made full screen.
         * 
         * @param[in] attribute Attribute to enable.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& enable_attribute(WindowAttribute attribute);

        /**
         * @brief Disables the given attribute.
         * Ensure that only a single attribute is passed as a parameter, in case of an invalid input,
         * the function returns safely.
         * Supported attributes are  
         *      WindowAttribute::Decorated, 
         *      WindowAttribute::Resizable, 
         *      WindowAttribute::Floating, 
         *      WindowAttribute::AutoIconify,
         *      WindowAttribute::FocusOnShow, 
         *      WindowAttribute::MousePassthrough
         * Some of these attributes are ignored for full screen windows. The new value will take effect if the window is later made windowed.
         * Some of these attributes are ignored for windowed mode windows. The new value will take effect if the window is later made full screen.
         * 
         * @param[in] attribute Attribute to disable.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& disable_attribute(WindowAttribute attribute);

        /**
         * @brief Checks if an attribute is enabled.
         * Ensure that only a single attribute is passed as a parameter.
         * If an invalid attribute or multiple attributes are given, the function returns false.
         * 
         * @param[in] attribute Attribute to check.
         * 
         * @retval bool
         * @returns Is the attribute enabled.
         */
        bool is_attribute_enabled(WindowAttribute attribute) const;

        /**
         * @brief Polls window events.
         */
        static void poll_events();

    private:
        /**
         * @brief Updates the window callbacks.
         * 
         * @retval Window&
         * @returns Reference to the updated variable.
         */
        Window& m_update_callbacks();


    private:
        /**
         * @property GLFW window.
         */
        GLFWwindow* m_window;

        /**
         * @property Previous key states.
         */
        mutable std::unordered_map<KeyCode, bool> m_previous_key_state;

        /**
         * @property Previous mouse states.
         */
        mutable std::unordered_map<MouseButtonCode, bool> m_previous_mouse_state;
    };
    
}