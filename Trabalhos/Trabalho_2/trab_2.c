#include <stdio.h>
#include <math.h>

#define EPSILON 1e-8
#define MAXIMO_INTERACOES 100
//Usei define pois meu compilador não aceitou const

typedef union {
    float x;
    struct {
        unsigned int f : 23;
        unsigned int E : 8;
        unsigned int s : 1;
    } bits;
} floatIEEE;

const double sqrt2 = 1.4142135623730950488016887;
const double invsqrt2 = 1.0 / sqrt2;
const int B = 127;

float newtonSqrt(float A) {
    if (A == 0) return 0;
    
    floatIEEE x0 = {A};
    double x, prev_x;
    
    // Estimativa inicial
    int e = x0.bits.E - B;
    x0.bits.f >>= 1;
    if (e & 1) {
        x0.bits.E = ((e+1) >> 1) + B;
        x = x0.x * invsqrt2;
    } else {
        x0.bits.E = (e >> 1) + B;
        x = x0.x;
    }
    
    // Newton-Raphson
    int iteracoes = 0;
    do {
        prev_x = x;
        x = 0.5 * (x + A/x);
        iteracoes++;
    } while (fabs(x - prev_x) > EPSILON * x && iteracoes < MAXIMO_INTERACOES);
    
    return (float)x;
}

int main() {
    printf("   A   | Newton-Raphson |    sqrt()    | Diferença\n");
    printf("-------|----------------|--------------|--------------\n");
    for (float A = 50.0f; A <= 70.0f; A += 1.0f) {
        float newtonResult = newtonSqrt(A);
        float sqrtResult = sqrtf(A);
        double dif = newtonResult - sqrtResult;
        printf("%6.2f | %14.10f | %12.10f | %10.10f\n", A, newtonResult, sqrtResult, dif);
    }
    return 0;
}