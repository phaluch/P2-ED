/*
5 diferentes tipos de sort.
Selection Sort
Bubble Sort
Quick Sort
Merge Sort
Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct number_set *set;

struct number_set  // Estrutura para carregar vetor de inteiros e tamanho do vetor.
{
    int len;
    int *arr;
};

set criarSet(int len)  // Aloca memória para vetor de len inteiros
{
    set S = (set)malloc(sizeof(S));
    S->len = len;
    S->arr = malloc(sizeof(int)*len);
    return S;
}

set criarSetFromUser()  // Cria set dinamicamente de input do usuário
{
    set S = (set)malloc(sizeof(S)); // Inicializa struct para receber atributos
    int len;
    printf("Digite o tamanho do conjunto de números\n");
    scanf("%d",&len);
    S->len = len;  // Coloca tamanho do vetor no atributo .len
    S->arr = malloc(sizeof(int)*len);  // Aloca len inteiros como vetor
    printf("Digite os valores separados por vírgula.\n");
    scanf("%d",S->arr); // Lê um a um os valores digitados pelo usuário;
    int i;
    for(i=1;i<S->len;i++)
    {
        scanf(", %d",&(S->arr[i]));
    }
    fflush(stdin);  // Libera stdin para evitar problemas.
    return S;
}

void printArr(set S)
{
    // Printa cada elemento de um set, separado por vírgula.
    int i;
    for(i=0;i<S->len;i++)
    {
        printf("%d, ",S->arr[i]);
    }
    printf("\n");
}

void selectionSort(set S)
{
    int i, j;
    for(i=0;i<S->len-1;i++)
    {
        int min = S->arr[i];
        int index, changed = 0;
        for(j = i+1;j < S->len; j++)
        {
            if(S->arr[j] < min)
            {
                index = j;
                changed = 1;
                min = S->arr[j];
            }
        }
        if(changed)
        {
            int temp = S->arr[i];
            S->arr[i] = min;
            S->arr[index] = temp;
        }
        printArr(S);
    }
}

void insertionSort(set S)
{
    int i,j, tempIndex, tempValue;
    for(i = 0; i<S->len; i++)
    {
        tempValue = S->arr[i];
        tempIndex = i;
        for(j=i+1; j<S->len;j++)
        {
            if(S->arr[j] < tempValue)
            {
                tempValue = S->arr[j];
                tempIndex = j;
            }
        }
        for(;tempIndex>i;tempIndex--)
        {
            S->arr[tempIndex] = S->arr[tempIndex-1];
        }
        S->arr[i] = tempValue;
    }
}

int partition(set S, int l, int r)
{
    int j=r;  // Coloca j como o último índice do array.
    int v = S->arr[r]; // v recebe o último valor do array.
    int temp;  // Variável usada para a troca de valores a longo da função.
    for(;;)
    {  //Loop infinito, só sai quando acha o break; dentro da função.
        while(S->arr[l] < v)  // Anda do início l até encontrar valor >= v
        {
            l++;
        };
        while(S->arr[j] >= v)// Anda do fim r até encontrar valor < v
        {
            j--;
            if(j==0) break;  // Se chegar a 0, é porque é o único da lista ou a lista está vazia.
        };
        if(l >= j) break;   // Se for True é porque até onde se cruzam está tudo ordenado
        // Caso não se cruzem...
        temp = S->arr[l];   // Trocando os itens de índices i e j;
        S->arr[l] = S->arr[j];
        S->arr[j] = temp;
    }
    printf("\tout: (%d,%d) vira (%d,%d)\n",r,S->arr[r],l,S->arr[l]);
    S->arr[r] = S->arr[l];
    S->arr[l] = v;  // Lembrando que v é o valor do item pivô
    return l;  // l é o índice do item que foi colocado no lugar, ou seja, a divisão;
}

void quickSort(set S, int l, int r)
{
    int i;
    if(r <= l) return;  // Caso de partição vazia ou unitária
    i = partition(S, l, r);
    quickSort(S, l, i-1);
    quickSort(S, i, r);
}

void mergeSort(set S, int l ,int r)
{
    
}

void main(void)
{
    set S = criarSetFromUser();
    printArr(S);
    //selectionSort(S);
    //insertionSort(S);
    quickSort(S,0,S->len-1);
    printArr(S);
}