#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/convert_values.h>
#include <core/error_handler.h>

namespace bskgl::opengl {

    int32_t convert(TextureBase::Type type) {
        switch (type) {
            case TextureBase::Type::Texture2D:
                return GL_TEXTURE_2D;
            case TextureBase::Type::Texture3D:
                return GL_TEXTURE_3D;
            case TextureBase::Type::TextureCubeMap:
                return GL_TEXTURE_CUBE_MAP;
            case TextureBase::Type::Texture2DArray:
                return GL_TEXTURE_2D_ARRAY;
            case TextureBase::Type::TextureCubeMapArray:
                return GL_TEXTURE_CUBE_MAP_ARRAY;
            case TextureBase::Type::Texture1D:
                return GL_TEXTURE_1D;
            case TextureBase::Type::Texture1DArray:
                return GL_TEXTURE_1D_ARRAY;
            case TextureBase::Type::TextureRectangle:
                return GL_TEXTURE_RECTANGLE;
            case TextureBase::Type::TextureBuffer:
                return GL_TEXTURE_BUFFER;
            case TextureBase::Type::Texture2DMultisample:
                return GL_TEXTURE_2D_MULTISAMPLE;
            case TextureBase::Type::Texture2DMultisampleArray:
                return GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
            default:
                BSK_WARNING("Unsupported texture type.");
                return -1;
        }
    }

    int32_t convert(TextureBase::InternalFormat int_format) {
        switch (int_format) {
            case TextureBase::InternalFormat::Red:
                return GL_RED;
            case TextureBase::InternalFormat::RG:
                return GL_RG;
            case TextureBase::InternalFormat::RGB:
                return GL_RGB;
            case TextureBase::InternalFormat::RGBA:
                return GL_RGBA;
            case TextureBase::InternalFormat::Depth:
                return GL_DEPTH;
            case TextureBase::InternalFormat::DepthStencil:
                return GL_DEPTH_STENCIL;
            default:
                BSK_WARNING("Unsupported texture internal format.");
                return -1;
        }
    }

    int32_t convert(TextureBase::Format format) {
        switch (format) {
            case TextureBase::Format::Red:
                return GL_RED;
            case TextureBase::Format::RG:
                return GL_RG;
            case TextureBase::Format::RGB:
                return GL_RGB;
            case TextureBase::Format::RGBA:
                return GL_RGBA;
            case TextureBase::Format::Depth:
                return GL_DEPTH;
            case TextureBase::Format::DepthStencil:
                return GL_DEPTH_STENCIL;
            default:
                BSK_WARNING("Unsupported texture format.");
                return -1;
        }
    }

    int32_t convert(TextureBase::DataType datatype) {
        switch (datatype) {
            case TextureBase::DataType::UnsignedByte:
                return GL_UNSIGNED_BYTE;
            case TextureBase::DataType::Byte:
                return GL_BYTE;
            case TextureBase::DataType::UnsignedShort:
                return GL_UNSIGNED_SHORT;
            case TextureBase::DataType::Short:
                return GL_SHORT;
            case TextureBase::DataType::UnsignedInt:
                return GL_UNSIGNED_INT;
            case TextureBase::DataType::Int:
                return GL_INT;
            case TextureBase::DataType::Float:
                return GL_FLOAT;
            case TextureBase::DataType::HalfFloat:
                return GL_HALF_FLOAT;
            default:
                BSK_WARNING("Unsupported texture data type.");
                return -1;
        }
    }

    int32_t convert(TextureBase::MinFilter min_filter) {
        switch (min_filter) {
            case TextureBase::MinFilter::Nearest:
                return GL_NEAREST;
            case TextureBase::MinFilter::Linear:
                return GL_LINEAR;
            case TextureBase::MinFilter::NearestMipmapNearest:
                return GL_NEAREST_MIPMAP_NEAREST;
            case TextureBase::MinFilter::LinearMipmapNearest:
                return GL_LINEAR_MIPMAP_NEAREST;
            case TextureBase::MinFilter::NearestMipmapLinear:
                return GL_NEAREST_MIPMAP_LINEAR;
            case TextureBase::MinFilter::LinearMipmapLinear:
                return GL_LINEAR_MIPMAP_LINEAR;
            default:
                BSK_WARNING("Unsupported texture min filter.");
                return -1;
        }
    }

    int32_t convert(TextureBase::MagFilter mag_filter) {
        switch (mag_filter) {
            case TextureBase::MagFilter::Nearest:
                return GL_NEAREST;
            case TextureBase::MagFilter::Linear:
                return GL_LINEAR;
            default:
                BSK_WARNING("Unsupported texture mag filter.");
                return -1;
        }
    }

