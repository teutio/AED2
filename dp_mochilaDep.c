#include <stdio.h>
#include <stdlib.h>


int mochila(int** dp, int pesos[], int valores[], int n, int cap, int dep[]){
    int *incluido = (int*)malloc((n)*sizeof(int));
    int numb = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= cap; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                if (pesos[i-1] <= j){ // se o item cabe
                    if(dep[i] == -1){ // se o item i não possui dependencias, segue normalmente:
                        int ant = dp[i-1][j];
                        int atual = valores[i-1] + dp[i-1][j - pesos[i-1]];
                        if (atual > ant){
                            dp[i][j] = atual;
                            incluido[numb] = i;
                            numb++;
                        }
                        else
                            dp[i][j] = ant;
                    }
                    else{// se o item possui dependencia
                        int presente = 0;
                        for(int k = 0; k < numb; k++)
                            if (incluido[k] == dep[i])
                                presente = 1;
                        if(presente){ // se a dependencia ja esta inclusa, segue normalmente
                            int ant = dp[i-1][j];
                            int atual = valores[i-1] + dp[i-1][j - pesos[i-1]];
                            if (atual > ant){
                                dp[i][j] = atual;
                                incluido[numb] = i;
                                numb++;
                            }
                            else
                                dp[i][j] = ant;
                        }

                        }
                    }
                    else             
                        dp[i][j] = dp[i-1][j];    
                    
            }
        
}
    printf("o valor maximo e: %d",  dp[n][cap]);
    for(int i = 0; i < numb; i++)
        printf("o item %d foi incluido\n", incluido[i]);
}


int main(){
    int cap = 10;
    int pesos[] = {5, 4, 3, 6};
    int valores[] = {10, 7, 4, 12};
    int dep[] = {-1, 0, -1, -1, 2};
    int n = 4;

    int ** dp = (int**)malloc((n+1)*sizeof(int*));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((cap+1)*sizeof(int));
    mochila(dp, pesos, valores, n, cap, dep);
}