#include <context/context_manager.h>

namespace bskgl {

    ContextManager* ContextManager::s_instance = nullptr;

    ContextManager::~ContextManager() {
    }

    ContextManager& ContextManager::instance() {
        if (!s_instance)
            s_instance = new ContextManager();
        return *s_instance;
    }

    UUID ContextManager::create_context(ContextProperties properties) {
        UUID uuid = utils::UUIDGenerator::generate();
        m_contexts[uuid] = ContextHandle(new RenderContext(uuid, properties));
        return uuid;
    }

    ContextManager::ContextHandle ContextManager::get_context(UUID uuid) const {
        auto it = m_contexts.find(uuid);
        if (it != m_contexts.end())
            return it->second;
        return nullptr;
    }

    void ContextManager::destroy_context(UUID uuid) {
        auto it = m_contexts.find(uuid);
        if (it != m_contexts.end())
            m_contexts.erase(it);
    }

    void ContextManager::shutdown() {
        if (s_instance)
            delete s_instance;
    }

}