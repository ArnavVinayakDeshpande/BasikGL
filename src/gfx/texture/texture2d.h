/**
 * @file gfx/texture/texture2d.h
 * @brief Defines the Texture2D class for handling 2D textures in OpenGL.
 * @author Arnav Deshpande
 */

#pragma once

#include <core/core.h>
#include <sprite/sprite.h>
#include <gfx/texture/texture.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration for AssetManager class.
    class AssetManager;

    /**
     * @class Texture2D
     * @brief Represents a 2D texture in OpenGL.
     */
    class BSK_API Texture2D final : public TextureBase {
        friend AssetManager;
    public:
        /**
         * @property The default texture unit for binding.
         */
        uint16_t default_texture_unit = 0;

    private:
        /**
         * @brief Constructor
         * 
         * @param[in] texfile The path to the texture file.
         * @param[in] min_filter Min filter, default value is Nearest.
         * @param[in] mag_filter Mag filter, default value is Linear.
         * @param[in] wrap_mode_s Horizontal wrap mode, default value is Repeat.
         * @param[in] wrap_mode_t Vertical wrap mode, default value is Repeat.
         */
        Texture2D(
            UUID uuid, const std::filesystem::path& texfile,
            TextureBase::MinFilter min_filter = TextureBase::MinFilter::Nearest,
            TextureBase::MagFilter mag_filter = TextureBase::MagFilter::Linear,
            TextureBase::WrapMode wrap_mode_s = TextureBase::WrapMode::Repeat,
            TextureBase::WrapMode wrap_mode_t = TextureBase::WrapMode::Repeat
        );

        /**
         * @brief Constructor
         * 
         * @param[in] sprite The Sprite containing texture data.
         * @param[in] min_filter Min filter, default value is Nearest.
         * @param[in] mag_filter Mag filter, default value is Linear.
         * @param[in] wrap_mode_s Horizontal wrap mode, default value is Repeat.
         * @param[in] wrap_mode_t Vertical wrap mode, default value is Repeat.
         */
        Texture2D(
            UUID uuid, const Sprite& sprite,
            TextureBase::MinFilter min_filter = TextureBase::MinFilter::Nearest,
            TextureBase::MagFilter mag_filter = TextureBase::MagFilter::Linear,
            TextureBase::WrapMode wrap_mode_s = TextureBase::WrapMode::Repeat,
            TextureBase::WrapMode wrap_mode_t = TextureBase::WrapMode::Repeat
        );
        
    public:
        /**
         * @brief Move constructor.
         */
        Texture2D(Texture2D&& other) noexcept;
        
        /**
         * @brief Move Assignment operator.
         */
        Texture2D& operator=(Texture2D&& other) noexcept;
        
        /**
         * @brief Destructor
         */
        ~Texture2D();
        
        Texture2D(const Texture2D& other) = delete;
        Texture2D& operator=(const Texture2D& other) = delete;
        
        /**
         * @implements Asset::uuid()
         */
        [[nodiscard]]
        UUID uuid() const override;

        /**
         * @retval uint32_t
         * @returns OpenGL ID of the texture.
         */
        [[nodiscard]]
        uint32_t gl_id() const override;

        /**
         * @retval uint32_t 
         * @returns The width of the texture.
         */
        [[nodiscard]]
        uint32_t width() const override;

        /**
         * @retval uint32_t 
         * @returns The height of the texture.
         */
        [[nodiscard]]
        uint32_t height() const override;

        /**
         * @retval Type 
         * @returns The texture type.
         */
        [[nodiscard]]
        Type type() const override;

        /**
         * @retval InternalFormat 
         * @returns The internal format.
         */
        [[nodiscard]]
        InternalFormat internal_format() const override;

        /**
         * @retval Format 
         * @returns The format of the texture.
         */
        [[nodiscard]]
        Format format() const override;

        /**
         * @retval DataType 
         * @returns The texture data type.
         */
        [[nodiscard]]
        DataType data_type() const override;

        /**
         * @retval MinFilter
         * @returns The minification filter.
         */
        [[nodiscard]]
        MinFilter min_filter() const override;

        /**
         * @retval MagFilter 
         * @returns The magnification filter.
         */
        [[nodiscard]]
        MagFilter mag_filter() const override;

        /**
         * @retval WrapMode 
         * @returns The wrap mode for S (horizontal).
         */
        [[nodiscard]]
        WrapMode wrap_mode_s() const override;

        /**
         * @retval WrapMode 
         * @returns The wrap mode for T (vertical).
         */
        [[nodiscard]]
        WrapMode wrap_mode_t() const override;

        /**
         * @retval const Sprite& 
         * @returns The associated sprite.
         */
        [[nodiscard]]
        const Sprite& sprite() const;

        /**
         * @brief Sets the minification filter.
         * 
         * @param[in] min_filter The minification filter to set.
         * 
         * @retval Texture2D& 
         * @returns Reference to the updated variable.
         */
        Texture2D& set_min_filter(TextureBase::MinFilter min_filter);

        /**
         * @brief Sets the magnification filter
         * .
         * @param[in] mag_filter The magnification filter to set.
         * 
         * @retval Texture2D& 
         * @returns Reference to the updated variable.
         */
        Texture2D& set_mag_filter(TextureBase::MagFilter mag_filter);

        /**
         * @brief Sets the wrap mode for the S (horizontal) axis.
         * 
         * @param[in] wrap_mode The wrap mode to set.
         * 
         * @retval Texture2D& 
         * @returns Reference to the updated variable.
         */
        Texture2D& set_wrap_mode_s(TextureBase::WrapMode wrap_mode);

        /**
         * @brief Sets the wrap mode for the T (vertical) axis.
         * 
         * @param[in] wrap_mode The wrap mode to set.
         * 
         * @retval Texture2D& 
         * @returns Reference to the updated variable.
         */
        Texture2D& set_wrap_mode_t(TextureBase::WrapMode wrap_mode);

        /**
         * @brief Reads a texture from a file and loads it.
         * 
         * @param[in] texfile The path to the texture file.
         * 
         * @retval Texture2D& 
         * @returns The updated Texture2D instance.
         */
        Texture2D& read_from(const std::filesystem::path& texfile);

        /**
         * @brief Binds the texture to a specified texture unit.
         * 
         * @param[in] tex_unit_to_bind The texture unit to bind.
         */
        void bind(int32_t tex_unit_to_bind) const;

        /**
         * @brief Binds the texture to a specified texture unit.
         * Binds to the default texture unit.
         */
        void bind() const;

        /**
         * @brief Synchronizes texture data with the GPU.
         * 
         * @retval Texture2D& 
         * @returns Reference to the updated variable.
         */
        Texture2D& sync();

    public:
        /**
         * @property The texture type (Texture2D).
         */
        constexpr static TextureBase::Type texture_type = TextureBase::Type::Texture2D;

        /**
         * @property The data type of the texture (UnsignedByte).
         */
        constexpr static TextureBase::DataType tex_data_type = TextureBase::DataType::UnsignedByte;

    private:
        /**
         * @property UUID of this instance.
         */
        UUID m_uuid;

        /**
         * @property The OpenGL ID for the texture.
         */
        uint32_t m_glid;

        /**
         * @property The sprite associated with the texture.
         */
        Sprite m_sprite;

        /**
         * @property The internal format of the texture.
         */
        TextureBase::InternalFormat m_internal_format;

        /**
         * @property The format of the texture.
         */
        TextureBase::Format m_format;

        /**
         * @property The minification filter setting.
         */
        TextureBase::MinFilter m_min_filter;

        /**
         * @property The magnification filter setting.
         */
        TextureBase::MagFilter m_mag_filter;

        /**
         * @property The texture wrap mode along the S axis.
         */
        TextureBase::WrapMode m_wrap_mode_s;

        /**
         * @property The texture wrap mode along the T axis.
         */
        TextureBase::WrapMode m_wrap_mode_t;
    };

} 