/**
 * @file core/logger.h
 * @brief Contains functions used for logging content to console as well as file.
 * @author Arnav Deshpande
 */

#pragma once

#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#include <core/core.h>
#include <color/ansi_color_codes.h>

/**
 * @namespace bskgl
 * @brief Primary namespace of BasikGL library.
 */
namespace bskgl {

    /**
     * @class Logger
     * @brief Static class containing logging methods.
     * Contains log functions for both console and file.
     */
    class BSK_API Logger final {
    public:
        /**
         * @class Logger::Console
         * @brief Static class containing console logging methods.
         */
        class Console final {
        public:
            /**
             * @brief Logs content to the console
             * 
             * @param[in] content Content to log.
             */
            static void log(std::string_view content);

            /**
             * @brief Logs error message to the console.
             * 
             * @param[in] content Error message to log.
             * @param[in] file File in which error message was generated.
             * @param[in] func Function in which error nmessage was generated.
             * @param[in] line Line at which error message was generated.
             */
            static void error(const std::string& content, const std::string& file, const std::string& func, int32_t line);

            /**
             * @brief Logs information to the console.
             * 
             * @param[in] content Information to log.
             */
            static void info(const std::string& content);

            /**
             * @brief Logs variable amount of information the console.
             * Logs any and all types compatible with std::cout to the console.
             * 
             * @tparam First to @tparam ...Rest
             * 
             * @param[in] func Function in which the method was called.
             * @param[in] first First thing to log.
             * @param[in] rest(...) Rest of the things to log.
             */
            template <typename First, typename... Rest>
            static void trace(std::string_view func ,const First& first, const Rest&... rest) {
                std::string output(s_msg_format);
                std::ostringstream oss;
                oss << first;
                ((oss << ' ' << rest), ...);
                m_format_content(output, "trace", func, oss.str());

                std::cout 
                    << BSK_ANSI_COLOR_CODE_CYN_HIGH_INTENSITY
                    << output
                    << BSK_ANSI_COLOR_CODE_RESET
                    << '\n';
            }

            /**
             * @brief Flushes the console buffer.
             */
            static void flush_buffer();
        };

        /**
         * @class Logger::File
         * @brief Contains methods to log content to file.
         */
        class File final{
        public:
            /**
             * @brief Initializes the file logger.
             * Overrites content of the log file given.
             * 
             * @param[in] path Path to file used as log file, by default it is {CWD}/basik_log.txt.
             */
            static void initialize(const std::filesystem::path& path="basik_log.txt");

            /**
             * @brief Shutsdown and closes the log file.
             */
            static void shutdown();

            /**
             * @brief Returns path to the log file.
             * 
             * @retval const std::filesystem::path&
             * @returns Path to the log file.
             */
            [[nodiscard]] 
            static const std::filesystem::path& get_log_file();
            
            /**
             * @brief Returns if file logger has been initialized.
             * 
             * @retval bool
             * @returns If file logger has been initialied.
             */
            [[nodiscard]] 
            static bool is_initialized();

            /**
             * @brief Logs content to the console
             * 
             * @param[in] content Content to log.
             */
            static void log(std::string_view content);

            /**
             * @brief Logs error message to the console.
             * 
             * @param[in] content Error message to log.
             * @param[in] file File in which error message was generated.
             * @param[in] func Function in which error nmessage was generated.
             * @param[in] line Line at which error message was generated.
             */
            static void error(const std::string& content, const std::string& file, const std::string& func, int32_t line);

            /**
             * @brief Logs information to the console.
             * 
             * @param[in] content Information to log.
             */
            static void info(const std::string& content);

            /**
             * @brief Logs variable amount of information the console.
             * Logs any and all types compatible with std::cout to the console.
             * 
             * @tparam First to @tparam ...Rest
             * 
             * @param[in] func Function in which the method was called.
             * @param[in] first First thing to log.
             * @param[in] rest(...) Rest of the things to log.
             */
            template <typename First, typename... Rest>
            static void trace(std::string_view func, const First& first, const Rest&... rest) {
                if (!s_is_initalized) {
                    Logger::Console::error(
                        "Logging to file has not been initialized",
                        __FILE__,
                        "bskgl::Logger::File::trace(...)",
                        __LINE__);
                    return;
                }

                std::string output(s_msg_format);
                std::ostringstream oss;
                oss << first;
                ((oss << ' ' << rest), ...);
                Logger::m_format_content(output, "trace", func, oss.str());

                s_log_fstream << output << '\n';
            }

        private:
            /**
             * @property Path to the log file.
             */
            static std::filesystem::path s_logfile;

            /**
             * @property Log path file stream.
             */
            static std::ofstream s_log_fstream;

            /**
             * @property Flag showing if the logger has been initialized.
             */
            static bool s_is_initalized;
        };

    private:
        /**
         * @property Format for the logger.
         * @par %m is logger mode (log, error, info, trace).
         * @par %f is functionality, like file name, function name, line number for error, etc.
         * @par %c is the content to log.
         */
        constexpr static std::string_view s_msg_format = "[bskgl][%m](%f) %c";
        
    private:
        /**
         * @brief Formats content to suit the log format.
         * 
         * @param[inout] output Content to be formatted.
         * @param[in] mode Logger mode.
         * @param[in] functionality Logger functionality.
         * @param[in] content Content.
         */
        static void m_format_content(std::string& output, std::string_view mode, std::string_view functionality, std::string_view content);
    };

}

/**
 * @def BSK_CONSOLE_LOG
 * @brief Logs given message to console.
 * 
 * @param[in] msg Message to log.
 */
#define BSK_CONSOLE_LOG(msg)                bskgl::Logger::Console::log(msg);

/**
 * @def BSK_CONSOLE_ERROR
 * @brief Logs given error message to console.
 * Along with error message, also logs the file, function and line where the error message was generated.
 * 
 * @param[in] msg Error message to log.
 */
#define BSK_CONSOLE_ERROR(msg)              bskgl::Logger::Console::error(msg, __FILE__, BSK_FUNCTION_SIGNATURE, __LINE__);

/**
 * @def BSK_CONSOLE_INFO
 * @brief Logs given message to console.
 * It is meant to be used as a logging used by client to address users, not necessarily log matters related to the codebase itself.
 * 
 * @param[in] msg Information to log.
 */
#define BSK_CONSOLE_INFO(msg)               bskgl::Logger::Console::info(msg);

/**
 * @def BSK_CONSOLE_TRACE
 * @brief Logs multiple given values to console.
 * It takes in a variable number of parameters, and prints them using std::cout. 
 * Any type overloaded to be compatible with std::cout can be printed using this.
 * 
 * @param[in] __variable(...) All the contents to log.
 */
#define BSK_CONSOLE_TRACE(...)              bskgl::Logger::Console::trace(BSK_FUNCTION_SIGNATURE, __VA_ARGS__);