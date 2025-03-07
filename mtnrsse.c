#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//la fonctiom etudiee est une fonction parabolique, de type y=x^2

double g = 9.81; //accéleration de la pensanteur

double igrec(double x){
    return pow(x,2);
}

double prime(double x){
    return 2*x;
}

double seconde(double x){
    return 2;
}


double* Fonc(double** Xk, int i){
    double* F = malloc(2*sizeof(double));
    *F = Xk[i-1][1];
    double x = Xk[i-1][0];
    double Vx = Xk[i-1][1];
    double prim = prime(x);
    double sec = seconde(x);
    *(F+1) = -prim/(1+prim*prim)*(g + sec*Vx*Vx);
    /*dVx/dt = - y'/(1+y’^2) *  (g + y’’ * Vx^2)*/
    return F;
}

void euler_stylé(int nt, double t[nt], double** Xk){
    double dt;
    double* F;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        F = Fonc(Xk, i);
        Xk[i] = malloc(sizeof(double)*2);
        Xk[i][0]= Xk[i-1][0] + dt*F[0]; //x
        Xk[i][1] = Xk[i-1][1] + dt*F[1]; //xp
        free(F);
    }
}

int main(){
    const int N = 20000;
    double t[N];
    t[0] = 0;
    double pas = (10)/(N-1 + 0.0); //!\ WIP
    for(int i = 1; i<N; i++){
        t[i] = t[i-1] + pas;
    }
    double** Xk = malloc(sizeof(double*)*N);
    Xk[0] = malloc(sizeof(double)*2);
    Xk[0][0] = 0;
    Xk[0][1] = 5;
    euler_stylé(N, t, Xk);
    FILE* stream = fopen("Montagnes.txt", "a");
    for(int i=0; i<N; i++){
        fprintf(stream, "%.12f\t%.12f\t%.12f\n", t[i], Xk[i][0], Xk[i][1]);
        free(Xk[i]);
    }
    free(Xk);
    fclose(stream);
}


