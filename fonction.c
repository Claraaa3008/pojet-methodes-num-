#include "fonction.h"

double g = 9.81; //accéleration de la pensanteur

double igrec(double x){
    return sin(x);
}

double prime(double x){
    return cos(x);
}

double seconde(double x){
    //x +=1; //pour tromper -Werror
    return -sin(x);
}

//Collision à gerer pour l'atterissage

double* Fonc(double* Xk, double* Yk, double k, int décollage, int axe_x, int lock){
    double* F = malloc(2*sizeof(double));
    double x = Xk[0];
    double Vx = Xk[1];
    double prim = prime(x);
    double sec = seconde(x);
    if (axe_x==1){
        *F = Xk[1];
        if(lock == 0 && décollage == 1){
            *(F+1) = 0;
            /*dVx/dt nulle quand la bille est dans les airs*/
        }
        else{
            *(F+1) = -(prim + k)/(1+prim*prim)*(g + sec*Vx*Vx);
            /*dVx/dt = - (y'+ k)/(1+y’²) *  (g + y’’ * Vx²)*/
        }
    }
    else{
        *F = Yk[1];
        *(F+1) = -g;
        /*dVy/dt proportionnelle à l'accélération de la pensanteur quand la bille est dans les airs*/
    }
    return F;
}