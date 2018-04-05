// C Program for counting sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//necessário p/ função time()
#define RANGE 255

void gera_aleatorio(char vetor[],int tam){
    int i;
    srand(time(NULL));

    for(i=0;i<tam;i++){
        vetor[i]=rand() % 100;
       // printf("%c  ",vetor[i]);
    }
}

// alphabatical order
void countSort(char vetor[])
{
    // The output character array that will have sorted arr
    char output[strlen(vetor)];

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for(i = 0; vetor[i]; ++i)
        ++count[vetor[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];

    // Build the output character array
    for (i = 0; vetor[i]; ++i)
    {
        output[count[vetor[i]]-1] = vetor[i];
        --count[vetor[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; vetor[i]; ++i)
        vetor[i] = output[i];
}

// Driver program to test above function
int main(){
    int tam;
    puts("Digite o tamanho do vetor");
    scanf("%d", &tam);

    char vetor[tam];
    gera_aleatorio(vetor,tam);
    printf("A string aleatoria gerada foi : %s\n", vetor);
    countSort(vetor);

    printf("A string ordenada e %s\n", vetor);
    return 0;
}
