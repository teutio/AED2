#include <stdio.h>
#include <stdlib.h>

int bastao(int n, int p[]){
    int *dp = (int*)malloc((n+1)*sizeof(int));
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int valor = -1;
        for(int j = 1; j <= i; j++)
            if(p[j] + dp[i-j] > valor)
                valor = p[j] + dp[i-j];
        dp[i] = valor;
    }    
    return dp[n];
}

int main(){
    int n;
    printf("Particionar um bastao de quantidade n de pedavos\ncom cada porcao tendo um valor diferente.\nCalcular o maior valor possivel.\n\nInsira o valor de n: ");
    scanf("%d", &n);
    int *p = (int*)malloc(sizeof(int)*(n+1)); // array com preços
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        p[i] = i+2+(i%2)*2;
    for (int i = 1; i <= n; i++)
        printf("%d ", p[i]);
    int result = bastao(n, p);
    printf("\n\nPara um bastao de tamanho %d, temos %d reais.", n, result);

    return 0;
}