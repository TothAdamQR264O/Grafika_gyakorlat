#include "line.h"

#include <math.h>

void set_line_data(Line* line, double x1, double y1, double x2, double y2)
{
	line->x1 = x1;
	line->x2 = x2;
	line->y1 = y1;
	line->y2 = y2;
}

double get_x1(const Line* line){
	double x1 = line->x1;
	return x1;
}

double get_x2(const Line* line){
	double x2 = line->x2;
	return x2;
}

double get_y1(const Line* line){
	double y1 = line->y1;
	return y1;
}

double get_y2(const Line* line){
	double y2 = line->y2;
	return y2;
}
