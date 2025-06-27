#include <stdio.h>
#include <stdlib.h>


int escada(int n){
    int *dp = (int*)malloc((n+1)*sizeof(int));
    dp[0] = 0;
    dp[1] = 1; //com n = 1, temos 1 possibilidade
    dp[2] = 2; //com n = 2, temos 2 possibilidades
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main(){
    int n;
    printf("Quantas possibilidades existem para subir uma escada de \nn degraus podendo subir 1 ou 2 degraus por vez?\n\nInsira o valor de n: ");
    scanf("%d", &n);
    int result = escada(n);
    printf("Para %d degraus, temos %d possibilidades.", n, result);
    return 0;
}