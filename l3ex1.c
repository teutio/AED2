#include <stdio.h>

void Dano(int pod, int niv){
    int dano = pod;
    if(niv % 2){
        for(int i = 1; i < (niv/2); i++)
            dano = dano*pod;
        dano = dano*dano;
        dano = dano*pod;
    }
    else{
        for(int i = 1; i < (niv/2); i++)
            dano = dano*pod;
            dano = dano*dano;
    }
    printf("Seu dano total é: %d\n\n\n", dano);
}


int main(){

    int poder = 0;
    int nivel = 0;
    printf("Insira seu poder: ");
    scanf("%d",&poder);
    printf("Insira seu nivel: ");
    scanf("%d",&nivel);
    Dano(poder,nivel);

}