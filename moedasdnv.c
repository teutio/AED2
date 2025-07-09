#include <stdio.h>
#include <stdlib.h>


int moed(int moedas[], int n, int val){
int soma = 0;
int i = 0;
int qtd = 0;

while(soma < val){
    if(soma + moedas[i] <= val){
        soma += moedas[i];
        printf("%d usada\n", moedas[i]);
        qtd++;
        i++;
    }
    if(i == n-1)
        break;
}
if(soma < val)
    return -(val-soma);

return qtd;
}

int main(){

int moedas[] = {10, 4};
int n = 2;
int val = 18;

int result = moed(moedas, n, val);
if (result < 0)
    printf("nao ha solucao, sobrou %d", -result);
else
    printf("num min moedas: %d", result);
}