#include "textures.h"

#include <SDL2/SDL_image.h>

SDL_Texture* missile_texture = NULL;
SDL_Texture* star_texture = NULL;
SDL_Texture* planet_textures[5] = { 0 };
SDL_Texture* heart_container_texture = NULL;
SDL_Texture* heart_filled_texture = NULL;
SDL_Texture* score_texture = NULL;

void init_textures(SDL_Renderer* renderer) {
        missile_texture = IMG_LoadTexture(renderer, "./assets/missile.png");
        star_texture = IMG_LoadTexture(renderer, "./assets/star.png");
        SDL_SetTextureBlendMode(star_texture, SDL_BLENDMODE_BLEND);
        planet_textures[0] = IMG_LoadTexture(renderer, "./assets/planet1.png");
        planet_textures[1] = IMG_LoadTexture(renderer, "./assets/planet2.png");
        planet_textures[2] = IMG_LoadTexture(renderer, "./assets/planet3.png");
        planet_textures[3] = IMG_LoadTexture(renderer, "./assets/planet4.png");
        planet_textures[4] = IMG_LoadTexture(renderer, "./assets/planet5.png");

        heart_container_texture = IMG_LoadTexture(renderer, "./assets/heart_container.png");
        heart_filled_texture = IMG_LoadTexture(renderer, "./assets/heart_filled.png");
        score_texture = IMG_LoadTexture(renderer, "./assets/score.png");
        
}

void destroy_textures() {
        SDL_DestroyTexture(missile_texture);
        SDL_DestroyTexture(star_texture);
        for (int i=0; i<PLANET_TYPE_AMOUNT; i++) {
                SDL_DestroyTexture(planet_textures[i]);
        }
        SDL_DestroyTexture(heart_container_texture);
        SDL_DestroyTexture(heart_filled_texture);
        SDL_DestroyTexture(score_texture);
}
