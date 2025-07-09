#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int peso;
    int valor;
} item;

void bubble(item *itens, int n){
    item aux;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j ++){
            float atual = ((float)itens[j].valor/itens[j].peso);
            float prox = ((float)itens[j+1].valor/itens[j+1].peso);
            if(atual < prox){
                aux = itens[j];
                itens[j] = itens[j+1];
                itens[j+1] = aux;
            }
        }
}

float mochilafrac(item itens[], int n, int cap){
    int valor = 0;
    for(int i = 0; i < n; i++){
        if(itens[i].peso <= cap){
            cap -= itens[i].peso;
            valor += itens[i].valor;
            printf("item de peso %d colocado inteiro\n", itens[i].peso);
        }
        else if(cap == 0)
            break;
        else{
            float razao = (float)cap/itens[i].peso;
            cap -= razao*itens[i].peso;
            valor += razao*itens[i].valor;
            printf("item de peso %d colocado em %f\n", itens[i].peso, razao);
            break;
        }
    }
    return valor;

}







int main(){

int n = 3;
int cap = 40;
item itens[] = {
    {10, 10}, // 1
    {20, 40}, // 2
    {30, 40}  //1,6
    };

bubble(itens, n);

float result = mochilafrac(itens, n, cap);
printf("\nresult: %f", result);

}