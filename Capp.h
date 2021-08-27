#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include "SDL.h"
#include "Cevent.h"
#include "Csurface.h" 
 
class Capp : public Cevent{
    private:
        bool    Running;
        
        SDL_Window *sdlWindow;
        SDL_Renderer *sdlRenderer;
        SDL_Surface*    Surf_Test;
        SDL_Texture* sdlTexture;
        
 
    public:
 
        Capp();
 
        int OnExecute();
        
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
        
        void OnExit();
 
};
 
#endif
