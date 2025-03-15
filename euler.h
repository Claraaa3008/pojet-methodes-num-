//headers à revoir

void euler_stylé(int nt, double t[nt], double** Xk, double y[nt]){
    double dt;
    double* F;
    for(int i = 1; i<nt; i++){
        dt = t[i] - t[i-1];
        F = Fonc(Xk, i);
        Xk[i] = malloc(sizeof(double)*2);
        Xk[i][0]= Xk[i-1][0] + dt*F[0]; //x
        Xk[i][1] = Xk[i-1][1] + dt*F[1]; //xp
        y[i] = igrec(Xk[i][0]);
        free(F);
    }
}
