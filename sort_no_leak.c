#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
int read(int *a, int n);
void output(int *a, int n);

int main() {
    int *arr = malloc(sizeof(int)), n;

    if (input(arr, &n) == 0) {
        read(arr, n);
        output(arr, n);
    } else
        printf("n/a\n");

    free(arr);
}

int input(int *a, int *n) {
    char g, t;
    if ((scanf("%d%c", n, &t) == 2) && (t == ' ' || t == '\n')) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &g) == 2 && (g == '\n' || g == ' ')) {
            } else
                return 1;
        }
    } else
        return 1;
    return 0;
}
int read(int *a, int n) {
    int swap = 0;
    for (;;) {
        int flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) {
                swap = a[i - 1];
                a[i - 1] = a[i];
                a[i] = swap;
                flag++;
            }
        }
        if (flag == 0) break;
    }
    return 0;
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
