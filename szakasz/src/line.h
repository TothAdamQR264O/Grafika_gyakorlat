#ifndef LINE_H
#define LINE_H

/**
 * Vonal adatok
 */
typedef struct Line
{
	double x1;
	double y1;
	double x2;
	double y2;
} Line;

/**
 * Vonal adat bealitas
 */
void set_line_data(Line* line, double x1, double y1, double x2, double y2);

double get_x1(const Line* line);
double get_x2(const Line* line);
double get_y1(const Line* line);
double get_y2(const Line* line);

#endif // LINE_H
