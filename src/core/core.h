/**
 * @file core/core.h
 * @brief Contains core functionalites or macros.
 * @author Arnav Deshpande
 */

#pragma once

#include <cstdint>
#include <stdexcept>
#include <string_view>

/**
 * @def BSK_API
 * @brief If library is compiled to be dynamic, it exapnds to be a declspec attribute.
 */
#if defined(BSK_DYNAMIC)
    #ifdef BSK_SOURCE_FILE
        #define BSK_API __declspec(dllexport)
    #else
        #define BSK_API __declspec(dllimport)
    #endif
#else
    #define BSK_API
#endif

/**
 * @def BSK_FUNCTION_SIGNATURE
 * @brief Depending on the compiler, offers a pretty function signature.
 */
#if defined(_MSC_VER)
    #define BSK_FUNCTION_SIGNATURE __FUNCSIG__
#elif defined(__GNUC__) || defined(__clang__)
    #define BSK_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#else
    #define BSK_FUNCTION_SIGNATURE __func__
#endif

/**
 * @def BSK_LIB_VERSION_MAJOR
 * @brief Major version of current BasikGL library source code.
 */
#define BSK_LIB_VERSION_MAJOR       0

/**
 * @def BSK_LIB_VERSION_MAINOR
 * @brief Minor version of current BasikGL library source code.
 */
#define BSK_LIB_VERSION_MINOR       5

/**
 * @def BSK_OPENGL_VERSION_MAJOR
 * @brief Major OpenGL Context version used in this code base.
 */
#define BSK_OPENGL_VERSION_MAJOR    4

/**
 * @def BSK_OPENGL_VERSION_MINO
 * @brief Minor OpenGL Context version used in this code base.
 */
#define BSK_OPENGL_VERSION_MINOR    6

/**
 * @def BSK_INVALID_UUID
 * @brief Invalid UUID, value is -1.
 */
#define BSK_INVALID_UUID    (-1)

/**
 * @namespace bskgl
 * @brief Primary namespace of BasikGL library.
 */
namespace bskgl {

    /**
     * @property BasikGL universal unique identifier.
     */
    using UUID = uint64_t;

    class Timespan;

    /**
     * @brief Initializes the library.
     */
    void BSK_API initialize();

    /**
     * @brief Shuts down the lbirary.
     */
    void BSK_API shutdown();

    /**
     * @brief Returns the time since epoch.
     * Returns time since bskgl::initialize() was called.
     * 
     * @retval bskgl::Timespan ( @ref time/timespan.h )
     * @returns Time since epoc.
     */
    Timespan BSK_API time_since_epoch();

}