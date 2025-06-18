#include <stdio.h>
#include <time.h>

void Merge(int A[], int p, int q, int r){
    int parte1 = q-p+1;
    int parte2 = r-q;
    int P1[parte1];
    int P2[parte2]; // cria dois vetores auxiliares
    for(int i = 0; i<parte1; i++){
        P1[i] = A[p+i];
    }
    for(int i = 0; i<parte2; i++){
        P2[i] = A[q+i+1];
    } // copia cada metade do vetor principal
    int i = 0, j = 0, k = p;

    while(i < parte1 && j < parte2){ //maior/menor
        if(P1[i] <= P2[j]){
            A[k] = P1[i];
            i++;
        }
        else{
            A[k] = P2[j];
            j++;
        }
        k++;
    }

    while(i < parte1){
        A[k] = P1[i];
        k++;
        i++;
    }
    while(j < parte2){
        A[k] = P2[j];
        k++;
        j++;
    }
    
}

void MergeSort(int A[], int p, int r){
    if (p < r){
        int q = (p+r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1 , r);
        Merge(A, p, q, r);
    }
}




int main(){
    long int qtd = 1000;
    int num[1000];
    int i = 0;
    FILE *arq = fopen("1000.txt", "r");
    if(arq == NULL)
        printf("Erro no arquivo\n");
    while(!feof(arq) && i < qtd){
        fscanf(arq, "%d,", &num[i]);
        i++;
    }
    printf("\nNumeros no vetor!!\n");


    fclose(arq);
    clock_t comeco = clock();

    MergeSort(num, 0, qtd-1); // mergesort

    clock_t fim = clock();
    double tempoo = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("TEMPO UTILIZADO MERGE: %fs\n", tempoo);



    comeco = clock();

    //quicksort
    //nao consegui terminar :(

    fim = clock();
    tempoo = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("TEMPO UTILIZADO QUICK: %fs", tempoo);

}