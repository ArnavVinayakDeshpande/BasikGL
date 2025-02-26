#pragma once

#include <core/core.h>
#include <time/clock.h>

namespace bskgl {

    /// @todo

    class BSK_API Timer final {
    public:
        Timer(bool log_to_console = true, bool log_to_file = true);

        ~Timer();

        [[nodiscard]]
        Timespan stop();

    private:
        HighResolutionClock m_clock;
    };

}