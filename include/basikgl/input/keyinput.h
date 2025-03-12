/**
 * @file input/keyinput.h
 * @brief Provides keycodes for input polling.
 * @author Arnav Deshpande
 */

#pragma once

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum KeyCode
     * @brief Represents different keys, with mappings to standard key codes.
     */
    enum class KeyCode {
        Unknown,         
        Space,          
        Apostrophe,     
        Comma,          
        Minus,          
        Period,         
        Slash,          
        Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, 
        Semicolon,      
        Equal,          
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
        LeftBracket,    
        Backslash,      
        RightBracket,   
        GraveAccent,    
        Escape,         
        Enter,          
        Tab,            
        Backspace,      
        Insert,         
        Delete,         
        Right, Left, Down, Up, 
        PageUp, PageDown, Home, End, 
        CapsLock, ScrollLock, NumLock, 
        PrintScreen, Pause, 
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 
        Keypad0, Keypad1, Keypad2, Keypad3, Keypad4, Keypad5, Keypad6, Keypad7, Keypad8, Keypad9, 
        KeypadDecimal, 
        KeypadDivide, 
        KeypadMultiply, 
        KeypadSubtract, 
        KeypadAdd, 
        KeypadEnter, 
        KeypadEqual, 
        LeftShift, LeftControl, LeftAlt, LeftSuper, 
        RightShift, RightControl, RightAlt, RightSuper, 
        Menu 
    };

    /**
     * @enum KeyMode
     * @brief Represents different key modes, with mappings to standard key modes.
     */
    enum class KeyMode {
        None,
        Pressed,  
        Held,     
        Released  
    };

} 