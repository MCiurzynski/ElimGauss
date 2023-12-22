#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *a, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				int w, k;
				double m;
				for (w = a->r - 1; w >= 0; w--) {
					m = 0;
					for (k = w + 1; k < a->r; k++)
						m += a->data[w][k] * x->data[k][0];
					x->data[w][0] = (b->data[w][0] - m) / (a->data[w][w]);
				}

				return 0;
}


