/**
 * @file context/gl_tests.h
 * @brief Contains values for OpenGL Tests.
 * @author Arnav Deshpande
 */

#pragma once

#include <core/core.h>

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum GLTest
     * @brief Enum values for OpenGL Tests.
     */
    enum class GLTest  {
        None                    = -1,
        DepthTest               = 1 << 0,
        StencilTest             = 1 << 1,
        Blend                   = 1 << 2,
        CullFace                = 1 << 3,
        ScissorTest             = 1 << 4,
        Dither                  = 1 << 5,
        PolygonOffset           = 1 << 6,
        SampleAlphaToCoverage   = 1 << 7,
        SampleCoverage          = 1 << 8,
        Multisample             = 1 << 9,
        LineSmooth              = 1 << 10,
        PolygonSmooth           = 1 << 11,
        FramebufferSRGB         = 1 << 12,
        DebugOutput             = 1 << 13,
        DebugOutputSynchronous  = 1 << 14
    };

    /**
     * @brief Performs a bitwise OR operation on two GLTest values.
     * 
     * @param[in] lhs The left-hand side GLTest.
     * @param[in] rhs The right-hand side GLTest.
     * 
     * @retval GLTest 
     * @returns The resulting test set.
     */
    GLTest BSK_API operator|(GLTest lhs, GLTest rhs);

    /**
     * @brief Performs a bitwise XOR operation on two GLTest values.
     * @param[in] lhs The left-hand side GLTest.
     * @param[in] rhs The right-hand side GLTest.
     * 
     * @retval GLTest 
     * @returns The resulting test set.
     */
    GLTest BSK_API operator^(GLTest lhs, GLTest rhs);

    /**
     * @brief Checks if a given test is set.
     * @param[in] lhs The test set.
     * @param[in] rhs The test to check.
     * 
     * @retval bool 
     * @returns True if the test is set, false otherwise.
     */
    bool BSK_API operator&(GLTest lhs, GLTest rhs);

    /**
     * @enum GLClearBit
     * @brief Represents the possible buffer bits that can be cleared in OpenGL.
     */
    enum class GLClearBit {
        None        = -1,
        Color       = 1 << 0,   
        Depth       = 1 << 1,   
        Stencil     = 1 << 2,
        Accum       = 1 << 3
    };

    /**
     * @brief Overloads the bitwise OR operator to allow combining multiple GLClearBit values.
     * 
     * @param[in] lhs The left-hand side.
     * @param[in] rhs The right-hand side.
     * 
     * @retval GLClearBit
     * @returns The result.
     */
    GLClearBit BSK_API operator|(GLClearBit lhs, GLClearBit rhs);

    /**
     * @brief Performs a bitwise XOR operation on two GLClearBit values.
     * @param[in] lhs The left-hand side GLClearBit.
     * @param[in] rhs The right-hand side GLClearBit.
     * 
     * @retval GLTest 
     * @returns The resulting test set.
     */
    GLClearBit BSK_API operator^(GLClearBit lhs, GLClearBit rhs);

    /**
     * @brief Checks if a given test is set.
     * @param[in] lhs The test set.
     * @param[in] rhs The test to check.
     * 
     * @retval bool 
     * @returns True if the test is set, false otherwise.
     */
    bool BSK_API operator&(GLClearBit lhs, GLClearBit rhs);

}