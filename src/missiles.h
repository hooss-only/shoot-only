#pragma once

#include "missile.h"

#define MAX_MISSILE 100
extern struct missile missiles[MAX_MISSILE];

void add_missile(float x, float y);

void set_missiles_renderer(SDL_Renderer* renderer);

void render_missiles();
void tick_missiles(float dt);
