# **BasikGL**  
*A lightweight OpenGL-based graphics library.*

![Project Status](https://img.shields.io/badge/Status-In_Development-yellow)  

## **Table of Contents**
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Building the Project](#building-the-project)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [To-Do](#to-do)
- [License](#license)

---

## **Introduction**
BasikGL is a lightweight, modular OpenGL graphics library designed to simplify rendering and asset management. It provides a simple interface for handling **shaders, textures, vertex buffers, and model loading**, while maintaining flexibility for future expansions.

## **Features**
✅ **Shader Management** – Automatic uniform handling and efficient shader binding.  
✅ **Asset Management** – Uses a UUID-based asset manager to handle resources efficiently.  
✅ **Texture Handling** – Built-in support for texture loading and binding.  
✅ **Window Management** – Uses GLFW for cross-platform windowing.  
✅ **Logging System** – Console and file logging.  
<!-- ✅ **Model Loading** – Supports `.obj` and `.gltf` (future support planned).   -->

## **Installation**
### **Cloning the Repository**
```sh
git clone --recursive https://github.com/yourusername/BasikGL.git
cd BasikGL
```

### **Building the Project**
```sh
cmake -S .
```

### **Dependencies**
**BasikGL** requires the following external libraries:

Shipped with the project:

* **glad** – OpenGL function loader
* **stb_image** – Image loading
* **tiny_obj_loader** – .obj model loading

Git Submodules (External Dependencies):
* **glfw** – Window management
* **glm** – Math library

## **Usage**
### **Simplest Program**
```cpp
#include <basikgl/basikgl.h>

int32_t main(int32_t argc, const char* argv[]) {
    // initiailize the library
    bskgl::initialize();

    // get the context manager
    auto& ctx_manager = bskgl::ContextManager::instance();

    // create a context
    bskgl::ContextProperties properties(
        bskgl::WindowProperties(800, 800, "BasikGL Window"), // properties for context window
        bskgl::Color(128, 128, 128, 255) // clear color
    );
    bskgl::UUID ctx_uuid = ctx_manager.create_context(properties);

    // get the context
    auto ctx =  ctx_manager.get_context(ctx_uuid);
    
    // get the window
    bskgl::Window& window = ctx->window;

    // bind the context
    ctx->bind();

    // enter the main loop
    while (window.is_open()) {
        // clear the context
        ctx->clear();

        // render

        // swap window buffers
        window.swap_buffers();

        // poll window events
        bskgl::Window::poll_events();
    }

    // shutdown the library
    bskgl::shutdown();

    return 0;
}
```

### **Create a Shader**
```cpp
#include <basikgl/basikgl.h>

int32_t main(int32_t argc, const char* argv[]) {
    /* initialization and setup a context */

    // get the context asset manager
    auto& am = ctx->asset_manager;

    bskgl::UUID shader_uud = 
        am->create_asset(
            std::filesystem::path("vert.shader"),
            std::filesystem::path("frag.shader")
        );
    auto shdr = am->get_asset<bskgl::Shader>(shader_uuid);

    if (!shdr)
        BSK_ERROR("Couldn't create shader".);

    // bind the shader
    shdr->bind();

    /* shutdown and cleanup*/
}
```

### **Create a VertexArray**
```cpp
#include <basikgl/basikgl.h>

int32_t main(int32_t argc, const char* argv[]) {
    /* initialization and setup a context */

    // get the context asset manager
    auto& am = ctx->asset_manager;

    bskgl::UUID va_uuid = 
        am->create_asset(
            std::vector<bskgl::Vertex>({}),
            std::vector<uint32_t>({})
        );
    auto vao = am->get_asset<bskgl::Shader>(shader_uuid);

    if (!vao)
        BSK_ERROR("Couldn't create shader".);

    // bind the shader
    vao->bind();

    /* shutdown and cleanup*/
}
```

### **Render a Triangle**
```cpp
#include <basikgl/basikgl.h>

int32_t main(int32_t argc, const char* argv[]) {
    // initialize the library
    bskgl::initialize();

    // get the context manager
    bskgl::ContextManager& context_manager = bskgl::ContextManager::instance();

    // create a context
    bskgl::WindowProperties window_properties(800, 800, "BasikGL Window", bskgl::CursorMode::Normal, bskgl::default_window_attributes() ^ bskgl::WindowAttribute::Resizable);
    bskgl::ContextProperties context_properties(window_properties, bskgl::Color::black());
    bskgl::UUID context_uuid = context_manager.create_context(context_properties);
    bskgl::ContextManager::ContextHandle context = context_manager.get_context(context_uuid);

    // bind the context
    context->bind();

    // create a shader
    bskgl::UUID shader_uuid = 
        context->asset_manager.create_asset<bskgl::Shader>(
            std::filesystem::path("shaders/vert.shader"), 
            std::filesystem::path("shaders/pixel.shader")
        );

    // get the shader
    bskgl::AssetManager::AssetHandle<bskgl::Shader> shader = context->asset_manager.get_asset<bskgl::Shader>(shader_uuid);

    // set a color uniform (if you want)
    shader->set_uniform("u_color", bskgl::Color(128, 128, 128, 255));

    // create a triangle vertex array
    std::vector<bskgl::Vertex> triangle_vertices({
        bskgl::Vertex(glm::vec3( 0.0f,  0.5f, 0.0f)),
        bskgl::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
        bskgl::Vertex(glm::vec3( 0.5f, -0.5f, 0.0f))
    });
    bskgl::UUID triangle_va_uuid = context->asset_manager.create_asset<bskgl::VertexArray>(triangle_vertices);

    // enter the game loop
    while (context->window.is_open()) {
        // clear the context
        context->clear();

        // render the triangle
        context->renderer.render(triangle_va_uuid, shader_uuid);

        // swap window buffers
        context->window.swap_buffers();

        // poll window events
        bskgl::Window::poll_events();
    }

    // shutdown the library
    bskgl::shutdown();

    return 0;
}
```

## **Code Structure**

## **To-Do**
📌 **Planned Features & Improvements**
- [ ] Adding a **GUICamera**
- [ ] Adding an **OrthographicCamera**
- [ ] Adding more **Texture** support
- [ ] Adding a **Mesh** system
- [ ] Adding a **Material** system
- [ ] Adding a **Model** system
- [ ] Adding a **Model Loading** system
- [ ] Adding **Different Log Levels**
- [ ] Adding **Different Error Notification Levels**

## **License**
```
Apache License
Version 2.0, January 2004
```

## **Bugs**
- ✅ Clear color in constructor of **bskgl::ContextProperties** is not set properly.