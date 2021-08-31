#include "Capp.h"
#include <iostream>
 
void Capp::OnEvent(SDL_Event* Event) {
     Cevent::OnEvent(Event);
}

void Capp::OnLButtonDown(int mX, int mY) {
    int ID    = mX / 200;
    ID = ID + ((mY / 200) * 3);
    
    std::cout<< "id: "<<ID << std::endl;
 
    if(Grid[ID] != GRID_TYPE_NONE) {
        return;
    }
 
    if(CurrentPlayer == 0) {
        SetCell(ID, GRID_TYPE_X);
        CurrentPlayer = 1;
    }else{
        SetCell(ID, GRID_TYPE_O);
        CurrentPlayer = 0;
    }
}

void Capp::OnExit() {
    Running = false;
}
