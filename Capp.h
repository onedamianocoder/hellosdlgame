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
        //SDL_Surface*    Surf_Test;
        //SDL_Texture* sdlTexture;
        
        SDL_Surface*    Surf_Grid;
        SDL_Surface*    Surf_X;
        SDL_Surface*    Surf_O;
        SDL_Texture* Texture_Grid;
        SDL_Texture* Texture_X;
        SDL_Texture* Texture_O;
        
        int        Grid[9];
        int CurrentPlayer;
        
        enum {
           GRID_TYPE_NONE = 0,
           GRID_TYPE_X,
           GRID_TYPE_O
           };
        
 
    public:
 
        Capp();
 
        int OnExecute();
        
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
        
        void OnLButtonDown(int mX, int mY);
        
        void OnExit();
        
        void Reset();
        
        void SetCell(int ID, int Type);
 
};
 
#endif
