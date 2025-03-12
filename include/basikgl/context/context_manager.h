/**
 * @file context/context_manager.h
 * @brief Provides functionality for creating and managing contexts.
 * @author Arnav Deshpande
 */

#pragma once

#include <memory>
#include <unordered_map>
#include <memory>

#include <basikgl/core/core.h>
#include <basikgl/context/render_context.h>
#include <basikgl/utils/uuid_generator.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL Library.
 */
namespace bskgl {

    /**
     * @class ContextManager
     * @brief Singleton class for creating and managing contexts.
     */
    class BSK_API ContextManager final {
        friend void shutdown(); /// BasikGL Shutdown function
    public:
        /**
         * @typedef ContextHandle
         * @brief Return handle for all contexts, currently typedefed to std::shared_ptr.
         */
        using ContextHandle = std::shared_ptr<RenderContext>;

    private:
        /**
         * @brief Constructor
         */
        ContextManager() = default;

    public:
        /**
         * @brief Destructor
         */
        ~ContextManager();

        ContextManager(const ContextManager& other) = delete;
        ContextManager(ContextManager&& other) noexcept = delete;
        ContextManager& operator=(const ContextManager& other) = delete;
        ContextManager& operator=(ContextManager&& other) noexcept = delete;

    public:
        /**
         * @brief Creates a context.
         * 
         * @param[in] properties Context properties.
         * 
         * @retval UUID
         * @returns UUID of the context.
         */
        UUID create_context(ContextProperties properties);

        /**
         * @brief Returns requested context.
         * 
         * @param[in] uuid UUID of the context.
         * 
         * @retval ContextHandle
         * @returns ContextHandle of the requested context, else nullptr.
         */
        ContextHandle get_context(UUID uuid) const;

        /**
         * @brief Destroys the context.
         * 
         * @param[in] uuid Context handle.
         */
        void destroy_context(UUID uuid);
    
        /**
         * @brief Singleton instance of the class.
         * 
         * @retval ContextManager&
         * @returns Singleton instance of the class.
         */
        static ContextManager& instance();
    
        /**
         * @brief Delete the context manager.
         */
        static void shutdown();

    private:
        /**
         * @property ContextManager instance.
         */
        static ContextManager* s_instance;

    private:
        /**
         * @property Stored contexts.
         */
        std::unordered_map<UUID, ContextHandle> m_contexts;
    };

}