#include "score.h"

#include "textures.h"
#include "missiles.h"
#include "utils/collision.h"

void init_score(struct score* self, SDL_Renderer* renderer, struct player* player) {
        self->existance = true;
        self->renderer = renderer;
        self->rotation = rand() % 360;
        
        self->rect.w = 9 * 4;
        self->rect.h = 9 * 4;
        
        self->x = rand() % (800 - 9*4);
        self->y = -700 + rand() % 600;

        self->speed = (200 * (50.f / self->rect.w) + (rand() % 100));

        self->player = player;
}

void tick_score(struct score* self, float dt) {
        self->y += self->speed * dt;
        if (self->y > 600) {
                init_score(self, self->renderer, self->player);
        }

        int r = self->rect.w / 2;
        if (check_circle_collision(self->x + r, self->y + r, self->player->x + 8, self->player->y + 8, r)) {
                hurt_player(self->player);
                self->player->vx = -self->player->vx;
                if (self->player->vy < 0 || -self->player->vy > self->speed)
                        self->player->vy = -self->player->vy;
                else
                        self->player->vy = self->speed + 10;
        }
        
        for (int i=0; i<MAX_MISSILE; i++) {
                struct missile* m = &missiles[i];
                if (!m->existance) continue;
                if (check_circle_collision(self->x + r, self->y + r, m->x + m->rect.w/2.f, m->y + m->rect.w/2.f, r)) {
                        init_score(self, self->renderer, self->player);
                        m->existance = false;
                }
        }
}

void render_score(struct score* self) {
        self->rect.x = self->x;
        self->rect.y = self->y;
        SDL_RenderCopyEx(self->renderer, score_texture, NULL, &self->rect, self->rotation, NULL, SDL_FLIP_NONE);
}
