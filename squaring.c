#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n, data[NMAX];

  if (input(data, &n) == 0) {
    squaring(data, n);
    output(data, n);
  } else
    printf("n/a\n");
}

int input(int *a, int *n) {
  int g;
  if (scanf("%d.%d", n, &g) == 1 && *n <= NMAX && *n > 0) {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d.%d", p, &g) == 1) {
      } else {
        return 1;
        break;
      }
    }
  } else
    return 1;
  return 0;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    if (i <= n - 2)
      printf("%d ", a[i]);
    else
      printf("%d", a[i]);
  }
  printf("\n");
}

void squaring(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = a[i] * a[i];
  }
}
