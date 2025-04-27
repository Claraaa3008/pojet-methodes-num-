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

double* Fonc(double* Xk, double* Yk, double k, double Fs_m, int axe_x, int lock){
    double* F = malloc(2*sizeof(double));
    if (axe_x==1){
        *F = Xk[1];
        double x = Xk[0];
        double Vx = Xk[1];
        double prim = prime(x);
        double sec = seconde(x);
        if(lock == 0 && Fs_m <= 0){
            *(F+1) = 0;
            /*dVx/dt nulle quand la bille est dans les airs*/
        }
        else{
            *(F+1) = -(prim + k)/(1+prim*prim)*(g + sec*Vx*Vx);
            /*dVx/dt = - (y'+ k)/(1+y’^2) *  (g + y’’ * Vx^2)*/
        }
    }
    else{
        *F = Yk[1];
        //double y = Yk[0];
        //double Vy = Yk[1];
        double prim = prime(Xk[0]);
        //double sec = seconde(Xk[0]);
        if(lock == 0 && Fs_m <= 0){
            *(F+1) = -g;
            /*dVy/dt proportionnelle à l'accélération de la pensanteur quand la bille est dans les airs*/
        }
        else{
            *(F+1) = Fs_m*(1-prim*k)/sqrt(1+prim*prim) - g;
            //*(F+1) = (1-prim*k)/(1+prim*prim)*(g*prim + sec*Vy*Vy/(prim*prim)) - g;
            /*dVx/dt = - (y'+ k)/(1+y’^2) *  (g + y’’ * Vx^2)*/
        }
    }
    return F;
}