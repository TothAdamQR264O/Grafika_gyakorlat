#include "cube.h"

#include <GL/gl.h>

#include <math.h>

void init_cube(Cube* cube)
{
    cube->x = 0;
	cube->y = 0;
	cube->z = 0;
	
	cube->face_colors[0][0] = 1;
	cube->face_colors[0][1] = 1;
	cube->face_colors[0][2] = 1;
	
	cube->face_colors[1][0] = 0;
	cube->face_colors[1][1] = 0;
	cube->face_colors[1][2] = 1;
	
	cube->face_colors[2][0] = 0;
	cube->face_colors[2][1] = 1;
	cube->face_colors[2][2] = 0;
	
	cube->face_colors[3][0] = 1;
	cube->face_colors[3][1] = 1;
	cube->face_colors[3][2] = 0;
	
	cube->face_colors[4][0] = 1;
	cube->face_colors[4][1] = 0;
	cube->face_colors[4][2] = 1;
	
	cube->face_colors[5][0] = 1;
	cube->face_colors[5][1] = 0;
	cube->face_colors[5][2] = 0;
}

void set_cube_position(Cube* cube, int x, int y, int z)
{
    cube->x = x;
	cube->y = y;
	cube->z = z;
}


void set_cube_color(Cube* cube, int red, int green, int blue, int side){
		cube->face_colors[side][0] = red;
		cube->face_colors[side][1] = green;
		cube->face_colors[side][2] = blue;
}

void draw_cube(Cube* cube){
	
	glBegin(GL_QUADS);
	//fehér fent
	glColor3f(cube->face_colors[0][0], cube->face_colors[0][1], cube->face_colors[0][2]);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
	//kék hátsó
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
	//zöld első
	glColor3f(0, 1, 0);
	glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
	//sárga alsó
	glColor3f(1, 1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
	//lila bal
	glColor3f(1, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
	//piros jobb
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
	
	glEnd();
	
}