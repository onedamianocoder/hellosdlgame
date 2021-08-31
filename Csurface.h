#ifndef _CSURFACE_H_
    #define _CSURFACE_H_
 
#include <SDL.h>
 
class Csurface {
    public:
        Csurface();
 
    public:
        static SDL_Surface* OnLoad(char* File);
        static bool OnDraw(SDL_Renderer* Render_Dest, SDL_Texture* Texture_Src, int srcX, int srcY, int width, int height);
        static bool OnDraw(SDL_Renderer* Render_Dest, SDL_Texture* Texture_Src, int destX, int destY, 
               int destW, int destH, int srcX, int srcY, int srcW, int srcH);
        static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};
 
#endif
