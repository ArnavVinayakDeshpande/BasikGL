#include <context/context_properties.h>

namespace bskgl {

    ContextProperties::ContextProperties(WindowProperties win_prop, Color clr_col)
        :
        window_properties(std::move(win_prop)),
        clear_color(clr_col) { }

}