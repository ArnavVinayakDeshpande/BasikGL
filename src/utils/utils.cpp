#include <fstream>
#include <stdexcept>
#include <type_traits>
#include <iostream>
#include <sstream>

#include <utils/utils.h>
#include <core/error_handler.h>

namespace bskgl::utils {

    std::string read_file(const std::filesystem::path& path) {
        std::ifstream file(path);

        if (!file.is_open()) {
            BSK_ERROR("Could not open file " + path.string());
            return std::string("");
        }

        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    void replace_first_substring(std::string& str, std::string_view from, std::string_view to) {
        size_t pos = str.find(from);

        if (pos != std::string::npos)
            str.replace(pos, from.size(), to);
    }

    void replace_all_substrings(std::string& str, std::string_view from, std::string_view to) {
        size_t pos = 0;
        while ((pos = str.find(from, pos) != std::string::npos)) {
            str.replace(pos, from.size(), to);
            pos += to.size();  // Move past the replaced substring to avoid infinite loops
        }
    }

}