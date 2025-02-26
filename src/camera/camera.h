/**
 * @file camera/camera.h
 * @brief Contains base abstrace class for cameras.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include <core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class CameraBase
     * @brief Base abstract class for cameras.
     */
    class BSK_API CameraBase {
    public:
        /**
         * @brief Default Constructor
         */
        CameraBase() = default;

        /**
         * @brief Destructor
         */
        virtual ~CameraBase() = default;

        /**
         * @brief Returns position of the camera.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Position of camera as a 3-D vector.
         */
        virtual glm::vec3 position() const = 0;
        
        /**
         * @brief Returns position of the camera target.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Position of the camera target as a 3-D vector.
         */
        virtual glm::vec3 target() const = 0;

        /**
         * @brief Returns direction vector.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Direction vector of the camera as a normalized 3-D vector.
         */
        virtual glm::vec3 look_direction() const = 0;

        /**
         * @brief Returns up vector of the camera.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Camera up vector as a normalized 3-D vector.
         */
        virtual glm::vec3 camera_up() const = 0;

        /**
         * @brief Returns right vector of the camera.
         * 
         * @retval glm::vec3 ( @ref lib glm )
         * @returns Camera right vector as a normalized 3-D vector.
         */
        virtual glm::vec3 camera_right() const = 0;

        /**
         * @brief Returns view matrix.
         * 
         * @retval glm::mat4 ( @ref lib glm )
         * @returns View matrix of the camera as a 4x4 matrix.
         */
        virtual glm::mat4 view_matrix() const = 0;

        /**
         * @brief Returns projection matrix.
         * 
         * @retval glm::mat4 ( @ref lib glm )
         * @returns Projection matrix of the camera as a 4x4 matrix.
         */
        virtual glm::mat4 projection_matrix() const = 0;
    };

}