    int32_t convert(TextureBase::WrapMode wrap_mode) {
        switch (wrap_mode) {
            case TextureBase::WrapMode::Repeat:
                return GL_REPEAT;
            case TextureBase::WrapMode::MirroredRepeat:
                return GL_MIRRORED_REPEAT;
            case TextureBase::WrapMode::ClampToEdge:
                return GL_CLAMP_TO_EDGE;
            case TextureBase::WrapMode::ClampToBorder:
                return GL_CLAMP_TO_BORDER;
            default:
                BSK_WARNING("Unsupported texture wrap mode.");
                return -1;
        }
    }

    int32_t convert(GLTest test) {
        switch (test) {
            case GLTest::DepthTest:
                return GL_DEPTH_TEST;
            case GLTest::StencilTest:
                return GL_STENCIL_TEST;
            case GLTest::Blend:
                return GL_BLEND;
            case GLTest::CullFace:
                return GL_CULL_FACE;
            case GLTest::ScissorTest:
                return GL_SCISSOR_TEST;
            case GLTest::Dither:
                return GL_DITHER;
            case GLTest::PolygonOffset:
                return GL_POLYGON_OFFSET_FILL;
            case GLTest::SampleAlphaToCoverage:
                return GL_SAMPLE_ALPHA_TO_COVERAGE;
            case GLTest::SampleCoverage:
                return GL_SAMPLE_COVERAGE;
            case GLTest::Multisample:
                return GL_MULTISAMPLE;
            case GLTest::LineSmooth:
                return GL_LINE_SMOOTH;
            case GLTest::PolygonSmooth:
                return GL_POLYGON_SMOOTH;
            case GLTest::FramebufferSRGB:
                return GL_FRAMEBUFFER_SRGB;
            case GLTest::DebugOutput:
                return GL_DEBUG_OUTPUT;
            case GLTest::DebugOutputSynchronous:
                return GL_DEBUG_OUTPUT_SYNCHRONOUS;
            default:
                BSK_WARNING("Unsupported gl test .");
                return -1;
        }
    }

    int32_t convert(GLClearBit clearbit) {
        switch (clearbit) {
            case GLClearBit::Color:
                return GL_COLOR_BUFFER_BIT;
            case GLClearBit::Depth:
                return GL_DEPTH_BUFFER_BIT;
            case GLClearBit::Stencil:
                return GL_STENCIL_BUFFER_BIT;
            case GLClearBit::Accum:
                return GL_ACCUM_BUFFER_BIT;
            default:
                BSK_WARNING("Unsupported gl clear bit.")
                return -1;
        }
    }

    TextureBase::Type convert_to_basikgl_texture_type(int32_t type) {
        switch (type) {
            case GL_TEXTURE_2D:
                return TextureBase::Type::Texture2D;
            case GL_TEXTURE_3D:
                return TextureBase::Type::Texture3D;
            case GL_TEXTURE_CUBE_MAP:
                return TextureBase::Type::TextureCubeMap;
            case GL_TEXTURE_2D_ARRAY:
                return TextureBase::Type::Texture2DArray;
            case GL_TEXTURE_CUBE_MAP_ARRAY:
                return TextureBase::Type::TextureCubeMapArray;
            case GL_TEXTURE_1D:
                return TextureBase::Type::Texture1D;
            case GL_TEXTURE_1D_ARRAY:
                return TextureBase::Type::Texture1DArray;
            case GL_TEXTURE_RECTANGLE:
                return TextureBase::Type::TextureRectangle;
            case GL_TEXTURE_BUFFER:
                return TextureBase::Type::TextureBuffer;
            case GL_TEXTURE_2D_MULTISAMPLE:
                return TextureBase::Type::Texture2DMultisample;
            case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
                return TextureBase::Type::Texture2DMultisampleArray;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for type occured.");
                return TextureBase::Type::None;
        }
    }

    TextureBase::InternalFormat convert_to_basikgl_texture_internal_format(int32_t int_format) {
        switch (int_format) {
            case GL_RED:
                return TextureBase::InternalFormat::Red;
            case GL_RG:
                return TextureBase::InternalFormat::RG;
            case GL_RGB:
                return TextureBase::InternalFormat::RGB;
            case GL_RGBA:
                return TextureBase::InternalFormat::RGBA;
            case GL_DEPTH:
                return TextureBase::InternalFormat::Depth;
            case GL_DEPTH_STENCIL:
                return TextureBase::InternalFormat::DepthStencil;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for internal format occured.");
                return TextureBase::InternalFormat::None;
        }
    }

    TextureBase::Format convert_to_basikgl_texture_format(int32_t format) {
        switch (format) {
            case GL_RED:
                return TextureBase::Format::Red;
            case GL_RG:
                return TextureBase::Format::RG;
            case GL_RGB:
                return TextureBase::Format::RGB;
            case GL_RGBA:
                return TextureBase::Format::RGBA;
            case GL_DEPTH:
                return TextureBase::Format::Depth;
            case GL_DEPTH_STENCIL:
                return TextureBase::Format::DepthStencil;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for format occured.");
                return TextureBase::Format::None;
        }
    }

