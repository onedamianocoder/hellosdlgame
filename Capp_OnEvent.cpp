#include "Capp.h"
 
void Capp::OnEvent(SDL_Event* Event) {
     Cevent::OnEvent(Event);
}

void Capp::OnExit() {
    Running = false;
}
