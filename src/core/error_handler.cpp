#include <cassert>

#include <core/error_handler.h>
#include <core/logger.h>

namespace bskgl {

    bool ErrorHandler::disable_console_log = false;

    void ErrorHandler::fatal(const std::string& message, const std::string& file, const std::string& func, int32_t line) {
        if (!disable_console_log)
            Logger::Console::error("[FATAL] " + message, file, func, line);

        if (Logger::File::is_initialized())
            Logger::File::error("[FATAL] " + message, file, func, line);
        
        throw std::runtime_error("Fatal Error: " + message);
    }

    void ErrorHandler::error(const std::string& message, const std::string& file, const std::string& func, int32_t line) {
        if (!disable_console_log)
            Logger::Console::error(message, file, func, line);

        if (Logger::File::is_initialized())
            Logger::File::error(message, file, func, line);
    }

    void ErrorHandler::warning(const std::string& message) {
        if (!disable_console_log)
            Logger::Console::info("[WARNING] " + message);

        if (Logger::File::is_initialized())
            Logger::File::info("[WARNING] " + message);
    }

    void ErrorHandler::assert_check(bool condition, const std::string& message, const std::string& file, const std::string& func, int32_t line) {
        #if defined(BSK_DEBUG)
            if (!condition) {
                if (!disable_console_log)
                    Logger::Console::error("[ASSERT FAILED] " + message, file, func, line);

                if (Logger::File::is_initialized())
                    Logger::File::error("[ASSERT FAILED] " + message, file, func, line);

                assert(condition);  // Trigger assertion in debug mode
            }
        #else
            if (!condition) {
                if (!disable_console_log)
                    Logger::Console::error("[ASSERT ERROR] " + message, file, func, line);

                if (Logger::File::is_initialized())
                    Logger::File::error("[ASSERT ERROR] " + message, file, func, line);
            }
        #endif
    }

    void ErrorHandler::verify(bool condition, const std::string& message, const std::string& file, const std::string& func, int32_t line) {
        #if defined(BSK_DEBUG)
            if (!condition) {
                if (!disable_console_log) 
                    Logger::Console::error("[CRITICAL CHECK FAILED]" + message, file, func, line);
                
                if (Logger::File::is_initialized())
                    Logger::File::error("[CRITICAL CHECK FAILED]" + message, file, func, line);
                assert(condition);    
            }
        #else
            if (!condition) {
                if (!disable_console_log)
                    Logger::Console::error("[CRITICAL CHECK FAILED]" + message, file, func, line);

                if (Logger::File::is_initialized())
                    Logger::File::error("[CRITICAL CHECK FAILED]" + message, file, func, line);
                throw std::runtime_error(message);
            }
        #endif
    }

}