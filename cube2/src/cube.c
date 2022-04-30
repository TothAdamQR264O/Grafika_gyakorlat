#include "cube.h"

#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>

#include <math.h>

void init_cube(Cube* cube)
{
	for(int i = 0; i < 6; i++){
		init_szin(&(cube->szin[i]));
	}
	cube->texture_id = load_texture("assets/textures/red.png");
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
	
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);
	//fehér fent
	glColor3f(1, 1, 1);
	glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
	//kék hátsó
	draw_color(cube, 1);
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
	
	
/*
    glColor3f(1, 0, 1);
	//glBindTexture(GL_TEXTURE_2D, draw_szin(&(cube->szin[0]), 2));
	//glBindTexture(GL_TEXTURE_2D, cube->texture_id);
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
	//glBindTexture(GL_TEXTURE_2D, cube->texture_id);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, 0);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, 0);
    glEnd();*/
	
}

void draw_color(Cube* cube, int color){
	if(color == 1){
		//glColor3f(1, 1, 1);
	}
	if(color == 2){
		//glColor3f(0, 0, 1);
	}
	if(color == 3){
		//glColor3f(0, 1, 0);
	}
	if(color == 4){
		//glColor3f(1, 1, 0);
	}
	if(color == 5){
		//glColor3f(1, 0, 1);
	}
	if(color == 6){
		//glColor3f(1, 0, 0);
	}
}