#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    double return_x = exp(x);
    return return_x;
}

int main(int argc, char** argv) {
    double a = 0.0, b = 1.0, t_inicial, t_final, h, S;
    long int n = 8000000000;
    h = (b - a) / n;
    S = (f(a) + f(b)) / 2.0;
    t_inicial = omp_get_wtime();

#pragma omp parallel for default(none) firstprivate(n, a, h) reduction(+:S) schedule(static) num_threads(4)
    for (long int i = 1; i < n - 1; i++) S += f(a + i * h);
    S *= h;

    t_final = omp_get_wtime();
    printf("Foram gastos %3.1f segundos\n", t_final - t_inicial);
    printf("Com n = %ld trapezoides, a estimativa da integral de %lf até %lf é %lf\n", n, a, b, S);
    return 0;
}