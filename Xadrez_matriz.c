#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 8 // Tamanho do tabuleiro


#define VAZIO  '.' //colocação das peças no tabuleiro
#define TORRE  'T'
#define BISPO  'B'
#define CAVALO 'C' 
#define RAINHA 'R'
#define REI    'K'  
#define PEAO   'P'

char tabuleiro[TAM][TAM]; //aqui é a definição do tabuleiro. Usei char para fazer a representação com letras


void iniciar_tabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }

    tabuleiro[0][0] = TORRE;
    tabuleiro[0][1] = CAVALO;
    tabuleiro[0][2] = BISPO;
    tabuleiro[0][3] = RAINHA;
    tabuleiro[0][4] = REI;
    tabuleiro[0][5] = BISPO;
    tabuleiro[0][6] = CAVALO;
    tabuleiro[0][7] = TORRE;

    //colocação dos peões usando for, vai percorrer as casas da segunda linha
    // e em cada coluna vai colocar um peão 
    //for (int j = 0; j < TAM; j++) {
    //    tabuleiro[1][j] = PEAO;
    //}
}

void imprimir_tabuleiro() {
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf(" %d ", j);
    }
    printf("\n\n");

    // linhas do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i); // número da linha
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                printf("[ ]"); // casa vazia
            } else {
                printf("[%c]", tabuleiro[i][j]); // peça
            }
        }
        printf("\n");
    }
    printf("\n");
}

int valido (int x, int y){ //isso aqui é pra verificar se a posição é válida, não pode escolher posições fora do tabuleiro 8x8
    return x >= 0 && x <TAM && y >=0 && y < TAM;
}

int mover_torre(int x1, int y1, int x2, int y2){ //verifica se escolheu a torre, a lógica é simples, a torre está na posição x,y
    if(tabuleiro[x1][y1] != TORRE){              // se escolher uma posição diferente da posição da torre, vai printar um erro no console
       printf("Não há uma torre nessa posição (%d,%d)\n", x1, y1);
       return 0;
    }
    
    if(!valido(x2,y2)){ //verifica se a posição ta dentro do tabuleiro, puxa a função ali de cima.
    printf("Posição de destino inválida.\n");
    return 0;
    }
    
    if(x1 != x2 && y1 != y2){ //verifica se escolheu uma posição válida pra torre. estou confuso com o operador lógico
        printf("A torre so se move em linha reta.\n");
        return 0;
    }

    if(x1 == x2 && y1 != y2){ //verifica se a posição (horizontal) ta bloquada usando o VAZIO **a sintaxe do c é meio estranha*
        int dy = (y2>y1) ? 1: -1;
        for(int y = y1 + dy; y != y2; y += dy){
            if(tabuleiro[x1][y] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x1, y);
                return 0;
            }
        }
    }

    if(y1 == y2 && x1 != x2){ //verifica se a posição (vertical) ta bloquada usando o VAZIO, igual a função de cima, só troquei x por y
        int dx = (x2>x1) ? 1: -1;
        for(int x = x1 + dx; x != x2; x += dx){
            if(tabuleiro[x][y1] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x, y1);
                return 0;
            }
        }
    }

    tabuleiro[x2][y2] = TORRE; //movimento propriamente dito
    tabuleiro[x1][y1] = VAZIO;
    printf("Torre movida para a posição (%d,%d)\n", x2, y2);
    return 1;
}

int mover_bispo(int x1, int y1, int x2, int y2){
    if(tabuleiro[x1][y1] != BISPO){              
       printf("Não há um bispo nessa posição (%d,%d)\n", x1, y1);
       return 0;
    }

    if(!valido(x2,y2)){                       //não foi uma boa ideia usar a palavra "valido" pra verificar se 
    printf("Posição de destino inválida.\n"); //o movimento ta dentro do tabuleiro,
    return 0;                                 //na próxima tentativa é melhor usar outra palavra
    }

    if(abs(x1 - x2) != abs(y1 - y2)){                  //Aqui precisei usar uma estrutura diferente pra validar o movimento do bispo
        printf("O Bispo só se move na diagonal.\n");   //infelizmente ainda estou confuso com o operador lógico
        return 0;                                      //pq não usar só o oposto do validador da torre? 
                                                       //resposta: o bispo tem restrições diferentes, a melhor opção é comparar o módulo
    }                                                  //das diferenças

    if(y1 == y2 && x1 != x2){ //verifica se a posição diagonal ta bloqueada
        int dx = (x2>x1) ? 1: -1;
        int dy = (y2>y1) ? 1: -1;
        int x = x1 + dx;
        int y = y1 + dy;
        while(x != x2 && y != y2){
            if(tabuleiro[x][y] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x, y1);
                return 0;
            }
            x += dx;
            y += dy;
        }
    }

    tabuleiro[x2][y2] = BISPO; //movimento propriamente dito
    tabuleiro[x1][y1] = VAZIO;
    printf("Bispo movido para a posição (%d,%d)\n", x2, y2);
    return 1;

}

