#include <stdio.h>

int multiplicaDois(int valor);
void multiplicaDoisV2(int *valor);


void main(){
    int valor;
    scanf("%d", &valor);
    printf("Valor antes da função: %d \n", valor);
    multiplicaDois(&valor);
    printf("Valor antes da função: %d \n", valor);
    multiplicaDoisV2(&valor);

}

int multiplicaDois(int valor){
    valor = valor*2;
    printf("Valor dentro da função: %d \n", valor);
    return valor;
}

void multiplicaDoisV2(int *valor){
    *valor = *valor*2;
    printf("Valor dentro da função: %d \n", valor);
    printf("Valor dentro da função: %X \n", &valor);
}


