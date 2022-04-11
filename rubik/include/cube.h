#ifndef CUBE_H
#define CUBE_H

#include "utils.h"

#include <stdbool.h>

/**
 * Kocka helyzete és oldal sziei
 */
typedef struct Cube
{
    double x;
	double y;
	double z;
	
	int colors[6];
} Cube;

/**
 * Initialize the cube position and colors.
 */
void init_cube(Cube* cube);

/**
 * Set cube position.
 */
void set_cube_position(Cube* cube, double x, double y, double z);
/**
 *Kocka egyik oldalának a szine
 */
void set_cube_color(Cube* cube, double red, double green, double blue, int side);

#endif /* CUBE_H */
