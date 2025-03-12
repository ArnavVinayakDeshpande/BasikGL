/**
 * @file basikgl.h
 * @brief Includes every basikgl functionality.
 * @author Arnav Deshpande
 */

/// @dir core
#include <basikgl/core/core.h>
#include <basikgl/core/error_handler.h>
#include <basikgl/core/logger.h>
#include <basikgl/core/convert_values.h>

/// @dir time
#include <basikgl/time/timespan.h>
#include <basikgl/time/clock.h>
#include <basikgl/time/timer.h>

/// @dir context
#include <basikgl/context/asset_manager.h>
#include <basikgl/context/context_properties.h>
#include <basikgl/context/render_context.h>
#include <basikgl/context/context_manager.h>

/// @dir window
#include <basikgl/window/window_attributes.h>
#include <basikgl/window/window_properties.h>
#include <basikgl/window/window_callbacks.h>
#include <basikgl/window/window.h>

/// @dir gfx
#include <basikgl/gfx/vertex.h>
#include <basikgl/gfx/vertexbuffer.h>
#include <basikgl/gfx/indexbuffer.h>
#include <basikgl/gfx/vertexarray.h>
#include <basikgl/gfx/shader.h>

/// @dir render
#include <basikgl/render/renderer.h>

/// @dir sprite
#include <basikgl/sprite/sprite.h>

/// @dir gfx/texture
#include <basikgl/gfx/texture/texture.h>
#include <basikgl/gfx/texture/texture2d.h>

/// @dir input
#include <basikgl/input/keyinput.h>
#include <basikgl/input/mouseinput.h>
#include <basikgl/input/cursor.h>

/// @dir camera
#include <basikgl/camera/camera.h>
#include <basikgl/camera/gui_camera.h>
#include <basikgl/camera/perspective_camera.h>
#include <basikgl/camera/player_camera.h>

/// @dir color
#include <basikgl/color/color.h>
#include <basikgl/color/ansi_color_codes.h>

/// @dir utils
#include <basikgl/utils/utils.h>
#include <basikgl/utils/uuid_generator.h>