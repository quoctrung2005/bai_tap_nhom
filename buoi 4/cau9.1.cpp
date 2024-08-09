#include <stdio.h>

double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double S1_recursive(int n) {
    if (n == 1)
        return 1.0 / (1 * 2 * 3);
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    double result = S1_recursive(n);
    printf("S(n) = %lf\n", result);

    return 0;
}
 
