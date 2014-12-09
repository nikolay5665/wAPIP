#include "wapi_core.h"

char WAPI *wAPIVersion(  ){
    return WAPI_VER;
}




void WAPI  wAPIInit( HINSTANCE hInst, char* ClassName){

    wapi->init(hInst, ClassName);

}
template<class T>
    int WAPI wAPICreate(  );
