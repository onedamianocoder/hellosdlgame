#include "Capp.h"
 
void Capp::OnRender() {
     
     SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 255, 255);
     SDL_RenderClear(sdlRenderer);
     
     //specifyng less or more then original dimension, the image will
     //be shrinked or expanded, not cropped.
     Csurface::OnDraw(sdlRenderer, sdlTexture, 0, 0, 50, 100);
     
     SDL_RenderPresent(sdlRenderer);
}
