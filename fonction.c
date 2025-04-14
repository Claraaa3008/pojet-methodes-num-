#include "fonction.h"

double g = 9.81; //accéleration de la pensanteur
double k = 0.57; //coeff de frottement cinétique

double igrec(double x){
    return pow(x,2);
}

double prime(double x){
    return 2*x;
}

double seconde(double x){
    x += 1; //pour tromper -Werror
    return 2;
}

double* Fonc(double* Xk){
    double* F = malloc(2*sizeof(double));
    *F = Xk[1];
    double x = Xk[0];
    double Vx = Xk[1];
    double prim = prime(x);
    double sec = seconde(x);
    *(F+1) = -prim/(1+prim*prim)*(g + sec*Vx*Vx);
    /*dVx/dt = - y'/(1+y’^2) *  (g + y’’ * Vx^2)*/
    return F;

double* FoncFrott(double* Xk){
    double* F = malloc(2*sizeof(double));
    *F = Xk[1];
    double x = Xk[0];
    double Vx = Xk[1];
    double prim = prime(x);
    double sec = seconde(x);
    *(F+1) = -prim -k/(1+prim*prim)*(g + sec*Vx*Vx);
    /*dVx/dt = - y'-k/(1+y’^2) *  (g + y’’ * Vx^2)*/
    return F;
}
