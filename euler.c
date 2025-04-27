#include "euler.h"
#include "fonction.h"

void euler(int nt, double t[nt], double** Xk, double** Yk, double k, double Fs_m[nt], int lock){
    double dt;
    double* F;
    int décollage = 0;
    double vT;
    double prim;
    double frottement = k;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        F = Fonc(Xk[i-1], Yk[i-1], frottement, décollage, 1, lock);
        Xk[i] = malloc(sizeof(double)*2);
        Xk[i][0]= Xk[i-1][0] + dt*F[0]; //x
        Xk[i][1] = Xk[i-1][1] + dt*F[1]; //Vx
        Yk[i] = malloc(sizeof(double)*2);
        if(lock == 0 && décollage == 1){
            F = Fonc(Xk[i-1], Yk[i-1], frottement, décollage, 0, lock);
            Yk[i][0] = Yk[i-1][0] + dt*F[0]; //y
            Yk[i][1] = Yk[i-1][1] + dt*F[1]; //Vy
        }
        else{
            Yk[i][0] = igrec(Xk[i][0]); //y
            Yk[i][1] = prime(Xk[i][0])*Xk[i][1]; //Vy
        }
        if(Yk[i][0] <= igrec(Xk[i-1][0]) && décollage == 1){
            décollage = 0;
            frottement = k;
            prim = prime(Xk[i-1][0]);
            vT = (Xk[i-1][1] + prim*Yk[i-1][1]);
            Xk[i][1] = vT/(1+prim*prim);
            Yk[i][0] = igrec(Xk[i][0]);
            Yk[i][1] = prime(Xk[i][0])*Xk[i][1];
        }
        Fs_m[i] = (Xk[i][1]*Xk[i][1]*seconde(Xk[i][0]) + g)/sqrt(1+Yk[i][1]*Yk[i][1]); //Force réaction du support
        if(Fs_m[i] <= 0){ 
            décollage = 1;
            frottement = 0;
        }
        free(F); //pour l'appel de Fonc(...);
    }
}