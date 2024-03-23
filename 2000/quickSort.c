#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction de partition pour le tri rapide
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Tri rapide récursif
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Générer un tableau aléatoire de 2000 éléments
    int n = 2000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Valeurs aléatoires entre 0 et 9999
    }

    // Mesurer le temps d'exécution
    clock_t start, end;
    double temps_execution;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    temps_execution = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'execution du tri rapide pour %d elements : %.6f secondes\n", n, temps_execution);

    return 0;
}
