#include "player.h"
#include "missiles.h"
#include "utils/logger.h"

#include <SDL2/SDL_image.h>

void init_player(struct player* self, SDL_Renderer* renderer) {
        self->renderer = renderer;
        self->x = 800/2.f - 4*4/2.f;
        self->y = 600/1.5f;
        self->rect.x = 0;
        self->rect.y = 0;
        self->rect.w = 4 * 4;
        self->rect.h = 4 * 4;
        self->normal_texture = IMG_LoadTexture(self->renderer, "./assets/player.png");
        SDL_SetTextureBlendMode(self->normal_texture, SDL_BLENDMODE_BLEND);

        self->animation_textures[0] = IMG_LoadTexture(self->renderer, "./assets/player_broken1.png");
        self->animation_textures[1] = IMG_LoadTexture(self->renderer, "./assets/player_broken2.png");

        self->texture = self->normal_texture;

        self->speed = 0.03;

        self->vx = 0;
        self->vy = 0;

        self->ax = 0;
        self->ay = 0;

        self->hp = 1;
        self->invincible = false;

        self->animation_timer = 0;
        self->dead = false;
}

void handle_player_event(struct player* self, SDL_Event* e) {
        if (self->dead) return;

        if (e->type == SDL_KEYDOWN) {
                SDL_Scancode scancode = e->key.keysym.scancode;
                if (e->key.repeat) return;
                
                switch (scancode) {
                        case SDL_SCANCODE_W:
                                self->ay -= self->speed;
                                break;
                        case SDL_SCANCODE_S:
                                self->ay += self->speed;
                                break;
                        case SDL_SCANCODE_D:
                                self->ax += self->speed;
                                break;
                        case SDL_SCANCODE_A:
                                self->ax -= self->speed;
                                break;
                        case SDL_SCANCODE_SPACE:
                                add_missile(self->x+4, self->y);
                                self->vy += 100;
                                break;
                        default:
                                break;
                }
        }

        else if (e->type == SDL_KEYUP) {
                SDL_Scancode scancode = e->key.keysym.scancode;
                
                switch (scancode) {
                        case SDL_SCANCODE_W:
                                self->ay += self->speed;
                                break;
                        case SDL_SCANCODE_S:
                                self->ay -= self->speed;
                                break;
                        case SDL_SCANCODE_D:
                                self->ax -= self->speed;
                                break;
                        case SDL_SCANCODE_A:
                                self->ax += self->speed;
                                break;
                        default:
                                break;
                }
        }
}

void tick_player(struct player* self, float dt) {
        LOG_set_logger_name("Player");

        if (self->dead) {
                Uint32 now = SDL_GetTicks();
                if (now - self->animation_timer > 200)
                        self->texture = self->animation_textures[0];
                if (now - self->animation_timer > 400)
                        self->texture = self->animation_textures[1];
                if (now - self->animation_timer > 600)
                        self->texture = NULL;
        }

        self->vx += self->ax;
        self->vy += self->ay;
        float nx = 0, ny = 0;
        nx = self->x + self->vx  * dt;
        ny = self->y + self->vy * dt;
        
        if (nx >= 0 && nx <= 800 - 4 * 4)
                self->x = nx;
        else
                self->vx = 0;

        if (ny >= 0) 
                self->y = ny;
        else
                self->vy = 0;

        if (ny > 600 && self->vy > 0) {
                self->vy = -self->vy;
                hurt_player(self);
        }

        if (self->invincible && SDL_GetTicks() - self->invincible_timer > 2000)
                self->invincible = false;
}

void render_player(struct player* self) {
        self->rect.x = (int) self->x;
        self->rect.y = (int) self->y;
        if (!self->dead)
                SDL_SetTextureAlphaMod(self->texture, self->invincible ? 128 : 255);
        SDL_RenderCopy(self->renderer, self->texture, NULL, &self->rect);
}

void destroy_player(struct player* self) {
        SDL_DestroyTexture(self->normal_texture);
        SDL_DestroyTexture(self->animation_textures[0]);
        SDL_DestroyTexture(self->animation_textures[1]);
}

void hurt_player(struct player* self) {
        if (!self->invincible) {
                self->hp -= 1;
        }

        if (self->hp <= 0 && !self->dead) {
                self->dead = true;
                self->animation_timer = SDL_GetTicks();
                return;
        }

        self->invincible = true;
        self->invincible_timer = SDL_GetTicks();
}
