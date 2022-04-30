#ifndef CUBE_H
#define CUBE_H

#include "utils.h"
#include "texture.h"
#include "szin.h"
#include <obj/model.h>

#include <stdbool.h>

/**
 * Kocka helyzete és oldal sziei
 */
typedef struct Cube
{
	Szin szin[6];
	GLuint texture_id;
    int x;
	int y;
	int z;
	int face_colors[6];
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
void set_cube_color(Cube* cube, double red, double green, double blue, int side);

void draw_cube(Cube* cube);
void draw_color(Cube* cube, int color);

#endif /* CUBE_H */