    TextureBase::DataType convert_to_basikgl_texture_data_type(int32_t datatype) {
        switch (datatype) {
            case GL_UNSIGNED_BYTE:
                return TextureBase::DataType::UnsignedByte;
            case GL_BYTE:
                return TextureBase::DataType::Byte;
            case GL_UNSIGNED_SHORT:
                return TextureBase::DataType::UnsignedShort;
            case GL_SHORT:
                return TextureBase::DataType::Short;
            case GL_UNSIGNED_INT:
                return TextureBase::DataType::UnsignedInt;
            case GL_INT:
                return TextureBase::DataType::Int;
            case GL_FLOAT:
                return TextureBase::DataType::Float;
            case GL_HALF_FLOAT:
                return TextureBase::DataType::HalfFloat;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for data type occured.");
                return TextureBase::DataType::None;
        }
    }

    TextureBase::MinFilter convert_to_basikgl_texture_min_filter(int32_t min_filter) {
        switch (min_filter) {
            case GL_NEAREST:
                return TextureBase::MinFilter::Nearest;
            case GL_LINEAR:
                return TextureBase::MinFilter::Linear;
            case GL_NEAREST_MIPMAP_NEAREST:
                return TextureBase::MinFilter::NearestMipmapNearest;
            case GL_LINEAR_MIPMAP_NEAREST:
                return TextureBase::MinFilter::LinearMipmapNearest;
            case GL_NEAREST_MIPMAP_LINEAR:
                return TextureBase::MinFilter::NearestMipmapLinear;
            case GL_LINEAR_MIPMAP_LINEAR:
                return TextureBase::MinFilter::LinearMipmapLinear;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for min filter occured.");
                return TextureBase::MinFilter::None;
        }
    }

    TextureBase::MagFilter convert_to_basikgl_texture_mag_filter(int32_t mag_filter) {
        switch (mag_filter) {
            case GL_NEAREST:
                return TextureBase::MagFilter::Nearest;
            case GL_LINEAR:
                return TextureBase::MagFilter::Linear;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for mag filter occured.");
                return TextureBase::MagFilter::None;
        }
    }

    TextureBase::WrapMode convert_to_basikgL_texture_wrap_mode(int32_t wrap_mode) {
        switch (wrap_mode) {
            case GL_REPEAT:
                return TextureBase::WrapMode::Repeat;
            case GL_MIRRORED_REPEAT:
                return TextureBase::WrapMode::MirroredRepeat;
            case GL_CLAMP_TO_EDGE:
                return TextureBase::WrapMode::ClampToEdge;
            case GL_CLAMP_TO_BORDER:
                return TextureBase::WrapMode::ClampToBorder;
            default:
                BSK_WARNING("Invalid conversion from opengl texture value to basigkl enum for wrap mode occured.");
                return TextureBase::WrapMode::None;
        }
    }

    GLTest convert_to_basikgl_gltest(int32_t test) {
        switch (test) {
            case GL_DEPTH_TEST:
                return GLTest::DepthTest;
            case GL_STENCIL_TEST:
                return GLTest::StencilTest;
            case GL_BLEND:
                return GLTest::Blend;
            case GL_CULL_FACE:
                return GLTest::CullFace;
            case GL_SCISSOR_TEST:
                return GLTest::ScissorTest;
            case GL_DITHER:
                return GLTest::Dither;
            case GL_POLYGON_OFFSET_FILL:
                return GLTest::PolygonOffset;
            case GL_SAMPLE_ALPHA_TO_COVERAGE:
                return GLTest::SampleAlphaToCoverage;
            case GL_SAMPLE_COVERAGE:
                return GLTest::SampleCoverage;
            case GL_MULTISAMPLE:
                return GLTest::Multisample;
            case GL_LINE_SMOOTH:
                return GLTest::LineSmooth;
            case GL_POLYGON_SMOOTH:
                return GLTest::PolygonSmooth;
            case GL_FRAMEBUFFER_SRGB:
                return GLTest::FramebufferSRGB;
            case GL_DEBUG_OUTPUT:
                return GLTest::DebugOutput;
            case GL_DEBUG_OUTPUT_SYNCHRONOUS:
                return GLTest::DebugOutputSynchronous;
            default:
            BSK_WARNING("Invalid conversion from opengl test value to basigkl enum for gl tests occured.");
                return GLTest::None;
        }
    }

    GLClearBit convert_to_basikgl_gl_clear_bit(int32_t clearbit) {
        switch (clearbit) {
            case GL_COLOR_BUFFER_BIT:
                return GLClearBit::Color;
            case GL_DEPTH_BUFFER_BIT:
                return GLClearBit::Depth;
            case GL_STENCIL_BUFFER_BIT:
                return GLClearBit::Stencil;
            case GL_ACCUM_BUFFER_BIT:
                return GLClearBit::Accum;
            default:
                BSK_WARNING("Invalid conversion from opengl clear bit value to basigkl enum for gl clear bits occured.");
                return GLClearBit::None;
        }
    }

}

