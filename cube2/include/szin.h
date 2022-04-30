#ifndef SZIN_H
#define SZIN_H

#include "utils.h"
#include "texture.h"
#include <obj/model.h>
#include <stdbool.h>

/**
 * Kocka helyzete és oldal sziei
 */
typedef struct Szin
{
	GLuint white_texture_id;
	GLuint blue_texture_id;
	GLuint green_texture_id;
	GLuint yello_texture_id;
	GLuint purple_texture_id;
	GLuint red_texture_id;
} Szin;

/**
 * Initialize the szin position and Szin.
 */
void init_szin(Szin* szin);

GLuint draw_szin(Szin* szin, int color);

#endif /* SZIN_H */
