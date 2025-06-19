#include <stdio.h>
#include <stdlib.h>

int mochila(int** dp, int* pesos, int* valores, int n, int cap){
    int ant, atual;
    for (int i = 0; i <= n; i++)
        for(int j = 0; j <= cap; j++){
            if (i == 0 || j == 0)// caso base, linha 0 e coluna 0 sao 0
                dp[i][j] = 0;
            else{
                if(pesos[i-1] <= j){ // se o peso do item for menor que a capacidade da mochila
                    ant = dp[i-1][j]; // valor anterior, sem o item
                    atual = valores[i-1] + dp[i-1][j - pesos[i-1]]; // valor do item +
                    // o valor dos outros itens (linha anterior [i-1]) com o peso que sobrou pra preencher[j-pesos[i-1])
                    if(atual > ant)
                        dp[i][j] = atual; // se a soma dos valores atual for maior que o anterior, colocar a atual
                    else
                        dp[i][j] = ant; // se nao, repetir
                }
                else
                    dp[i][j] = dp[i-1][j];; // se o peso do item for maior, nao incluir o item (repetir o anterior)
            }
        }
    return dp[n][cap];
}

int main(){
    int cap = 10;
    int pesos[] = {5, 4, 3, 6};
    int valores[] = {10, 7, 4, 12};
    int n = 4;

    printf("Problema da Mochila");
   
    int **dp = (int**)malloc((n+1)*sizeof(int*)); // aloca as linhas
    for(int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((cap+1)*sizeof(int)); // aloca as colunas
    
    int max = mochila(dp, pesos, valores, n, cap);

    printf("\nO valor maximo e %d!!\n\n", max);

return 0;
}