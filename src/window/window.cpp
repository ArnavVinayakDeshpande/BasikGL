#include <GLFW/glfw3.h>

#include <window/window.h>
#include <core/convert_values.h>
#include <core/error_handler.h>

namespace bskgl {

    static void set_glfw_hints(WindowAttribute attributes) {

        for (
            WindowAttribute attr : 
            {
                WindowAttribute::Resizable, 
                WindowAttribute::Visible, 
                WindowAttribute::Decorated, 
                WindowAttribute::Focused, 
                WindowAttribute::AutoIconify, 
                WindowAttribute::Floating, 
                WindowAttribute::Maximized, 
                WindowAttribute::CenterCursor, 
                WindowAttribute::TransparentFramebuffer, 
                WindowAttribute::FocusOnShow, 
                WindowAttribute::ScaleToMonitor,
                WindowAttribute::ScaleFramebuffer,
                WindowAttribute::MousePassthrough              
            }
        ) {
            bool is_enabled = attributes & attr;
            glfwWindowHint(glfw::convert(attr), is_enabled? GLFW_TRUE : GLFW_FALSE);
        }
    }

    Window::Window(const WindowProperties& properties) {
        BSK_VERIFY(properties.width != 0, " Given window width is zero.");
        BSK_VERIFY(properties.height != 0, " Given window height is zero.");
        
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, BSK_OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, BSK_OPENGL_VERSION_MINOR);

        set_glfw_hints(properties.attributes);
        
        m_window =
            glfwCreateWindow(
                properties.width,
                properties.height,
                properties.title.c_str(),
                nullptr, nullptr);
        this->set_cursor_mode(properties.cursor_mode);

        // Initialize cached states
        for (
            int32_t i = static_cast<int32_t>(KeyCode::Space);
            i <= static_cast<int32_t>(KeyCode::Escape);
            i++
        ) {
            m_previous_key_state[static_cast<KeyCode>(i)] = false;
        }
        for (
            int32_t i = static_cast<int32_t>(MouseButtonCode::Button1);
            i <= static_cast<int32_t>(MouseButtonCode::Button8);
            i++
        ) {
            m_previous_mouse_state[static_cast<MouseButtonCode>(i)] = false;
        }

