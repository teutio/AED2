#include <stdio.h>
#include <stdlib.h>


int sol = 0;


void impressao(int labSol[], int k){
    printf("\nSol No %d:\n", sol);
    for(int i = 0; i < k; i++)
        printf("    Laboratorio %d\n", labSol[i]);   
    printf("\n");
}


int verifica(int labSol[], int compat[], int itens){
    for(int i = 0; i < itens; i ++)
        if(compat[ labSol[i] ])
            return 0;

    return 1;
}


void laboratorios(int n, int k, int **mat, int labSol[], int itens, int inicio){
    if(itens == k){
        sol++;
        impressao(labSol, k);
        return;
    }

    for(int i = inicio; i < n; i++){ // pra cada laboratorio
        if(verifica(labSol, mat[i], itens)){

            labSol[itens] = i; // adiciona o item

            laboratorios(n, k, mat, labSol, itens+1, i+1); // chamada recursiva, chama comecando do proximo lab

            labSol[itens] = -1; // remove o item
        }
    }
}


int main(){
    int n = 5;
    int k = 3;

    int **mat = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
        mat [i] = (int*)malloc(n*sizeof(int)); // aloca cada coluna
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j)
                mat[i][j] = 0;
            else{
                int valor = rand()%2;
                mat[j][i] = valor;
                mat[i][j] = valor;
            }
        }
        for(int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    int *labSol = (int*)malloc(k*sizeof(int));
    for(int i = 0; i < k; i++)
        labSol[i] = -1;

    laboratorios(n, k, mat, labSol, 0, 0);
    
}