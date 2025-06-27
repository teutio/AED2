//SELECAO DE TAREFAS GULOSO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tarefa
{
    int i;
    int f;
} tarefa;

void bubble(tarefa *tarefas, int n){
    tarefa aux;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++)
            if(tarefas[j].f > tarefas[j+1].f){
                aux = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = aux;
            }
}


void selecTarefas(tarefa *tarefas, int n){
    int fim = tarefas[0].f;
    for(int i = 1; i < n; i++)
        if (tarefas[i].i > fim){
            fim = tarefas[i].f;
            printf("(%d, %d) ", tarefas[i].i, tarefas[i].f);
        }
}

int main(){
    srand(time(NULL));
    int n;
    printf("Insira n: ");
    scanf("%d", &n);
    tarefa *tarefas = (tarefa*)malloc(n* sizeof(tarefa));
    for(int i = 0; i < n; i++){
        tarefas[i].i = i + rand()%6+1;
        tarefas[i].f = rand()%4+tarefas[i].i;
    }
    bubble(tarefas, n);
    for(int i = 0; i < n; i++)
        printf("(%d, %d) ", tarefas[i].i, tarefas[i].f);
    
    printf("\n\nSolucao: ");

    selecTarefas(tarefas, n);
}