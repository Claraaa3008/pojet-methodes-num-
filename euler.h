#ifndef EULER_H
#define EULER_H

#include <stdlib.h>
#include <stdio.h>

void euler(int nt, double t[nt], double** Xk, double** Yk, double k, double Fs_m[nt], int lock);

#endif