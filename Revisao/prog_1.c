#include <stdio.h>
#include <string.h>

void desenharMenu();
int controleMenu();
void mensagemErro(int errorCode , char *mensagem);

void desenharMenu(){
    printf("******* Menu principal *******\n");
    printf("*        1) Cadastro         *\n");
    printf("*        2) Atualizar        *\n");
    printf("*        3) Exclusão         *\n");
    printf("*        4) Consulta         *\n");
    printf("*        5) Sair             *\n");
    printf("******************************\n");
    printf("Selecione uma opção: ");
}

int controleMenu(){
    int opcao;
    scanf("%d", &opcao);

    if((opcao >= 1) && (opcao <= 5)){

        return 1;
    }
    
    return 0;
}

void mensagemErro(int errorCode, char *mensagem){
    switch (errorCode)
    {
    case 0:
        mensagem = "Opcão invalida! Digite uma opção valida\n";
        break;
    
    default:
        break;
    }
}

void main (){
    char str[240] = {' '}; 
    char *mensagem = str;

    desenharMenu();
    mensagemErro(controleMenu(), mensagem);
    
}