        glfwSetWindowUserPointer(m_window, this);
        m_update_callbacks();
    }

    Window::Window(Window&& other) noexcept
        :
        m_window(other.m_window),
        m_previous_key_state(std::move(other.m_previous_key_state)),
        m_previous_mouse_state(std::move(other.m_previous_mouse_state)) {
        other.m_window = nullptr;
    }

    Window& Window::operator=(Window&& other) noexcept {
        if (this == &other)
            return *this;

        m_window = other.m_window;
        m_previous_key_state = std::move(other.m_previous_key_state);
        m_previous_mouse_state = std::move(other.m_previous_mouse_state);
        other.m_window = nullptr;

        return *this;
    }

    Window::~Window() {
        if (m_window)
            glfwDestroyWindow(m_window);
    }

    static Window& get_window(GLFWwindow* window) {
        return *static_cast<Window*>(glfwGetWindowUserPointer(window));
    }

    uint32_t Window::width() const {
        int32_t width;

        glfwGetWindowSize(m_window, &width, nullptr);

        return static_cast<uint32_t>(width);
    }
    uint32_t Window::height() const {
        int32_t height;

        glfwGetWindowSize(m_window, nullptr, &height);

        return static_cast<uint32_t>(height);
    }

    std::string_view Window::title() const {
        return glfwGetWindowTitle(m_window);
    }

    CursorMode Window::cursor_mode() const {
        int32_t mode = glfwGetInputMode(m_window, GLFW_CURSOR);
        
        return glfw::convert_to_basikgl_cursor_mode(mode);
    }

    Window& Window::set_properties(const WindowProperties& properties) {
        this->set_width(properties.width);
        this->set_height(properties.height);
        this->set_title(properties.title);
        this->set_cursor_mode(properties.cursor_mode);
        /// @todo attributes
        this->set_window_position(properties.window_pos);
    
        return *this;
    }

    Window& Window::set_width(uint32_t width) {
        glfwSetWindowSize(m_window, width, this->height());

        return *this;
    }

    Window& Window::set_height(uint32_t height) {
        glfwSetWindowSize(m_window, this->width(), height);

        return *this;
    }

    Window& Window::set_title(const std::string& title) {
        glfwSetWindowTitle(m_window, title.c_str());

        return *this;
    }

    Window& Window::set_cursor_mode(CursorMode mode) {
        glfwSetInputMode(m_window, GLFW_CURSOR, glfw::convert(mode));

        return *this;
    }

    Window& Window::set_window_position(glm::ivec2 position) {
        glfwSetWindowPos(m_window, position.x, position.y);

        return *this;
    }

    Window& Window::set_cursor_position(glm::dvec2 position) {
        glfwSetCursorPos(m_window, position.x, position.y);

        return *this;
    }

    void Window::make_ctx_current() const {
        glfwMakeContextCurrent(m_window);
    }

    bool Window::is_open() const {
        return !glfwWindowShouldClose(m_window);
    }

    bool Window::is_closed() const {
        return glfwWindowShouldClose(m_window);
    }

    bool Window::is_key_pressed(KeyCode keycode) const {
        bool is_pressed = glfwGetKey(m_window, glfw::convert(keycode)) == GLFW_PRESS;
        bool was_pressed = m_previous_key_state[keycode];
        m_previous_key_state[keycode] = is_pressed;
        return is_pressed && !was_pressed;
    }

    bool Window::is_key_released(KeyCode keycode) const {
        bool is_released = glfwGetKey(m_window, glfw::convert(keycode)) == GLFW_RELEASE;
        bool was_pressed = m_previous_key_state[keycode];
        m_previous_key_state[keycode] = !is_released;
        return is_released && was_pressed;
    }

    bool Window::is_key_held(KeyCode keycode) const {
        return glfwGetKey(m_window, glfw::convert(keycode)) == GLFW_PRESS;
    }

    bool Window::is_mouse_button_pressed(MouseButtonCode button) const {
        bool is_pressed = glfwGetMouseButton(m_window, glfw::convert(button)) == GLFW_PRESS;
        bool was_pressed = m_previous_mouse_state[button];
        m_previous_mouse_state[button] = is_pressed;
        return is_pressed && !was_pressed;
    }

    bool Window::is_mouse_button_held(MouseButtonCode button) const {
        bool is_released = glfwGetMouseButton(m_window, glfw::convert(button)) == GLFW_RELEASE;
        bool was_pressed = m_previous_mouse_state[button];
        m_previous_mouse_state[button] = !is_released;
        return is_released && was_pressed;
    }
    
    bool Window::is_mouse_button_released(MouseButtonCode button) const {
        return glfwGetMouseButton(m_window, glfw::convert(button)) == GLFW_PRESS;
    }

    glm::dvec2 Window::cursor_position() const {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);
        return glm::dvec2(xpos, ypos);
    }

    glm::ivec2 Window::window_position() const {
        int32_t xpos, ypos;
        glfwGetWindowPos(m_window, &xpos, &ypos);
        return glm::ivec2(xpos, ypos);
    }

    void Window::swap_buffers() const {
        glfwSwapBuffers(m_window);
    }   

    Window& Window::m_update_callbacks() {
        // Key callback
        auto key_callback =
            [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t modes) {
                Window& win = get_window(window);

                KeyCode keycode = glfw::convert_to_basikgl_key_code(key);

                win.callbacks.key_held_callback(win, keycode);

            };
        glfwSetKeyCallback(m_window, key_callback);

        // Mouse callback
        auto mouse_callback =
            [](GLFWwindow* window, int32_t button, int32_t action, int32_t modes) {
                Window& win = get_window(window);

                MouseButtonCode button_code = glfw::convert_to_basikgl_mouse_button_code(button);

                win.callbacks.mouse_button_held_callback(win, button_code);
            };
        glfwSetMouseButtonCallback(m_window, mouse_callback);

        // Character callback
        auto char_callback =
            [](GLFWwindow* window, uint32_t character) {
                Window& win = get_window(window);
                win.callbacks.char_callback(win, character);
            };
        glfwSetCharCallback(m_window, char_callback);

        // Cursor pos callback
        auto cursor_pos_callback =
            [](GLFWwindow* window, double xpos, double ypos) {
                Window& win = get_window(window);
                win.callbacks.cursor_pos_callback(win, glm::dvec2(xpos, ypos));
            };
        glfwSetCursorPosCallback(m_window, cursor_pos_callback);

        // Cursor enter callback
        auto cursor_enter_callback =
            [](GLFWwindow* window, int32_t entered) {
                Window& win = get_window(window);
                win.callbacks.cursor_enter_callback(win, static_cast<bool>(entered));
            };
        glfwSetCursorEnterCallback(m_window, cursor_enter_callback);

        // Scroll callback
        auto scroll_callback =
            [](GLFWwindow* window, double x_offset, double y_offset) {
                Window& win = get_window(window);
                win.callbacks.scroll_callback(win, glm::dvec2(x_offset, y_offset));
            };
        glfwSetScrollCallback(m_window, scroll_callback);

        // Framebuffer resize callback
        auto framebuffer_resize_callback =
            [](GLFWwindow* window, int32_t width, int32_t height) {
                Window& win = get_window(window);
                win.callbacks.framebuffer_resize_callback(
                    win, 
                    glm::uvec2(
                        static_cast<uint32_t>(width),
                        static_cast<uint32_t>(height)
                    )
                );
            };
        glfwSetFramebufferSizeCallback(m_window, framebuffer_resize_callback);

        // Window close callback
        auto window_close_callback =
            [](GLFWwindow* window) {
                Window& win = get_window(window);
                win.callbacks.window_close_callback(win);
            };
        glfwSetWindowCloseCallback(m_window, window_close_callback);

        // Window focus callback
        auto window_focus_callback =
            [](GLFWwindow* window, int32_t focused) {
                Window& win = get_window(window);
                win.callbacks.window_focus_callback(win, static_cast<bool>(focused));
            };
        glfwSetWindowFocusCallback(m_window, window_focus_callback);

        // Window maximize callback
        auto window_maximize_callback =
            [](GLFWwindow* window, int32_t maximized) {
                Window& win = get_window(window);
                win.callbacks.window_maximize_callback(win, static_cast<bool>(maximized));
            };
        glfwSetWindowMaximizeCallback(m_window, window_maximize_callback);

        // Window refresh callback
        auto window_refresh_callback =
            [](GLFWwindow* window) {
                Window& win = get_window(window);
                win.callbacks.window_refresh_callback(win);
            };
        glfwSetWindowRefreshCallback(m_window, window_refresh_callback);

        // Window pos callback
        auto window_pos_callback =
            [](GLFWwindow* window, int32_t xpos, int32_t ypos) {
                Window& win = get_window(window);
                win.callbacks.window_pos_callback(win, glm::ivec2(xpos, ypos));
            };
        glfwSetWindowPosCallback(m_window, window_pos_callback);

        return *this;
    }

    Window& Window::open() {
        glfwSetWindowShouldClose(m_window, GLFW_FALSE);

        return *this;
    }

    Window& Window::close() {
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);

        return *this;
    }

    Window& Window::minimize() {
        glfwIconifyWindow(m_window);

        return *this;
    }

    Window& Window::maximize() {
        glfwMaximizeWindow(m_window);

        return *this;
    }

    Window& Window::restore() {
        glfwRestoreWindow(m_window);

        return *this;
    }

    Window& Window::focus() {
        glfwFocusWindow(m_window);

        return *this;
    }

    Window& Window::request_attention() {
        glfwRequestWindowAttention(m_window);

        return *this;
    }

    Window& Window::center_window_on_monitor() {
        // Get the window monitor
        GLFWmonitor* monitor = glfwGetWindowMonitor(m_window);

        // Verify
        BSK_VERIFY(monitor != nullptr, " Monitor of window is null");

        // Get monitor work area
        int32_t monitor_x, monitor_y, monitor_width, monitor_height;
        glfwGetMonitorWorkarea(monitor, &monitor_x, &monitor_y, &monitor_width, &monitor_height);

        // Get window size
        int32_t window_width, window_height;
        glfwGetWindowSize(m_window, &window_width, &window_height);

        // Compute centered position
        int new_x = monitor_x + (monitor_width - window_width) / 2;
        int new_y = monitor_y + (monitor_height - window_height) / 2;

        // Set the position
        glfwSetWindowPos(m_window, new_x, new_y);

        return *this;
    }

    Window& Window::center_cursor_on_window() {
        glm::dvec2 pos(
            static_cast<double>(this->width()) / 2.0f,
            static_cast<double>(this->height()) / 2.0f);
        
        this->set_cursor_position(pos);

        return *this;
    }

    Window& Window::enable_attribute(WindowAttribute attribute) {
        if (attribute == WindowAttribute::None)
            return *this;

        int32_t glfw_value = glfw::convert(attribute);

        if (glfw_value == -1)
            return *this;

        glfwSetWindowAttrib(m_window, glfw_value, GLFW_TRUE);

        return *this;   
    }
    
    Window& Window::disable_attribute(WindowAttribute attribute) {
        if (attribute == WindowAttribute::None)
            return *this;

        int32_t glfw_value = glfw::convert(attribute);

        if (glfw_value == -1)
            return *this;

        glfwSetWindowAttrib(m_window, glfw_value, GLFW_FALSE);

        return *this;   
    }

    bool Window::is_attribute_enabled(WindowAttribute attribute) const {
        if (attribute == WindowAttribute::None)
            return false;

        int32_t glfw_value = glfw::convert(attribute);

        if (glfw_value == -1)
            return false;

        return glfwGetWindowAttrib(m_window, glfw_value) == GLFW_TRUE;
    }

    void Window::poll_events() {
        glfwPollEvents();
    }

}