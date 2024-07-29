#include <stdio.h>

void main(){

    int* iptr;
    int a = -8;

    iptr = &a; // Atribui o endereço de memória da variavel 'a' para a variavel 'iptr'

    printf("\nValor de iptr = %p", iptr); //Valor que a variavel 'iptr' armazena
    printf("\nEndereço de a = %p (hexadecimal)", &a); //Endereço de memória da variavel 'a' em hexadecimal
    printf("\nEndereço de a = %lld (decimal)", &a); //Endereço de memória da viriavel 'a' no formato inteiro
    printf("\nValor armazenado em a = %d", a); //Valor que 'a' armazana
    printf("\nValor apontado por iptr (*iptr) = %d", *iptr); //Valor que está armazenado no endereço de memória que iptr guarda
    printf("\nTamanho do inteiro [sizeof(int)] = %d (bytes)", sizeof(int));
    printf("\nTamanho do ponteiro para inteiro [sizeof(int*)] = %d (bytes)", sizeof(int*));
    printf("\nTamanho do float [sizeof(float)] = %d (bytes)", sizeof(float));
    printf("\nTamanho do ponteiro para float [sizeof(float*)] = %d (bytes)", sizeof(float*));
    
    printf("\nValor armazenado em a = %d", a);
    printf("\nValor apontado por iptr (*iptr) = %d", *iptr);

    a = a/2;
    printf("\nValor armazenado em a = %d", a);
    printf("\nValor apontado por iptr (*iptr) = %d", *iptr);
    
    *iptr = -4*(*iptr); 
    printf("\nValor armazenado em a = %d", a);
    printf("\nValor apontado por iptr (*iptr) = %d", *iptr);
    
    printf("\n\n");

}