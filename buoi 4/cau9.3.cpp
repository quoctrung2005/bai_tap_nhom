#include <stdio.h>

int sum_recursive(int n) {
    if (n == 1)
        return 1;
    return n + sum_recursive(n - 1);
}

int S3_recursive(int n) {
    if (n == 1)
        return 1;
    return sum_recursive(n) + S3_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = S3_recursive(n);
    printf("S(n) = %d\n", result);

    return 0;
}

