#ifndef __WAPI_MAIN_H__
    #define __WAPI_MAIN_H__

#ifndef _WINDOWS_H
    #include <windows.h>
#endif

#include "wapi_comp.h"

#ifdef BUILD_DLL
    #define WAPI __declspec(dllexport)
#else
    #define WAPI __declspec(dllimport)
#endif


#define wAPIMainLoop()     MSG msg;\
    while( GetMessage(&msg, NULL, 0, 0) )\
    {\
        TranslateMessage(&msg);\
        DispatchMessage(&msg);\
    }

#ifdef __cplusplus
extern "C"
{
#endif



char WAPI *wAPIVersion(  );
void WAPI  wAPIInit( HINSTANCE, char* );












#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
