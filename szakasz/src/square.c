#include "square.h"

#include <math.h>

void set_square_data(Square* square, double Sx1, double Sy1, double Sx2, double Sy2)
{
	square->Sx1 = Sx1;
	square->Sx2 = Sx2;
	square->Sy1 = Sy1;
	square->Sy2 = Sy2;
}

double get_Sx1(const Square* square){
	double x1 = square->Sx1;
	return x1;
}

double get_Sx2(const Square* square){
	double x2 = square->Sx2;
	return x2;
}

double get_Sy1(const Square* square){
	double y1 = square->Sy1;
	return y1;
}

double get_Sy2(const Square* square){
	double y2 = square->Sy2;
	return y2;
}
