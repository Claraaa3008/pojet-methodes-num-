
#include "euler.h"
#include "fonction.h"

void euler(int nt, double t[nt], double** Xk, double y[nt][2], double k, double Fs_m[nt]){
    double dt;
    double* F;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        F = Fonc(Xk[i-1], k);
        Xk[i] = malloc(sizeof(double)*2);
        Xk[i][0]= Xk[i-1][0] + dt*F[0]; //x
        Xk[i][1] = Xk[i-1][1] + dt*F[1]; //Vx
        y[i][0] = igrec(Xk[i][0]);//y(x)
        y[i][1] = prime(Xk[i][0]);//y'(x)
        Fs_m[i] = (Xk[i][1]*Xk[i][1]*seconde(Xk[i][0]) + g)/sqrt(1+y[i][1]*y[i][1]); //Force réaction du support
        free(F);//pour le Fonc(Xk, i)
    }
}

/*void euler2(int nt, double t[nt], double** Xk, double y[nt]){
    printf("Not implemented yet, coming soon, date TBA\n");
}*/