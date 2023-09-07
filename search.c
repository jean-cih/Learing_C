#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
void output(int *a, int n);
double variance(int *a, int n);

int main() {
  int n, data[NMAX];
  int disaster = 0;
  if (input(data, &n) == 0) {
    double u = mean(data, n);
    double r = variance(data, n);
    for (int l = 0; l < n; l++) {
      if ((data[l] % 2 == 0) && (data[l] >= u) &&
          ((data[l] >= u - 3 * r) || (data[l] <= u + 3 * r))) {
        printf("%d\n", data[l]);
        disaster = 1;
        if (disaster == 1) {
          break;
        }
      }
    }
    if (disaster == 1) {

    } else
      printf("0\n");

  } else
    printf("n/a\n");

  return 0;
}

int input(int *a, int *n) {
  int t = 0, y = 0;
  if ((scanf("%d.%d", n, &t) == 1) && *n <= NMAX && *n > 0) {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p)) {
      } else if (scanf("%d.%d", n, &y) || scanf("%lc", n)) {
        return 1;
      }
    }
  } else
    return 1;
  return 0;
}
double mean(int *a, int n) {
  double h = 0;
  double math_mean = 0;
  for (int i = 0; i < n; i++) {
    h += a[i];
  }
  math_mean = (double)h / n;
  return math_mean;
}
double variance(int *a, int n) {
  double math_mean = mean(a, n);
  double disp = 0;
  double sq_disp = 0;
  for (int i = 0; i < n; i++) {
    disp += ((a[i] - math_mean) * (a[i] - math_mean)) / (n - 1);
  }
  sq_disp = sqrt(disp);
  return sq_disp;
}