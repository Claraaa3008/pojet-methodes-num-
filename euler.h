#ifndef EULER_H
#define EULER_H

#include <stdlib.h>
#include <stdio.h>

void euler(int nt, double t[nt], double** Xk, double y[nt]);
void euler2(int nt, double t[nt], double** Xk, double y[nt]);

#endif