#include <stdio.h>
#include <stdlib.h>

int part(int n){
    int **dp = (int**)malloc(sizeof(int*)*(n+1));
    for(int i = 0; i <= n ; i++)
        dp[i] = (int*)malloc(sizeof(int)*(n+1));

    for(int i = 0; i <= n ; i++)
        dp[0][i] = 1;  
    for(int i = 1; i <= n ; i++)
        dp[i][0] = 0;        

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j ++){
            dp[i][j] = dp[i][j-1]; // nao incluir j, repetir o anterior
            if(i - j >= 0)
                dp[i][j] += dp[i-j][j];
        }
    return dp[n][n];
}

int main(){
    int n;
    printf("Quantidade de possibilidades para particionar um inteiro n\ncom numeros de 1 até n.\n\nInsira o valor de n: ");
    scanf("%d", &n);

    int result = part(n);

    printf("\n\nPara um inteiro %d, temos %d possibilidades.", n, result);
    return 0;
}