namespace bskgl::glfw {

    int32_t convert(KeyCode key_code) {
        switch (key_code) {
            case KeyCode::Unknown:
                return GLFW_KEY_UNKNOWN;                         
            case KeyCode::Space:
                return GLFW_KEY_SPACE;                          
            case KeyCode::Apostrophe:
                return GLFW_KEY_APOSTROPHE;                     
            case KeyCode::Comma:
                return GLFW_KEY_COMMA;                          
            case KeyCode::Minus:
                return GLFW_KEY_MINUS;                          
            case KeyCode::Period:
                return GLFW_KEY_PERIOD;                         
            case KeyCode::Slash:
                return GLFW_KEY_SLASH;                          
            case KeyCode::Num0:
                return GLFW_KEY_0;                 
            case KeyCode::Num1:
                return GLFW_KEY_1;                 
            case KeyCode::Num2:
                return GLFW_KEY_2;                 
            case KeyCode::Num3:
                return GLFW_KEY_3;                 
            case KeyCode::Num4:
                return GLFW_KEY_4;                 
            case KeyCode::Num5:
                return GLFW_KEY_5;                 
            case KeyCode::Num6:
                return GLFW_KEY_6;                 
            case KeyCode::Num7:
                return GLFW_KEY_7;                 
            case KeyCode::Num8:
                return GLFW_KEY_8;                 
            case KeyCode::Num9:
                return GLFW_KEY_9;                 
            case KeyCode::Semicolon:
                return GLFW_KEY_SEMICOLON;                      
            case KeyCode::Equal:
                return GLFW_KEY_EQUAL;                          
            case KeyCode::A:
                return GLFW_KEY_A;                 
            case KeyCode::B:
                return GLFW_KEY_B;                 
            case KeyCode::C:
                return GLFW_KEY_C;                 
            case KeyCode::D:
                return GLFW_KEY_D;                 
            case KeyCode::E:
                return GLFW_KEY_E;                 
            case KeyCode::F:
                return GLFW_KEY_F;                 
            case KeyCode::G:
                return GLFW_KEY_G;                 
            case KeyCode::H:
                return GLFW_KEY_H;                 
            case KeyCode::I:
                return GLFW_KEY_I;                 
            case KeyCode::J:
                return GLFW_KEY_J;                 
            case KeyCode::K:
                return GLFW_KEY_K;                 
            case KeyCode::L:
                return GLFW_KEY_L;                 
            case KeyCode::M:
                return GLFW_KEY_M;                 
            case KeyCode::N:
                return GLFW_KEY_N;                 
            case KeyCode::O:
                return GLFW_KEY_O;                 
            case KeyCode::P:
                return GLFW_KEY_P;                 
            case KeyCode::Q:
                return GLFW_KEY_Q;                 
            case KeyCode::R:
                return GLFW_KEY_R;                 
            case KeyCode::S:
                return GLFW_KEY_S;                 
            case KeyCode::T:
                return GLFW_KEY_T;                 
            case KeyCode::U:
                return GLFW_KEY_U;                 
            case KeyCode::V:
                return GLFW_KEY_V;                 
            case KeyCode::W:
                return GLFW_KEY_W;                 
            case KeyCode::X:
                return GLFW_KEY_X;                 
            case KeyCode::Y:
                return GLFW_KEY_Y;                 
            case KeyCode::Z:
                return GLFW_KEY_Z;                 
            case KeyCode::LeftBracket:
                return GLFW_KEY_LEFT_BRACKET;                    
            case KeyCode::Backslash:
                return GLFW_KEY_BACKSLASH;                      
            case KeyCode::RightBracket:
                return GLFW_KEY_RIGHT_BRACKET;                   
            case KeyCode::GraveAccent:
                return GLFW_KEY_GRAVE_ACCENT;                    
            case KeyCode::Escape:
                return GLFW_KEY_ESCAPE;                         
            case KeyCode::Enter:
                return GLFW_KEY_ENTER;                          
            case KeyCode::Tab:
                return GLFW_KEY_TAB;                            
            case KeyCode::Backspace:
                return GLFW_KEY_BACKSPACE;                      
            case KeyCode::Insert:
                return GLFW_KEY_INSERT;                         
            case KeyCode::Delete:
                return GLFW_KEY_DELETE;                         
            case KeyCode::Right:
                return GLFW_KEY_RIGHT;                 
            case KeyCode::Left:
                return GLFW_KEY_LEFT;                 
            case KeyCode::Down:
                return GLFW_KEY_DOWN;                 
            case KeyCode::Up:
                return GLFW_KEY_UP;                 
            case KeyCode::PageUp:
                return GLFW_KEY_PAGE_UP;                 
            case KeyCode::PageDown:
                return GLFW_KEY_PAGE_DOWN;                 
            case KeyCode::Home:
                return GLFW_KEY_HOME;                 
            case KeyCode::End:
                return GLFW_KEY_END;                 
            case KeyCode::CapsLock:
                return GLFW_KEY_CAPS_LOCK;                 
            case KeyCode::ScrollLock:
                return GLFW_KEY_SCROLL_LOCK;                 
            case KeyCode::NumLock:
                return GLFW_KEY_NUM_LOCK;                 
            case KeyCode::PrintScreen:
                return GLFW_KEY_PRINT_SCREEN;                 
            case KeyCode::Pause:
                return GLFW_KEY_PAUSE;                 
            case KeyCode::F1:
                return GLFW_KEY_F1;                 
            case KeyCode::F2:
                return GLFW_KEY_F2;                 
            case KeyCode::F3:
                return GLFW_KEY_F3;                 
            case KeyCode::F4:
                return GLFW_KEY_F4;                 
            case KeyCode::F5:
                return GLFW_KEY_F5;                 
            case KeyCode::F6:
                return GLFW_KEY_F6;                 
            case KeyCode::F7:
                return GLFW_KEY_F7;                 
            case KeyCode::F8:
                return GLFW_KEY_F8;                 
            case KeyCode::F9:
                return GLFW_KEY_F9;                 
            case KeyCode::F10:
                return GLFW_KEY_F10;                 
            case KeyCode::F11:
                return GLFW_KEY_F11;                 
            case KeyCode::F12:
                return GLFW_KEY_F12;                 
            case KeyCode::Keypad0:
                return GLFW_KEY_KP_0;                 
            case KeyCode::Keypad1:
                return GLFW_KEY_KP_1;                 
            case KeyCode::Keypad2:
                return GLFW_KEY_KP_2;                 
            case KeyCode::Keypad3:
                return GLFW_KEY_KP_3;                 
            case KeyCode::Keypad4:
                return GLFW_KEY_KP_4;                 
            case KeyCode::Keypad5:
                return GLFW_KEY_KP_5;                 
            case KeyCode::Keypad6:
                return GLFW_KEY_KP_6;                 
            case KeyCode::Keypad7:
                return GLFW_KEY_KP_7;                 
            case KeyCode::Keypad8:
                return GLFW_KEY_KP_8;                 
            case KeyCode::Keypad9:
                return GLFW_KEY_KP_9;                 
            case KeyCode::KeypadDecimal:
                return GLFW_KEY_KP_DECIMAL;                 
            case KeyCode::KeypadDivide:
                return GLFW_KEY_KP_DIVIDE;                 
            case KeyCode::KeypadMultiply:
                return GLFW_KEY_KP_MULTIPLY;                 
            case KeyCode::KeypadSubtract:
                return GLFW_KEY_KP_SUBTRACT;                 
            case KeyCode::KeypadAdd:
                return GLFW_KEY_KP_ADD;                 
            case KeyCode::KeypadEnter:
                return GLFW_KEY_KP_ENTER;                 
            case KeyCode::KeypadEqual:
                return GLFW_KEY_KP_EQUAL;                 
            case KeyCode::LeftShift:
                return GLFW_KEY_LEFT_SHIFT;                 
            case KeyCode::LeftControl:
                return GLFW_KEY_LEFT_CONTROL;                 
            case KeyCode::LeftAlt:
                return GLFW_KEY_LEFT_ALT;                 
            case KeyCode::LeftSuper:
                return GLFW_KEY_LEFT_SUPER;                 
            case KeyCode::RightShift:
                return GLFW_KEY_RIGHT_SHIFT;                 
            case KeyCode::RightControl:
                return GLFW_KEY_RIGHT_CONTROL;                 
            case KeyCode::RightAlt:
                return GLFW_KEY_RIGHT_ALT;                 
            case KeyCode::RightSuper:
                return GLFW_KEY_RIGHT_SUPER;                 
            case KeyCode::Menu:
                return GLFW_KEY_MENU;                
            default:
                BSK_WARNING("Unsupported key code.");
                return -1;
        }
    }

