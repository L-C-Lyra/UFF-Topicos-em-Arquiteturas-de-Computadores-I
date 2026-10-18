#include <stdio.h>
#include <math.h>
#include <mpi.h>

double f(double x) {
    double return_x = exp(x);
    return return_x;
}

int main(int argc, char** argv) {
    int meu_rank, num_procs, origem = 0, destino = 0, etiq = 3;
    double a = 0.0, b = 1.0, t_inicial, t_final, x, h, S = 0.0, total;
    long int n = 100000000;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    h = (b - a) / n;
    if (!meu_rank) {
        t_inicial = MPI_Wtime();
        S = (f(a) + f(b)) / 2.0;
    }
    for (x = a + h * (meu_rank + 1); x < b; x += num_procs * h) S += f(x);
    S *= h;
    if (!meu_rank) {
        total = S;
        for (origem = 1; origem < num_procs; origem++) {
            MPI_Recv(&S, 1, MPI_DOUBLE, origem, etiq, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total += S;
        }
    } else MPI_Send(&S, 1, MPI_DOUBLE, destino, etiq, MPI_COMM_WORLD);
    if (!meu_rank) {
        t_final = MPI_Wtime();
        printf("Foram gastos %3.1f segundos\n", t_final - t_inicial);
        printf("Com n = %ld trapezoides, a estimativa da integral de %lf a %lf = %lf\n", n, a, b, total);
    }
    MPI_Finalize();
    return 0;
}