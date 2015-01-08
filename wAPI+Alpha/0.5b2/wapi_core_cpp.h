/** �������� ������� � ������� wAPI+ **/

void _W_API_Event_Listener( WPARAM wP, LPARAM lP )
{
    switch( HIWORD( wP ) )
    {
        case BN_CLICKED:
            if( wapi->_T_BUTTONS[ LOWORD( wP ) ] != NULL )
                if( wapi->_T_BUTTONS[ LOWORD( wP ) ]->onClick != NULL  ){
                       wapi->_T_BUTTONS[ LOWORD( wP ) ]->onClick( wapi->_T_BUTTONS[ LOWORD( wP ) ] );
                        return;
            }
            if( wapi->_T_CHECKBOX[ LOWORD( wP ) ] != NULL ){
                if( wapi->_T_CHECKBOX[ LOWORD( wP ) ]->onClick != NULL )
                       //wapi->_T_CHECKBOX[ LOWORD( wP ) ]->onClick( wapi->_T_CHECKBOX[ LOWORD( wP ) ] );
                       return;

            }
        break;
        case EN_CHANGE:
            if( wapi->_T_EDIT[ LOWORD( wP ) ] != NULL ){
                if( wapi->_T_EDIT[ LOWORD( wP ) ]->onEdit != NULL )
                    //wapi->_T_EDIT[ LOWORD( wP ) ]->onEdit( wapi->_T_EDIT[ LOWORD( wP ) ] );
                    return;
            }
            Message( wapi->_T_EDIT[ LOWORD(wP) ]->getText() );
            if( wapi->_T_MEMO[ LOWORD( wP ) ] != NULL ){
                if(  wapi->_T_MEMO[ LOWORD( wP ) ]->onEdit != NULL )
                    //wapi->_T_MEMO[ LOWORD( wP ) ]->onEdit( wapi->_T_MEMO[ LOWORD( wP ) ] );
                    return;
            }
            if( wapi->_T_EDITP[ LOWORD( wP ) ] != NULL ){
                if(  wapi->_T_EDITP[ LOWORD( wP ) ]->onEdit != NULL )
                    //wapi->_T_EDITP[ LOWORD( wP ) ]->onEdit( wapi->_T_EDITP[ LOWORD( wP ) ] );
                    return;
            }
        break;
    }
}

LRESULT CALLBACK WAPI_W_NDPROC(HWND hwnd, UINT msg, WPARAM wP, LPARAM lP)
{
    switch( msg )
    {
        case WM_COMMAND:
            _W_API_Event_Listener( wP, lP );
        break;
        case WM_KEYDOWN:
            if( wapi->HotFunction != NULL )
                wapi->HotFunction( LOWORD(wP) );
        break;
        case WM_QUIT:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wP, lP);
    }
    return 0;
}
void CALLBACK _W_API_TIMER_PROC(HWND hWnd, UINT msg, UINT_PTR id, DWORD dwTime)
{
    if( wapi->_T_TIMER[ id ]->repeat == true )
    {
        if( wapi->_T_TIMER[ id ]->onTimer != NULL )
            wapi->_T_TIMER[ id ]->onTimer( wapi->_T_TIMER[ id ] );
    }else
        wapi->_T_TIMER[ id ]->Stop();
}
void Message(LPSTR msg)
{
    MessageBoxA(0, msg, wapi->_C_LASSNAME, 0);
}
void Message(LPSTR msg, TForm* form)
{
    MessageBoxA(form->hWnd, msg, form->Caption, 0);
}
void Message(LPSTR msg, HWND hWnd)
{
    MessageBoxA(hWnd, msg, wapi->_C_LASSNAME, 0);
}
int _WAPI_P::__init(HINSTANCE hInst, LPSTR CN){

            HICON hIcon = wAPI_ICON;
            HCURSOR hCursor = wAPI_CURSOR;

            int win_style = 0;

            if( wAPI_NOCLOSE == 1 )
                win_style += CS_NOCLOSE;
            if( wAPI_HREDRAW == 1 )
                win_style += CS_HREDRAW;
            if( wAPI_VREDRAW == 1 )
                win_style += CS_VREDRAW;


            this->_W_ND.hInstance = hInst;
            this->_W_ND.lpszClassName = CN;
            this->_W_ND.lpfnWndProc = WAPI_W_NDPROC;
            this->_W_ND.style = win_style;
            this->_W_ND.cbSize = sizeof (WNDCLASSEX);


            this->_W_ND.hIcon = this->_W_ND.hIconSm = hIcon;
            this->_W_ND.hCursor = hCursor;
            this->_W_ND.lpszMenuName = NULL;
            this->_W_ND.cbClsExtra = 0;
            this->_W_ND.cbWndExtra = 0;
            this->_W_ND.hbrBackground = (HBRUSH)COLOR_WINDOW;

            if( !RegisterClassEx(&this->_W_ND) ){
                Message((char*)"Error registering class");
                return -1;
            }
            this->_C_LASSNAME = CN;
            this->_H_INST = hInst;

    return 0;
}

void TObject::Focus()
{
    SetFocus(this->hWnd);
}
void TObject::SetText( LPSTR caption )
{
    SetWindowText( this->hWnd, caption);
    this->Caption = caption;
}
LPSTR TObject::getText()
{
    char text[1000];
    SendMessage( this->hWnd, WM_GETTEXT, 1000, (LPARAM)text );
    return text;
}