    int32_t convert(KeyMode key_mode) {
        switch (key_mode) {
            case KeyMode::Pressed:
                return GLFW_PRESS;
            case KeyMode::Held:
                return GLFW_REPEAT;
            case KeyMode::Released:
                return GLFW_RELEASE;
            default:
                BSK_WARNING("Unsupported key mode.");
                return -1;
        }
    }

    int32_t convert(MouseButtonCode mouse_button) {
        switch (mouse_button) {
            case MouseButtonCode::Button1:
                return GLFW_MOUSE_BUTTON_1;
            case MouseButtonCode::Button2:
                return GLFW_MOUSE_BUTTON_2;
            case MouseButtonCode::Button3:
                return GLFW_MOUSE_BUTTON_3;
            case MouseButtonCode::Button4:
                return GLFW_MOUSE_BUTTON_4;
            case MouseButtonCode::Button5:
                return GLFW_MOUSE_BUTTON_5;
            case MouseButtonCode::Button6:
                return GLFW_MOUSE_BUTTON_6;
            case MouseButtonCode::Button7:
                return GLFW_MOUSE_BUTTON_7;
            case MouseButtonCode::Button8:
                return GLFW_MOUSE_BUTTON_8;
            default:
                BSK_WARNING("Unsupported mouse button code.");
                return -1;
        }
    }

