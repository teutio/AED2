#include <stdio.h>
#include <stdlib.h>


int mochila(int **dp, int pesos[], int valores[], int n, int cap){
    int ant, atual;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= cap; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                if(pesos[i-1] <= j){ // peso atual menor que a cap
                    ant = dp[i-1][j]; // valor anterior
                    atual = valores[i-1] + dp[i-1][j - pesos[i-1]]; // valor do item atual + valor com os itens anteriores com o peso que sobrou
                    dp[i][j] = (ant > atual) ? ant : atual;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
    return dp[n][cap];
}


int main(){
    int cap = 10;
    int pesos[] = {5, 4, 3, 6};
    int valores[] = {10, 7, 4, 12};
    int n = 4;

    int **dp = (int**)malloc((n+1)*sizeof(int*)); // aloca as linhas
    for(int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((cap+1)*sizeof(int)); // aloca as colunas
    
    int valor = mochila(dp, pesos, valores, n, cap);
    printf("%d", valor);
}