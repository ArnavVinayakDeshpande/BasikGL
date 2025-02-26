#include <context/gl_tests.h>

namespace bskgl {

    GLTest operator|(GLTest lhs, GLTest rhs) {
        return static_cast<GLTest>(static_cast<int>(lhs) | static_cast<int>(rhs));
    }

    GLTest operator^(GLTest lhs, GLTest rhs) {
        return static_cast<GLTest>(static_cast<int>(lhs) ^ static_cast<int>(rhs));
    }

    bool operator&(GLTest lhs, GLTest rhs) {
        return static_cast<bool>(static_cast<int>(lhs) & static_cast<int>(rhs));
    }

    GLClearBit operator|(GLClearBit a, GLClearBit b) {
        return static_cast<GLClearBit>(static_cast<int>(a) | static_cast<int>(b));
    }

    GLClearBit operator^(GLClearBit lhs, GLClearBit rhs) {
        return static_cast<GLClearBit>(static_cast<int>(lhs) ^ static_cast<int>(rhs));
    }

    bool operator&(GLClearBit lhs, GLClearBit rhs) {
        return static_cast<bool>(static_cast<int>(lhs) & static_cast<int>(rhs));
    }

}