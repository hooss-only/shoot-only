#pragma once

#include <SDL2/SDL.h>
#include <stdlib.h>

extern SDL_Texture* missile_texture;
extern SDL_Texture* star_texture;
extern SDL_Texture* planet_textures[5];

void init_textures(SDL_Renderer* renderer);
void destroy_textures();

#define PLANET_TYPE_AMOUNT 5
