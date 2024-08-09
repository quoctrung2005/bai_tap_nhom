#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo ma trận ngẫu nhiên
void taoMaTran(int a[][100], int m, int n, int k) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// 3.1: Xuất các cột chỉ chứa số lẻ
void xuatCacCotSoLe(int a[][100], int m, int n) {
    for (int j = 0; j < n; j++) {
        int isOddColumn = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                isOddColumn = 0;
                break;
            }
        }
        if (isOddColumn) {
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// 3.2: Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
int timMaxTrenBien(int a[][100], int m, int n) {
    int max = a[0][0];
    for (int i = 0; i < m; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
        if (a[m - 1][j] > max) max = a[m - 1][j];
    }
    return max;
}

// 3.3: Đếm số phần tử có chứa chữ số 2
int coChuSo2(int n) {
    while (n != 0) {
        if (n % 10 == 2) return 1;
        n /= 10;
    }
    return 0;
}

int demPhanTuCoChuSo2(int a[][100], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (coChuSo2(a[i][j])) count++;
        }
    }
    return count;
}

// 3.4: Xuất các phần tử cực tiểu của ma trận
void xuatCucTieu(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMin = 1;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] <= a[i][j]) {
                        isMin = 0;
                        break;
                    }
                }
                if (!isMin) break;
            }
            if (isMin) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

// 3.5: Sắp xếp các dòng của ma trận theo yêu cầu
void sapXepDong(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (i % 2 == 0) { // Dòng chẵn
                    if (a[i][j] < a[i][k]) {
                        int temp = a[i][j];
                        a[i][j] = a[i][k];
                        a[i][k] = temp;
                    }
                }
                else { // Dòng lẻ
                    if (a[i][j] > a[i][k]) {
                        int temp = a[i][j];
                        a[i][j] = a[i][k];
                        a[i][k] = temp;
                    }
                }
            }
        }
    }
}

// 3.6: Sắp xếp các cột của ma trận theo yêu cầu
void sapXepCot(int a[][100], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if (j % 2 == 0) { // Cột chẵn
                    if (a[i][j] > a[k][j]) {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
                else { // Cột lẻ
                    if (a[i][j] < a[k][j]) {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
    }
}

// 3.7: Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
int kiemTraGiamDanZicZac(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            if (a[i][j] < a[i + 1][j]) return 0;
        }
    }
    return 1;
}

// 3.8: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongChan(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        int allEven = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = 0;
                break;
            }
        }
        if (allEven) printf("Dong %d\n", i);
    }
}

// 3.9: Liệt kê các dòng chứa giá trị giảm dần
void lietKeDongGiamDan(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        int isDescending = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                isDescending = 0;
                break;
            }
        }
        if (isDescending) printf("Dong %d\n", i);
    }
}

// 3.10: Tìm giá trị xuất hiện nhiều nhất trong ma trận
int timGiaTriXuatHienNhieuNhat(int a[][100], int m, int n) {
    int count[1001] = { 0 }; // Giả sử giá trị phần tử trong khoảng từ 0 đến 1000
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            count[a[i][j]]++;
        }
    }
    int maxValue = 0, maxCount = 0;
    for (int i = 0; i <= 1000; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxValue = i;
        }
    }
    return maxValue;
}

// 3.11: Tìm các chữ số xuất hiện nhiều nhất trong ma trận
void timChuSoXuatHienNhieuNhat(int a[][100], int m, int n) {
    int digitCount[10] = { 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num > 0) {
                digitCount[num % 10]++;
                num /= 10;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > maxCount) {
            maxCount = digitCount[i];
        }
    }
    printf("Cac chu so xuat hien nhieu nhat: ");
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 3.12: Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[][100], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    for (int j = 1; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += a[i][j];
        }
        if (colSum < minSum) {
            minSum = colSum;
        }
    }
    printf("Cac cot co tong nho nhat: ");
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += a[i][j];
        }
        if (colSum == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// 3.13: Hoán vị hai cột i và j trong ma trận
void hoanViCot(int a[][100], int m, int col1, int col2) {
    for (int i = 0; i < m; i++) {
        int temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}

// 3.14: Hoán vị hai dòng k và l trong ma trận
void hoanViDong(int a[][100], int row1, int row2, int n) {
    for (int j = 0; j < n; j++) {
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}

int main() {
    int m = 5, n = 6, k = 20; 
    int a[100][100];

    taoMaTran(a, m, n, k);
    printf("Ma tran ngau nhien:\n");
    xuatMaTran(a, m, n);

    printf("\nCac cot chi chua so le:\n");
    xuatCacCotSoLe(a, m, n);

    int maxBien = timMaxTrenBien(a, m, n);
    printf("\nPhan tu lon nhat tren bien: %d\n", maxBien);

    int countChuSo2 = demPhanTuCoChuSo2(a, m, n);
    printf("\nSo phan tu co chu so 2: %d\n", countChuSo2);

    printf("\nCac phan tu cuc tieu cua ma tran:\n");
    xuatCucTieu(a, m, n);

    printf("\nSap xep dong cua ma tran:\n");
    sapXepDong(a, m, n);
    xuatMaTran(a, m, n);

    printf("\nSap xep cot cua ma tran:\n");
    sapXepCot(a, m, n);
    xuatMaTran(a, m, n);

    int isZicZac = kiemTraGiamDanZicZac(a, m, n);
    printf("\nMa tran giam dan ziczac: %s\n", isZicZac ? "Co" : "Khong");

    printf("\nChi so cac dong chua toan gia tri chan:\n");
    lietKeDongChan(a, m, n);

    printf("\nCac dong chua gia tri giam dan:\n");
    lietKeDongGiamDan(a, m, n);

    int mostFrequentValue = timGiaTriXuatHienNhieuNhat(a, m, n);
    printf("\nGia tri xuat hien nhieu nhat: %d\n", mostFrequentValue);

    printf("\nCac chu so xuat hien nhieu nhat trong ma tran:\n");
    timChuSoXuatHienNhieuNhat(a, m, n);

    printf("\nCac cot co tong nho nhat:\n");
    lietKeCotTongNhoNhat(a, m, n);

    printf("\nHoan vi cot 1 va 2 cua ma tran:\n");
    hoanViCot(a, m, 1, 2);
    xuatMaTran(a, m, n);

    printf("\nHoan vi dong 1 va 2 cua ma tran:\n");
    hoanViDong(a, 1, 2, n);
    xuatMaTran(a, m, n);

    return 0;
}
