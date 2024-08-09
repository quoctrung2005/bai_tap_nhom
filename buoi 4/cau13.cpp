#include <stdio.h>


int find_nth_term_recursive(int n, int a, int q) {
    if (n == 1)
        return a;
    return q * find_nth_term_recursive(n - 1, a, q);
}

int main() {
    int n, a, q;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);
    printf("Nhap gia tri a (hang dau): ");
    scanf("%d", &a);
    printf("Nhap gia tri q (cong boi): ");
    scanf("%d", &q);

    int result = find_nth_term_recursive(n, a, q);
    printf("Gia tri phan tu thu %d cua cap so nhan la: %d\n", n, result);

    return 0;
}

