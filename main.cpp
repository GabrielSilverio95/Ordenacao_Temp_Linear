// C Program for counting sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>//necessário p/ função time()


using namespace std;

int valor_max(int a[], int n){
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void gera_aleatorio(int vetor[],int tam){
    int i;
    srand(time(NULL));
    for(i=0;i<tam;i++){
        vetor[i]= rand() % 10;
    }
}

void countSort_estavel(int a[],int n,int k){
    int b[n],c[k+1],i;


    // inicializa o vetor auxiliar com 0
    for (i = 0 ; i < k + 1 ; i++)
        c[i] = 0;
    // Armazena a contagem de cada caractere
    for(i = 0; i < n ; ++i)
        c[a[i]] = c[a[i]] + 1;
    // Ordena os indices do vetor auxiliar
    for (i = 1; i < k + 1; ++i)
        c[i] = c[i] + c[i-1];
    for (i = 0; i < n; i++){
        b[c[a[i]] - 1] = a[i];
        c[a[i]]= c[a[i]] - 1;
    }
   // Retorna os valores ordenados para o vetor
    for (i = 0; i < n; ++i)
        a[i] = b[i];
}

void countSort_instavel(int a[],int n,int k){
    int b[n],c[k+1],i,j;

    vector<int> d;
    // inicializa o vetor auxiliar com 0
    for (i = 0 ; i < k + 1 ; i++)
        c[i] = 0;
    // Armazena a contagem de cada caractere
    for(i = 0; i < n ; ++i)
        c[a[i]] = c[a[i]] + 1;

    for (i = 0; i < k + 1; i++){
        for (j = 0 ; j < c[i] ; i++)
            d.push_back(i);
    }
   // Retorna os valores ordenados para o vetor
    for (i = 0; i < n; ++i)
        a[i] = d[i];
}

void countSort_estavel_radix(int a[],int n,int k, int carac){
    int b[n],c[k+1],i;
    // inicializa o vetor auxiliar com 0
    for (i = 0 ; i < k + 1 ; i++)
        c[i] = 0;
    // Armazena a contagem de cada caractere
    for(i = 0; i < n ; ++i)
        c[ (a[i]/carac)%10 ] = c[ (a[i]/carac)%10 ] + 1;
    // Ordena os indices do vetor auxiliar
    for (i = 1; i < k + 1; ++i)
        c[i] = c[i] + c[i-1];

    for (i = 0; i < n; i++){
        b[c[((a[i]/carac)%10)]-1] = a[i];
        c[(a[i]/carac)%10]= c[(a[i]/carac)%10] - 1;
    }
   // Retorna os valores ordenados para o vetor
    for (i = 0; i < n; ++i)
        a[i] = b[i];
}

void radixsort(int a[], int n){
    // Find the maximum number to know number of digits
    int k = valor_max(a, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int caract = 1; k/caract > 0; caract *= 10)
        countSort_estavel_radix(a,n,k, caract);
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n){
    // 1) Cria n baldes vazios
    vector<float> b[n];

    // 2) Coloca o vetor em diferentes baldes
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // indice dos baldes
       b[bi].push_back(arr[i]);
    }

    // 3) Ordena cada balde
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    // 4) Concatena todos os baldes dentro do arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}

int main(){
    int n,k;

    n=6;

    int a[n];
    gera_aleatorio(a,n);
    k= valor_max(a,n);

    cout <<"O vetor a ser ordenado pelo Counting Sort e:\n";

    for (int i=0; i<n; i++)
       cout << a[i] << " ";

    countSort_instavel(a,n,k);

    printf("\nO vetor ordenado pelo Counting Sort e:\n");

    for (int i=0; i < n; i++)
        cout << a[i] << " ";

    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    cout << "\nO vetor a ser ordenado com Bucket Sort e:\n";
    n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++)
       cout << arr[i] << " ";


    bucketSort(arr, n);

    cout << "\nO vetor ordenado com o Bucket Sort e: \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";

       int a2[n];
       gera_aleatorio(a2,n);

       cout <<"\nO vetor a ser ordenado pelo Radix Sort e:\n";

    for (int i=0; i<n; i++)
       cout << a2[i] << " ";

       radixsort(a2,n);

 cout <<"\nO vetor ordenado pelo Radix Sort e:\n";

    for (int i=0; i<n; i++)
       cout << a2[i] << " ";
    return 0;
}
