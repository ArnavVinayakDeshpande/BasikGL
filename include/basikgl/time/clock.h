/**
 * @file time/clock.h
 * @brief Contains definition for CLock class.
 * @author Arnav Deshpande
 */

#pragma once

#include <chrono>

#include <basikgl/time/timespan.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class HighResolutionClock
     * @brief Clock class to be used for many purposes.
     */
    class HighResolutionClock {
    public:
        /**
         * @brief Default Constructor
         */
        HighResolutionClock();

        /**
         * @brief Copy Constructor
         */
        HighResolutionClock(const HighResolutionClock& other) = default;

        /**
         * @brief Move Constructor
         */
        HighResolutionClock(HighResolutionClock&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        HighResolutionClock& operator=(const HighResolutionClock& other) = default;

        /**
         * @brief Move Assignment Operator
         */
        HighResolutionClock& operator=(HighResolutionClock&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        virtual ~HighResolutionClock() = default;

        /**
         * @brief Restarts the clock.
         * 
         * @retval bskgl::Timespan ( @ref time/timespan.h) 
         * @returns Timespan of the total time the clock has ticked before being resetted.
         */
        Timespan restart();

        /**
         * @brief Returns elapsed time.
         * 
         * @retval bskgl::Timespan ( @ref time/timespan.h )
         * @returns Timespan of the total time the clock has ticked since it last got resetted.
         */
        [[nodiscard]] 
        Timespan elapsed_time() const;

        /**
         * @brief Returns delta time.
         * 
         * @retval bskgl::Timespan ( @ref time/timespan.h )
         * @returns Delta time calculated by difference using clock ticks.
         */
        [[nodiscard]] 
        Timespan delta_time() const;

        /**
         * @brief Ticks the clock.
         * 
         * @retval HighResolutionClock&
         * @returns Reference to the updated variable.
         */
        HighResolutionClock& tick();

    private:
        using ClockType = std::chrono::high_resolution_clock;
        using TimePoint = std::chrono::time_point<ClockType>;

    private:
        /**
         * @property Start time of the clock.
         */
        TimePoint m_start_time;

        /**
         * @property Time of last tick.
         */
        TimePoint m_last_tick;

        /**
         * @property Delta time.
         */
        Timespan m_delta_time;
    };

    /**
     * @typedef HighResolutionClock
     */
    typedef HighResolutionClock Clock;

} 