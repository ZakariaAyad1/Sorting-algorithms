#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction r�cursive pour r�soudre les Tours de Hano�
void hanoi(int n, char depart, char intermediaire, char destination) {
    if (n == 1) {
        printf("D�placer le disque 1 de la tige %c vers la tige %c\n", depart, destination);
        return;
    }
    hanoi(n - 1, depart, destination, intermediaire);
    printf("D�placer le disque %d de la tige %c vers la tige %c\n", n, depart, destination);
    hanoi(n - 1, intermediaire, depart, destination);
}

int main() {
    // Nombre de disques
    int n = 2000;

    // Mesurer le temps d'ex�cution
    clock_t start, end;
    double temps_execution;

    start = clock();
    hanoi(n, 'A', 'B', 'C');
    end = clock();
    temps_execution = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'ex�cution pour %d disques : %.6f secondes\n", n, temps_execution);

    return 0;
}
