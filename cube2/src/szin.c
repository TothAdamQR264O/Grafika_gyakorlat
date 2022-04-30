#include "szin.h"

#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_szin(Szin* szin)
{
	szin->white_texture_id = load_texture("assets/textures/white.png");
	szin->blue_texture_id = load_texture("assets/textures/blue.png");
	szin->green_texture_id = load_texture("assets/textures/green.png");
	szin->yello_texture_id = load_texture("assets/textures/yello.png");
	szin->purple_texture_id = load_texture("assets/textures/purple.png");
	szin->red_texture_id = load_texture("assets/textures/red.png");
}

GLuint draw_szin(Szin* szin, int color){
	if(color == 1){
		return szin->white_texture_id;
	}
	if(color == 2){
		return szin->blue_texture_id;
	}
	if(color == 3){
		glBindTexture(GL_TEXTURE_2D, szin->green_texture_id);
	}
	if(color == 4){
		glBindTexture(GL_TEXTURE_2D, szin->yello_texture_id);
	}
	if(color == 5){
		glBindTexture(GL_TEXTURE_2D, szin->purple_texture_id);
	}
	if(color == 6){
		glBindTexture(GL_TEXTURE_2D, szin->red_texture_id);
	}
	//return szin->green_texture_id;
}