
#include "RK4.h"

void RK4(int nt, double t[nt], double y0, double y[nt]){
    double dt, td;
    double k, k2, k3, k4;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        td = (t[i] + t[i-1])/2.0;
        k = dt * f(y[i-1], t[i-1]);
        k2 = dt * f(y[i-1] + k/2.0, td);
        k3 = dt * f(y[i-1] + k2/2.0, td);
        k4 = dt * f(y[i-1] + k3, t[i]);
        y[i] =  y[i-1] + (k+2*k2+2*k3+k4)/6; 
    }
}
