// Test the fsave-optimization-record option and tha tthe file isn't empty
// Make sure that https://bugs.llvm.org/show_bug.cgi?id=51642
// doesn't happen again
//
// RUN: mkdir -p %t/test && cd %t/test
// RUN: %clang -S -O2 -fsave-optimization-record -emit-llvm %s -o save-optimization-record.c.opt
// RUN: test -s save-optimization-record.c.opt.yaml
// REQUIRES: clang

// marking it as failing util the bug is addressed

#define N 1536
float A[N][N];
float B[N][N];
float C[N][N];

void init_array()
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = (1+(i*j)%1024)/2.0;
            B[i][j] = (1+(i*j)%1024)/2.0;
        }
    }
}

int main()
{
    int i, j, k;
    double t_start, t_end;
    init_array();
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
    return 0;
}
