#include "planet.h"

#include "textures.h"
#include "missiles.h"

void init_planet(struct planet* self, SDL_Renderer* renderer, struct player* player) {
        self->existance = true;
        self->renderer = renderer;
        self->rotation = rand() % 360;
        self->type = rand() % PLANET_TYPE_AMOUNT;
        
        int width, height;
        SDL_QueryTexture(planet_textures[self->type], NULL, NULL, &width, &height);
        self->rect.w = width * 4;
        self->rect.h = height * 4;
        
        self->x = rand() % (800 - width);
        self->y = -700 + rand() % 600;

        self->speed = (200 * (50.f / self->rect.w) + (rand() % 100));

        self->player = player;
}

bool check_collision(float x1, float y1, float x2, float y2, int r) {
        float dx = x1 - x2, dy = y1 - y2;
        return dx*dx + dy*dy < r*r;
}

void tick_planet(struct planet* self, float dt) {
        self->y += self->speed * dt;
        if (self->y > 600) {
                init_planet(self, self->renderer, self->player);
        }

        int r = self->rect.w / 2;
        if (check_collision(self->x + r, self->y + r, self->player->x + 8, self->player->y + 8, r)) {
                hurt_player(self->player);
                self->player->vx = -self->player->vx;
                if (self->player->vy < 0 || -self->player->vy > self->speed)
                        self->player->vy = -self->player->vy;
                else
                        self->player->vy = self->speed + 10;
        }
        
        for (int i=0; i<MAX_MISSILE; i++) {
                struct missile* m = &missiles[i];
                if (check_collision(self->x + r, self->y + r, m->x + m->rect.w/2.f, m->y + m->rect.w/2.f, r)) {
                        m->existance = false;
                }
        }
}

void render_planet(struct planet* self) {
        self->rect.x = self->x;
        self->rect.y = self->y;
        SDL_RenderCopyEx(self->renderer, planet_textures[self->type], NULL, &self->rect, self->rotation, NULL, SDL_FLIP_NONE);
}
