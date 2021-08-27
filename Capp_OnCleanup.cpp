#include "Capp.h"
 
void Capp::OnCleanup() {
     SDL_FreeSurface(Surf_Test);
     SDL_Quit();
}
