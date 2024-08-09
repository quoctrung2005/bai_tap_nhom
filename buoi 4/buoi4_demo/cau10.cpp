#include <stdio.h>


int fibonacci(int n) {
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


void xuatFibonacci(int m, int n) {
    int i = 1;
    int fib;

   
    while (1) {
        fib = fibonacci(i);
        if (fib >= m)
            break;
        i++;
    }

 
    while (fib <= n) {
        printf("%d ", fib);
        i++;
        fib = fibonacci(i);
    }
}

int main() {
    int m, n;
    printf("Nhap m: ");
    scanf("%d", &m);
    printf("Nhap n: ");
    scanf("%d", &n);

    printf("Cac so Fibonacci trong doan [%d, %d]: ", m, n);
    xuatFibonacci(m, n);
    printf("\n");

    return 0;
}

