#include <stdio.h>


int fibonacci(int n) {
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int maxFibonacciRecursive(int n, int i) {
    int fib = fibonacci(i);
    if (fib >= n)
        return fibonacci(i - 1);
    return maxFibonacciRecursive(n, i + 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = maxFibonacciRecursive(n, 1);
    printf("So Fibonacci lon nhat nho hon %d (de quy) la: %d\n", n, result);

    return 0;
}

