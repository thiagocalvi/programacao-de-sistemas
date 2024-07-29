#include <stdio.h>

void main(){
    float* p;
    float a = 2;
    float b = a;

    p = &a;
    printf("Endereço de 'a' = %p\n", p);

    p = &b;
    printf("Endereço de 'b' = %p\n", p);

    printf("Valor de a = %f\n", a);
    printf("Valor de b = %f\n", b);


    printf("Valor de *p = %f\n", *p);
    printf("Tamanho de um float = %d (bytes)\n", sizeof(float));

    a = 5*b;
    p = &b;
    printf("Valor a: %f\n", a);
    printf("Valor b: %f\n", b);
    printf("Valor de *p = %f\n", *p);



}