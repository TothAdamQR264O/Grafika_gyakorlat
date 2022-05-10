#ifndef CUBE_H
#define CUBE_H

#include "utils.h"

#include <stdbool.h>

/**
 * Kocka helyzete és oldal sziei
 */
typedef struct Cube
{
	double face_colors[6][3];
} Cube;

/**
 * Initialize the cube position and colors.
 */
void init_cube(Cube* cube);

/**
 *Kocka egyik oldalának a szine
 */
void set_cube_color(Cube* cube, double red, double green, double blue, int side);

double get_cube_color_R(Cube* cube, int side);
double get_cube_color_G(Cube* cube, int side);
double get_cube_color_B(Cube* cube, int side);

void draw_cube(Cube* cube);

#endif /* CUBE_H */
