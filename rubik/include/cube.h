#ifndef CUBE_H
#define CUBE_H

#include "utils.h"

#include <stdbool.h>

/**
 * Kocka helyzete és oldal sziei
 */
typedef struct Cube
{
    int x;
	int y;
	int z;
	
	int face_colors[6][3];
} Cube;

/**
 * Initialize the cube position and colors.
 */
void init_cube(Cube* cube);

/**
 * Set cube position.
 */
void set_cube_position(Cube* cube, int x, int y, int z);
/**
 *Kocka egyik oldalának a szine
 */
void set_cube_color(Cube* cube, int red, int green, int blue, int side);

void draw_cube(Cube* cube);

#endif /* CUBE_H */
