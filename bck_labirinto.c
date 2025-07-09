#include <stdio.h>
#include <stdlib.h>


int labirinto(int mapa [4][4], int n, int lin, int col){

    printf("Linha %d Coluna %d\n", lin+1, col+1);
    // Se a célula atual é um obstáculo ou fora dos limites, não é um caminho válido
    if (lin >= n || col >= n || mapa[lin][col] == 1) {
        return 0; // Caminho não existe por aqui
    }

    // Se chegou ao destino
    if (lin == n - 1 && col == n - 1) {
        return 1; // Caminho encontrado
    }

    // Tenta mover para a direita
    if (labirinto(mapa, n, lin, col + 1)) {
        return 1; // Caminho encontrado por este ramo
    }

    // Se não encontrou para a direita, tenta mover para baixo
    if (labirinto(mapa, n, lin + 1, col)) {
        return 1; // Caminho encontrado por este ramo
    }

    // Se nenhuma das direções levou a um caminho, este é um beco sem saída
    return 0;
/*
    if(lin == n-1 && col == n-1)
        fim = 1;
    
    if(mapa[lin][col+1] == 0 && col+1 < n)
        //explora para a direita
        fim = labirinto(mapa, n, fim, lin, col+1);
    
    if(mapa[lin+1][col] == 0 && lin+1 < n)
        //explora para baixo
        fim = labirinto(mapa, n, fim, lin+1, col);
    
    return fim;*/
}

int main(){
    int n = 4;
    int mapa[4][4] = {
        {0,0,0,1},
        {1,1,0,1},
        {0,0,0,1},
        {1,0,0,0}
    };

    int fim = labirinto(mapa, n, 0, 0);

    if(fim)
        printf("Caminho existe");
    else    
        printf("Caminho nao existe");

}

