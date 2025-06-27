//SELECAO RECEITAS GULOSO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tarefa
{
    int L; //data limite
    int R; //receita
} tarefa;

void bubble(tarefa *tarefas, int n){
    tarefa aux;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++)
            if(tarefas[j].R < tarefas[j+1].R){
                aux = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = aux;
            }
}

void receita(tarefa *tarefas, int n){
    int limMax = 0;
    for(int i = 0; i < n; i++)
        if(limMax < tarefas[i].L)
            limMax = tarefas[i].L;

    int *solucao = (int*)malloc(limMax* sizeof(int));
    for(int i = 0; i < limMax; i++)
        solucao[i] = 0; // cria vetor de solucao vazio

    
    for(int i = 0; i < n; i++){
        if(solucao[tarefas[i].L-1] == 0){
            solucao[tarefas[i].L-1] = tarefas[i].R;
            printf("\nSelecionou (%d, %d)", tarefas[i].L, tarefas[i].R);
        }          
    }
    int result = 0;
    for(int i = 0; i < limMax; i++){
        printf("\n(%d) +", solucao[i]);
        result += solucao[i]; // cria vetor de solucao vazio
    }
    printf("Receita max: %d", result);

}
int main(){ // uma tarefa a cada dia de prazo. definir prazo maximo

tarefa *tarefas = (tarefa*)malloc(6* sizeof(tarefa));
tarefas[0].L = 1; tarefas[0].R = 7;
tarefas[1].L = 1; tarefas[1].R = 8;
tarefas[2].L = 2; tarefas[2].R = 4;
tarefas[3].L = 3; tarefas[3].R = 6;
tarefas[4].L = 3; tarefas[4].R = 5;
tarefas[5].L = 4; tarefas[5].R = 10;

bubble(tarefas, 6);
for(int i = 0; i < 6; i++)
    printf("(%d, %d) ", tarefas[i].L, tarefas[i].R);

receita(tarefas, 6);
}