#pragma once

#include <SDL2/SDL.h>

struct player {
        SDL_Rect rect;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
};

void init_player(struct player* self, SDL_Renderer* renderer);
void render_player(struct player* self);
