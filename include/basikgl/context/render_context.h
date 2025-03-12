/**
 * @file context/render_context.h
 * @brief Provides functionality for creating and using a render context.
 * @author Arnav Deshpande
 */

#pragma once

#include <basikgl/core/core.h>
#include <basikgl/context/context_properties.h>
#include <basikgl/context/asset_manager.h>
#include <basikgl/context/gl_tests.h>
#include <basikgl/window/window.h>
#include <basikgl/render/renderer.h>
#include <basikgl/color/color.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /// @brief Forward declaration for ContextManager class.
    class ContextManager;

    /**
     * @class RenderContext
     * @brief Represents a render context for OpenGL rendering.
     */
    class BSK_API RenderContext final {
        friend ContextManager;
    public:
        /**
         * @property Window used for the context.
         */
        Window window;

        /**
         * @property Asset Manager used for managing assets tied to this context.
         */
        AssetManager asset_manager;

        /***
         * @property Renderer associated with this context.
         */
        Renderer renderer;

    private:
        /**
         * @brief Constructor
         * 
         * @param[in] uuid UUID of this instance.
         * @param[in] properties Context properties.
         */
        RenderContext(UUID uuid, const ContextProperties& properties);

    public:
        /**
         * @brief Move Constructor
         */
        RenderContext(RenderContext&& other) noexcept;

        /**
         * @brief Move Assignment Operator
         */
        RenderContext& operator=(RenderContext&& other) noexcept;

        /**
         * @brief Destructor
         */
        ~RenderContext();

        RenderContext(const RenderContext& other) = delete;
        RenderContext& operator=(const RenderContext& other) = delete;

        /**
         * @retval UUID
         * @returns UUID of this instance.
         */
        UUID uuid() const;

        /**
         * @retval Color
         * @returns Screen clear color.
         */
        [[nodiscard]]
        Color clear_color() const;

        /**
         * @brief Clears the context buffer bits.
         */
        void clear() const;

        /**
         * @brief Enables a given test.
         * 
         * @param[in] test Test to enable.
         * 
         * @retval RenderContext&
         * @returns Reference to the updated variable.
         */
        RenderContext& enable(GLTest test);

        /**
         * @brief Disables a given test.
         * 
         * @param[in] test Test to disable.
         * 
         * @retval RenderContext&
         * @returns Reference to the updated variable.
         */
        RenderContext& disable(GLTest test);

        /**
         * @brief Sets the clear bits.
         * 
         * @param[in] clear_bits Clears bits to set.
         * 
         * @retval RenderContext&
         * @returns Reference to the updated variable.
         */
        RenderContext& set_clear_bits(GLClearBit clear_bits);

        /**
         * @brief Sets the screen clear color.
         * 
         * @param[in] color Color to set.
         * 
         * @retval RenderContext&
         * @returns Reference to the updated variable.
         */
        RenderContext& set_clear_color(const Color& color);

        /**
         * @brief Binds the current context.
         */
        void bind() const;

    private:
        /**
         * @property UUID of this instance.
         */
        UUID m_uuid;

        /**
         * @property Enabled tests.
         */
        GLTest m_enabled_tests;

        /**
         * @property Clear Bits
         */
        GLClearBit m_clearbits = GLClearBit::Color;
    };

}