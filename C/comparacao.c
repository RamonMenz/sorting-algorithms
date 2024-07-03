#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 1000000 // Maior número possível que estará no vetor
#define T 10 // Número de testes
#define Q 5 // Quantidade de algoritmos de ordenação
#define NTAM 4 // Número de tamanhos diferentes para os vetores

const int tamanhos[NTAM] = {50000, 100000, 150000, 200000}; // Tamanhos dos vetores a serem testados
const char *nomes_algoritmos[Q] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort"};

void testar(int arr0[], int arr1[], int resultados[T][Q], int index, double dif, clock_t ini, clock_t fim, int TAM);
void salvarResultados(float medias[Q][NTAM]);
void criarArray(int arr[], int TAM);
void copiarArray(int arrO[], int arrD[], int TAM);
void exibirArray(int arr[], int TAM);
void bubbleSort(int arr[], int TAM);
void selectionSort(int arr[], int TAM);
void insertionSort(int arr[], int TAM);
void mergeSort(int arr[], int aux[], int ini, int fim);
void quickSort(int arr[], int ini, int fim);

int main() {
    clock_t ini, fim;
    double dif;
    int resultados[T][Q];
    float medias[Q][NTAM], media;

    for(int t = 0; t < NTAM; t++) {
        int TAM = tamanhos[t];
        int *arr0 = malloc(TAM * sizeof(int));
        int *arr1 = malloc(TAM * sizeof(int));

        if (arr0 == NULL || arr1 == NULL) {
            printf("Erro ao alocar memória para os vetores.\n");
            return 1;
        }

        printf("Testando vetores de tamanho: %d\n", TAM);
        for (int i = 0; i < T; i++) {
            printf("[Teste %d]\n", i + 1);
            testar(arr0, arr1, resultados, i, dif, ini, fim, TAM);
        }

        printf("[Resumo dos testes]\n");
        for (int i = 0; i < T; i++) {
            printf("Teste %2d - ", i + 1);
            for(int j = 0; j < Q; j++) {
                printf("%d ", resultados[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (int i = 0; i < Q; i++) {
            for(int j = 0; j < T; j++) {
                media += resultados[j][i];
            }
            medias[i][t] = media / T;
            printf("%s:\t %10.1f ms\n", nomes_algoritmos[i], medias[i][t]);
            media = 0;
        }
        printf("------------------------------------------------------\n\n");

        free(arr0);
        free(arr1);
    }

    salvarResultados(medias);

    system("PAUSE");
    return 0;
}

void testar(int arr0[], int arr1[], int resultados[T][Q], int index, double dif, clock_t ini, clock_t fim, int TAM) {
    criarArray(arr0, TAM);

    copiarArray(arr0, arr1, TAM);
    ini = clock();
    bubbleSort(arr1, TAM);
    fim = clock();
    dif = fim - ini;
    printf("Tempo para ordenar com Bubble Sort:\t %10.0f ms\n", dif / (CLOCKS_PER_SEC / 1000));
    resultados[index][0] = dif;

    copiarArray(arr0, arr1, TAM);
    ini = clock();
    selectionSort(arr1, TAM);
    fim = clock();
    dif = fim - ini;
    printf("Tempo para ordenar com Selection Sort:\t %10.0f ms\n", dif / (CLOCKS_PER_SEC / 1000));
    resultados[index][1] = dif;

    copiarArray(arr0, arr1, TAM);
    ini = clock();
    insertionSort(arr1, TAM);
    fim = clock();
    dif = fim - ini;
    printf("Tempo para ordenar com Insertion Sort:\t %10.0f ms\n", dif / (CLOCKS_PER_SEC / 1000));
    resultados[index][2] = dif;

    copiarArray(arr0, arr1, TAM);
    ini = clock();
    quickSort(arr1, 0, TAM - 1);
    fim = clock();
    dif = fim - ini;
    printf("Tempo para ordenar com Quick Sort:\t %10.0f ms\n", dif / (CLOCKS_PER_SEC / 1000));
    resultados[index][3] = dif;

    ini = clock();
    mergeSort(arr0, arr1, 0, TAM - 1); //   O Merge Sort ficou por ultimo
    fim = clock(); //                       para poder utilizar o arr1 como
    dif = fim - ini; //                     vetor auxiliar
    printf("Tempo para ordenar com Merge Sort:\t %10.0f ms\n", dif / (CLOCKS_PER_SEC / 1000));
    resultados[index][4] = dif;

    printf("\n");
}

void salvarResultados(float medias[Q][NTAM]) {
    FILE *output;
    output = fopen("resultados.csv", "w");

    if (output == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(output, "Algoritmo;50 mil inteiros;100 mil inteiros;150 mil inteiros;200 mil inteiros\n");
    for (int i = 0; i < Q; i++) {
        fprintf(output, "%s", nomes_algoritmos[i]);
        for (int t = 0; t < NTAM; t++) {
            fprintf(output, ";%10.1f", medias[i][t]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
    printf("Arquivo 'resultados.csv' criado com sucesso!\n\n");
}

void criarArray(int arr[], int TAM) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        arr[i] = rand() % (NMAX + 1);
    }
}

void copiarArray(int arrO[], int arrD[], int TAM) {
    for (int i = 0; i < TAM; i++) {
        arrD[i] = arrO[i];
    }
}

void exibirArray(int arr[], int TAM) {
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int TAM) {
    int temp;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int TAM) {
    int minIndex, temp;
    for (int i = 0; i < TAM - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < TAM; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (arr[i] > arr[minIndex]) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int TAM) {
    int key, j;
    for (int i = 1; i < TAM; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int ini, int fim) {
    if (ini < fim) {
        int pivot = arr[fim], i = ini, aux;
        for (int j = ini; j < fim - 1; j++) {
            if (arr[j] <= pivot) {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
                i++;
            }
        }
        aux = arr[i];
        arr[i] = arr[fim];
        arr[fim] = aux;
        pivot = i;
        quickSort(arr, ini, pivot - 1);
        quickSort(arr, pivot + 1, fim);
    }
}

void mergeSort(int arr[], int aux[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(arr, aux, ini, meio);
        mergeSort(arr, aux, meio + 1, fim);
        int i = ini, j = meio + 1, k = ini;
        while (i <= meio && j <= fim) {
            if (arr[i] < arr[j]) {
                aux[k] = arr[i];
                i++;
            } else {
                aux[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= meio) {
            aux[k] = arr[i];
            k++;
            i++;
        }
        while (j <= fim) {
            aux[k] = arr[j];
            k++;
            j++;
        }
        for (i = ini; i <= fim; i++) {
            arr[i] = aux[i];
        }
    }
}
