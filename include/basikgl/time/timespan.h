/**
 * @file time/timespan.h
 * @brief Contains definition for the Timespan class.
 * @author Arnav Deshpande
 */

#pragma once

#include <iostream>

#include <basikgl/core/core.h>

/**
 * @namespace bksgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class Timespan
     * @brief Represents a span of time.
     */
    class BSK_API Timespan {
    public:
        /**
         * @brief Constructor
         * 
         * @param[in] time_in_seconds Value of the time span in seconds, by default it is 0.
         */
        explicit Timespan(float time_in_seconds = 0.0f);

        /**
         * @brief Copy Constructor
         */
        Timespan(const Timespan& other) = default;

        /**
         * @brief Move Constructor
         */
        Timespan(Timespan&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        Timespan& operator=(const Timespan& other) = default;

        /**
         * @brief Move Assignment Operator
         */
        Timespan& operator=(Timespan&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        virtual ~Timespan() = default;

        /**
         * @brief Returns value of time span.
         * 
         * @retval float
         * @returns Value of time span in seconds.
         */
        float as_seconds() const;

        /**
         * @brief Returns value of time span.
         * 
         * @retval float
         * @returns Value of time span in milliseconds.
         */
        float as_milliseconds() const;

        /**
         * @brief Returns value of time span.
         * 
         * @retval float
         * @returns Value of time span in microseconds.
         */
        float as_microseconds() const;

        /**
         * @brief Returns value of time span.
         * 
         * @retval float
         * @returns Value of time span in nanoseconds.
         */
        float as_nanoseconds() const;

        /**
         * @brief Float operator
         * 
         * @returns Value of time span in seconds.
         */
        operator float() const;

        /**
         * @brief Equality operator
         * 
         * @param[in] other Timespan to check with
         * 
         * @retval bool
         * @returns If two timespans are equal.
         */
        bool operator==(const Timespan& other) const;

    private:
        /**
         * @property Value of time span in seconds.
         */
        float m_time_seconds;
    };

    /**
     * @brief Operator overload for bskgl::Timespan class.
     * 
     * @param[inout] os std::ostream Object.
     * @param[in] ts Timespan to be printed.
     * 
     * @retval std::ostream&
     * @returns @param os
     */
    std::ostream& BSK_API operator<<(std::ostream& os, const Timespan& ts);

} 