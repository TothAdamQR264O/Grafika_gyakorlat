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
	int palet[6][3];
} Szin;

/**
 * Initialize the szin position and Szin.
 */
void init_szin(Szin* szin);

void draw_szin(Szin* szin, int color);

#endif /* SZIN_H */
