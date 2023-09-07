#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
void output(int *numbers, int number, int length);

int main() {
    int arr[NMAX], n, array[NMAX];
    if (input(arr, &n) == 0) {
        int sum = sum_numbers(arr, n);
        int num = find_numbers(arr, n, sum, array);
        output(array, sum, num);
    }

    else
        printf("n/a\n");
}

int input(int *buffer, int *length) {
    char t, u;

    if ((scanf("%d%c", length, &t) == 2 && *length <= NMAX && *length > 0) && (t == ' ' || t == '\n')) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if ((scanf("%d%c", p, &u)) && (u == ' ' || u == '\n')) {
                continue;
            } else
                return 1;
            break;
        }
    } else
        return 1;
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int k = 0;
    for (int i = 0; i < length; i++) {
        if (number != 0 && buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[k] = buffer[i];
            k++;
        } else if (number == 0 || buffer[i] == 0 || number % buffer[i] != 0)
            continue;
    }
    return k;
}

void output(int *buffer, int number, int length) {
    printf("%d\n", number);
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}