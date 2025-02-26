/**
 * @file basikgl.h
 * @brief Includes every basikgl functionality.
 * @author Arnav Deshpande
 */

/// @dir core
#include <core/core.h>
#include <core/error_handler.h>
#include <core/logger.h>
#include <core/convert_values.h>

/// @dir time
#include <time/timespan.h>
#include <time/clock.h>

/// @dir context
#include <context/asset_manager.h>
#include <context/context_properties.h>
#include <context/render_context.h>
#include <context/context_manager.h>

/// @dir window
#include <window/window_attributes.h>
#include <window/window_properties.h>
#include <window/window_callbacks.h>
#include <window/window.h>

/// @dir gfx
#include <gfx/vertex.h>
#include <gfx/vertexbuffer.h>
#include <gfx/indexbuffer.h>
#include <gfx/vertexarray.h>
#include <gfx/shader.h>

/// @dir sprite
#include <sprite/sprite.h>

/// @dir gfx/texture
#include <gfx/texture/texture.h>
#include <gfx/texture/texture2d.h>

/// @dir input
#include <input/keyinput.h>
#include <input/mouseinput.h>
#include <input/cursor.h>

/// @dir camera
#include <camera/camera.h>
#include <camera/gui_camera.h>
#include <camera/perspective_camera.h>
#include <camera/player_camera.h>

/// @dir utils
#include <utils/utils.h>
#include <utils/uuid_generator.h>