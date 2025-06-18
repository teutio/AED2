#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int l[], int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(l[j] > l[j+1]){
                aux = l[j];
                l[j] = l[j+1];
                l[j+1] = aux;
            }
        }
    }
}

void distribuicao(int minimos[], int valores[], int n, int doces){
    int doce = 0, crianca = 0, numero = 0;
    while(doce < doces && crianca < n){
        if(valores[doce] >= minimos[crianca]){
            printf("Crianca %d de necessidade %d recebe o doce %d\n", crianca+1, minimos[crianca], valores[doce]);
            doce++;
            crianca++;
        }
        else
            doce++;
    }
}

int main(){
    srand(time(NULL));
    int n, doces;

    printf("Insira o No de Criancas: ");
    scanf("%d", &n);
    int *minimos = (int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++)
        minimos[i] = rand()%5+n;

    printf("Insira o No de Doces: ");
    scanf("%d", &doces);
    int *valores = (int*)malloc(doces* sizeof(int));
    for (int i = 0; i < doces; i++)
        valores[i] = rand()%5+n;

    bubble(minimos, n);
    bubble(valores, doces);

    distribuicao(minimos, valores, n, doces);

    return 0;
}