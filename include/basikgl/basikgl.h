/**
 * @file basikgl.h
 * @brief Includes every basikgl functionality.
 * @author Arnav Deshpande
 */

/// @dir core
#include "../../src/core/core.h"
#include "../../src/core/error_handler.h"
#include "../../src/core/logger.h"
#include "../../src/core/convert_values.h"

/// @dir time
#include "../../src/time/timespan.h"
#include "../../src/time/clock.h"

/// @dir context
#include "../../src/context/asset_manager.h"
#include "../../src/context/context_properties.h"
#include "../../src/context/render_context.h"
#include "../../src/context/context_manager.h"

/// @dir window
#include "../../src/window/window_attributes.h"
#include "../../src/window/window_properties.h"
#include "../../src/window/window_callbacks.h"
#include "../../src/window/window.h"

/// @dir gfx
#include "../../src/gfx/vertex.h"
#include "../../src/gfx/vertexbuffer.h"
#include "../../src/gfx/indexbuffer.h"
#include "../../src/gfx/vertexarray.h"
#include "../../src/gfx/shader.h"

/// @dir sprite
#include "../../src/sprite/sprite.h"

/// @dir gfx/texture
#include "../../src/gfx/texture/texture.h"
#include "../../src/gfx/texture/texture2d.h"

/// @dir input
#include "../../src/input/keyinput.h"
#include "../../src/input/mouseinput.h"
#include "../../src/input/cursor.h"

/// @dir camera
#include "../../src/camera/camera.h"
#include "../../src/camera/gui_camera.h"
#include "../../src/camera/perspective_camera.h"
#include "../../src/camera/player_camera.h"

/// @dir utils
#include "../../src/utils/utils.h"
#include "../../src/utils/uuid_generator.h"