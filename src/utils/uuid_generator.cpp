#include <random>

#include <utils/uuid_generator.h>

namespace bskgl::utils {

    std::unordered_set<UUID> UUIDGenerator::s_seen_uuids({ static_cast<UUID>(BSK_INVALID_UUID) });

    UUID UUIDGenerator::generate() {
        static std::random_device rd;
        static std::mt19937_64 generator(rd());
        static std::uniform_int_distribution<uint64_t> distribution;

        uint64_t uid;

        do {
            uid = distribution(generator);
        } while(!s_seen_uuids.insert(uid).second);

        return uid;
    }

    bool UUIDGenerator::exists(uint64_t uid) {
        return s_seen_uuids.contains(uid);
    }

}