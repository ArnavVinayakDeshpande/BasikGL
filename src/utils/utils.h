/**
 * @file utils/utils.h
 * @brief Contains utility function.
 * @author Arnav Deshpande
 */

#pragma once

#include <string>
#include <string_view>
#include <filesystem>

#include <core/core.h>

/**
 * @namespace bskgl::utils
 * @brief Namespace for utility functions in BasikGL.
 */
namespace bskgl::utils {

    /**
     * @brief Reads contents of given file.
     * 
     * @param[in] path Path to file.
     * 
     * @retval std::string
     * @returns Contents of the given file.
     */
    [[nodiscard]]
    std::string BSK_API read_file(const std::filesystem::path& path);

    /**
     * @brief Replaces substring within given string.
     * Replaces first occurence of the given substring in the string.
     * 
     * @param[inout] str Reference to string containing the substring to be replaced.
     * @param[in] from Substring to replace.
     * @param[in] to Substring to replace with.
     */
    void BSK_API replace_first_substring(std::string& str, std::string_view from, std::string_view to);

    /**
     * @brief Replaces substring within given string.
     * Replaces all occurences of the given substring in the string.
     * 
     * @param[inout] str Reference to string containing the substring to be replaced.
     * @param[in] from Substring to replace.
     * @param[in] to Substring to replace with.
     */
    void BSK_API replace_all_substrings(std::string& str, std::string_view from, std::string_view to);


} 