#include "point.h"

void point(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}