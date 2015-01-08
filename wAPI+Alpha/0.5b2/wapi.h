/** �������� **/
#define WAPI
#ifndef _WINDOWS_H
    #include<windows.h>
    ///!#include<windowsx.h>
    #define _WINDOWS_H
#endif

#ifndef wAPI_ICON ///����������� ������
    #define wAPI_ICON LoadIcon(NULL, IDI_APPLICATION);
#endif
#ifndef wAPI_NOCLOSE /// ��������� �������� ����
    #define wAPI_NOCLOSE 0
#endif
#ifndef wAPI_HREDRAW /// �������������� ���� ��� �������������� ��������
    #define wAPI_HREDRAW 0
#endif
#ifndef wAPI_VREDRAW /// �������������� ���� ��� ������������ ��������
    #define wAPI_VREDRAW 0
#endif
#ifndef wAPI_CURSOR ///����������� ������
    #define wAPI_CURSOR LoadCursor(NULL, IDC_ARROW)
#endif

#ifndef _WAPI_CORE_H
    #define _WAPI_CORE_H
    #include "wapi_core.h"
#endif
#define wapi_setEvent( event, func_name ) wapi->event = func_name


int WAPI wapi_Init( HINSTANCE hInstance, LPSTR CN )
{
    return wapi->__init( hInstance,  CN);
}
void WAPI wapi_MainLoop()
{
    MSG msg;
    while( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void WAPI run( LPSTR filename )
{
        WinExec( filename, 0 );
}
