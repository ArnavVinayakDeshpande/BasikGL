#include <time/timespan.h>

namespace bskgl {

    Timespan::Timespan(float time_in_seconds)
        :
        m_time_seconds(time_in_seconds) { }

    float Timespan::as_seconds() const {
        return m_time_seconds;
    }

    float Timespan::as_milliseconds() const {
        return m_time_seconds * 10e3;
    }

    float Timespan::as_microseconds() const {
        return m_time_seconds * 10e6;
    }

    float Timespan::as_nanoseconds() const {
        return m_time_seconds * 10e9;
    }

    Timespan::operator float() const {
        return this->as_seconds();
    }
    
    bool Timespan::operator==(const Timespan& other) const {
        return m_time_seconds == other.m_time_seconds;
    }

    std::ostream& operator<<(std::ostream& os, const Timespan& ts) {
        // don't flush the buffer or print out newline character, cuz why not
        os << "Timespan: " << ts.as_seconds() << " sec";
    
        return os;
    }

}