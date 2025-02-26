#include <glm/gtc/matrix_transform.hpp>

#include <camera/player_camera.h>

namespace bskgl {

    PlayerCamera::PlayerCamera(float aspect_ratio, float fov, float near_plane, float far_plane, float speed, float mouse_sensitivity)
        : 
        m_aspect_ratio(aspect_ratio), 
        m_fov(fov), 
        m_near_plane(near_plane), 
        m_far_plane(far_plane),
        m_speed(speed),
        m_mouse_sensitivity(mouse_sensitivity) {
        m_update_camera_vectors();
    }

    glm::vec3 PlayerCamera::position() const {
        return m_position; 
    }

    glm::vec3 PlayerCamera::target() const {
        return m_position + m_front;
    }

    glm::vec3 PlayerCamera::look_direction() const {
        return m_front; 
    }

    glm::vec3 PlayerCamera::camera_up() const {
        return m_up; 
    }

    glm::vec3 PlayerCamera::camera_right() const {
        return m_right; 
    }

        glm::mat4 PlayerCamera::view_matrix() const {
        return glm::lookAt(m_position, this->target(), m_up);
    }

    glm::mat4 PlayerCamera::projection_matrix() const {
        return glm::perspective(glm::radians(m_fov), m_aspect_ratio, m_near_plane, m_far_plane);
    }

    glm::mat4 PlayerCamera::view_projection_matrix() const {
        return this->projection_matrix() * this->view_matrix();
    }

    PlayerCamera& PlayerCamera::strafe(PlayerStrafeDirection direction, Timespan deltatime) {
        float velocity = m_speed * deltatime.seconds();

        switch (direction) {
            case PlayerStrafeDirection::CameraUp:
                m_position += m_up * velocity;
                break;
            case PlayerStrafeDirection::CameraDown:
                m_position -= m_up * velocity;
                break;
            case PlayerStrafeDirection::CameraFront:
                m_position += m_front * velocity;
                break;
            case PlayerStrafeDirection::CameraBack:
                m_position -= m_front * velocity;
                break;
            case PlayerStrafeDirection::CameraRight:
                m_position += m_right * velocity;
                break;
            case PlayerStrafeDirection::CameraLeft:
                m_position -= m_right * velocity;
                break;
            case PlayerStrafeDirection::WorldUp:
                m_position += glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
                break;
            case PlayerStrafeDirection::WorldDown:
                m_position -= glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
                break;
            case PlayerStrafeDirection::WorldFront:
                m_position += glm::vec3(0.0f, 0.0f, -1.0f) * velocity;
                break;
            case PlayerStrafeDirection::WorldBack:
                m_position += glm::vec3(0.0f, 0.0f, 1.0f) * velocity;
                break;
            case PlayerStrafeDirection::WorldRight:
                m_position += glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
                break;
            case PlayerStrafeDirection::WorldLeft:
                m_position -= glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
                break;
        }

        this->m_update_camera_vectors();

        return *this;
    }

    PlayerCamera& PlayerCamera::turn(glm::dvec2 offset, bool constrain_pitch) {
        offset.x *= m_mouse_sensitivity;
        offset.y *= m_mouse_sensitivity;

        m_yaw += offset.x;
        m_pitch -= offset.y;  // Reversed since y-coordinates range from bottom to top

        if (constrain_pitch) {
            m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
        }

        m_update_camera_vectors();
        return *this;
    }

    float PlayerCamera::fov() const {
        return m_fov;
    }

    float PlayerCamera::aspect_ratio() const {
        return m_aspect_ratio;
    }

    float PlayerCamera::near_clip_distance() const {
        return m_near_plane;
    }

    float PlayerCamera::far_clip_distance() const {
        return m_far_plane;
    }

    float PlayerCamera::speed() const {
        return m_speed;
    }

    float PlayerCamera::yaw() const {
        return m_yaw;
    }

    float PlayerCamera::pitch() const {
        return m_pitch;
    }

    float PlayerCamera::mouse_sensitivity() const {
        return m_mouse_sensitivity;
    }

    PlayerCamera& PlayerCamera::set_position(const glm::vec3& position) {
        m_position = position;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_target(const glm::vec3& target) {
        m_front = target - m_position;
        
        m_update_camera_vectors();

        return *this;
    }

    PlayerCamera& PlayerCamera::set_fov(float fov) {
        m_fov = fov;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_aspect_ratio(float aspect_ratio) {
        m_aspect_ratio = aspect_ratio;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_near_clip_distance(float near) {
        m_near_plane = near;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_far_clip_distance(float far) {
        // TODO: ensure near and far are valid
        m_far_plane = far;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_clip_distance(float near, float far) {
        m_near_plane = near;
        m_far_plane = far;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_speed(float speed) {
        m_speed = speed;
        
        return *this;
    }

    PlayerCamera& PlayerCamera::set_yaw(float yaw) {
        m_yaw = yaw;
        m_update_camera_vectors();                

        return *this;    
    }

    PlayerCamera& PlayerCamera::set_pitch(float pitch, bool constrain_pitch) {
        m_pitch = pitch;

        if (constrain_pitch)
            m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
        m_update_camera_vectors();        

        return *this;    
    }

    PlayerCamera& PlayerCamera::set_mouse_sensitivity(float mouse_sensitivity) {
        m_mouse_sensitivity = mouse_sensitivity;

        return *this;    
    }

    PlayerCamera& PlayerCamera::reset() {
        m_position = glm::vec3(0.0f, 0.0f, 3.0f);
        m_front = glm::vec3(0.0f, 0.0f, -1.0f);
        m_up = glm::vec3(0.0f, 1.0f, 0.0f);
        m_right = glm::vec3(1.0f, 0.0f, 0.0f);
        m_yaw = -90.0f;
        m_pitch = 0.0f;

        return *this;
    }

    // Update camera vectors
    void PlayerCamera::m_update_camera_vectors() {
        // Recalculate Right and Up vectors
        glm::vec3 front;
        front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        front.y = sin(glm::radians(m_pitch));
        front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        m_front = glm::normalize(front);

        m_right = glm::normalize(glm::cross(m_front, s_world_up));
        m_up = glm::normalize(glm::cross(m_right, m_front));
    }

}