    int32_t convert(CursorMode cursor_mode) {
        switch (cursor_mode) {
            case CursorMode::Normal:
                return GLFW_CURSOR_NORMAL;
            case CursorMode::Disabled:
                return GLFW_CURSOR_DISABLED;
            case CursorMode::Hidden:
                return GLFW_CURSOR_HIDDEN;
            case CursorMode::Captured:
                return GLFW_CURSOR_CAPTURED;
            default:
                BSK_WARNING("Unsupported cursor mode.");
                return -1;
        }
    }

    int32_t convert(WindowAttribute attribute) {
        switch (attribute) {
            case WindowAttribute::Resizable:
                return GLFW_RESIZABLE;
            case WindowAttribute::Visible:
                return GLFW_VISIBLE;
            case WindowAttribute::Decorated:
                return GLFW_DECORATED;
            case WindowAttribute::Focused:
                return GLFW_FOCUSED;
            case WindowAttribute::AutoIconify:
                return GLFW_AUTO_ICONIFY;
            case WindowAttribute::Floating:
                return GLFW_FLOATING;
            case WindowAttribute::Maximized:
                return GLFW_MAXIMIZED;
            case WindowAttribute::CenterCursor:
                return GLFW_CENTER_CURSOR;
            case WindowAttribute::TransparentFramebuffer:
                return GLFW_TRANSPARENT_FRAMEBUFFER;
            case WindowAttribute::FocusOnShow:
                return GLFW_FOCUS_ON_SHOW;
            case WindowAttribute::ScaleToMonitor:
                return GLFW_SCALE_TO_MONITOR;
            case WindowAttribute::ScaleFramebuffer:
                return GLFW_SCALE_FRAMEBUFFER;
            case WindowAttribute::MousePassthrough:
                return GLFW_MOUSE_PASSTHROUGH;
            default:
                BSK_WARNING("Unsupported window attribute.");
                return -1;
        }
    }
    
