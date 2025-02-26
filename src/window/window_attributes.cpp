#include <GLFW/glfw3.h>

#include <window/window_attributes.h>

namespace bskgl {

    WindowAttribute operator|(WindowAttribute _lhs, WindowAttribute _rhs) {
        return 
            static_cast<WindowAttribute>(
                static_cast<uint16_t>(_lhs) | static_cast<uint16_t>(_rhs));
    }

    WindowAttribute operator^(WindowAttribute _lhs, WindowAttribute _rhs) {
        return 
            static_cast<WindowAttribute>(
                static_cast<uint16_t>(_lhs) ^ static_cast<uint16_t>(_rhs));
    }

    bool operator&(WindowAttribute _lhs, WindowAttribute _rhs) {
        return
            static_cast<bool>(
                static_cast<uint16_t>(_lhs) & static_cast<uint16_t>(_rhs));
    }

    WindowAttribute default_window_attributes() {
        return 
			WindowAttribute::Resizable 		    |
			WindowAttribute::Visible 			|
			WindowAttribute::Decorated		    |
			WindowAttribute::Focused 			|
			WindowAttribute::AutoIconify 	    |
			WindowAttribute::CenterCursor	    |
			WindowAttribute::FocusOnShow 	    |
			WindowAttribute::ScaleFramebuffer;
    }

    glm::ivec2 default_window_position() {
        return glm::ivec2(GLFW_ANY_POSITION);
    }

}