#include <chrono>

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <core/core.h>
#include <core/error_handler.h>
#include <time/timespan.h>
#include <context/context_manager.h>

namespace bskgl {

    static bool g_is_lib_initalized = false;
    static std::chrono::time_point<std::chrono::high_resolution_clock> g_time_initialized;

    void initialize() {
        // if library has already been initialized, no need to initialize it again
        if (g_is_lib_initalized)
            return;

        // initialize glfw
        if (!glfwInit()) {
            BSK_FATAL_ERROR("Coudln't initialize glfw.");
            return;
        }

        // initialaztion window
        glfwWindowHint(GLFW_OPENGL_PROFILE,  GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, BSK_OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, BSK_OPENGL_VERSION_MINOR);
        GLFWwindow* init_window = glfwCreateWindow(800, 450, "Initialization Window", NULL, NULL);

        if (!init_window) {
            BSK_FATAL_ERROR("Failed to create initializtion window.");
            return;
        }

        glfwMakeContextCurrent(init_window);

        // initialize glad
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            BSK_FATAL_ERROR("Failed to initialize OpenGL (glad).");
        }

        // destroy the initialization window
        glfwDestroyWindow(init_window);

        // set the initialization parameters
        g_time_initialized = std::chrono::high_resolution_clock::now();
        g_is_lib_initalized = true;
    }

    void shutdown() {
        // set the initialized flag
        g_is_lib_initalized = false;

        // delete the context
        delete ContextManager::s_instance;

        // terminate glfw
        glfwTerminate();
    }

    Timespan BSK_API time_since_epoch() {
        if (!g_is_lib_initalized)
            return Timespan(0.0f);
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = now - g_time_initialized;
        return Timespan(elapsed.count());
    }

}