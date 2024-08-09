#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double S4_recursive(int n) {
    if (n == 1)
        return -(1.0 + 2) / factorial(2);
    double term = pow(-1, n) * ((2 * n - 1) + 2 * n) / factorial(2 * n);
    return term + S4_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    double result = S4_recursive(n);
    printf("S(n) = %lf\n", result);

    return 0;
}

