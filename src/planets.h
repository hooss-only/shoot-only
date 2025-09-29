#pragma once

#include "planet.h"

#define MAX_PLANET 20
extern struct planet planets[MAX_PLANET];

void add_planet();

void set_planets_renderer(SDL_Renderer* renderer);
void set_planets_player(struct player* player);

void render_planets();
void tick_planets(float dt);
