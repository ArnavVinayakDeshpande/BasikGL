/// @include Basikgl library
#include <basikgl/basikgl.h>

static const std::filesystem::path g_cwd = std::filesystem::path(BSKGL_EXAMPLES_DIR) / "triangle";
static const std::filesystem::path g_assets_dir = g_cwd / "assets";

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
            std::filesystem::path(g_assets_dir / "shaders/vert.shader"), 
            std::filesystem::path(g_assets_dir / "shaders/pixel.shader")
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