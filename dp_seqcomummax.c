#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void seqComum(char *s1, char *s2){
    int tam1 = strlen(s1);
    int tam2 = strlen(s2);

    int **dp = (int**)malloc((tam1+1)*sizeof(int*)); // aloca as linhas
        for(int i = 0; i <= tam1; i++)
            dp[i] = (int*)malloc((tam2+1)*sizeof(int)); // aloca as colunas

    for(int i = 0; i <= tam1; i ++)
        for(int j = 0; j <= tam2; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) // encontrou um valor
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    printf("resultado: %d",dp[tam1][tam2]);


}

int main(){

    seqComum("ACDE","ACE");
}