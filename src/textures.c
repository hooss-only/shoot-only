#include "textures.h"

#include <SDL2/SDL_image.h>

SDL_Texture* missile_texture = NULL;

void init_textures(SDL_Renderer* renderer) {
        missile_texture = IMG_LoadTexture(renderer, "./assets/missile.png");
}
