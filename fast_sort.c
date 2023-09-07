#include <stdio.h>
#define NMAX 10
#define root i + sh
#define left 2 * i + 1 + sh
#define right 2 * i + 2 + sh

int input(int *a);
void output_quick(int *a);
void quick_sort(int *a, int j);
void output_heap(int *a);
void heap_sort(int *a);

int main() {
    int arr[NMAX];

    if (input(arr) == 0) {
        quick_sort(arr, NMAX - 1);
        output_quick(arr);
        heap_sort(arr);
        output_heap(arr);

    } else
        printf("n/a\n");
}

int input(int *a) {
    int size = 10;
    char g;
    for (int *p = a; p - a < size; p++) {
        if (scanf("%d%c", p, &g) == 2 && (g == '\n' || g == ' ')) {
        } else
            return 1;
    }
    return 0;
}

void output_quick(int *a) {
    int size = 10;
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void output_heap(int *a) {
    int size = 10;
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quick_sort(int *a, int j) {
    int size = j;
    int k = 0;
    int c = a[(int)(j / 2)];
    int tmp = 0;
    do {
        while (a[k] < c) k++;
        while (a[j] > c) j--;

        if (k <= j) {
            tmp = a[k];
            a[k] = a[j];
            a[j] = tmp;
            k++;
            j--;
        }

    } while (k <= j);
    {
        if (j > 0) quick_sort(a, j);
        if (size > k) quick_sort(a + k, size - k);
    }
}
void heap_sort(int *a) {
    int i, sh = 0, b = 0, swap = 0;
    while (1) {
        for (i = 0; i < 10; ++i) {
            if (right < 10) {
                if (a[root] > a[left] || a[root] > a[right]) {
                    if (a[left] < a[right]) {
                        swap = a[root];
                        a[root] = a[left];
                        a[left] = swap;
                        b = 1;
                    } else if (a[right] < a[left]) {
                        swap = a[root];
                        a[root] = a[right];
                        a[right] = swap;
                        b = 1;
                    }
                }
            } else if (left < 10) {
                if (a[root] > a[left]) {
                    swap = a[root];
                    a[root] = a[left];
                    a[left] = swap;
                    b = 1;
                    b = 1;
                }
            }
        }
        if (!b) sh++;
        if (sh + 2 == 10) break;
    }
}
