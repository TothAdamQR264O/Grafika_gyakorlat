#include "cube.h"

#include <GL/gl.h>

#include <math.h>

void init_cube(Cube* cube)
{
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

void set_cube_color(Cube* cube, double red, double green, double blue, int side){
		cube->face_colors[side][0] = red;
		cube->face_colors[side][1] = green;
		cube->face_colors[side][2] = blue;
}

double get_cube_color_R(Cube* cube, int side){
		return cube->face_colors[side][0];
}

double get_cube_color_G(Cube* cube, int side){
		return cube->face_colors[side][1];
}

double get_cube_color_B(Cube* cube, int side){
		return cube->face_colors[side][2];
}

void draw_cube(Cube* cube){
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	
	glBegin(GL_QUADS);
	//fehér fent
	glColor3f(cube->face_colors[0][0], cube->face_colors[0][1], cube->face_colors[0][2]);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
	//kék hátsó
	glColor3f(cube->face_colors[1][0], cube->face_colors[1][1], cube->face_colors[1][2]);	
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
	//zöld első
	glColor3f(cube->face_colors[2][0], cube->face_colors[2][1], cube->face_colors[2][2]);
	glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
	//sárga alsó
	glColor3f(cube->face_colors[3][0], cube->face_colors[3][1], cube->face_colors[3][2]);
	glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
	//lila bal
	glColor3f(cube->face_colors[4][0], cube->face_colors[4][1], cube->face_colors[4][2]);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
	//piros jobb
	glColor3f(cube->face_colors[5][0], cube->face_colors[5][1], cube->face_colors[5][2]);
	glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
	
	glEnd();
	
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	
}