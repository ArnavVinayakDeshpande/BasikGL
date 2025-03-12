#include <time/timer.h>
#include <core/logger.h>

namespace bskgl {
 
    HighResolutionTimer::HighResolutionTimer() 
        :
        m_start_time(ClockType::now()) { }

    HighResolutionTimer::~HighResolutionTimer() { } 
    
    Timespan HighResolutionTimer::stop() {
        Timepoint current_time = ClockType::now();
        Timespan time(
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::duration<float>(
                    current_time - m_start_time
                )
            ).count()
        );
        m_start_time = current_time;
        return time;
    }

    Timespan HighResolutionTimer::elapsed() const {
        return Timespan(
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::duration<float>(
                    ClockType::now() - m_start_time
                )
            ).count()
        );
    }

}