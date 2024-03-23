#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tri par s�lection
void triSelection(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // G�n�rer un tableau al�atoire de 2000 �l�ments
    int n = 2000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Valeurs al�atoires entre 0 et 9999
    }

    // Mesurer le temps d'ex�cution
    clock_t start, end;
    double temps_execution;

    start = clock();
    triSelection(arr, n);
    end = clock();
    temps_execution = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'execution du tri par selection pour %d elements : %.6f secondes\n", n, temps_execution);

    return 0;
}
