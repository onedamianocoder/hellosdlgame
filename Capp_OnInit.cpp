#include "Capp.h"
#include <iostream>
 
bool Capp::OnInit() {
     if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "sdlinit failed \n";
        system("PAUSE");
        return false;
    }
 
    if(SDL_CreateWindowAndRenderer(640, 480, 0, &sdlWindow, &sdlRenderer) < 0) {
        std::cout << "CreateWindowAndRenderer failed \n";
        system("PAUSE");
        return false;
    }
    
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
    
    return true;
}
