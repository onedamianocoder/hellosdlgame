#include "Csurface.h"
#include <iostream>
#include "SDL_image.h"
 
Csurface::Csurface() {
}
 
SDL_Surface* Csurface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
 
    if((Surf_Temp = IMG_Load(File)) == NULL) {
        std::cout << "LoadBMP failed \n";
        system("PAUSE");
        return NULL;
    }
 
    SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
    Surf_Return = SDL_ConvertSurface(Surf_Temp, format, 0);
    //Surf_Return = Surf_Temp;
    SDL_FreeSurface(Surf_Temp);
    SDL_FreeFormat(format);
 
    return Surf_Return;
}

bool Csurface::OnDraw(SDL_Renderer* Render_Dest, SDL_Texture* Texture_Src, int srcX, int srcY, int width, int height) {
    if(Render_Dest == NULL || Texture_Src == NULL) {
        return false;
    }
 
    SDL_Rect DstR;
 
    DstR.x = srcX;
    DstR.y = srcY;
    DstR.w = width;
    DstR.h = height;
 
    //srcrect --> bacground su cui disegno
    //dstrect --> texture disegnata
    SDL_RenderCopy( Render_Dest, Texture_Src, NULL, &DstR); 
 
    return true;
}

bool Csurface::OnDraw(SDL_Renderer* Render_Dest, SDL_Texture* Texture_Src, int destX, int destY, 
                                    int destW, int destH, int srcX, int srcY, int srcW, int srcH) {
    if(Render_Dest == NULL || Texture_Src == NULL) {
        return false;
    }
    
    //position and dimension of destination (bkgnd)
    SDL_Rect DestR;
 
    DestR.x = destX;
    DestR.y = destY;
    DestR.w = destW;
    DestR.h = destH;
 
    //position and dimension of source 
    SDL_Rect SrcR;
 
    SrcR.x = srcX;
    SrcR.y = srcY;
    SrcR.w = srcW;
    SrcR.h = srcH;
 
    //SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
    SDL_RenderCopy( Render_Dest, Texture_Src, &SrcR, &DestR);
 
    return true;
}

bool Csurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }
 
    SDL_SetColorKey(Surf_Dest, SDL_TRUE, SDL_MapRGB(Surf_Dest->format, R, G, B));
 
    return true;
}
