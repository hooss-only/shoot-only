#pragma once

#include <SDL2/SDL.h>

struct player {
        float x;
        float y;
        float vx;
        float vy;
        SDL_Rect rect;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
};

void init_player(struct player* self, SDL_Renderer* renderer);
void tick_player(struct player* self, float dt);
void render_player(struct player* self);
