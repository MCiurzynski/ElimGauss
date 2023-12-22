#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *a, Matrix *b){
	int i, w, k;
	double x;
	if (a->r != a->c || b->r != a->r || b->c != 1)
		return 1;
	for (k = 0; k < a->r - 1; k++) {
		for (w = k+1; w < a->r; w++){
			x = a->data[w][k] / a->data[k][k];
			for (i = k; i < a->r; i++) {
				a->data[w][i] -= a->data[k][i]*x;
			}
			b->data[w][0] -= b->data[k][0]*x;
		}
	}
	return 0;
}

