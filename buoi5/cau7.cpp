#include <stdio.h>

// Ham de quy tinh so tien sau m nam
double tinhLaiSuat(int n, double x, int m) {
    if (m == 0) {
        return n;  // Sau 0 nam thi so tien van la so tien goc
    } else {
        return tinhLaiSuat(n, x, m - 1) * (1 + x / 100);
    }
}

int main() {
    int n;  // So tien goi ban dau (trieu dong)
    double x;  // Lai suat moi nam (%)
    int m;  // So nam goi

    // Nhap vao cac gia tri
    printf("Nhap so tien goi ban dau (trieu dong): ");
    scanf("%d", &n);
    printf("Nhap lai suat moi nam (%%): ");
    scanf("%lf", &x);
    printf("Nhap so nam goi: ");
    scanf("%d", &m);

    // Tinh so tien sau m nam
    double ketQua = tinhLaiSuat(n, x, m);
    printf("So tien sau %d nam la: %.2lf trieu dong\n", m, ketQua);

    return 0;
}

