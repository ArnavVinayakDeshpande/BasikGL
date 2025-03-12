/**
 * @file camera/player_camera.h
 * @brief Contains player camera class.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/glm.hpp>

#include <basikgl/camera/camera.h>
#include <basikgl/time/timespan.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum PlayerStrafeDirection
     */
    enum class PlayerStrafeDirection {
        CameraUp,       // Move up based on camera orientation
        CameraDown,     // Move down based on camera orientation
        CameraFront,    // Move forward based on where the camera is looking
        CameraBack,     // Move backward based on where the camera is looking
        CameraRight,    // Move right relative to camera direction
        CameraLeft,     // Move left relative to camera direction

        WorldUp,        // Move along world Y-axis (absolute up)
        WorldDown,      // Move along world Y-axis (absolute down)
        WorldFront,     // Move along world Z-axis (absolute forward)
        WorldBack,      // Move along world Z-axis (absolute backward)
        WorldRight,     // Move along world X-axis (absolute right)
        WorldLeft       // Move along world X-axis (absolute left)
    };

    /**
     * @class PlayerCamera
     * @brief Imeplements player movement and turning.
     * @implements CameraBase ( @ref camera/camera.h )
     */
    class BSK_API PlayerCamera final : public CameraBase {
    public:
        /**
         * @brief Constructor
         * 
         * @param[in] aspec_ratio Aspect ratio of the camera.
         * @param[in] fov FOV of the camera in degrees, default value is 45.
         * @param[in] near_plane Near clip distance of the camera in NDC, default value is 1.0.
         * @param[in] far_plane Far clip distance of the camera in NDC, default value is 10.0.
         * @param[in] speed Speed of the player camera, default value is 5.0.
         * @param[in] mouse_sensitivity Mouse sensitivity for turning, default value is 1.0.
         */
        explicit PlayerCamera(float aspect_ratio, float fov = 45.0f, float near_plane = 1.0f, float far_plane = 10.0f, float speed = 5.0f, float mouse_sensitivity = 1.0f);

        /**
         * @brief Copy Constructor
         */
        PlayerCamera(const PlayerCamera& other) = default;

        /**
         * @brief Move Constructor
         */
        PlayerCamera(PlayerCamera&& other) noexcept = default;

        /**
         * @brief Copy Assignment Operator
         */
        PlayerCamera& operator=(const PlayerCamera& other) = default;

        /**
         * @brief Move Assignment Operator
         */
        PlayerCamera& operator=(PlayerCamera&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        ~PlayerCamera() = default;

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
         * @brief Returns speed of the camera.
         * 
         * @retval float
         * @returns Speed of the camera.
         */
        [[nodiscard]]
        float speed() const;

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

        /**
         * @brief Returns mouse sensitivity of the camera.
         * 
         * @retval float
         * @returns Mouse sensitivity of the camera.
         */
        [[nodiscard]]
        float mouse_sensitivity() const;

        /**
         * @brief Sets the position of the camera.
         * 
         * @param[in] position New position.
         * 
         * @retval PlayerCamera& 
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_position(const glm::vec3& position);

        /**
         * @brief Sets the camera target.
         * 
         * @param[in] target New target for the camera.
         * 
         * @retval PlayerCamera& 
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_target(const glm::vec3& target);

        /**
         * @brief Sets camera fov.
         * 
         * @param[in] fov FOV for the camera in degrees.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_fov(float fov);

        /**
         * @brief Sets the aspect ratio.
         * 
         * @param[in] aspect_ratio New aspect ratio.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_aspect_ratio(float aspect_ratio);

        /**
         * @brief Sets near clip distance.
         * 
         * @param[in] near Near clip distance.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_near_clip_distance(float near);

        /**
         * @brief Sets far clip distance.
         * 
         * @param[in] far Far clip distance.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_far_clip_distance(float far);

        /**
         * @brief Sets clip distances.
         * 
         * @param[in] near Near clip distance.
         * @param[in] far Far clip distance.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_clip_distance(float near, float far);

        /**
         * @brief Sets speed of the camera.
         * 
         * @param[in] speed Speed of the camera.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_speed(float speed);

        /**
         * @brief Sets yaw of the camera.
         * 
         * @param[in] yaw Yaw of the camera in degrees.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_yaw(float yaw_in_deg);

        /**
         * @brief Sets pitch of the camera.
         * 
         * @param[in] pitch Pitch of the camera in degrees.
         * @param[in] contrain_itch Should the pitch be clamped to prevent flip of camera, default value is true
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_pitch(float pitch_in_deg, bool constrain_pitch = true);
        
        /**
         * @brief Sets mouse sensitivity of the camera.
         * 
         * @param[in] mouse_sensitivity Mouse sensitivity of the camera.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& set_mouse_sensitivity(float mouse_sensitivity);
    
        /**
         * @brief Resets the camera back to the original position.
         * Resets position to (0, 0, 3), pointing at (0, 0, 0) with no yaw and no pitch.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& reset();

        /**
         * @brief Strafes the camera.
         * 
         * @param[in] direction Direction to strafe in.
         * @param[in] timespan Delta time for speed calculations.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& strafe(PlayerStrafeDirection direction, Timespan delta_time);

        /**
         * @brief Turns the camera.
         * 
         * @param[in] mouse_offset Mouse offset for pitch and yaw calculations.
         * @param[in] contrain_pitch Constrains pitch to prevent mouse flipping, default value is true.
         * 
         * @retval PlayerCamera&
         * @returns Reference to the updated variable.
         */
        PlayerCamera& turn(glm::dvec2 mouse_offset, bool constrain_pitch = true);

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
         * @property Speed of the camera.
         */
        float m_speed;

        /**
         * @property Yaw of the camera in degrees, starts from -90.0 so that it faces the origin.
         */
        float m_yaw = -90.0f;

        /**
         * @property Pitch of the camera in degrees, starts from 0 so that it faces the origin.
         */
        float m_pitch = 0.0f;

        /**
         * @property Mouse sensitivity of the camera.
         */
        float m_mouse_sensitivity;
    };

}

/* 
TODO: Error Handling for negative FOV and stuff
*/