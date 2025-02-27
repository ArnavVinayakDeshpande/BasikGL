/**
 * @file core/error_handler.h
 * @brief Used for error handling and notifying.
 * @author Arnav Deshpande
 */

#pragma once

#include <string>

#include "core.h"

/**
 * @namespace bskgl
 * @brief Primary namespace of BasikGL Library.
 */
namespace bskgl {

    /**
     * @class ErrorHandler
     * @brief Static class for notifying about errors.
     */
    class BSK_API ErrorHandler {
    public:
        /**
         ** !!!!! IMPORTANT !!!!!
         * @property Flag to indicate if error handler should log to console.
         * If set to true, logging to file must be initialized else no error will be logged.
         */
        static bool disable_console_log;

    public:
        /**
         * @brief Creates a fatal error.
         * It stops execution of the program, used for fatal and critical errors.
         * 
         * @param[in] message Error message.
         * @param[in] file File in which the error occurred.
         * @param[in] func Function in which the error occurred.
         * @param[in] line Line at which the error occured.
         */
        static void fatal(const std::string& message, const std::string& file, const std::string& func, int32_t line);

        /**
         * @brief Creates an error.
         * It doesn't stop execution of the program, used for significant errors but not fatal.
         * 
         * @param[in] message Error message.
         * @param[in] file File in which the error occurred.
         * @param[in] func Function in which the error occurred.
         * @param[in] line Line at which the error occured.
         */
        static void error(const std::string& message, const std::string& file, const std::string& func, int32_t line);
        
        /**
         * @brief Creates a warning.
         * 
         * @param[in] message Warning message,
         */
        static void warning(const std::string& message);

        /**
         * @brief Asserts a condition in debug mode.
         * It only logs the result in release or distribution mode, and asserts the condition in debug mode.
         * 
         * @param[in] condition Condition to assert.
         * @param[in] message Message to log if the condition is false.
         * @param[in] func Function in which this method was called.
         * @param[in] line Line at which this method was called.
         */
        static void assert_check(bool condition, const std::string& message, const std::string& file, const std::string& func, int32_t line);

        /**
         * @brief Checks if a condition is critical.
         * In debug mode, it throws an assertion. In non-debug mode it throws an exception.
         * 
         * @param[in] condition Condition to check.
         * @param[in] message Message to log if the condition is false.
         * @param[in] func Function in which this method was called.
         * @param[in] line Line at which this method was called.
         */
        static void verify(bool condition, const std::string& message, const std::string& file, const std::string& func, int32_t line);
    };

}

/**
 * @def BSK_FATAL_ERROR
 * @brief Macro for fatal error.
 * 
 * @param[in] msg Error message.
 */
#define BSK_FATAL_ERROR(msg)                        bskgl::ErrorHandler::fatal(msg, __FILE__, BSK_FUNCTION_SIGNATURE, __LINE__);

/**
 * @def BSK_ERROR
 * @brief Macro for error.
 * 
 * @param[in] msg Error message.
 */
#define BSK_ERROR(msg)                              bskgl::ErrorHandler::error(msg, __FILE__, BSK_FUNCTION_SIGNATURE, __LINE__);

/**
 * @def BSK_WARNING
 * @brief Macro for warning.
 * 
 * @param[in] msg Warn message.
 */
#define BSK_WARNING(msg)                            bskgl::ErrorHandler::warning(msg);

/**
 * @def BSK_ASSERT
 * @brief Macro for assert.
 * Assert only works in debug mode, in any other mode it merely logs if the condition is false.
 * 
 * @param[in] cond Condition to check.
 * @param[in] msg Message to log if condition is false.
 */
#define BSK_ASSERT(cond, msg)                       bskgl::ErrorHandler::assert_check(cond, msg, __FILE__, BSK_FUNCTION_SIGNATURE, __LINE__);

/**
 * @def BSK_VERIFY
 * @brief Macro for critical check.
 * Asserts in debug mode, throws an exception in non-debug mode.
 * 
 * @param[in] cond Condition to check.
 * @param[in] msg Message to log if condition is false.
 */
#define BSK_VERIFY(cond, msg)               bskgl::ErrorHandler::verify(cond, msg, __FILE__, BSK_FUNCTION_SIGNATURE, __LINE__);