    KeyCode convert_to_basikgl_key_code(int32_t key_code) {
        switch (key_code) {
            case GLFW_KEY_UNKNOWN:                         
                return KeyCode::Unknown;
            case GLFW_KEY_SPACE:                          
                return KeyCode::Space;
            case GLFW_KEY_APOSTROPHE:                     
                return KeyCode::Apostrophe;
            case GLFW_KEY_COMMA:                          
                return KeyCode::Comma;
            case GLFW_KEY_MINUS:                          
                return KeyCode::Minus;
            case GLFW_KEY_PERIOD:                         
                return KeyCode::Period;
            case GLFW_KEY_SLASH:                          
                return KeyCode::Slash;
            case GLFW_KEY_0:                 
                return KeyCode::Num0;
            case GLFW_KEY_1:                 
                return KeyCode::Num1;
            case GLFW_KEY_2:                 
                return KeyCode::Num2;
            case GLFW_KEY_3:                 
                return KeyCode::Num3;
            case GLFW_KEY_4:                 
                return KeyCode::Num4;
            case GLFW_KEY_5:                 
                return KeyCode::Num5;
            case GLFW_KEY_6:                 
                return KeyCode::Num6;
            case GLFW_KEY_7:                 
                return KeyCode::Num7;
            case GLFW_KEY_8:                 
                return KeyCode::Num8;
            case GLFW_KEY_9:                 
                return KeyCode::Num9;
            case GLFW_KEY_SEMICOLON:                      
                return KeyCode::Semicolon;
            case GLFW_KEY_EQUAL:                          
                return KeyCode::Equal;
            case GLFW_KEY_A:                 
                return KeyCode::A;
            case GLFW_KEY_B:                 
                return KeyCode::B;
            case GLFW_KEY_C:                 
                return KeyCode::C;
            case GLFW_KEY_D:                 
                return KeyCode::D;
            case GLFW_KEY_E:                 
                return KeyCode::E;
            case GLFW_KEY_F:                 
                return KeyCode::F;
            case GLFW_KEY_G:                 
                return KeyCode::G;
            case GLFW_KEY_H:                 
                return KeyCode::H;
            case GLFW_KEY_I:                 
                return KeyCode::I;
            case GLFW_KEY_J:                 
                return KeyCode::J;
            case GLFW_KEY_K:                 
                return KeyCode::K;
            case GLFW_KEY_L:                 
                return KeyCode::L;
            case GLFW_KEY_M:                 
                return KeyCode::M;
            case GLFW_KEY_N:                 
                return KeyCode::N;
            case GLFW_KEY_O:                 
                return KeyCode::O;
            case GLFW_KEY_P:                 
                return KeyCode::P;
            case GLFW_KEY_Q:                 
                return KeyCode::Q;
            case GLFW_KEY_R:                 
                return KeyCode::R;
            case GLFW_KEY_S:                 
                return KeyCode::S;
            case GLFW_KEY_T:                 
                return KeyCode::T;
            case GLFW_KEY_U:                 
                return KeyCode::U;
            case GLFW_KEY_V:                 
                return KeyCode::V;
            case GLFW_KEY_W:                 
                return KeyCode::W;
            case GLFW_KEY_X:                 
                return KeyCode::X;
            case GLFW_KEY_Y:                 
                return KeyCode::Y;
            case GLFW_KEY_Z:                 
                return KeyCode::Z;
            case GLFW_KEY_LEFT_BRACKET:                    
                return KeyCode::LeftBracket;
            case GLFW_KEY_BACKSLASH:                      
                return KeyCode::Backslash;
            case GLFW_KEY_RIGHT_BRACKET:                   
                return KeyCode::RightBracket;
            case GLFW_KEY_GRAVE_ACCENT:                    
                return KeyCode::GraveAccent;
            case GLFW_KEY_ESCAPE:                         
                return KeyCode::Escape;
            case GLFW_KEY_ENTER:                          
                return KeyCode::Enter;
            case GLFW_KEY_TAB:                            
                return KeyCode::Tab;
            case GLFW_KEY_BACKSPACE:                      
                return KeyCode::Backspace;
            case GLFW_KEY_INSERT:                         
                return KeyCode::Insert;
            case GLFW_KEY_DELETE:                         
                return KeyCode::Delete;
            case GLFW_KEY_RIGHT:                 
                return KeyCode::Right;
            case GLFW_KEY_LEFT:                 
                return KeyCode::Left;
            case GLFW_KEY_DOWN:                 
                return KeyCode::Down;
            case GLFW_KEY_UP:                 
                return KeyCode::Up;
            case GLFW_KEY_PAGE_UP:                 
                return KeyCode::PageUp;
            case GLFW_KEY_PAGE_DOWN:                 
                return KeyCode::PageDown;
            case GLFW_KEY_HOME:                 
                return KeyCode::Home;
            case GLFW_KEY_END:                 
                return KeyCode::End;
            case GLFW_KEY_CAPS_LOCK:                 
                return KeyCode::CapsLock;
            case GLFW_KEY_SCROLL_LOCK:                 
                return KeyCode::ScrollLock;
            case GLFW_KEY_NUM_LOCK:                 
                return KeyCode::NumLock;
            case GLFW_KEY_PRINT_SCREEN:                 
                return KeyCode::PrintScreen;
            case GLFW_KEY_PAUSE:                 
                return KeyCode::Pause;
            case GLFW_KEY_F1:                 
                return KeyCode::F1;
            case GLFW_KEY_F2:                 
                return KeyCode::F2;
            case GLFW_KEY_F3:                 
                return KeyCode::F3;
            case GLFW_KEY_F4:                 
                return KeyCode::F4;
            case GLFW_KEY_F5:                 
                return KeyCode::F5;
            case GLFW_KEY_F6:                 
                return KeyCode::F6;
            case GLFW_KEY_F7:                 
                return KeyCode::F7;
            case GLFW_KEY_F8:                 
                return KeyCode::F8;
            case GLFW_KEY_F9:                 
                return KeyCode::F9;
            case GLFW_KEY_F10:                 
                return KeyCode::F10;
            case GLFW_KEY_F11:                 
                return KeyCode::F11;
            case GLFW_KEY_F12:                 
                return KeyCode::F12;
            case GLFW_KEY_KP_0:                 
                return KeyCode::Keypad0;
            case GLFW_KEY_KP_1:                 
                return KeyCode::Keypad1;
            case GLFW_KEY_KP_2:                 
                return KeyCode::Keypad2;
            case GLFW_KEY_KP_3:                 
                return KeyCode::Keypad3;
            case GLFW_KEY_KP_4:                 
                return KeyCode::Keypad4;
            case GLFW_KEY_KP_5:                 
                return KeyCode::Keypad5;
            case GLFW_KEY_KP_6:                 
                return KeyCode::Keypad6;
            case GLFW_KEY_KP_7:                 
                return KeyCode::Keypad7;
            case GLFW_KEY_KP_8:                 
                return KeyCode::Keypad8;
            case GLFW_KEY_KP_9:                 
                return KeyCode::Keypad9;
            case GLFW_KEY_KP_DECIMAL:                 
                return KeyCode::KeypadDecimal;
            case GLFW_KEY_KP_DIVIDE:                 
                return KeyCode::KeypadDivide;
            case GLFW_KEY_KP_MULTIPLY:                 
                return KeyCode::KeypadMultiply;
            case GLFW_KEY_KP_SUBTRACT:                 
                return KeyCode::KeypadSubtract;
            case GLFW_KEY_KP_ADD:                 
                return KeyCode::KeypadAdd;
            case GLFW_KEY_KP_ENTER:                 
                return KeyCode::KeypadEnter;
            case GLFW_KEY_KP_EQUAL:                 
                return KeyCode::KeypadEqual;
            case GLFW_KEY_LEFT_SHIFT:                 
                return KeyCode::LeftShift;
            case GLFW_KEY_LEFT_CONTROL:                 
                return KeyCode::LeftControl;
            case GLFW_KEY_LEFT_ALT:                 
                return KeyCode::LeftAlt;
            case GLFW_KEY_LEFT_SUPER:                 
                return KeyCode::LeftSuper;
            case GLFW_KEY_RIGHT_SHIFT:                 
                return KeyCode::RightShift;
            case GLFW_KEY_RIGHT_CONTROL:                 
                return KeyCode::RightControl;
            case GLFW_KEY_RIGHT_ALT:                 
                return KeyCode::RightAlt;
            case GLFW_KEY_RIGHT_SUPER:                 
                return KeyCode::RightSuper;
            case GLFW_KEY_MENU:                
                return KeyCode::Menu;
            default:
                BSK_WARNING("Invalid conversion from glfw key code value to basigkl enum for key code occured.");
                return KeyCode::Unknown;
        }
    }

