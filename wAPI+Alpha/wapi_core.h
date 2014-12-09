#define WAPI_VER "0.1"

LRESULT CALLBACK _WAPI_WNDPROC(HWND hwnd, UINT msg, WPARAM wP, LPARAM lP)
{
    switch(msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            DefWindowProc(hwnd, msg, wP, lP);
    }
    return 0;
}

class __WAPI{
public:
    WNDCLASSEX WAPI_wnd;
    void init(  HINSTANCE hInst, char* ClassName ){
            HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
            HCURSOR hCursor = LoadCursor(NULL, IDC_ARROW);

            WNDCLASSEX wnd;

            wnd.hInstance = hInst;
            wnd.lpszClassName = ClassName;
            wnd.lpfnWndProc = _WAPI_WNDPROC;
            wnd.style = CS_HREDRAW | CS_VREDRAW;
            wnd.cbSize = sizeof (WNDCLASSEX);


            wnd.hIcon = wnd.hIconSm = hIcon;
            wnd.hCursor = hCursor;
            wnd.lpszMenuName = NULL;
            wnd.cbClsExtra = 0;
            wnd.cbWndExtra = 0;
            wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;

            if( !RegisterClassEx(&wnd) )
            {
                char buff [] = "Error create of class ";
                MessageBox(0, strcat(buff, ClassName), ClassName,0);
            }
    }
}*wapi;
