#ifndef FONCTION_H
#define FONCTION_H

#include <math.h>
#include <stdlib.h>

extern double g;

double igrec(double x);

double prime(double x);

double seconde(double x);

double* Fonc(double* Xk, double* Yk, double k, double Fs_m, int axe_x, int lock);

#endif