#include "Capp.h"
 
void Capp::OnRender() {
     
     SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 255, 255);
     SDL_RenderClear(sdlRenderer);
     
     //specifyng less or more then original dimension, the image will
     //be shrinked or expanded, not cropped.
     Csurface::OnDraw(sdlRenderer, Texture_Grid, 0, 0, 600, 600);
     
     for(int i = 0;i < 9;i++) {
      int X = (i % 3) * 200;
      int Y = (i / 3) * 200;
 
      if(Grid[i] == GRID_TYPE_X) {
         Csurface::OnDraw(sdlRenderer, Texture_X, X, Y, 200, 200);
      }else
         if(Grid[i] == GRID_TYPE_O) {
           Csurface::OnDraw(sdlRenderer, Texture_O, X, Y, 200, 200);
         }
     }
     
     SDL_RenderPresent(sdlRenderer);
}
