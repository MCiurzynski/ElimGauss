#include "gauss.h"
#include <stdlib.h>
#include <math.h>

int eliminate(Matrix *a, Matrix *b){
	int i, w, k, j;
	double x, tmp;
	if (a->r != a->c || b->r != a->r || b->c != 1)
		return 1;
	for (k = 0; k < a->r - 1; k++) {
		for (w = k+1; w < a->r; w++) {
			for (i = w; i < a->r; i++) {
				if (abs(a->data[w][k]) < abs(a->data[i][k])) {
					for (j = 0; j < a->r; j++) {
						tmp = a->data[k][j];
						a->data[k][j] = a->data[i][j];
						a->data[i][j] = tmp;
					}
					tmp = b->data[k][0];
					b->data[k][0] = b->data[i][0];
					b->data[i][0] = tmp;
				} 
			}
			if( a->data[k][k] == 0 ) {
				return 1;
			}
			x = a->data[w][k] / a->data[k][k];
			for (i = k; i < a->r; i++) {
				a->data[w][i] -= a->data[k][i]*x;
			}
			b->data[w][0] -= b->data[k][0]*x;
		}
	}
	return 0;
}

