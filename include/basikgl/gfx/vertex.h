/**
 * @file gfx/vertex.h
 * @brief Contains implementation for a bskgl vertex.
 * @author Arnav Deshpande
 */

#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <basikgl/core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @struct Vertex
     * @brief Represents a bskgl vertex.
     */
    struct BSK_API Vertex final {
        /**
         * @property Position of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         */
        glm::vec3 position;

        /**
         * @property Normal vector of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         * @note While setting the normal vector, ensure its normalized.
         */
        glm::vec3 normal;

        /**
         * @property UV texel coordinates of the vertex, only used for texture mapping, as a glm::vec2 ( @ref lib glm ).
         */
        glm::vec2 tex_coords;

        /**
         * @brief Constructor
         * Initializes position to be origin, normal to be unit vector pointing out of the screen, tex coord as origin.
         */
        Vertex()
            : 
            position(glm::vec3(0.0f)),
            normal(glm::vec3(0.0f, 0.0f, 1.0f)), 
            tex_coords(glm::vec2(0.0f)) { }

        /**
         * @brief Constructor
         * Initializes normal to be unit vector pointing out of the screen, tex coord as origin.
         * 
         * @param[in] pos Position of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         */
        Vertex(const glm::vec3& pos)
            :
            position(pos),
            normal(glm::vec3(0.0f, 0.0f, 1.0f)),
            tex_coords(glm::vec2(0.0f)) { }

        /**
         * @brief Constructor
         * Initializes normal to be unit vector pointing out of the screen.
         * 
         * @param[in] pos Position of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         * @param[in] texpos UV texture coordinates as a glm::vec2 ( @ref lib glm ).
         */
        Vertex(const glm::vec3& pos, const glm::vec2& texpos)
            :
            position(pos),
            normal(glm::vec3(0.0f, 0.0f, 1.0f)),
            tex_coords(texpos) { }

        /**
         * @brief Constructor
         * 
         * @param[in] pos Position of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         * @param[in] normal Normal vector of the vertex in 3-D space as a glm::vec3 ( @ref lib glm ).
         * @param[in] texpos UV texture coordinates as a glm::vec2 ( @ref lib glm ).
         * 
         * @note Ensure normal vector is normalized.
         */
        Vertex(const glm::vec3& pos, const glm::vec3& normal, const glm::vec2& texpos)
            : 
            position(pos),
            normal(normal),
            tex_coords(texpos) { }

        /**
         * @brief Equality operator.
         * 
         * @retval bool
         * @returns If all components of the vertex are equal.
         */
        inline bool operator==(const Vertex& _other) const {
            return
                this->position == _other.position &&
                this->normal == _other.normal &&
                this->tex_coords == _other.tex_coords;
        }
    };

} 