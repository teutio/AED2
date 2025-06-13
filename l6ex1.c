#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int procura(int **piramide, int andar, int sala){




    
}


int main(){
    srand(time(NULL));
    int andares, salas,soma = 0, alvo = 17;
    scanf("%d", &andares);
    int **piramide = (int**)malloc(andares*sizeof(int*));
    // preenche a piramide
    for(int i = 0; i < andares; i++){
        salas = i + 1;
        piramide [i] = (int*)malloc(salas*sizeof(int));
        for(int j = 0; j < salas; j++)
            piramide [i][j] = rand()%10;
        for(int j = 0; j < salas; j++)
            printf("%d ", piramide[i][j]);
        printf("\n");
    }

return 0;
}