    KeyMode convert_to_basikgl_key_mode(int32_t key_mode) {
        switch (key_mode) {
            case GLFW_PRESS:
                return KeyMode::Pressed;
            case GLFW_REPEAT:
                return KeyMode::Held;
            case GLFW_RELEASE:
                return KeyMode::Released;
            default:
                BSK_WARNING("Invalid conversion from glfw key mode value to basigkl enum for key mode occured.");
                return KeyMode::None;
        }
    }

    MouseButtonCode convert_to_basikgl_mouse_button_code(int32_t mouse_button) {
        switch (mouse_button) {
            case GLFW_MOUSE_BUTTON_1:
                return MouseButtonCode::Button1;
            case GLFW_MOUSE_BUTTON_2:
                return MouseButtonCode::Button2;
            case GLFW_MOUSE_BUTTON_3:
                return MouseButtonCode::Button3;
            case GLFW_MOUSE_BUTTON_4:
                return MouseButtonCode::Button4;
            case GLFW_MOUSE_BUTTON_5:
                return MouseButtonCode::Button5;
            case GLFW_MOUSE_BUTTON_6:
                return MouseButtonCode::Button6;
            case GLFW_MOUSE_BUTTON_7:
                return MouseButtonCode::Button7;
            case GLFW_MOUSE_BUTTON_8:
                return MouseButtonCode::Button8;
            default:
                BSK_WARNING("Invalid conversion from glfw mouse button value to basigkl enum for mouse button code occured.");
                return MouseButtonCode::None;
        }
    }

    CursorMode convert_to_basikgl_cursor_mode(int32_t cursor_mode) {
        switch (cursor_mode) {
            case GLFW_CURSOR_NORMAL:
                return CursorMode::Normal;
            case GLFW_CURSOR_DISABLED:
                return CursorMode::Disabled;
            case GLFW_CURSOR_HIDDEN:
                return CursorMode::Hidden;
            case GLFW_CURSOR_CAPTURED:
                return CursorMode::Captured;
            default:
                BSK_WARNING("Invalid conversion from glfw cursor mode value to basigkl enum for cursor mode occured.");
                return CursorMode::None;
        }
    }

    WindowAttribute convert_to_basikgl_window_attribute(int32_t attribute) {
        switch (attribute) {
            case GLFW_RESIZABLE:
                return WindowAttribute::Resizable;
            case GLFW_VISIBLE:
                return WindowAttribute::Visible;
            case GLFW_DECORATED:
                return WindowAttribute::Decorated;
            case GLFW_FOCUSED:
                return WindowAttribute::Focused;
            case GLFW_AUTO_ICONIFY:
                return WindowAttribute::AutoIconify;
            case GLFW_FLOATING:
                return WindowAttribute::Floating;
            case GLFW_MAXIMIZED:
                return WindowAttribute::Maximized;
            case GLFW_CENTER_CURSOR:
                return WindowAttribute::CenterCursor;
            case GLFW_TRANSPARENT_FRAMEBUFFER:
                return WindowAttribute::TransparentFramebuffer;
            case GLFW_FOCUS_ON_SHOW:
                return WindowAttribute::FocusOnShow;
            case GLFW_SCALE_TO_MONITOR:
                return WindowAttribute::ScaleToMonitor;
            case GLFW_SCALE_FRAMEBUFFER:
                return WindowAttribute::ScaleFramebuffer;
            case GLFW_MOUSE_PASSTHROUGH:
                return WindowAttribute::MousePassthrough;
            default:
                BSK_WARNING("Invalid conversion from glfw window attribute value to basigkl enum for window attribute occured.");
                return WindowAttribute::None;
        }
    }

}