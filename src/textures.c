#include "textures.h"

#include <SDL2/SDL_image.h>

SDL_Texture* missile_texture = NULL;
SDL_Texture* star_texture = NULL;

void init_textures(SDL_Renderer* renderer) {
        missile_texture = IMG_LoadTexture(renderer, "./assets/missile.png");
        star_texture = IMG_LoadTexture(renderer, "./assets/star.png");
        SDL_SetTextureBlendMode(star_texture, SDL_BLENDMODE_BLEND);
}

void destroy_textures() {
        SDL_DestroyTexture(missile_texture);
        SDL_DestroyTexture(star_texture);
}
