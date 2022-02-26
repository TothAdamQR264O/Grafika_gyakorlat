#ifndef COLOR_H
#define COLOR_H

/**
 * Szin adatok
 */
typedef struct Color
{
	int Red;
	int Green;
	int Blue;
} Color;

/**
 * Vonal adat bealitas
 */
void set_color_data(Color* color, int r, int g, int b);

int get_red(const Color* color);
int get_green(const Color* color);
int get_blue(const Color* color);

#endif // COLOR_H
