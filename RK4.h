#ifndef RK4_H
#define RK4_h

#include <stdarg.h>
#include <stdlib.h>

void RK4(int nt, double t[nt], double** Xk, double y[nt][2]);
double* buffering(double* buffer, double* Xk, double* Ki, double Q);
double* dé_thé(double dt, double* K);
void free_me(int n, ...);

#endif