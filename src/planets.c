#include "planets.h"

SDL_Renderer* planet_renderer;
struct player* planet_player;
struct planet planets[MAX_PLANET] = { 0 };

void add_planet() {
        for (int i=0; i<MAX_PLANET; i++) {
                if (!planets[i].existance) {
                        init_planet(&planets[i], planet_renderer, planet_player);
                        return;
                }
        }
}

void set_planets_renderer(SDL_Renderer* renderer) {
        planet_renderer = renderer;
}

void set_planets_player(struct player* player) {
        planet_player = player;
}

void render_planets() {
        for (int i=0; i<MAX_PLANET; i++) {
                if (planets[i].existance) {
                        render_planet(&planets[i]);
                }
        }
}

void tick_planets(float dt) {
        for (int i=0; i<MAX_PLANET; i++) {
                if (planets[i].existance) {
                        tick_planet(&planets[i], dt);
                }
        }
}
