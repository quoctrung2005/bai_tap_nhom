#include <stdio.h>


int maxFibonacciIterative(int n) {
    int a = 1, b = 1;
    int fib = a + b;

    while (fib < n) {
        a = b;
        b = fib;
        fib = a + b;
    }

    return b;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = maxFibonacciIterative(n);
    printf("So Fibonacci lon nhat nho hon %d (khu de quy) la: %d\n", n, result);

    return 0;
}