int mover_rainha(int x1, int y1, int x2, int y2){
    if(tabuleiro[x1][y1] != RAINHA){ 
       printf("Não há uma Rainha nessa posição (%d,%d)\n", x1, y1);
       return 0;
    }

    if(!valido(x2,y2)){ //verifica se a posição ta dentro do tabuleiro, puxa a função ali de cima.
    printf("Posição de destino inválida.\n");
    return 0;
    }

    if(x1 == x2 && y1 != y2){ //verifica se a posição horizontal ta bloquada 
        int dy = (y2>y1) ? 1: -1;
        for(int y = y1 + dy; y != y2; y += dy){
            if(tabuleiro[x1][y] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x1, y);
                return 0;
            }
        }
    }
    
    if(y1 == y2 && x1 != x2){ //verifica se a posição vertical ta bloquada
        int dx = (x2>x1) ? 1: -1;
        for(int x = x1 + dx; x != x2; x += dx){
            if(tabuleiro[x][y1] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x, y1);
                return 0;
            }
        }
    }

    if(y1 == y2 && x1 != x2){ //verifica se a posição diagonal ta bloqueada
        int dx = (x2>x1) ? 1: -1;
        int dy = (y2>y1) ? 1: -1;
        int x = x1 + dx;
        int y = y1 + dy;
        while(x != x2 && y != y2){
            if(tabuleiro[x][y] != VAZIO){
                printf("Posição bloqueada (%d,%d).\n", x, y1);
                return 0;
            }
            x += dx;
            y += dy;
        }
    }

    tabuleiro[x2][y2] = RAINHA; //movimento propriamente dito
    tabuleiro[x1][y1] = VAZIO;
    printf("Rainha movido para a posição (%d,%d)\n", x2, y2);
    return 1;

}

//usar switch dentro de switch é a melhor opção? analisar isso.
//resposta: não é a melhor opção, ficou muito confuso, mas ainda não tenho certeza

void escolher_peça(){
    int peca;
    do{
    printf("Escolha a peça.\n");
    printf("0. Voltar ao menu principal.\n");
    printf("1. Torre.\n");
    printf("2. Bispo.\n");
    printf("3. Rainha.\n");
    scanf("%d", &peca);
    switch (peca){
    case 1:{
        int x1, y1, x2, y2;
        printf("Movimento da Torre.\n");
        printf("Digite a posição inicial da torre.\n");
        scanf("%d %d", &x1, &y1);
        printf("Digite a posição de destino.\n");
        scanf("%d %d", &x2, &y2);
       if(mover_torre(x1, y1, x2, y2)){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
                printf("Movimento realizado!\n");
        }else{
            printf("Falha no movimento.\n");
        }
        imprimir_tabuleiro();
    }
    break;
    case 2:{
        int x1, y1, x2, y2;
        printf("Movimento do Bispo.\n");
        printf("Digite a posição inicial do Bispo.\n");
        scanf("%d %d", &x1, &y1);
        printf("Digite a posição de destino.\n");
        scanf("%d %d", &x2, &y2);
        if(mover_bispo(x1, y1, x2, y2)){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
                printf("Movimento realizado.\n");
        }else{
            printf("Falha no movimento.\n");
        }
        imprimir_tabuleiro();
    }
    break;
    case 3:
        int x1, y1, x2, y2;
        printf("Movmento da Rainha.\n");
        printf("Digite a posição inicial da Rainha.\n");
        scanf("%d %d", &x1, &y1);
        printf("Digite a posição de destino.\n");
        scanf("%d %d", &x2, &y2);
        if(mover_rainha(x1, y1, x2, y2)){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
                printf("Movimento realizado.\n");
        }else{
            printf("Falha no movimento.\n");
        }
        imprimir_tabuleiro();
    case 0:
        printf("Voltando ao menu.\n");
    break;
    default:
    break;
    }
}while(peca != 0);
}

int main(){
    int xadrez;
    do{
    printf("XADREZ\n\n");
    printf("1. iniciar Xadrez\n");
    printf("2. Regras.\n");
    printf("3. Sair do jogo.\n");
    scanf("%d",&xadrez);
    switch (xadrez){
    case 1:
        iniciar_tabuleiro();
        imprimir_tabuleiro();
        escolher_peça();
        break;
    case 2:
        printf("Para mover a peça digite a posição x e y desse jeito --> 0 0 || 3 0\nSem vírgulas, apenas um espaço entre os números\n");
        printf("Pressione Enter para voltar ao menu\n");
        while (getchar() != '\n'); // nova solução para o problema do scanf consumir o enter, 
        getchar();                 //ao invés de usar dois getchar, usa essa estrutura
        break;
    case 3:
        printf("saindo...");
        break;
    default:
        break;
    }
}while(xadrez !=3); //ok, dei uma roubadinha usando o while aqui ao invés de usar no movimento das peças, mas ainda é um while né :)
return 0;           //sim, copiei a estrutura do projeto anterior
}
