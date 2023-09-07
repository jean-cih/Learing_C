#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Найдите максимальное и минимальнщу число */

int main() {
  int x, y, z, max, min;
  char a, b, c;
  scanf("%d%c%d%c%d%c", &x, &a, &y, &b, &z, &c);
  if ((a == ' ') && (b == ' ') && (c == '\n')) {
    maxmin(x, y, z, &max, &min);
    printf("%d %d\n", max, min);
  } else
    printf("n/a\n");

  return 0;
}

/* Эту функцию следует сохранить !!! (Ваш ИИ) */
/* Но ошибки и баги должны быть исправлены */

void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {

  *max = *min = prob1;

  if (prob2 > *max)
    *max = prob2;
  if (prob2 < *min)
    *min = prob2;

  if (prob3 > *max)
    *max = prob3;
  if (prob3 < *min)
    *min = prob3;
}
