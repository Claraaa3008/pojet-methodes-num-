#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Inclusion des headers
#include "fonction.h" //la fonction étudiée est une fonction parabolique, de type y=x^2
#include "euler.h"
#include "RK4.h"

int main(int argc, char** argv){
    const int N = 20000;
    int param[2] = {-1, -1};
    double k;
    double t[N];
    t[0] = 0;
    double pas = (1)/(N-1 + 0.0); //!\ WIP
    for(int i = 1; i<N; i++){
        t[i] = t[i-1] + pas;
    }
        for(int arg = 1; arg<argc; arg++){
        if(strcmp(argv[arg], "avec") == 0){
            param[0] = 1;
        }
        else if(strcmp(argv[arg], "sans") == 0){
            param[0] = 0;
        }
        else if(strcmp(argv[arg], "euler") == 0){
            param[1] = 0;
        }
        else if(strcmp(argv[arg], "rk4") == 0){
            param[1] = 1;
        }
    }
    if(param[0] == -1 || param[1] == -1){
        printf("Il manque un argument à l'execution correcte du programme, il faut specifier la méthode euler ou rk4 ainsi que avec ou sans  frottement");
        return 0;
    }
    double** Xk = malloc(sizeof(double*)*N);
    double y[N][2];
    double Fs_m[N];
    Xk[0] = malloc(sizeof(double)*2);
    Xk[0][0] = 0;
    Xk[0][1] = 5;
    y[0][0] = igrec(Xk[0][0]);
    y[0][1] = prime(Xk[0][0]);
    Fs_m[0] = (Xk[0][1]*Xk[0][1]*seconde(Xk[0][0]) + g)/sqrt(1+y[0][1]*y[0][1]);
    FILE* stream;
    for(int i = 0; i<2; i++){
        if(param[0] == 1){
            k = pow(10,-3)/0.08;
            //k correspond au quotient de coefficient acier/acier µ(10^-3) par le rayon de la bille (8cm)
        }
        else{
            k = 0;
            //Pas de frottement
        }
        if(param[1] == 0){
            euler(N, t, Xk, y, k, Fs_m);
        }
        else{
            RK4(N, t, Xk, y, k, Fs_m);
        }
    }
    if(access("Mtn.txt", F_OK) == 0){
        remove("Mtn.txt");
    }
    stream = fopen("Mtn.txt", "a");
    for(int i=0; i<N; i++){
        fprintf(stream, "%.12f\t%.12f\t%.12f\t%.12f\t%.12f\t%.12f\n", t[i], Xk[i][0], Xk[i][1], y[i][0], y[i][1], Fs_m[i]);
        free(Xk[i]);
    }
    free(Xk);
    fclose(stream);
    return 1;
}


