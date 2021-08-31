#include "Capp.h"
#include <iostream>
 
bool Capp::OnInit() {
     if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "sdlinit failed \n";
        system("PAUSE");
        return false;
    }
 
    if(SDL_CreateWindowAndRenderer(600, 600, 0, &sdlWindow, &sdlRenderer) < 0) {
        std::cout << "CreateWindowAndRenderer failed \n";
        system("PAUSE");
        return false;
    }
    
    /*
    if((Surf_Test = Csurface::OnLoad("myimage.bmp")) == NULL) {
         std::cout << "image loading failed \n";
         system("PAUSE");
         return false;
       
    }
    
    if( (sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Test)) == NULL) {
        std::cout << "CreateTextureFromSurface failed \n";
        system("PAUSE");
        return false;
    }
    */
    
    if((Surf_Grid = Csurface::OnLoad("grid.png")) == NULL) {
    return false;
    }
 
    if((Surf_X = Csurface::OnLoad("x.png")) == NULL) {
    return false;
    }
 
    if((Surf_O = Csurface::OnLoad("o.png")) == NULL) {
    return false;
    }
    
    Csurface::Transparent(Surf_X, 255, 0, 255);
    Csurface::Transparent(Surf_O, 255, 0, 255);
    Reset();
    
    if( (Texture_Grid = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Grid)) == NULL) {
        return false;
    }else{
          SDL_FreeSurface(Surf_Grid);
          }
    
    if( (Texture_X = SDL_CreateTextureFromSurface(sdlRenderer, Surf_X)) == NULL) {
        return false;
    }else{
          SDL_FreeSurface(Surf_X);
          }
    
    if( (Texture_O = SDL_CreateTextureFromSurface(sdlRenderer, Surf_O)) == NULL) {
        return false;
    }else{
          SDL_FreeSurface(Surf_O);
          }
    
    return true;
}
