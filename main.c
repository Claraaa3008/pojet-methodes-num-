#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Inclusion des headers
#include "fonction.h" //la fonction étudiée est une fonction parabolique, de type y=x^2
#include "euler.h"
#include "RK4.h"

int main(int argc, char** argv){
    const int N = 2000;
    double t[N];
    t[0] = 0;
    double pas = (10)/(N-1 + 0.0); //!\ WIP
    for(int i = 1; i<N; i++){
        t[i] = t[i-1] + pas;
    }
    double** Xk = malloc(sizeof(double*)*N);
    double y[N];
    Xk[0] = malloc(sizeof(double)*2);
    Xk[0][0] = 0;
    Xk[0][1] = 5;
    FILE* stream;
    if(strcmp(argv[argc], "euler")==0){
        euler(N, t, Xk, y);
        stream = fopen("Mtn_euler.txt", "a");
    }
    else if(strcmp(argv[argc], "rk4")==0){
        RK4(N, t, Xk, y);
        stream = fopen("Mtn_rk4.txt", "a");
    }
    else{
        euler(N, t, Xk, y);
        stream = fopen("Mtn.txt", "a");
    }
    for(int i=0; i<N; i++){
        fprintf(stream, "%.12f\t%.12f\t%.12f\n", t[i], Xk[i][0], Xk[i][1]);
        free(Xk[i]);
    }
    free(Xk);
    fclose(stream);
}


