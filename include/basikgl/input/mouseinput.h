/**
 * @file input/mouseinput.h
 * @brief Provides values for mouse input polling.
 * @author Arnav Deshpande
 */

#pragma once

/**
 * @namespace bskgl
 * @brief Primary namespace for BasikGL library.
 */
namespace bskgl {

    /**
     * @enum MouseButtonCode
     * @brief Represents different mouse buttons, with mappings to standard button codes.
     */
    enum class MouseButtonCode {
        None,
        Button1,      
        Button2,      
        Button3,      
        Button4,      
        Button5,      
        Button6,      
        Button7,      
        Button8,      
        LeftButton = Button1,   
        RightButton = Button2,  
        MiddleButton = Button3, 
        LastButton = Button8    
    };

} 