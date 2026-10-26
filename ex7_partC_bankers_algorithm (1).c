/*
 * EX NO 7 - Part C: Deadlock avoidance using Banker's Algorithm (safety check)
 * Compile: gcc ex7_partC_bankers_algorithm.c -o bankers
 * Run    : ./bankers
 * Sample input: 3 3 / 3 3 2 / 0 1 0 2 0 0 3 0 2 / 1 2 2 0 1 1 2 1 0
 */
#include <stdio.h>

int main() {
    int n, r, i, j, ok = 1;
    printf("Enter matrix dimensions (processes resources): ");
    scanf("%d%d", &n, &r);
    int a[r], al[n][r], nd[n][r], f[n];
    printf("Enter available resources: ");
    for (i = 0; i < r; i++) scanf("%d", &a[i]);
    printf("Enter Allocation matrix (%d x %d):\n", n, r);
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++) scanf("%d", &al[i][j]);
    printf("Enter Need matrix (%d x %d):\n", n, r);
    for (i = 0; i < n; i++) {
        f[i] = 0;
        for (j = 0; j < r; j++) scanf("%d", &nd[i][j]);
    }
    for (i = 0; i < n; i++)
        if (!f[i]) {
            for (j = 0; j < r; j++)
                if (nd[i][j] > a[j]) break;
            if (j == r) {
                for (j = 0; j < r; j++) a[j] += al[i][j];
                f[i] = 1;
            }
        }
    for (i = 0; i < n; i++)
        if (!f[i]) ok = 0;
    printf("Railway Reservation State: %s", ok ? "SAFE" : "DEADLOCK");
    return 0;
}
