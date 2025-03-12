#include <glad/glad.h>
#include <basikgl/basikgl.h>

static const std::filesystem::path g_assets_dir = std::filesystem::path(ASSETS_DIR);

void run() {
    using namespace bskgl;

    auto& ctx_manager = ContextManager::instance();

    UUID ctx_uuid = 
        ctx_manager.create_context(
            ContextProperties(
                WindowProperties(800, 800, "Window")
#if 1
                ,
                Color(255, 255, 255, 255)
#endif
            )
        );
    auto ctx = ctx_manager.get_context(ctx_uuid);
    ctx->bind();
    Window& win = ctx->window;

#if 0
    ctx->set_clear_color(Color(255, 255, 255, 255));
#endif
    win.callbacks.key_held_callback  = 
        [](Window&, KeyCode key) {
        };

    auto& am = ctx->asset_manager;

    UUID shdr = am.create_asset<Shader>(
        g_assets_dir / "shaders/vert.shader", 
        g_assets_dir / "shaders/pixel.shader");
    UUID vao = 
        am.create_asset<VertexArray>(
            std::vector<Vertex>({
                Vertex(glm::vec3(0.0f, 0.5f, 0.0f)),
                Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
                Vertex(glm::vec3(0.5f, -0.5f, 0.0f))
            })
        );
    std::shared_ptr<Shader> shader = am.get_asset<Shader>(shdr);
    std::shared_ptr<VertexArray> va = am.get_asset<VertexArray>(vao);

    Clock clock;

    shader->set_uniform("u_model", glm::mat4(1.0f));

    PlayerCamera camera(static_cast<float>(win.width()) / static_cast<float>(win.height()));

    glm::dvec2 first_cursor_pos = win.cursor_position();

    win.callbacks.cursor_pos_callback =
        [&](Window& win, glm::dvec2 cursor_pos) {
            static glm::dvec2 last_cursor_pos = first_cursor_pos;
            glm::dvec2 offset = cursor_pos - last_cursor_pos;
            last_cursor_pos = cursor_pos;
            camera.turn(offset);
        };

    while (win.is_open()) {
        clock.tick();
        ctx->clear();

        shader->set_uniform(
            "u_color", 
            Color(
                glm::vec4(
                    glm::cos(clock.elapsed_time()), 
                    glm::sin(clock.elapsed_time()), 
                    1.0f, 1.0f
                )
            )
        );
        shader->set_uniform("u_viewproj", camera.view_projection_matrix());

        Timespan dt = clock.delta_time();

        if (win.is_key_held(KeyCode::W))
            camera.strafe(PlayerStrafeDirection::CameraFront, dt);
        else if (win.is_key_held(KeyCode::S))
            camera.strafe(PlayerStrafeDirection::CameraBack, dt);
        if (win.is_key_held(KeyCode::A))
            camera.strafe(PlayerStrafeDirection::CameraLeft, dt);
        else if (win.is_key_held(KeyCode::D))
            camera.strafe(PlayerStrafeDirection::CameraRight, dt);
        if (win.is_key_held(KeyCode::Space))
            camera.strafe(PlayerStrafeDirection::CameraUp, dt);
        else if (win.is_key_held(KeyCode::LeftShift))
            camera.strafe(PlayerStrafeDirection::CameraDown, dt);

        if (win.is_key_pressed(KeyCode::R)) {
            if (win.is_attribute_enabled(WindowAttribute::Resizable))
                win.disable_attribute(WindowAttribute::Resizable);
            else 
                win.enable_attribute(WindowAttribute::Resizable);
        }

        ctx->renderer.render(va->uuid(), shader->uuid());

        win.swap_buffers();
        Window::poll_events();
    }

}

int32_t main(int32_t argc, const char* argv[]) {
    bskgl::initialize();

    // lazy laod
    bskgl::ContextManager::instance();

    run();

    bskgl::shutdown();

    return 0;
}