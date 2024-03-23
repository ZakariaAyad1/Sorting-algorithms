#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tri simple (Tri � bulles)
void triSimple(int T[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (T[j] > T[j + 1]) {
                int tmp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = tmp;
            }
        }
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
    triSimple(arr, n);
    end = clock();
    temps_execution = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'execution du tri simple pour %d elements : %.6f secondes\n", n, temps_execution);

    return 0;
}
