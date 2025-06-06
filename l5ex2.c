#include <stdio.h>
#include <stdlib.h>

int numMoedas(int moedas[], int num, int tam){
    int sol[num+1];
    for(int i = 1; i <= num; i++)
        sol[i] = 9999;
    sol[0] = 0;

    for(int i = 1; i <= num; i++) //percorre na horizontal ate o numero
        for(int j = 0; j < tam; j++) //percorre pra cada moeda que temos
            if (moedas[j] <= i && sol[i-moedas[j]] != 9999) //se o valor da moeda é menor ou igual ao numero e 
                if(sol[i-moedas[j]]+1 < sol[i]) // valor minimo entre os dois
                       sol[i] = sol[i-moedas[j]]+1;

    for(int i = 0; i <= num; i++)
        printf("%d \n",sol[i]);

    if(sol[num] != 9999)
        return sol[num];
}

int main(){
    int moedas[] = {1, 2, 3};
    int tam = sizeof(moedas)/sizeof(moedas[0]);
    printf("%d\n", tam);
    int num = 7;
    int result = numMoedas(moedas, num, tam);
    printf("O Menor No de Feiticos para conseguir %d de gemas é %d", num, result);
    return 0;

}
