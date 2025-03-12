#include <glm/gtc/matrix_transform.hpp>

#include <camera/perspective_camera.h>

namespace bskgl {

    PerspectiveCamera::PerspectiveCamera(PerspectiveCameraProperties properties)
        : 
        m_aspect_ratio(properties.aspect_ratio), 
        m_fov(properties.fov), 
        m_near_plane(properties.near_clip_distance), 
        m_far_plane(properties.far_clip_distance) {
        m_update_camera_vectors();
    }

    glm::vec3 PerspectiveCamera::position() const {
        return m_position; 
    }

    glm::vec3 PerspectiveCamera::target() const {
        return m_position + m_front;
    }

    glm::vec3 PerspectiveCamera::look_direction() const {
        return m_front; 
    }

    glm::vec3 PerspectiveCamera::camera_up() const {
        return m_up; 
    }

    glm::vec3 PerspectiveCamera::camera_right() const {
        return m_right; 
    }

    glm::mat4 PerspectiveCamera::view_matrix() const {
        return glm::lookAt(m_position, this->target(), m_up);
    }

    glm::mat4 PerspectiveCamera::projection_matrix() const {
        return glm::perspective(glm::radians(m_fov), m_aspect_ratio, m_near_plane, m_far_plane);
    }

    glm::mat4 PerspectiveCamera::view_projection_matrix() const {
        return this->projection_matrix() * this->view_matrix();
    }

    float PerspectiveCamera::fov() const {
        return m_fov;
    }

    float PerspectiveCamera::aspect_ratio() const {
        return m_aspect_ratio;
    }

    float PerspectiveCamera::near_clip_distance() const {
        return m_near_plane;
    }

    float PerspectiveCamera::far_clip_distance() const {
        return m_far_plane;
    }

    float PerspectiveCamera::yaw() const {
        return m_yaw;
    }

    float PerspectiveCamera::pitch() const {
        return m_pitch;
    }

    PerspectiveCameraProperties PerspectiveCamera::properties() const {
        return PerspectiveCameraProperties(m_aspect_ratio, m_fov, m_near_plane, m_far_plane);
    }

    PerspectiveCamera& PerspectiveCamera::set_position(const glm::vec3& position) {
        m_position = position;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_target(const glm::vec3& target) {
        m_front = target - m_position;
        
        m_update_camera_vectors();

        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_fov(float fov) {
        m_fov = fov;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_aspect_ratio(float aspect_ratio) {
        m_aspect_ratio = aspect_ratio;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_near_clip_distance(float near) {
        m_near_plane = near;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_far_clip_distance(float far) {
        // TODO: ensure near and far are valid
        m_far_plane = far;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_clip_distance(float near, float far) {
        m_near_plane = near;
        m_far_plane = far;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::set_pitch(float pitch, bool constrain_pitch) {
        m_pitch = pitch;

        if (constrain_pitch)
            m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
        m_update_camera_vectors();        

        return *this;    
    }

    PerspectiveCamera& PerspectiveCamera::set_properties(PerspectiveCameraProperties properties) {
        m_aspect_ratio = properties.aspect_ratio;
        m_fov = properties.fov;
        m_near_plane = properties.near_clip_distance;
        m_far_plane = properties.far_clip_distance;
        
        return *this;
    }

    PerspectiveCamera& PerspectiveCamera::reset() {
        m_position = glm::vec3(0.0f, 0.0f, 3.0f);
        m_front = glm::vec3(0.0f, 0.0f, -1.0f);
        m_up = glm::vec3(0.0f, 1.0f, 0.0f);
        m_right = glm::vec3(1.0f, 0.0f, 0.0f);
        m_yaw = -90.0f;
        m_pitch = 0.0f;

        return *this;
    }

    // Update camera vectors
    void PerspectiveCamera::m_update_camera_vectors() {
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