#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  


void torre() {
    int i, width = 20;
        for (i = 0; i < width; i++) {
            system("cls"); //apagar a posição anterior  
            for (int j = 0; j < i; j++) {  
                printf(" ");
            }
            printf("*\n");
            usleep(10000);
        }
    }
void bispo(){
    int i, width = 20;
    for (i = 0; i < width; i++) {
        system("cls"); //apagar a posição anterior  
        for (int j = 0; j < i; j++) {  
            printf(" ");
        }
        printf("*\n");
        usleep(10000);
        }

}


void rainha(){
    int i, width = 20;
        for (i = 0; i < width; i++) {
            system("cls"); //apagar a posição anterior  
            for (int j = 0; j < i; j++) {  
                printf(" ");
            }
            printf("*\n");
            usleep(10000);
        }

}
//copiei a função da torre e apliquei na rainha e no bispo apenas pra não gerar erro de compilação
int main() {
    int xadrez;
    do{
        printf("Menu\n");
        printf("1.Torre\n");
        printf("2.Bispo\n");
        printf("3.Rainha\n");
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
        printf("Saindo...");
            break;

        default:
        printf("Opção inválida.\n");
        }
        
    }while(xadrez !=4);
return 0;
}

    
