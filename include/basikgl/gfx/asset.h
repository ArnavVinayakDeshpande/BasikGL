/**
 * @file gfx/assets.h
 * @brief Contains base class to be inherited by any bskgl asset.
 * @author Arnav Deshpande
 */

#pragma once

#include <basikgl/core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace used in BasikGL library.
 */
namespace bskgl {

    /**
     * @class Asset
     * @brief Base class for all basikgl assets.
     */
    class Asset {
    public:
        virtual UUID uuid() const = 0;
    };

}