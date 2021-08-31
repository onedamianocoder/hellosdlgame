#include "Capp.h"
 
void Capp::OnCleanup() {
     //SDL_FreeSurface(Surf_Test);
     //SDL_FreeSurface(Surf_Grid);
     //SDL_FreeSurface(Surf_X);
     //SDL_FreeSurface(Surf_O);
     SDL_DestroyTexture(Texture_Grid);
     SDL_DestroyTexture(Texture_X);
     SDL_DestroyTexture(Texture_O);
     
     SDL_Quit();
}
