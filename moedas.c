//MOEDAS EM GULOSO
#include <stdio.h>
#include <stdlib.h>


void numMoedas(int moedas[], int num, int tam){
    printf("O troco sera de: ");

    for(int i = 0; i < tam; i++){
        while(moedas[i] <= num){
            num -= moedas[i];
            printf("%d ", moedas[i]);
        }
        if(num == 0)
            break;
    }

    if (num > 0)
        printf("Nao foi possivel. Sobrou %d", num);
}

int main(){
    int moedas[] = {3, 2, 1};
    int tam = sizeof(moedas)/sizeof(moedas[0]);
    printf("%d\n", tam);
    int num = 7;
    numMoedas(moedas, num, tam);
    return 0;

}
