#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

// Hàm tạo ma trận ngẫu nhiên
void taoMaTran(int a[][MAX], int n, int k) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// 4.1: Sắp xếp đường chéo phụ tăng dần
void sapXepDuongCheoPhuTangDan(int a[][MAX], int n) {
    int* diagonal = (int*)malloc(n * sizeof(int));

    // Lấy các phần tử trên đường chéo phụ
    for (int i = 0; i < n; i++) {
        diagonal[i] = a[i][n - i - 1];
    }

    // Sắp xếp đường chéo phụ tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diagonal[i] > diagonal[j]) {
                int temp = diagonal[i];
                diagonal[i] = diagonal[j];
                diagonal[j] = temp;
            }
        }
    }

    // Gán lại các phần tử vào ma trận
    for (int i = 0; i < n; i++) {
        a[i][n - i - 1] = diagonal[i];
    }

    free(diagonal);
}

// 4.1: Sắp xếp đường chéo phụ giảm dần
void sapXepDuongCheoPhuGiamDan(int a[][MAX], int n) {
    int* diagonal = (int*)malloc(n * sizeof(int));

    // Lấy các phần tử trên đường chéo phụ
    for (int i = 0; i < n; i++) {
        diagonal[i] = a[i][n - i - 1];
    }

    // Sắp xếp đường chéo phụ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diagonal[i] < diagonal[j]) {
                int temp = diagonal[i];
                diagonal[i] = diagonal[j];
                diagonal[j] = temp;
            }
        }
    }

    // Gán lại các phần tử vào ma trận
    for (int i = 0; i < n; i++) {
        a[i][n - i - 1] = diagonal[i];
    }

    free(diagonal);
}

// 4.2: Sắp xếp các dòng của ma trận
void sapXepDong(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (i % 2 == 0) { // Dòng chẵn: giảm dần
                    if (a[i][j] < a[i][k]) {
                        int temp = a[i][j];
                        a[i][j] = a[i][k];
                        a[i][k] = temp;
                    }
                }
                else { // Dòng lẻ: tăng dần
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

// 4.3: Sắp xếp các cột của ma trận
void sapXepCot(int a[][MAX], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if (j % 2 == 0) { // Cột chẵn: tăng dần
                    if (a[i][j] > a[k][j]) {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
                else { // Cột lẻ: giảm dần
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

// 4.4: Sắp xếp các phần tử trên các đường chéo chính và song song với đường chéo chính
void sapXepDuongCheoChinhTangDan(int a[][MAX], int n) {
    // Lấy các phần tử trên đường chéo chính và các đường chéo song song
    for (int d = -n + 1; d < n; d++) {
        int size = (d < 0) ? (n + d) : (n - d);
        int* diagonal = (int*)malloc(size * sizeof(int));

        // Lấy các phần tử trên đường chéo chính hoặc song song
        for (int i = 0; i < size; i++) {
            int row = (d >= 0) ? i : i - d;
            int col = (d >= 0) ? i + d : i;
            diagonal[i] = a[row][col];
        }

        // Sắp xếp đường chéo
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (diagonal[i] > diagonal[j]) {
                    int temp = diagonal[i];
                    diagonal[i] = diagonal[j];
                    diagonal[j] = temp;
                }
            }
        }

        // Gán lại các phần tử vào ma trận
        for (int i = 0; i < size; i++) {
            int row = (d >= 0) ? i : i - d;
            int col = (d >= 0) ? i + d : i;
            a[row][col] = diagonal[i];
        }

        free(diagonal);
    }
}

// 4.5: Di chuyển các phần tử chẵn và lẻ
void sapXepChanLe(int a[][MAX], int n) {
    int* temp = (int*)malloc(n * n * sizeof(int));
    int index = 0;

    // Lấy các phần tử chẵn
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                temp[index++] = a[i][j];
            }
        }
    }

    // Lấy các phần tử lẻ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                temp[index++] = a[i][j];
            }
        }
    }

    // Gán lại các phần tử vào ma trận
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[index++];
        }
    }

    free(temp);
}

// 4.6: Kiểm tra đối xứng qua đường chéo chính
int kiemTraDoiXung(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n = 4, k = 20; // Ví dụ: ma trận 4x4 với các phần tử từ 0 đến 20
    int a[MAX][MAX];

    taoMaTran(a, n, k);
    printf("Ma tran ngau nhien:\n");
    xuatMaTran(a, n);

    printf("\nSắp xếp đường chéo phụ tăng dần:\n");
    sapXepDuongCheoPhuTangDan(a, n);
    xuatMaTran(a, n);

    printf("\nSắp xếp đường chéo phụ giảm dần:\n");
    sapXepDuongCheoPhuGiamDan(a, n);
    xuatMaTran(a, n);

    printf("\nSắp xếp các dòng của ma trận:\n");
    sapXepDong(a, n);
    xuatMaTran(a, n);

    printf("\nSắp xếp các cột của ma trận:\n");
    sapXepCot(a, n);
    xuatMaTran(a, n);

    printf("\nSắp xếp các phần tử trên các đường chéo chính và song song:\n");
    sapXepDuongCheoChinhTangDan(a, n);
    xuatMaTran(a, n);

    printf("\nDi chuyển các phần tử chẵn và lẻ:\n");
    sapXepChanLe(a, n);
    xuatMaTran(a, n);

    int isSymmetric = kiemTraDoiXung(a, n);
    printf("\nMa tran doi xung qua duong cheo chinh: %s\n", isSymmetric ? "Co" : "Khong");

    return 0;
}
