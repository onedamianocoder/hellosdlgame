#include <iostream>
#include "Capp.h"
 
Capp::Capp() {
    sdlWindow = NULL;
    sdlRenderer = NULL;
    Surf_Test = NULL;
    sdlTexture = NULL;
    Running = true;
}
 
int Capp::OnExecute() {
    //onInit will fill winDisplay
    if(OnInit() == false) {
        return -1;
    }
 
    //structure that hold info about the event
    SDL_Event Event;
 
    while(Running) {
        //std::cout << "running game loop \n";
        //check for events and pass them to OnEvent
        //SDL:PollEvent grab any avent in the queue, this is we have to loop
        //trough them. Once queue is empty SDL_PollEvent return false.
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        //once finished continue 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
 
int main(int argc, char* argv[]) {
    //std::cout << "declaring Capp \n";
    Capp theApp;
     
    //std::cout << "Executing theapp \n";
    return theApp.OnExecute();
}
