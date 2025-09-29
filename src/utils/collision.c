#include "collision.h"

bool check_circle_collision(float x1, float y1, float x2, float y2, int r) {
        float dx = x1 - x2, dy = y1 - y2;
        return dx*dx + dy*dy < r*r;
}
