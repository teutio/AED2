#include <stdio.h>

int somar(int folha[], int tam){
    int total = 0;
    for (int i = 0; i<tam; i++)
        total += folha[i];
    return total;
}

int main(){
    int folha[3] = {10,10,10};
    int tam = sizeof(folha)/sizeof(folha[0]);
    printf("\nA soma dos salarios e de %d reais.",somar(folha,tam));

return 0;
}