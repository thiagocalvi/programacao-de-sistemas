#include <stdio.h>
#include <math.h>

float newtonSqrt(float A);

//União para manipular diretamente os bits do float
typedef union {
    float x;
    struct {
        unsigned int f : 23; // Mantissa
        unsigned int E : 8; // Expoente
        unsigned int s : 1; // Sinal
    } bits;
} floatIEEE;

const double EPSILON = 1e-8; // Precisão para o critério de parada
const double sqrt2 = 1.4142135623730950488016887; // Aproximação da raiz quadrada de 2
const double invsqrt2 = 1.0 / sqrt2; //  Inverso da raiz quadrada de 2
const int B = 127;  // Bias do expoente para float em IEEE-754

float newtonSqrt(float A) {
    if (A == 0) return 0; // Caso especial: raiz de 0 é 0
    
    floatIEEE x0 = {A};
    double x, prev_x;
    
    // Cálculo da estimativa inicial
    int e = x0.bits.E - B; // Obtém o expoente real
    x0.bits.f >>= 1; // Divide a mantissa por 2

    // Ajusta o expoente e a estimativa inicial baseado na paridade de e
    if (e & 1) { 
        // Se e é ímpar
        x0.bits.E = ((e+1) >> 1) + B;
        x = x0.x * invsqrt2;
    } else {
        // Se e é par
        x0.bits.E = (e >> 1) + B;
        x = x0.x;
    }
    
    // Newton-Raphson
    do {
        prev_x = x;
        x = 0.5 * (x + A/x); // Fórmula de Newton-Raphson para raiz quadrada
    } while (fabs(x - prev_x) > EPSILON * x);
    
    // Converte o resultado final para float
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