#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#define MAX_HP 5

struct player {
        float x, y;
        float vx, vy;
        float ax, ay;
        float speed;
        int hp;
        bool invincible;
        Uint32 invincible_timer;
        SDL_Rect rect;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
        
        SDL_Texture* normal_texture;
        SDL_Texture* animation_textures[2];

        Uint32 animation_timer;
        bool dead;
};

void init_player(struct player* self, SDL_Renderer* renderer);
void handle_player_event(struct player* self, SDL_Event* e);
void tick_player(struct player* self, float dt);
void render_player(struct player* self);
void destroy_player(struct player* self);

void hurt_player(struct player* self);
