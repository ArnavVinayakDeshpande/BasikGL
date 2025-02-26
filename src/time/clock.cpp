#include <time/clock.h>

namespace bskgl {

    HighResolutionClock::HighResolutionClock() 
        :
        m_start_time(ClockType::now()),
        m_last_tick(m_start_time), 
        m_delta_time(0.0f) { }

    Timespan HighResolutionClock::restart() {
        auto now = ClockType::now();
        std::chrono::duration<float> elapsed = now - m_start_time;
        m_start_time = now;
        return Timespan(elapsed.count());
    }

    Timespan HighResolutionClock::elapsed_time() const {
        auto now = ClockType::now();
        std::chrono::duration<float> elapsed = now - m_start_time;
        return Timespan(elapsed.count());
    }

    Timespan HighResolutionClock::delta_time() const {
        return m_delta_time;
    }

    HighResolutionClock& HighResolutionClock::tick() {
        auto now = ClockType::now();
        std::chrono::duration<float> frame_time = now - m_last_tick;
        
        // Update delta time
        m_delta_time = Timespan(frame_time.count());
        m_last_tick = now;

        return *this;
    }

}