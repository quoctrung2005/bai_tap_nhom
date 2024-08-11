#include <stdio.h>

// a. Tim chu so dau tien cua n (de quy)
int chuSoDauTien(int n) {
    if (n < 10) {
        return n;  // Chu so dau tien la chu so duy nhat con lai
    }
    return chuSoDauTien(n / 10);
}

// b. Tim chu so dao nguoc cua so nguyen duong n (de quy)
int daoNguocHelper(int n, int soDaoNguoc) {
    if (n == 0) {
        return soDaoNguoc;
    }
    return daoNguocHelper(n / 10, soDaoNguoc * 10 + n % 10);
}

int daoNguoc(int n) {
    return daoNguocHelper(n, 0);
}

// c. Tim chu so lon nhat cua so nguyen duong n (de quy)
int chuSoLonNhat(int n) {
    if (n < 10) {
        return n;  // Neu n chi co 1 chu so, no chinh la chu so lon nhat
    }
    int maxCuaPhanConLai = chuSoLonNhat(n / 10);  // Goi de quy cho phan con lai
    int chuSoCuoi = n % 10;  // Lay chu so cuoi cung
    return (chuSoCuoi > maxCuaPhanConLai) ? chuSoCuoi : maxCuaPhanConLai;
}

// d. Tim chu so nho nhat cua so nguyen duong n (de quy)
int chuSoNhoNhat(int n) {
    if (n < 10) {
        return n;  // Neu n chi co 1 chu so, no chinh la chu so nho nhat
    }
    int minCuaPhanConLai = chuSoNhoNhat(n / 10);  // Goi de quy cho phan con lai
    int chuSoCuoi = n % 10;  // Lay chu so cuoi cung
    return (chuSoCuoi < minCuaPhanConLai) ? chuSoCuoi : minCuaPhanConLai;
}

// e. Kiem tra so nguyen duong n co toan chu so le hay khong (de quy)
int kiemTraToanLe(int n) {
    if (n == 0) {
        return 1;  // Ket thuc de quy, tat ca cac chu so da duoc kiem tra
    }
    if ((n % 10) % 2 == 0) {
        return 0;  // Neu co chu so chan, tra ve 0
    }
    return kiemTraToanLe(n / 10);
}

// f. Kiem tra so nguyen duong n co toan chu so chan hay khong (de quy)
int kiemTraToanChan(int n) {
    if (n == 0) {
        return 1;  // Ket thuc de quy, tat ca cac chu so da duoc kiem tra
    }
    if ((n % 10) % 2 != 0) {
        return 0;  // Neu co chu so le, tra ve 0
    }
    return kiemTraToanChan(n / 10);
}

int main() {
    int n;

    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    printf("Chu so dau tien cua %d la: %d\n", n, chuSoDauTien(n));
    printf("Chu so dao nguoc cua %d la: %d\n", n, daoNguoc(n));
    printf("Chu so lon nhat cua %d la: %d\n", n, chuSoLonNhat(n));
    printf("Chu so nho nhat cua %d la: %d\n", n, chuSoNhoNhat(n));
    printf("So %d co toan chu so le hay khong? %s\n", n, kiemTraToanLe(n) ? "Co" : "Khong");
    printf("So %d co toan chu so chan hay khong? %s\n", n, kiemTraToanChan(n) ? "Co" : "Khong");

    return 0;
}

