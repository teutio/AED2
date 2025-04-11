#include <stdio.h>

void TesouroPerdido(int ilha[], int inic, int fim, int posicao){
    if(fim >= inic){
    int meio = (inic+fim)/2;
    if(ilha[meio] == posicao){
        printf("O tesouro foi encontrado na posição %d!!", posicao);
        return;
    }
    if(posicao > ilha[meio]){
        TesouroPerdido(ilha,meio+1,fim, posicao);
        return;
    }
    TesouroPerdido(ilha,inic,meio-1,posicao);
    return;
    
    }
    printf("O tesouro não foi encontrado na posição %d :( \n\n", posicao);
}

int main(){
    int ilha[] = {1,2,3,4,5,6,7,8,9,10};
    int posicao;
    int qtd;
    printf("insira a posição a ser procurada: ");
    scanf("%d",&posicao);
    printf("insira a quantidade de posicoes na ilha: ");
    scanf("%d",&qtd);
    for(int i = 0; i < qtd; i++){
        printf("insira a posicao: ");
        scanf("%d", &ilha[i]);
    }
    TesouroPerdido(ilha, 0, qtd, posicao);
    return 0;
}