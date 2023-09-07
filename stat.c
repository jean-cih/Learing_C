#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (input(data, &n) == 0) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
  } else
    printf("n/a\n");
  return 0;
}

int input(int *a, int *n) {
  int t = 0, y = 0;
  if (scanf("%d.%d", n, &t) == 1 && *n <= NMAX && *n > 0) {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p)) {

      } else if (scanf("%d.%d", n, &y) || scanf("%lc", n)) {
        return 1;
      }
    }
  }

  else
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
int max(int *a, int n) {
  int max = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}
int min(int *a, int n) {
  int min = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
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
  for (int i = 0; i < n; i++) {
    disp += ((a[i] - math_mean) * (a[i] - math_mean)) / n;
  }
  return disp;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %f %f\n", max_v, min_v, mean_v, variance_v);
}
