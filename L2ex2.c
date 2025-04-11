#include <stdio.h>

void inversao(int*, int*);

int cont = 0;
int main(){
	int A [] = {4,3,2,5,1,6};
	int n = 3;
	for(int i = 0; i < n-1;i++){
		int j = i+1;
		if(A[i]>A[j]){
			inversao(&A[i],&A[j]);
		}		
	}
	for(int i = 0; i<n;i++){
		printf("posicao %d: %d\n",i, A[i]);
	}
    printf("%d",cont);
return 0;
}

void inversao(int* i, int* j){
	int aux = *i;
	*i = *j;
	*j = aux;
	cont++;
}