#include <time/timespan.h>

namespace bskgl {

    Timespan::Timespan(float time_in_seconds)
        :
        m_time_seconds(time_in_seconds) { }

    float Timespan::seconds() const {
        return m_time_seconds;
    }

    float Timespan::milliseconds() const {
        return m_time_seconds * 10e3;
    }

    float Timespan::microseconds() const {
        return m_time_seconds * 10e6;
    }

    float Timespan::nanoseconds() const {
        return m_time_seconds * 10e9;
    }

    Timespan::operator float() const {
        return this->seconds();
    }
    
    bool Timespan::operator==(const Timespan& other) const {
        return m_time_seconds == other.m_time_seconds;
    }

    std::ostream& operator<<(std::ostream& os, const Timespan& ts) {
        // Don't flush the buffer or print out newline character, cuz whyy not
        os << "Timespan: " << ts.seconds() << " sec";
    
        return os;
    }

}