#include <stdio.h>
#include <stdlib.h>

int main() {
    int tabuleiro [8][8] = {0}; //tamanho do tabuleiro

    for(int i = 0; i < 8; i++){
            for(int j=0; j<8; j++){
                if (tabuleiro[i][j] == 0)
                    printf("[ ]");
            }
        printf("\n");
        }
    return 0;
}