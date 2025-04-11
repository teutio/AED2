#include <stdio.h>

void hanoi(int num, char ori, char trab, char dest);

int main(){
    printf("\n-- TORRE DE HANOI --\n");
    hanoi(2,'A','B','C');
    printf("\n\n-- FIM --");
    return 0;
}

void hanoi (int num, char a, char b, char c){
    if(num>0){
        hanoi(num-1,a,c,b);
        printf("\nMovendo a peca %d para o pino %c", num, c);
        hanoi(num-1,b,a,c); 
    }
}