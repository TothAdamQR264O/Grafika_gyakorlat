#ifndef SQUARE_H
#define SQUARE_H

/**
 * Négyzet adatok
 */
typedef struct Square
{
	double Sx1;
	double Sy1;
	double Sx2;
	double Sy2;
} Square;

/**
 * Vonal adat bealitas
 */
void set_square_data(Square* square, double Sx1, double Sy1, double Sx2, double Sy2);

double get_Sx1(const Square* square);
double get_Sx2(const Square* square);
double get_Sy1(const Square* square);
double get_Sy2(const Square* square);

#endif // Square_H
