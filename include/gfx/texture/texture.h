/**
 * @file gfx/texture/texture.h
 * @brief Contains abstract base class for textures.
 * @author Arnav Deshpande
 */

#pragma once

#include <core/core.h>
#include <gfx/asset.h>
#include <sprite/sprite.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @class TextureBase
     * @brief Abstract base class for textures.
     */
    class BSK_API TextureBase : public Asset {
    public:
        /**
         * @enum Type
         * @brief Contains OpenGL texture types.
         */
        enum class Type : uint32_t {
            None,
            Texture2D,
            Texture3D,
            TextureCubeMap,
            Texture2DArray,
            TextureCubeMapArray,
            Texture1D,
            Texture1DArray,
            TextureRectangle,
            TextureBuffer,
            Texture2DMultisample,
            Texture2DMultisampleArray,
        };

        /**
         * @enum InternalFormat
         * @brief Contains OpenGL texture internal formats.
         */
        enum class InternalFormat : uint32_t {
            None,
            Red,
            RG,
            RGB,
            RGBA,
            Depth,
            DepthStencil,
        };

        /**
         * @enum Format
         * @brief Contains OpenGL texture formats.
         */
        enum class Format : uint32_t {
            None,
            Red,
            RG,
            RGB,
            RGBA,
            Depth,
            DepthStencil,
        };

        /**
         * @enum DataType
         * @brief Contains OpenGL texture data types.
         */
        enum class DataType : uint32_t {
            None,
            UnsignedByte,
            Byte,
            UnsignedShort,
            Short,
            UnsignedInt,
            Int,
            Float,
            HalfFloat,
        };

        /**
         * @enum MinFIlter
         * @brief Contains OpenGL texture min filters.
         */
        enum class MinFilter : uint32_t {
            None,
            Nearest,
            Linear,
            NearestMipmapNearest,
            LinearMipmapNearest,
            NearestMipmapLinear,
            LinearMipmapLinear,
        };

        /**
         * @enum MagFilter
         * @brief Contains OpenGL texture mag filters.
         */
        enum class MagFilter : uint32_t {
            None,
            Nearest,
            Linear,
        };

        /**
         * @enum WrapMode
         * @brief Contains OpenGL texture wrap modes.
         */
        enum class WrapMode : uint32_t {
            None,
            Repeat,
            MirroredRepeat,
            ClampToEdge,
            ClampToBorder,
        };

    public:
        /**
         * @brief Constructor
         */
        TextureBase() = default;

        /**
         * @brief Destructor
         */
        virtual ~TextureBase() = default;

        /**
         * @retval uint32_t
         * @returns OpenGL ID of the texture/
         */
        virtual uint32_t gl_id() const = 0;

        /**
         * @retval uint32_t
         * @returns Width of the texture.
         */
        virtual uint32_t width() const = 0;

        /**
         * @retval uint32_t
         * @returns Height of the texture.
         */
        virtual uint32_t height() const = 0;

        /**
         * @retval TextureBase::Type
         * @returns Type of the texture.
         */
        virtual Type type() const = 0;

        /**
         * @retval TextureBase::InternalFormat
         * @returns Internal format of the texture.
         */
        virtual InternalFormat internal_format() const = 0;

        /**
         * @retval TextureBase::Format
         * @returns Format of the texture.
         */
        virtual Format format() const = 0;

        /**
         * @retval TextureBase::DataType
         * @returns Data type of the texture.
         */
        virtual DataType data_type() const = 0;

        /**
         * @retval TextureBase::MinFilter
         * @returns Min filter of the texture.
         */
        virtual MinFilter min_filter() const = 0;

        /**
         * @retval TextureBase::MagFilter
         * @returns Mag filter of the texture.
         */
        virtual MagFilter mag_filter() const = 0;

        /**
         * @retval TextureBase::WrapMode
         * @returns Wrap mode of the texture.
         */
        virtual WrapMode wrap_mode_s() const = 0;

        /**
         * @retval TextureBase::WrapMode
         * @returns Wrap mode of the texture.
         */
        virtual WrapMode wrap_mode_t() const = 0;
    };

}