#pragma once

#include <map>

enum class SEKeyCode : uint8_t
{
    /* The unknown key */
    UNKNOWN

    /* Printable keys */
    ,SPACE
    ,APOSTROPHE           /* ' */
    ,COMMA                /* , */
    ,MINUS                /* - */
    ,PERIOD               /* . */
    ,SLASH                /* / */
    ,NUM_0                  
    ,NUM_1                  
    ,NUM_2                  
    ,NUM_3                  
    ,NUM_4                  
    ,NUM_5                  
    ,NUM_6                  
    ,NUM_7                  
    ,NUM_8                  
    ,NUM_9                  
    ,SEMICOLON            /* ; */
    ,EQUAL                /* = */
    ,A                  
    ,B                  
    ,C                  
    ,D                  
    ,E                  
    ,F                  
    ,G                  
    ,H                  
    ,I                  
    ,J                  
    ,K                  
    ,L                  
    ,M                  
    ,N                  
    ,O                  
    ,P                  
    ,Q                  
    ,R                  
    ,S                  
    ,T                  
    ,U                  
    ,V                  
    ,W                  
    ,X                  
    ,Y                  
    ,Z                  
    ,LEFT_BRACKET         /* [ */
    ,BACKSLASH            /* \ */
    ,RIGHT_BRACKET        /* ] */
    ,GRAVE_ACCENT         /* ` */
    ,WORLD_1             /* non-US #1 */
    ,WORLD_2             /* non-US #2 */
    ,ESCAPE             
    ,ENTER              
    ,TAB                
    ,BACKSPACE          
    ,INSERT             
    ,DELETE             
    ,RIGHT              
    ,LEFT               
    ,DOWN               
    ,UP                 
    ,PAGE_UP            
    ,PAGE_DOWN          
    ,HOME               
    ,END                
    ,CAPS_LOCK          
    ,SCROLL_LOCK        
    ,NUM_LOCK           
    ,PRINT_SCREEN       
    ,PAUSE              
    ,F1                 
    ,F2                 
    ,F3                 
    ,F4                 
    ,F5                 
    ,F6                 
    ,F7                 
    ,F8                 
    ,F9                 
    ,F10                
    ,F11                
    ,F12                
    ,F13                
    ,F14                
    ,F15                
    ,F16                
    ,F17                
    ,F18                
    ,F19                
    ,F20                
    ,F21                
    ,F22                
    ,F23                
    ,F24                
    ,F25                
    ,KP_0               
    ,KP_1               
    ,KP_2               
    ,KP_3               
    ,KP_4               
    ,KP_5               
    ,KP_6               
    ,KP_7               
    ,KP_8               
    ,KP_9               
    ,KP_DECIMAL         
    ,KP_DIVIDE          
    ,KP_MULTIPLY        
    ,KP_SUBTRACT        
    ,KP_ADD             
    ,KP_ENTER           
    ,KP_EQUAL           
    ,LEFT_SHIFT         
    ,LEFT_CONTROL       
    ,LEFT_ALT           
    ,LEFT_SUPER         
    ,RIGHT_SHIFT        
    ,RIGHT_CONTROL      
    ,RIGHT_ALT          
    ,RIGHT_SUPER        
    ,MENU               
    ,MAX
};

class SInput
{
    //todo: replace std function with a better callback implementation..
    // one that allows several bound callbacks (observer pattern)
    //std::map<SEKeyCode, std::function> KeyBindings;
public:
    virtual ~SInput(){}
    virtual void ReceiveInput(int key, int action, int mods) = 0;

    //void BindKey(SEKeyCode key, std::function callback);
};

class SInputGL : public SInput
{
    //todo: consider alternative to map?
    std::map<int, SEKeyCode> GlfwToSEKey;
public:

    SInputGL();
    void ReceiveInput(int key, int action, int mods) override;
};