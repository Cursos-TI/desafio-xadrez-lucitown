#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  


void torre() {
    int movimento_torre; //ok, acredito que não fiz exatamente como era pra ser a torre. Mas acho que no pedido não tava explicito
    do{                  //que eu deveria fazer o movimento usando as palavras "esquerda". Bom, corrigirei isso caso necessário, mas 
        printf("0.voltar ao menu principal.\n"); //ficou interessante do jeito que tá.
        printf("1. Mover na horizontal.\n");
        printf("2. Mover na vertical.\n");
        scanf("%d", &movimento_torre);
        switch (movimento_torre) {
        case 1: {
            int i, width = 5;
                for (i = 0; i < width; i++) {
                    system("cls"); //apagar a posição anterior  
                    printf("Direita.\n");
                    for (int j = 0; j < i; j++) {  
                        printf("\n");
                    }
                    printf("*\n");
                    usleep(300000); // isso aqui é pra não fazer o movimento muito rápido
                }
        break;
        }        
        case 2:{
            int i, height = 5;
                for (i=0; i<height; i++){
                    printf("Baixo.\n");
                    system("cls");
                    for (int j = 0; j < i;j++){
                        printf("\n");
                    }
                    printf("*\n");
                    usleep(300000);
                }
        break;
        }
        case 0:                
            printf("Voltando ao menu principal...\n");
            break;
        default:
        break;
    }
    }while (movimento_torre != 0);
    }


void bispo(){
    int movimento_bispo;
    do{
        printf("0.voltar ao menu principal.\n");
        printf("1. Mover na diagonal.\n");
        scanf("%d", &movimento_bispo);
        switch (movimento_bispo){
        case 1: {
                int i = 1;
                while (i <= 5) { //aqui ele vai apenar imprimir o nome do movimento 
                    printf("bispo %d: Cima, Direita\n", i);
                    i++;
                    usleep(300000); 
                }
                break;
            }
        default:
        break;
    }
    }while(movimento_bispo != 0);
}

void rainha() {
    int i, tamanho = 8;  // Tamanho do movimento (tabuleiro de 8 casas para exemplo)

    // Imprime a linha em branco para separar do movimento das outras peças
    printf("\n");

    // Movimento horizontal para a esquerda (sem quebra de linha)
    for (i = 0; i < tamanho; i++) {
        system("cls");
        for (int j = 0; j < tamanho - i - 1; j++) {  // Criando espaços antes do asterisco
            printf(" ");
        }
        printf("*");  // A peça se move para a esquerda
        usleep(300000);
    }
    //como não foi pedido essa parte aqui, vou comentar ela
    /* 
    // Movimento horizontal (direita)
    for (i = 0; i < tamanho; i++) {
        system("cls");
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
        usleep(100000);
    }

    // Movimento vertical (baixo)
    for (i = 0; i < tamanho; i++) {
        system("cls");
        for (int j = 0; j < tamanho; j++) {
            if (j == i) {
                printf("*\n");
            } else {
                printf(" ");
            }
        }
        usleep(100000);
    }

    // Movimento diagonal (diagonal: Cima, Direita)
    for (i = 0; i < tamanho; i++) {
        system("cls");
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
        usleep(100000);
    }

    // Movimento diagonal (diagonal: Baixo, Esquerda)
    for (i = 0; i < tamanho; i++) {
        system("cls");
        for (int j = tamanho - 1; j >= i; j--) {
            printf(" ");
        }
        printf("*\n");
        usleep(100000);
    }
    */
}


void cavalo() {
    int i, movimentos_horizontais = 1, movimentos_verticais = 2;
    
    // Imprime a linha em branco para separar do movimento das outras peças
    printf("\n"); //acho que imprimir vários "_" poderia separar melhor visualmente, vou testar isso no futuro, inclusive usando algum for/while/do-while

    // Loop aninhado: primeiro o movimento horizontal e depois o vertical
    for (i = 0; i < movimentos_horizontais; i++) {
        // Movimento horizontal: Esquerda
        printf("Esquerda\n");

        // Loop interno (do-while) para o movimento vertical: Baixo
        int j = 0;
        do {
            printf("Baixo\n");
            j++;
        } while (j < movimentos_verticais);
    }
}


int main() {
    int xadrez;
    do{
        printf("Menu\n");
        printf("1.Torre\n");
        printf("2.Bispo\n");
        printf("3.Rainha\n");
        printf("4.Cavalo\n");
        printf("Escolha uma opção\n");
        scanf("%d", &xadrez);
        switch (xadrez){

        case 1:
        torre();
            break;
        
        case 2:
        bispo();
            break;
        
        case 3:
        rainha();
            break;

        case 4:
        cavalo();
            break;

        case 5:
        printf("Saindo...");
            break;

        default:
        printf("Opção inválida.\n");
        }
        
    }while(xadrez !=5);
return 0;
}

    
