#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

struct missile {
        bool existance;
        float x;
        float y;
        float speed;
        SDL_Rect rect;
        SDL_Renderer* renderer;
};

void init_missile(struct missile* self, SDL_Renderer* renderer);
void render_missile(struct missile* self);
void tick_missile(struct missile* self, float dt);
