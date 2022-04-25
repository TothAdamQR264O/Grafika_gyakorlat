#include "cube.h"

#include <GL/gl.h>

#include <math.h>

void init_cube(Cube* cube)
{
    cube->x = 0;
	cube->y = 0;
	cube->z = 0;
}

void set_cube_position(Cube* cube, int x, int y, int z)
{
    cube->x = x;
	cube->y = y;
	cube->z = z;
}


void set_cube_color(Cube* cube, double red, double green, double blue, int side){
		cube->face_colors[side] = red;
		cube->face_colors[side] = green;
		cube->face_colors[side] = blue;
}

void draw_cube(Cube* cube){
	
	glBegin(GL_QUADS);
	
	glColor3f(1, 1, 1);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5f, 0.5, 0.5);
    glVertex3f(0.5f, -0.5, 0.5);
	
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5f, 0.5, -0.5);
    glVertex3f(-0.5f, -0.5, -0.5);
	
	glColor3f(0, 1, 0);
	glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5f, 0.5, -0.5);
    glVertex3f(0.5f, -0.5, -0.5);
	
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5f, 0.5, -0.5);
    glVertex3f(0.5f, -0.5, -0.5);
	
	glColor3f(0, 1, 1);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5f, -0.5, -0.5);
    glVertex3f(0.5f, -0.5, 0.5);
	
	glColor3f(1, 0, 1);
	glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5f, 0.5, 0.5);
    glVertex3f(0.5f, 0.5, -0.5);
	
	
	glEnd();
}