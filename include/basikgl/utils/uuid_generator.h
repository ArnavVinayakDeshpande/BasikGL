/**
 * @file utils/uuid_generator.h
 * @brief Contains generator classes for unique identifiers.
 * @author Arnav Deshpande
 */

#pragma once

#include <unordered_set>

#include <basikgl/core/core.h>

/**
 * @namespace bskgl::utils
 * @brief Namespace for utility function in BasikGL.
 */
namespace bskgl::utils {

    /**
     * @class UUIDGenerator
     * @brief Generates universal unique identifier.
     */
    class BSK_API UUIDGenerator final {
    public:
        /**
         * @brief Generates a basikgl uuid.
         * 
         * @retval bskgl::UUID
         * @returns basikg UUID
         */
        static UUID generate();

        /**
         * @brief Checks if given uuid exists in this instance.
         * 
         * @param[in] uuid uuid to check.
         * 
         * @retval bool
         * @returns If given uuid exist in this instance.
         */
        static bool exists(UUID uuid);

    private:
        /**
         * @property Contains previously created values. 
         */
        static std::unordered_set<UUID> s_seen_uuids;
    };

}