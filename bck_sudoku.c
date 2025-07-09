#include <stdio.h>
#include <stdlib.h>

void impressao(int tab[9][9], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf(" %d", tab[i][j]);  
        printf("\n");
    }
    printf("\n\n");
}

int finalizado(int tab[9][9], int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(tab[i][j] == 0)
                return 0;    
    return 1;
}



int verifica(int tab [9] [9], int n, int lin, int col, int val){
    for(int i = 0; i < n; i++)
        if(tab[lin][i] == val) //linha
            return 0;
    
    for(int i = 0; i < n; i++)
        if(tab[i][col] == val) //coluna
            return 0;

    int x = (lin/3)*3; // 0 para 0 1 2, 3 para 3 4 5, 6 para 6 7 8
    int y = (col/3)*3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) // subquadrado
            if(tab[x+i][y+j] == val)
                return 0;

    return 1;
}

int sudoku(int tab[9][9], int n){

    if(finalizado(tab,n)){
        printf("Solucao: ");
        impressao(tab, n);
        return 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(tab[i][j] == 0){
                for(int val = 1; val <= n; val++)
                    if(verifica(tab, n, i, j, val))
                        tab[i][j] = val;
                        sudoku(tab, n);
                        tab[i][j] = 0;
                        return;
            }
        }
    }
}


int main(){
    int n = 9;
    int tab[9][9] ={
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    sudoku(tab, n);

    return 0;
}