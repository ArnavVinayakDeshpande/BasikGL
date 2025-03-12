/**
 * @file camera/gui_camera.h
 * @brief Provides functionality for a basic GUI-like orthographic camera.
 * @author Arnav Deshpande
 */

#pragma once

#include <basikgl/core/core.h>
#include <basikgl/camera/camera.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL Library.
 */
namespace bskgl {

    /**
     * @class GUICamera
     * @brief Provides functionality for a GUI Camera 3 NDC units away from xy-plane to act as a GUI overlooking orthographic camera.
     * @implements bskgl::CameraBase
     */
    class BSK_API GUICamera final : public CameraBase {
    public:
        static constexpr float z_position = 3.0f;
        static constexpr glm::vec3 look_direction = glm::vec3(0.0f, 0.0f, -1.0f);

    public:
        GUICamera(float left, float right, float bottom, float top, float near_clip_distance = -1.0f, float far_clip_distance = 10.0f);    

    private:
    
    };

}