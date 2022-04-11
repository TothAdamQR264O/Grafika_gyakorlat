#include "cube.h"

#include <GL/gl.h>

#include <math.h>

void init_cube(Cube* cube)
{
    cube->x = 0;
	cube->y = 0;
	cube->z = 0;
}

void set_cube_position(Cube* cube, double x, double y, double z)
{
    cube->x = x;
	cube->y = y;
	cube->z = z;
}


void set_cube_color(Cube* cube, double red, double green, double blue, int side){
		cube->colors[side] = red;
		cube->colors[side] = green;
		cube->colors[side] = blue;
}
