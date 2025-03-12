/**
 * @file camera/camera.h
 * @brief Contains base abstrace class for cameras.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include <basikgl/core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @struct PerspectiveCameraProperties
     * @brief Camera properties needed for perspective projection.
     */
    struct BSK_API PerspectiveCameraProperties {
        /**
         * @property Aspect ratio of the camera.
         */
        float aspect_ratio;

        /**
         * @property FOV of the camera in degrees.
         */
        float fov;

        /**
         * @property Near clip distance of the camera in NDC coordinates.
         */
        float near_clip_distance;
        
        /**
         * @property Far clip distance of the camera in NDC coordinates/
         */
        float far_clip_distance;

        /**
         * @brief Constructor
         * 
         * @param[in] aspect_ratio Aspect ratio of the camera.
         * @param[in] fov_deg FOV of the camera in degrees, default value is 45.0.
         * @param[in] near_clip_distance Near clip distance of the camera in NDC coordinates, default value is 1.0.
         * @param[in] far_clip_distance Far clip distance of the camera in NDC coordinates, default value is 10.0.
         */
        PerspectiveCameraProperties(float aspect_ratio, float fov_deg = 45.0f, float near_clip_distance = 1.0f, float far_clip_distance = 10.0f)
            :
            aspect_ratio(aspect_ratio),
            fov(fov_deg),
            near_clip_distance(near_clip_distance),
            far_clip_distance(far_clip_distance) { }
    };

    /**
     * @struct OrthographicCameraProperties
     * @brief Camera properties needed for orthographic projection.
     */
    struct BSK_API OrthographicCameraProperties {
        /**
         * @property Left limit of the view box in NDC coordinates.
         */
        float left;

        /**
         * @property Right limit of the view box in NDC coordinates.
         */
        float right;

        /**
         * @property Bottom limit of the view box in NDC coordinates.
         */
        float bottom;

        /**
         * @property Top limit of the view box in NDC coordinates.
         */
        float top;

        /**
         * @property Near clip distance in NDC coordinates.
         */
        float near_clip_distance;

        /**
         * @property Far clip distance in NDC coordinates.
         */
        float far_clip_distance;

        /**
         * @brief Constructor
         * 
         * @param[in] left Left limit of the view box in NDC coordinates.
         * @param[in] right Right limit of the view box in NDC coordinates.
         * @param[in] bottom Bottom limit of the view box in NDC coordinates.
         * @param[in] top Top limit of the view box in NDC coordinates.
         * @param[in] near_clip_distance clip distance of the camera in NDC coordinates, default value is -1.0.
         * @param[in] far_clip_distance Far clip distance of the camera in NDC coordinates, default value is 10.0.
         * 
         */
        OrthographicCameraProperties(float left, float right, float bottom, float top, float near_clip_distance = -1.0f, float far_clip_distance = 10.0f)
            :
            left(left),
            right(right),
            bottom(bottom),
            top(top),
            near_clip_distance(near_clip_distance),
            far_clip_distance(far_clip_distance) { }        
    };

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