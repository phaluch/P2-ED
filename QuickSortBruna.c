#include<stdio.h>
#include<stdlib.h>

void quick_sort(int * vetor, int inicio, int fim);

int main ()
{
	int i, tamanho;
	int * vetor;
	
	printf("digite o tamanho do vetor \n");
	scanf("%d", &tamanho);
	
	vetor=(int*)malloc(sizeof(int)*tamanho);
	
	printf("digite os numeros para preencher o vetor \n");
	
	for (i=0; i<tamanho; i++)
	{
		scanf("%d", &vetor[i]);
	}
	
	for(i=0; i<tamanho; i++)
	{
		printf("%d \t", vetor[i]);
	}
	
	quick_sort(vetor, 0, tamanho-1);
	
	for(i=0; i<tamanho; i++)
	{
		printf("%d \t", vetor[i]);
	}
	
	return 0;
}	
	



void quick_sort(int * vetor, int inicio, int fim)
{
	int i, j, aux, pivot;
	i=inicio;
	pivot=inicio;
	j=fim;
	while (i<j)
	{
		while(vetor[i]<=vetor[pivot] && i<fim)
		{
			i++;
		}
		while(vetor[j]>vetor[pivot] && j>inicio)
		{
			j--;
		}	
		if(i<j)
		{
			aux = vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=aux;
		}
	}
	aux=vetor[pivot];
	vetor[pivot]=vetor[j];
	vetor[j] = aux;
	quick_sort(vetor, inicio, j-1);
	quick_sort(vetor, j+1, fim);
}