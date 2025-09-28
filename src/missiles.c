#include "missiles.h"

#include "utils/logger.h"

SDL_Renderer* global_renderer;
struct missile missiles[MAX_MISSILE] = { 0 };

void add_missile(float x, float y) {
        LOG_set_logger_name("Missiles");
        LOG_printf(LOG_DEBUG, "MISSILE LAUNCH!!\n");
        for (int i=0; i<MAX_MISSILE; i++) {
                if (!missiles[i].existance) {
                        init_missile(&missiles[i], global_renderer);
                        missiles[i].x = x;
                        missiles[i].y = y;
                        return;
                }
        }
        LOG_printf(LOG_WARNING, "Max Missile Reached!\n");
}

void set_missiles_renderer(SDL_Renderer* renderer) {
        global_renderer = renderer;
}

void render_missiles() {
        for (int i=0; i<MAX_MISSILE; i++) {
                if (missiles[i].existance) {
                        render_missile(&missiles[i]);
                }
        }
}

void tick_missiles(float dt) {
        for (int i=0; i<MAX_MISSILE; i++) {
                if (missiles[i].existance) {
                        tick_missile(&missiles[i], dt);
                }
        }
}
