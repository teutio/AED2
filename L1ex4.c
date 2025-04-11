/*
Criar uma lista duplamente encadeada circular "muro infinito", e buscar um elemento alvo, que está em uma posição desconhecida.
Quis ter certeza de ter um único elemento alvo "0" e de não saber qual a posição dele, usando o rand().
A busca é feita indo para a direita e depois para a esquerda, já que o alvo pode estar mais próximo de qualquer um dos dois lados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct blo{
int num;
struct blo* prox;
struct blo* ant;
}bloco;


bloco* adicionaBloco(bloco* primeiro, bloco* base, int num);
bloco* criarMuro(int n, int alvo);
int buscarAlvo(bloco* inic, int n, int alvo);

bloco* adicionaBloco(bloco* primeiro, bloco* base, int num) {
    bloco* novo = (bloco*)malloc(sizeof(bloco));
    novo->num = num;
    novo->ant = base;
    novo->prox = primeiro;
    base->prox = novo;
    primeiro->ant = novo;
    return novo;
}

bloco* criarMuro(int n, int alvo) {
    bloco* primeiro = (bloco*)malloc(sizeof(bloco)); // cria um bloco com o alvo
    primeiro->num = alvo;
    primeiro->prox = primeiro;
    primeiro->ant = primeiro;

    bloco* pont = primeiro;
    for(int i = 0; i<n-1; i++){
        pont = adicionaBloco(primeiro, pont, (rand()%n-1)+2); //adiciona n-1 blocos com um numero entre 1 e n 
    }

    bloco* inicio = primeiro;
    for(int i = 0; i<(rand()%n); i++) //seleciona uma posicao aleatoria para ser o início da busca
        inicio = inicio->prox;
    return inicio;
}

int buscarAlvo(bloco* inic, int n, int alvo){
    bloco* pont = inic;
    int passos = n/2;
    if(pont->num == alvo) // checa o alvo na posicao inicial
        return 0;
    for(int i = 1; i<passos+1;i++){
        for(int d = 0; d<i;d++){
            pont = pont->prox;
            if(pont->num == alvo)
                return i;
            pont = inic;
            pont = pont->ant;
            if(pont->num == alvo)
                return -i;
            pont = inic;
        }

    }
}


int main(){
    srand(time(NULL));
    int n = 6;
    int alvo = 0;
    bloco* inic = criarMuro(n, alvo);
    
    int posicao = buscarAlvo(inic, n, alvo);



    // imprimir
    bloco* pont = inic;
    printf("---- Muro Infinito ----\n    n = %d  alvo = %d\n\nMuro: ", n, alvo);
    for(int i = 0; i<n;i++){
        printf("|%d| ",pont->num);
        pont = pont->prox;
    }
    return 0;
}


