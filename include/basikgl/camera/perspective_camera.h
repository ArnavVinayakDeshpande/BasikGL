/**
 * @file camera/perspective_camera.h
 * @brief Contains perspective camera class.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/glm.hpp>

#include <camera/camera.h>
#include <time/timespan.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class PerspectiveCamera
     * @brief Imeplements a basic camera with perspective projection.
     * @implements CameraBase ( @ref camera/camera.h )
     */
    class BSK_API PerspectiveCamera final : public CameraBase {
    public:
        /**
         * @brief Constructor
         * 
         * @param[in] camera_properties An instance of PerspectiveCameraProperties.
         */
        explicit PerspectiveCamera(PerspectiveCameraProperties camera_properties);

        /**
         * @brief Copy Constructor
         */
        PerspectiveCamera(const PerspectiveCamera& other) = default;

        /**
         * @brief Move Constructor
         */
        PerspectiveCamera(PerspectiveCamera&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        PerspectiveCamera& operator=(const PerspectiveCamera& other) = default;

        /**
         * @brief Move Assignment Operator
         */
        PerspectiveCamera& operator=(PerspectiveCamera&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        ~PerspectiveCamera() = default;

        /**
         * @implements bskgl::CameraBase::position()
         */
        [[nodiscard]]
        glm::vec3 position() const override;

        /**
         * @implements bskgl::CameraBase::target()
         */
        [[nodiscard]]
        glm::vec3 target() const override;

        /**
         * @implements bskgl::CameraBase::look_direction()
         */
        [[nodiscard]]
        glm::vec3 look_direction() const override;

        /**
         * @implements bskgl::CameraBase::camera_up()
         */
        [[nodiscard]]
        glm::vec3 camera_up() const override;

        /**
         * @implements bskgl::CameraBase::camera_right()
         */
        [[nodiscard]]
        glm::vec3 camera_right() const override;

        /**
         * @implements bskgl::CameraBase::view_matrix()
         */
        [[nodiscard]]
        glm::mat4 view_matrix() const override;

        /**
         * @implements bskgl::CameraBase::projection_matrix()
         */
        [[nodiscard]]
        glm::mat4 projection_matrix() const override;

        /**
         * @brief Returns view projection matrix.
         * 
         * @retval glm::mat4 ( @ref lib glm )
         * @returns View projection matrix of the camera.
         */
        [[nodiscard]]
        glm::mat4 view_projection_matrix() const;

        /**
         * @brief Returns aspect ratio of the camera.
         * 
         * @retval float 
         * @returns Aspect ratio of the camera.
         */
        [[nodiscard]]
        float aspect_ratio() const;
        
        /**
         * @brief Returns fov of the camera in degrees.
         * 
         * @retval float
         * @returns FOV of the camera in degrees.
         */
        [[nodiscard]]
        float fov() const;

        /**
         * @brief Returns near clip distance of the camera.
         * 
         * @retval float
         * @returns Near clip distance of the camera.
         */
        [[nodiscard]]
        float near_clip_distance() const;

        /**
         * @brief Returns far clip distance of the camera.
         * 
         * @retval float
         * @returns Far clip distance of the camera.
         */
        [[nodiscard]]
        float far_clip_distance() const;

        /**
         * @brief Returns yaw of the camera.
         * 
         * @retval float
         * @returns Yaw of the camera in degrees.
         */
        [[nodiscard]]
        float yaw() const;

        /**
         * @brief Returns pitch of the camera.
         * 
         * @retval float
         * @returns Pitch of the camera in degrees.
         */
        [[nodiscard]]
        float pitch() const;

        [[nodiscard]]
        /**
         * @retval PerspectiveCameraProperties
         * @returns Perspective projection properties.
         */
        PerspectiveCameraProperties properties() const;

        /**
         * @brief Sets the position of the camera.
         * 
         * @param[in] position New position.
         * 
         * @retval PerspectiveCamera& 
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_position(const glm::vec3& position);

        /**
         * @brief Sets the camera target.
         * 
         * @param[in] target New target for the camera.
         * 
         * @retval PerspectiveCamera& 
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_target(const glm::vec3& target);

        /**
         * @brief Sets camera fov.
         * 
         * @param[in] fov FOV for the camera in degrees.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_fov(float fov);

        /**
         * @brief Sets the aspect ratio.
         * 
         * @param[in] aspect_ratio New aspect ratio.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_aspect_ratio(float aspect_ratio);

        /**
         * @brief Sets near clip distance.
         * 
         * @param[in] near Near clip distance.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_near_clip_distance(float near);

        /**
         * @brief Sets far clip distance.
         * 
         * @param[in] far Far clip distance.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_far_clip_distance(float far);

        /**
         * @brief Sets clip distances.
         * 
         * @param[in] near Near clip distance.
         * @param[in] far Far clip distance.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_clip_distance(float near, float far);

        /**
         * @brief Sets yaw of the camera.
         * 
         * @param[in] yaw Yaw of the camera in degrees.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_yaw(float yaw_in_deg);

        /**
         * @brief Sets pitch of the camera.
         * 
         * @param[in] pitch Pitch of the camera in degrees.
         * @param[in] contrain_itch Should the pitch be clamped to prevent flip of camera, default value is true
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_pitch(float pitch_in_deg, bool constrain_pitch = true);
    
        /**
         * @brief Sets the camera properties.
         * 
         * @param[in] camera_properties Camera properties.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& set_properties(PerspectiveCameraProperties properties);

        /**
         * @brief Resets the camera back to the original position.
         * Resets position to (0, 0, 3), pointing at (0, 0, 0) with no yaw and no pitch.
         * 
         * @retval PerspectiveCamera&
         * @returns Reference to the updated variable.
         */
        PerspectiveCamera& reset();

    private:
        /**
         * @property Normalized World Up Vector.
         */
        static constexpr glm::vec3 s_world_up = glm::vec3(0.0f, 1.0f, 0.0f);

    private:
        /**
         * @brief Update camera vector.
         */
        void m_update_camera_vectors();

    private:
        /**
         * @property Position of the camera in 3-D space.
         */
        glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 3.0f);

        /**
         * @property Front facing vector of the camera.
         */
        glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);

        /**
         * @property Up vector of the camera.
         */
        glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

        /**
         * @property Right vector of the camera.
         */
        glm::vec3 m_right = glm::vec3(1.0f, 0.0f, 0.0f);

        /**
         * @property Aspect ratio of the camera.
         */
        float m_aspect_ratio;
        
        /**
         * @property FOV of the camera in degrees.
         */
        float m_fov;

        /**
         * @property Near clip distance of the camera.
         */
        float m_near_plane;

        /**
         * @property Far clip distance of the camera.
         */
        float m_far_plane;

        /**
         * @property Yaw of the camera in degrees, starts from -90.0 so that it faces the origin.
         */
        float m_yaw = -90.0f;

        /**
         * @property Pitch of the camera in degrees, starts from 0 so that it faces the origin.
         */
        float m_pitch = 0.0f;
    };

}

/* 
TODO: Error Handling for negative FOV and stuff
*/