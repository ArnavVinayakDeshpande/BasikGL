#pragma once

#include <basikgl/core/core.h>
#include <basikgl/input/cursor.h>
#include <basikgl/window/window_attributes.h>

namespace bskgl {
    
    /**
     * @struct WindowProperties
     * @brief Holds the properties used to create and configure a window.
     */
    struct BSK_API WindowProperties final {
        /** 
         * @property Width .
         */
        uint32_t width;

        /** 
         * @property Height .
         */
        uint32_t height;

        /** 
         * @property Title .
         */
        std::string title;

        /** 
         * @property Cursor mode .
         */
        CursorMode cursor_mode;

        /** 
         * @property Attributes .
         */
        WindowAttribute attributes;

        /** 
         * @property Window position .
         */
        glm::ivec2 window_pos;

        /**
         * @brief Constructs a WindowProperties object.
         * @param[in] width The width of the window.
         * @param[in] height The height of the window.
         * @param[in] title The title of the window.
         * @param[in] cursor_mode The cursor mode.
         * @param[in] win_attr The window attributes.
         * @param[in] win_position The window position.
         * @param[in] cursor_position The cursor position.
         */
        WindowProperties(
            uint32_t win_width, 
            uint32_t win_height, 
            const std::string& win_title,
            CursorMode win_cursor_mode = CursorMode::Normal,
            WindowAttribute win_attr = default_window_attributes(),
            glm::ivec2 win_position = default_window_position()
        )
            :
            width(win_width),
            height(win_height),
            title(win_title),
            cursor_mode(win_cursor_mode),
            attributes(win_attr),
            window_pos(win_position) { }

        WindowProperties(const WindowProperties& _other) = default;
        WindowProperties(WindowProperties&& _other) noexcept = default;
        WindowProperties& operator=(const WindowProperties& _other) = default;
        WindowProperties& operator=(WindowProperties&& _other) noexcept = default;
        ~WindowProperties() = default;
    };

    }