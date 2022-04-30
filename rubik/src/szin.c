#include "szin.h"

#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_szin(Szin* szin)
{
	szin->palet[0][0] = 1;
	szin->palet[0][1] = 1;
	szin->palet[0][2] = 1;
	
	szin->palet[1][0] = 0;
	szin->palet[1][1] = 0;
	szin->palet[1][2] = 1;
	
	szin->palet[2][0] = 0;
	szin->palet[2][1] = 1;
	szin->palet[2][2] = 0;
	
	szin->palet[3][0] = 1;
	szin->palet[3][1] = 1;
	szin->palet[3][2] = 0;
	
	szin->palet[4][0] = 1;
	szin->palet[4][1] = 0;
	szin->palet[4][2] = 1;
	
	szin->palet[5][0] = 1;
	szin->palet[5][1] = 0;
	szin->palet[5][2] = 0;
}

void draw_szin(Szin* szin, int color){
	if(color == 1){
		glColor3f(szin->palet[0][0], szin->palet[0][1], szin->palet[0][2]);
	}
	if(color == 2){
		glColor3f(szin->palet[1][0], szin->palet[1][1], szin->palet[1][2]);
	}
	if(color == 3){
		glColor3f(szin->palet[2][0], szin->palet[2][1], szin->palet[2][2]);
	}
	if(color == 4){
		glColor3f(szin->palet[3][0], szin->palet[3][1], szin->palet[3][2]);
	}
	if(color == 5){
		glColor3f(szin->palet[4][0], szin->palet[4][1], szin->palet[4][2]);
	}
	if(color == 6){
		glColor3f(szin->palet[5][0], szin->palet[5][1], szin->palet[5][2]);
	}
}