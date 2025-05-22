#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct{
    float x;
    float y;
} P;

void MergeX(P A[], int p, int q, int r){
    int parte1 = q-p+1;
    int parte2 = r-q;
    P A1[parte1];
    P A2[parte2]; // cria dois vetores auxiliares
    for(int i = 0; i<parte1; i++){
        A1[i] = A[p+i];
    }
    for(int i = 0; i<parte2; i++){
        A2[i] = A[q+i+1];
    } // copia cada metade do o vetor principal
    int i = 0, j = 0, k = p;

    while(i < parte1 && j < parte2){ //maior/menor
        if(A1[i].x <= A2[j].x){
            A[k] = A1[i];
            i++;
        }
        else{
            A[k] = A2[j];
            j++;
        }
        k++;
    }

    while(i < parte1){
        A[k] = A1[i];
        k++;
        i++;
    }
    while(j < parte2){
        A[k] = A2[j];
        k++;
        j++;
    }
    
}
void MergeSortX(P A[], int p, int r){
    if (p < r){
        int q = (p+r)/2;
        MergeSortX(A, p, q);
        MergeSortX(A, q+1 , r);
        MergeX(A, p, q, r);
    }
}

void MergeY(P A[], int p, int q, int r){
    int parte1 = q-p+1;
    int parte2 = r-q;
    P A1[parte1];
    P A2[parte2]; // cria dois vetores auxiliares
    for(int i = 0; i<parte1; i++){
        A1[i] = A[p+i];
    }
    for(int i = 0; i<parte2; i++){
        A2[i] = A[q+i+1];
    } // copia cada metade do vetor principal
    int i = 0, j = 0, k = p;

    while(i < parte1 && j < parte2){ //maior/menor
        if(A1[i].y <= A2[j].y){
            A[k] = A1[i];
            i++;
        }
        else{
            A[k] = A2[j];
            j++;
        }
        k++;
    }

    while(i < parte1){
        A[k] = A1[i];
        k++;
        i++;
    }
    while(j < parte2){
        A[k] = A2[j];
        k++;
        j++;
    }
    
}
void MergeSortY(P A[], int p, int r){
    if (p < r){
        int q = (p+r)/2;
        MergeSortY(A, p, q);
        MergeSortY(A, q+1 , r);
        MergeY(A, p, q, r);
    }
}

float dis(P p1, P p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float parMaisProx(int n, P pontos[], P* pMin1, P* pMin2){
    // Quando n é pequeno, comparar diretamente ------------------------
    if (n <= 3){
        float min = 9999.9999;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                float dist = dis(pontos[i], pontos[j]);
                if (dist < min){
                    min = dist;
                    *pMin1 = pontos[i];
                    *pMin2 = pontos[j];
                }
            }
        }
        return min;
    }
    // Se n é grande, dividir o plano em dois lados recursivamente -------
    int meio = n/2;
    P pMeio = pontos[meio];
    P pEsq1, pEsq2, pDir1, pDir2;
    float minEsq = parMaisProx(meio, pontos, &pEsq1, &pEsq2); 
    float minDir = parMaisProx(n-meio, pontos+meio, &pDir1, &pDir2);

    // Mínimo entre direita e esquerda -----------------------------------
    float min;
    if (minEsq < minDir){
        min = minEsq;
        *pMin1 = pEsq1;
        *pMin2 = pEsq2;
    }
    else{
        min = minDir;
        *pMin1 = pDir1;
        *pMin2 = pDir2;
    }
    // Ainda pode haver uma distância mínima entre pontos de lados diferentes ----------------
    // Criar uma faixa a partir do meio, com a largura sendo o dobro do tamanho mínimo encontrado
    P faixa[n];
    int cont = 0; //  numero de pontos na faixa
    for(int i = 0; i < n; i++){
        if (fabs(pontos[i].x - pMeio.x) < min){
            faixa[cont] = pontos [i];
            cont++;
        } 
    }
    
    // Encontrar o mais proximo dentro da faixa
    MergeSortY(faixa, 0, cont-1); // ordena a faixa com relacao a Y

    for(int i = 0; i < cont; i++){
            for(int j = i+1; j < cont && (faixa[j].y - faixa[i].y) < min; j++){
                float d = dis(faixa[i], faixa[j]);
                if (d < min){
                    min = d;
                    *pMin1 = faixa[i];
                    *pMin2 = faixa[j];
                }
            }
        }
  return min;
}

int main(){
    srand(time(NULL));
    
    // Inserção dos pontos ----------------------------------------------
    int n;
    printf("Numero de pontos: ");
    scanf("%d", &n);
    printf("----------------------------\n");
    clock_t inicio = clock();
    clock_t comeco = clock();
    P *pontos = (P*)malloc(n*sizeof(P)); //                                    O(n)
    for (int i = 0; i < n; i++){
        float a = rand() % 10000 + 0, b = rand() % 10000 + 0;
        pontos[i].x = a;
        pontos[i].y = b;
    }

    clock_t fim = clock();
    double tempooooo = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("TEMPO CRIACAO VETOR PONTOS: %fs\n", tempooooo);

    // Ordenamento dos pontos --------------------------------------------
    comeco = clock();
    MergeSortX(pontos, 0, n-1); //                                             O(n log n)
    fim = clock();
    double tempooo = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("TEMPO ORDENACAO VETOR PONTOS: %fs\n", tempooo);
    // Definição da distância mínima -------------------------------------
    P pMin1 = {0,0};
    P pMin2 = {0,0};

     comeco = clock();

    float min = parMaisProx(n, pontos, &pMin1, &pMin2); //                     O(n log n)

    fim = clock();
    double tempoo = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("TEMPO FUNCAO PARMAISPROX: %fs\n", tempoo);

    clock_t final = clock();
    double tempo = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("----------------------------\n");
    printf("TEMPO UTILIZADO TOTAL: %fs\n", tempo);

    printf("\n\nA distancia minima e: %.2f\n",min);
    printf("O Ponto Minimo 1 e: (%.2f , %.2f)\n", pMin1.x, pMin1.y);
    printf("O Ponto Minimo 2 e: (%.2f , %.2f)\n", pMin2.x, pMin2.y);

    return 0;
}