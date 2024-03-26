#include"menu.h"
int main()
{
    ReadSettings();
    if(MenuStartSequeceOnOff==0)
    {
        MenuStartSequece();
    }
    MenuMainLoop();
    return 0;

}
