#include "RK4.h"
#include "fonction.h"

double* buffering(double* buffer, double* Xk, double* Ki, double Q, int i){
    if(i == 2){
        buffer[0] = Xk[0] + Ki[0]/Q;
        buffer[1] = Xk[0] + Ki[0]/Q;
    }
    else if(i == 3){
        buffer[0] = Xk[0] + Ki[0]/Q;
        buffer[1] = Xk[0] + Ki[0]/Q;
    }
    else{
        buffer[0] = Xk[0] + Ki[0]/Q;
        buffer[1] = Xk[0] + Ki[0]/Q;
    }
    return buffer;
}

double* dé_thé(double dt, double* K){
    K[0] *= dt;
    K[1] *= dt;
    return K;
}

void free_me(int n, ...){
    va_list Ki;
    va_start(Ki, n);
    double* K;
    for(int i=0; i<n; i++){
        K = va_arg(Ki,double*);
        free(K);
    }
    va_end(Ki);
}

void RK4(int nt, double t[nt], double** Xk, double y[nt]){
    double dt /*, td*/;
    double* K,* K2,* K3,* K4;
    double* buffer = malloc(sizeof(double)*2);
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        //td = (t[i] + t[i-1])/2.0;
        K = dé_thé(dt, Fonc(Xk[i-1]));
        K2 = dé_thé(dt,Fonc(buffering(buffer, Xk[i-1], K, 2.0, 2)));
        K3 = dé_thé(dt, Fonc(buffering(buffer, Xk[i-1], K2, 2.0, 3)));
        K4 = dé_thé(dt, Fonc(buffering(buffer, Xk[i-1], K3, 1, 4)));
        Xk[i][0] = Xk[i-1][0] + (K[0]+2*K2[0]+2*K3[0]+K4[0])/6; 
        Xk[i][1] = Xk[i-1][1] + (K[1]+2*K2[1]+2*K3[1]+K4[1])/6;
        y[i] = igrec(Xk[i][0]);
        free_me(4, K,K2, K3, K4);
    }
    free(buffer);
}
