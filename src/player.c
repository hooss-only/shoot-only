#include "player.h"
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
        self->texture = IMG_LoadTexture(self->renderer, "./assets/player.png");

        self->speed = 100;

        self->vx = 0;
        self->vy = 0;

        self->ax = 0;
        self->ay = 0;
}

void handle_player_event(struct player* self, SDL_Event* e) {
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
        self->vx += self->ax * dt;
        self->vy += self->ay * dt;
        float nx = 0, ny = 0;
        nx = self->x + self->vx  * dt;
        ny = self->y + self->vy * dt;
        
        if (nx >= 0 && nx <= 800)
                self->x = nx;
        else
                self->vx = 0;

        if (ny >= 0 && ny <= 600) 
                self->y = ny;
        else
                self->vy = 0;
}

void render_player(struct player* self) {
        self->rect.x = (int) self->x;
        self->rect.y = (int) self->y;
        SDL_RenderCopy(self->renderer, self->texture, NULL, &self->rect);
}
