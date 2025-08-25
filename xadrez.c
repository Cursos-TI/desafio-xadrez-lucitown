#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  


void torreHorizontal(int movimento, int casas) {
    if (casas == 0) return; //condição de parada da função
    printf("Direita\n");  // Movimento para a direita
    torreHorizontal(movimento, casas - 1);  // Chamada recursiva para o próximo movimento
}

void torreVertical(int movimento, int casas) {
    if (casas == 0) return;
    printf("Baixo\n");  // Movimento para baixo
    torreVertical(movimento, casas - 1);  // Chamada recursiva para o próximo movimento
}

void torre() {
    int movimento_torre, casas;
    printf("Digite o número de casas para mover a Torre: ");
    scanf("%d", &casas);
    printf("1. Mover na horizontal.\n");
    printf("2. Mover na vertical.\n");
    scanf("%d", &movimento_torre);
    
    switch (movimento_torre) {
    case 1:
        torreHorizontal(movimento_torre, casas);
        break;
    case 2:
        torreVertical(movimento_torre, casas);
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }
}

void bispoVertical(int casas); //declaração da função recursiva
void bispoHorizontal(int casas);

void bispo() {
    int casas;
    printf("Digite o número de casas para mover o Bispo: ");
    scanf("%d", &casas);
    bispoVertical(casas);  // Inicia o movimento diagonal com a função recursiva
}

// Função recursiva para o movimento vertical
void bispoVertical(int casas) {
    if (casas == 0) return;
    printf("Cima\n");  // Movimento para cima (diagonal)
    bispoHorizontal(casas - 1);  // Chamada recursiva para o movimento horizontal
}

// Função recursiva para o movimento horizontal
void bispoHorizontal(int casas) {
    if (casas == 0) return;
    printf("Direita\n");  // Movimento para a direita (diagonal)
    bispoVertical(casas - 1);  // Chamada recursiva para o movimento vertical
}


void rainhaHorizontal(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");  // Movimento para a esquerda
    rainhaHorizontal(casas - 1);  // Chamada recursiva para o próximo movimento
}

void rainhaVertical(int casas) {
    if (casas == 0) return;
    printf("Baixo\n");  // Movimento para baixo
    rainhaVertical(casas - 1);  // Chamada recursiva para o próximo movimento
}

void rainha() {
    int movimento_rainha, casas;
    printf("Digite o número de casas para mover a Rainha: ");
    scanf("%d", &casas);
    printf("1. Mover na horizontal.\n");
    printf("2. Mover na vertical.\n");
    scanf("%d", &movimento_rainha);
    
    switch (movimento_rainha) {
    case 1:
        rainhaHorizontal(casas);  // Movimento horizontal para a esquerda
        break;
    case 2:
        rainhaVertical(casas);  // Movimento vertical para baixo
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }
}

void cavalo() {
    int i, j;
    int movimentos_verticais = 2;
    int movimentos_horizontais = 1;

    // Imprimir o movimento do Cavalo
    for (i = 0; i < movimentos_verticais; i++) {
        for (j = 0; j < movimentos_horizontais; j++) {
            if (i == 0) {
                printf("Cima\n");  // Movimento para cima
            } else {
                printf("Direita\n");  // Movimento para a direita
            }
        }
    }
}

int main() {
    int xadrez;
    do{
        printf("Menu\n");
        printf("1. Torre\n");
        printf("2. Bispo\n");
        printf("3. Rainha\n");
        printf("4. Cavalo\n");
        printf("5. Sair do jogo");
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

    
