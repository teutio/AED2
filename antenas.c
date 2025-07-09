#include <stdio.h>
#include <stdlib.h>

// QUESTAO 2 P2 - METODO GULOSO

typedef struct antena{
    int a;
    int b;
    int c;
} antena;

void bubble(antena *antenas, int n){
    antena aux;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++){
            if(antenas[j].a > antenas[j+1].a){
                aux = antenas[j];
                antenas[j] = antenas[j+1]; //ordena por inicio da cobertura
                antenas[j+1] = aux;
            }
        }
}

void coberturaF(antena *antenas, int n, int L){
    int custo = 0; // custo atual
    int sol = 0; // n de antenas usadas
    int alcance = 0;
    int cobertura = 0;
    
    antena *solucao = (antena*)malloc(n*sizeof(antena));
    
    bubble(antenas, n); // ordena as antenas por LOCAL DE INICIO

    while(alcance < L){
        int melhorAntena = -1;
        for(int i = 0; i < n; i++){
            if(antenas[i].a <= cobertura && antenas[i].b > alcance){
                alcance = antenas[i].b;
                melhorAntena = i;
                }
            }

        cobertura = alcance;
        solucao[sol] = antenas[melhorAntena];
        sol++;
        custo += antenas[melhorAntena].c;
        }

    if(cobertura < L){
        printf("\n-- NAO HA SOLUCAO --\n");
        for(int i = 0; i < sol; i++)
            printf("antena %d: a = %d b = %d c = %d\n", i+1, solucao[i].a,solucao[i].b,solucao[i].c);
    }
    else{
        printf("\n-- SOLUCAO ENCONTRADA --\n");
        for(int i = 0; i < sol; i++)
            printf("antena %d: a = %d b = %d c = %d\n", i+1, solucao[i].a,solucao[i].b,solucao[i].c);
        printf("custo total: %d\n\n",custo);
    }
}


int main(){
    int L = 6;
    int n = 3;
    antena *antenas= (antena*)malloc(n*sizeof(antena));
    antenas[0].a = 0; antenas[0].b = 4; antenas[0].c = 5;
    antenas[1].a = 5; antenas[1].b = 9; antenas[1].c = 6;
    antenas[2].a = 7; antenas[2].b = 9; antenas[2].c = 7;

    coberturaF(antenas, n, L);
    return 0;
}