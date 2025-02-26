#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

#include <core/logger.h>
#include <core/error_handler.h>
#include <utils/utils.h>

namespace bskgl {

    std::filesystem::path Logger::File::s_logfile;
    std::ofstream Logger::File::s_log_fstream;
    bool Logger::File::s_is_initalized = false;

    void Logger::Console::log(std::string_view content) {
        std::string output(s_msg_format);

        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

        m_format_content(output, "log", ss.str(), content);

        std::cout 
            << BSK_ANSI_COLOR_CODE_YEL_HIGH_INTENSITY
            << output
            << BSK_ANSI_COLOR_CODE_RESET
            << '\n';
    }

    void Logger::Console::error(const std::string& content, const std::string& file, const std::string& func, int32_t line) {
        std::string output(s_msg_format);

        m_format_content(
            output, 
            "err", 
            "F:" + file +", f:" + func + ", l:" + std::to_string(line),
            std::string("\n") + content);

        std::cerr
            << BSK_ANSI_COLOR_CODE_RED_HIGH_INTENSITY
            << output
            << BSK_ANSI_COLOR_CODE_RESET
            << '\n';
    }

    void Logger::Console::info(const std::string& content) {
        std::string output(s_msg_format);

        m_format_content(
            output,
            "info",
            "",
            content);

        std::cout
            << BSK_ANSI_COLOR_CODE_MAG_HIGH_INTENSITY
            << output
            << BSK_ANSI_COLOR_CODE_RESET
            << '\n';
    }

    void Logger::Console::flush_buffer() {
        std::cout.flush();
        std::cerr.flush();
    }

    void Logger::File::initialize(const std::filesystem::path& _path) {
        s_logfile = _path;

        s_log_fstream.open(s_logfile);

        if (s_log_fstream.bad()) {
            BSK_ERROR("Failed to open given log file" + _path.string());
            return;
        }
        
        s_is_initalized = true;
    }

    void Logger::File::shutdown() {
        s_log_fstream.close();
        s_is_initalized = false;
    }

    const std::filesystem::path& Logger::File::get_log_file() {
        return s_logfile;
    }

    bool Logger::File::is_initialized() {
        return s_is_initalized;
    }

    void Logger::File::log(std::string_view content) {
        if (!s_is_initalized) {
            BSK_ERROR("Logging to file has not been initialized");
            return;
        }

        std::string output(s_msg_format);

        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

        m_format_content(output, "log", ss.str(), content);

        s_log_fstream << output << '\n';
    }

    void Logger::File::error(const std::string& content, const std::string& file, const std::string& func, int32_t line) {
        if (!s_is_initalized) {
            BSK_ERROR("Logging to file has not been initialized");
            return;
        }

        std::string output(s_msg_format);

        m_format_content(
            output, 
            "err", 
            "F:" + file +", f:" + func + ", l:" + std::to_string(line),
            content);

        s_log_fstream << output << '\n';
    }

    void Logger::File::info(const std::string& content) {
        if (!s_is_initalized) {
            BSK_ERROR("Logging to file has not been initialized");
            return;
        }

        std::string output(s_msg_format);

        m_format_content(
            output,
            "info",
            "",
            content);

        s_log_fstream << output << '\n';
    }

    void Logger::m_format_content( std::string& output, std::string_view mode,  std::string_view functionality,  std::string_view content) {
        utils::replace_first_substring(output, "%m", mode);
        utils::replace_first_substring(output, "%f", functionality);
        utils::replace_first_substring(output, "%c", content);
    }

}