#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int r;
    int i;

    printf("Digite o numero inteiro (positivo ou negativo): \n");
    scanf("%d", &n);
    for (i = 31; i >= 0; i--){
        r = n >> i;
        
        if (r & 1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
    return 0;
}