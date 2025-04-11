#include <stdio.h>

int somar(int folha[], int tam){
    if (tam == 0)
        return 0;
    return folha[0]+somar(folha+1, tam-1);
}

int main(){
    int folha[3] = {10,10,10};
    int tam = sizeof(folha)/sizeof(folha[0]);
    printf("\nA soma dos salarios e de %d reais.",somar(folha,tam));

return 0;
}