#include "color.h"

#include <math.h>

void set_color_data(Color* color, int r, int g, int b)
{
	color->Red = r;
	color->Green = g;
	color->Blue = b;
}

int get_red(const Color* color){
	int r = color->Red;
	return r;
}

int get_green(const Color* color){
	int g = color->Green;
	return g;
}

int get_blue(const Color* color){
	int b = color->Blue;
	return b;
}