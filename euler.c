
#include "euler.h"
#include "fonction.h"

void euler(int nt, double t[nt], double** Xk, double** Yk, double k, double Fs_m[nt], int lock){
    double dt;
    double* F;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        F = Fonc(Xk[i-1], Yk[i-1], k, Fs_m[i-1], 1, lock);
        Xk[i] = malloc(sizeof(double)*2);
        Xk[i][0]= Xk[i-1][0] + dt*F[0]; //x
        Xk[i][1] = Xk[i-1][1] + dt*F[1]; //Vx
        F = Fonc(Xk[i-1], Yk[i-1], k, Fs_m[i-1], 0, lock);
        Yk[i] = malloc(sizeof(double)*2);
        Yk[i][0] = Yk[i-1][0] + dt*F[0]; //y
        Yk[i][1] = Yk[i-1][1] + dt*F[1]; //Vy
        Fs_m[i] = (Xk[i][1]*Xk[i][1]*seconde(Xk[i][0]) + g)/sqrt(1+Yk[i][1]*Yk[i][1]); //Force réaction du support
        free(F); //pour l'appel de Fonc(...);
    }
}