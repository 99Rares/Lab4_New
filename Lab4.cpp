#include <iostream>
#include "UI.h"
#include "Teste.h"
int main()
{   
    Teste t;
    t.test();
    Repo r;
    Controller c = Controller(r);
    UI ui = UI(c);

    ui.ui();
}


