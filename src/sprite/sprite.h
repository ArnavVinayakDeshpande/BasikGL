/**
 * @file sprite/sprite.h
 * @brief Contains definitions for Sprite class.
 * @author Arnav Deshpande
 */

#pragma once

#include <filesystem>
#include <memory>

#include <core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class Sprite
     * @brief Represents a 2-D sprite object.
     */
    class BSK_API Sprite final {
    public:
        /**
         * @brief Constructor
         */
        Sprite();

        /**
         * @brief Constructor
         * 
         * @param[in] path Path to the image.
         */
        Sprite(const std::filesystem::path& path);

        /**
         * @brief Copy Constructor
         */
        Sprite(const Sprite& other) ;

        /**
         * @brief Move Constructor
         */
        Sprite(Sprite&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        Sprite& operator=(const Sprite& other);

        /**
         * @brief Move Assignment Operator
         */
        Sprite& operator=(Sprite&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        ~Sprite();

        /**
         * @retval int32_t
         * @returns Width of the sprite.
         */
        int32_t width() const;

        /**
         * @retval int32_t
         * @returns Height of the sprite.
         */
        int32_t height() const;

        /**
         * @retval int32_t
         * @returns Number of color channels in the sprite.
         */
        int32_t channels() const;

        /**
         * @retval const unsigned char*
         * @returns Const pointer to the data in the sprite.
         */
        const unsigned char* data() const;

        /**
         * @brief Reads the given image in to the sprite.
         * 
         * @param[in] path Path to the image.
         * 
         * @retval Sprite&
         * @returns Reference to the updated variable.
         */
        Sprite& read_from(const std::filesystem::path& path);

        /**
         * @brief Checks if the sprite is valid.
         * 
         * @retval bool
         * @returns True if the sprite is valid.
         */
        bool is_valid() const;

    private:
        /**
         * @property Sprite width.
         */
        int32_t m_width;

        /**
         * @property Sprite height.
         */
        int32_t m_height;

        /**
         * @property Number of color channels in the sprite.
         */
        int32_t m_channels;

        /**
         * @property Data stored in the sprite.
         */
        std::unique_ptr<uint8_t[]> m_data;
    };

} 