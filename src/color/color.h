/**
 * @file color/color.h
 * @brief Contains color class definitions.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/glm.hpp>

#include <core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class Color
     * @brief Represents a color in RGBA format.
     */
    class BSK_API Color {
    public:
        /**
         * @brief Constructor
         * 
         * @param[in] red Red component as a uint8_t.
         * @param[in] green Green component as a uint8_t.
         * @param[in] blue Blue component as a uint8_t.
         * @param[in] alpha Alpha component as a uint8_t, default value is 255.
         */
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        /**
         * @brief Constructor
         * 
         * @param[in] rgb uint8_t value meant to be used for RGB components.
         * @param[in] alpha Alpha component as a uint8_t.
         */
        Color(uint8_t rgb, uint8_t alpha);

        /**
         * @brief Constructor
         * 
         * @param[in] rgba Color in RGBA format as a uint32_t.
         */
        Color(uint32_t rgba);

        /**
         * @brief Constructor
         * 
         * @param[in] rgba Color in RGBA normalized format as a glm::vec4 ( @ref lib glm ).
         * 
         * @note The function assumes given parameter is in normalized format and is not responsible for validating the input.
         */
        Color(const glm::vec4& rgba);

        /**
         * @brief Destructor
         */
        virtual ~Color() = default;

        /**
         * @brief Red component of the color.
         * 
         * @retval uint8_t
         * @returns Red component of the color.
         */
        [[nodiscard]]
        uint8_t red_component() const;

        /**
         * @brief Green component of the color.
         * 
         * @retval uint8_t
         * @returns Green component of the color.
         */
        [[nodiscard]]
        uint8_t green_component() const;

        /**
         * @brief Blue component of the color.
         * 
         * @retval uint8_t
         * @returns Blue component of the color.
         */
        [[nodiscard]]
        uint8_t blue_component() const;

        /**
         * @brief Alpha component of the color.
         * 
         * @retval uint8_t
         * @returns Alpha component of the color.
         */
        [[nodiscard]]
        uint8_t alpha_component() const;

        /**
         * @brief Returns the color itself.
         * 
         * @retval uint32_t
         * @returns Returns the color in non-normalized RGBA format.
         */
        [[nodiscard]]
        uint32_t rgba() const;

        /**
         * @brief Returns the color itself.
         * 
         * @retval glm::vec4 ( @ref lib glm )
         * @returns Returns the color in a RGBA normalized format.
         */
        [[nodiscard]]
        glm::vec4 normalized() const;

        /**
         * @brief Sets red component of the color.
         * 
         * @param[in] r Red component of the color as a uint8_t.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_red(uint8_t r);

        /**
         * @brief Sets green component of the color.
         * 
         * @param[in] g Green component of the color as a uint8_t.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_green(uint8_t g);

        /**
         * @brief Sets blue component of the color.
         * 
         * @param[in] b Blue component of the color as a uint8_t.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_blue(uint8_t b);

        /**
         * @brief Sets alpha component of the color.
         * 
         * @param[in] a Alpha component of the color as a uint8_t.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_alpha(uint8_t a);

        /**
         * @brief Sets the color.
         * 
         * @param[in] rgba Color in a non-normalized RGBA format as a uint32_t.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_rgba(uint32_t rgba);

        /**
         * @brief Sets the color.
         * 
         * @param[in] rgba Color in a normalized RGBA format as a glm::vec4 ( @ref lib glm ).
         * 
         * @note The function assumes given parameter is in normalized format and is not responsible for validating the input.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& set_rgba(const glm::vec4& rgba);

        /**
         * @brief Resets the component.
         * Resets the red component of the color.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& reset_red();

        /**
         * @brief Resets the component.
         * Resets the green component of the color.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& reset_green();

        /**
         * @brief Resets the component.
         * Resets the blue component of the color.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& reset_blue();

        /**
         * @brief Resets the component.
         * Resets the alpha component of the color.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& reset_alpha();

        /**
         * @brief Resets the color.
         * 
         * @retval Color&
         * @returns Reference to the updated variable.
         */
        Color& reset();

        /**
         * @brief Returns the complementary color.
         * 
         * @retval Color
         * @returns Complementary color.
         */
        [[nodiscard]]
        Color complementary() const;

        /**
         * @brief Adjusts the brightness of the color.
         * 
         * @param[in] factor Brightness factor (range -1.0 to 1.0).
         * 
         * @note This function is clamps parameter factor in the appropriate range.
         * 
         * @retval Color
         * @returns Brightness-adjusted color.
         */
        [[nodiscard]]
        Color adjust_brightness(float factor) const;

        /**
         * @brief Converts the color to grayscale.
         * 
         * @retval Color
         * @returns Grayscale version of the color.
         */
        [[nodiscard]]
        Color to_grayscale() const;

        /**
         * @brief Converts the color to HSV format.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Color in HSV format.
         */
        [[nodiscard]]
        glm::vec3 to_hsv() const;

    public:
        /**
         * @brief Returns a new color by linearly interpolating between two colors.
         * 
         * @param[in] lhs First color.
         * @param[in] rhs Second color.
         * @param[in] t Parameter, normalized between 0 and 1.
         * 
         * @note This function expects parameter "t" to be normalized and is not responsible for validating the input.
         * 
         * @retval Color
         * @returns Interpolated color.
         */
        [[nodiscard]]
        static Color mix(const Color& lhs, const Color& rhs, float t);

                /**
         * @brief Converts an HSV color to RGB.
         * 
         * @param[in] hsv HSV color as a glm::vec3.
         * 
         * @retval Color
         * @returns RGB representation of the HSV color.
         */
        [[nodiscard]]
        static Color from_hsv(const glm::vec3& hsv);

        /**
         * @brief Blends two colors using alpha blending.
         * 
         * @param[in] src Source color.
         * @param[in] dest Destination color.
         * 
         * @retval Color
         * @returns Blended color.
         */
        [[nodiscard]]
        static Color blend(const Color& src, const Color& dest);

        /**
         * @brief White color.
         * 
         * @retval Color
         * @returns White color.
         */
        [[nodiscard]]
        static Color white();

        /**
         * @brief Black color.
         * 
         * @retval Color
         * @returns Black color.
         */
        [[nodiscard]]
        static Color black();

        /**
         * @brief Red color.
         * 
         * @retval Color
         * @returns Red color.
         */
        [[nodiscard]]
        static Color red();

        /**
         * @brief Green color.
         * 
         * @retval Color
         * @returns Green color.
         */
        [[nodiscard]]
        static Color green();

        /**
         * @brief Blue color.
         * 
         * @retval Color
         * @returns Blue color.
         */
        [[nodiscard]]
        static Color blue();

    private:
        /**
         * @property Color stored in a non-normalized RGBA format as a uint32_t.
         */
        uint32_t m_rgba;
    };

} 