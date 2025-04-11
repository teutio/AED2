#include <stdio.h>

int somar(int folha[], int tam){
    if (tam == 0)
        return 0;
    else if (tam ==1)
        return folha[0];
    return folha[0]+folha[1]+somar(folha+2, tam-2);
}

int main(){
    int folha[1] = {10};
    int tam = sizeof(folha)/sizeof(folha[0]);
    printf("\nA soma dos salarios e de %d reais.",somar(folha,tam));

return 0;
}