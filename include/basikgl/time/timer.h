#pragma once

#include <chrono>

#include <basikgl/core/core.h>
#include <basikgl/time/timespan.h>

namespace bskgl {

    class BSK_API HighResolutionTimer {
    public:
        using ClockType = std::chrono::high_resolution_clock;
        using Timepoint = std::chrono::high_resolution_clock::time_point;

    public:
        HighResolutionTimer();
        ~HighResolutionTimer();

        [[nodiscard]]
        Timespan stop();

        [[nodiscard]]
        Timespan elapsed() const;

    private:
        Timepoint m_start_time;
    };

    using Timer = HighResolutionTimer;

}