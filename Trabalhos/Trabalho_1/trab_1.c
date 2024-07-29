#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaTabalaPrimos(unsigned int *tabelaPrimos);
int ehPrime(unsigned int *tabelaPrimos, int num);
void imprimeTabalaPrimos(unsigned int *primeTable, int max);


const int MAXIMO = 6400;
const int BITS_POR_INT = 32;


void criaTabalaPrimos(unsigned int *tabelaPrimos) {
    // Cria a tabela de primos com todas as posições como 1 (todos os numeros marcados como primo)
    memset(tabelaPrimos, 0xFF, (MAXIMO / BITS_POR_INT + 1) * sizeof(unsigned int));

    // Verifica os números de 2 ate a raiz quadrada de MAXIMO
    for (int i = 2; i * i <= MAXIMO; i++) {
        // Verifica se i eh primo (se o bit correspondente ainda está marcado como 1)
        if ((tabelaPrimos[i / BITS_POR_INT] & (1U << (i % BITS_POR_INT))) != 0){
            // Se i for primo, marca todos os seus multiplos como não primos
            for (int j = i * i; j <= MAXIMO; j += i) {
                // Calcula o indice do unsigned int e a posicao do bit para j
                // Cria uma mascara para marcar j como nao-primo (seta o bit para 0)
                // Aplica a mascara para marcar j como nao-primo
                tabelaPrimos[j / BITS_POR_INT] &= ~(1U << (j % BITS_POR_INT));
            }
        }
    }
}

// Consulta na tabela de primos se o numemro informado eh primo
int ehPrime(unsigned int *tabelaPrimos, int num){
    if (num < 2 || num > MAXIMO) return 0;
    return (tabelaPrimos[num / BITS_POR_INT] & (1U << (num % BITS_POR_INT))) != 0;
}

// Imprime a tabela de primos
void imprimeTabalaPrimos(unsigned int *primeTable, int max) {
    printf("Números primos até %d:\n", max);
    for (int i = 2; i <= max; i++) {
        if (ehPrime(primeTable, i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int main(){
    unsigned int *tabelaPrimos = (unsigned int *)malloc((MAXIMO / BITS_POR_INT + 1) * sizeof(unsigned int));
    
    if (tabelaPrimos == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    criaTabalaPrimos(tabelaPrimos);
    imprimeTabalaPrimos(tabelaPrimos, MAXIMO);

    int num;
    printf("Digite um número entre 0 e 6400 para verificar se é primo: ");
    scanf("%d", &num);
    
    if(num < 0 || num > MAXIMO){
        printf("Número informado está fora do intervalo permitido \n");
    } else{
        if(ehPrime(tabelaPrimos, num)) {
            printf("%d é primo.\n", num);
        } else{
            printf("%d não é primo.\n", num);
        }
    }

    free(tabelaPrimos);
    return 0;
}