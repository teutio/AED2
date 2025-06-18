#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sol = 0;

void impressao(int* valores, int andares){
    printf("Solucao %d: ", sol);
    for(int i = 0; i < andares; i++)
        if(valores[i] != 0)
            printf ("%d ", valores[i]);
    printf("\n");
}

void procura(int **piramide, int andar, int sala, int S, int valores[], int andares, int soma){

    soma += piramide[andar][sala];
    valores[andar] = piramide[andar][sala];

    if(soma == S){ //                  se a soma for S, imprime a solucao
        sol++;
        impressao(valores, andares); 
    }
    
    if(andar == andares-1 || soma > S) // se estiver na base ou a soma passar de S, poda a arvore
        return;

    if(soma + piramide[andar+1][sala] <= S) //                           explora pra esquerda
        procura(piramide, andar+1, sala, S, valores, andares, soma);

    if(soma + piramide[andar+1][sala+1] <= S) //                         explora pra direita
        procura(piramide, andar+1, sala+1, S, valores, andares, soma);

     valores[andar] = 0; //     zera o valor
}


int main(){
    srand(time(NULL));
    int andares, salas;
    printf("Insira o No de Andares: ");
    scanf("%d", &andares);
    printf("\nPiramide:\n");

    int *valores = (int*)malloc(andares* sizeof(int));
    for (int i = 0; i < andares; i++)
        valores[i] = 0;

    int S = andares*2;

    int **piramide = (int**)malloc(andares*sizeof(int*)); // aloca os andares

    for(int i = 0; i < andares; i++){
        salas = i + 1;
        piramide [i] = (int*)malloc(salas*sizeof(int)); // aloca cada sala
        for(int j = 0; j < salas; j++)
            piramide [i][j] = rand()%andares+1;
        for(int j = 0; j < salas; j++)
            printf("%d ", piramide[i][j]);
        printf("\n");
    }

    printf("Procurando a chave de valor %d...\n", S);

    procura(piramide, 0, 0, S, valores, andares, 0);

    if(sol == 0)
        printf("\nNenhuma solucao encontrada!!\n\n");
    else
        printf("Numero de Solucoes: %d\n", sol);

return 0;
}