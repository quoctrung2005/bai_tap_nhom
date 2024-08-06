#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc KhachHang
typedef struct {
    char hoVaTen[50];
    char soDienThoai[20];
    int soVeNguoiLon;
    int soVeTreEm;
    char tenPhim[100];
    char phongChieu[20];
    char xuatChieu[20];
    int tienPhaiTra;
} KhachHang;

#define MAX 100

KhachHang dskh[MAX];
int soLuongKhachHang = 0;

// Doc danh sach khach hang tu file
void docDanhSachKhachHang(const char* tenFile) {
    FILE* file = fopen(tenFile, "r");
    if (!file) {
        printf("Khong the mo file %s\n", tenFile);
        return;
    }

    while (fscanf(file, "%49[^,],%19[^,],%d,%d,%99[^,],%19[^,],%19[^,],%d\n",
        dskh[soLuongKhachHang].hoVaTen,
        dskh[soLuongKhachHang].soDienThoai,
        &dskh[soLuongKhachHang].soVeNguoiLon,
        &dskh[soLuongKhachHang].soVeTreEm,
        dskh[soLuongKhachHang].tenPhim,
        dskh[soLuongKhachHang].phongChieu,
        dskh[soLuongKhachHang].xuatChieu,
        &dskh[soLuongKhachHang].tienPhaiTra) != EOF) {
        soLuongKhachHang++;
    }

    fclose(file);
}

// Xuat danh sach khach hang ra man hinh
void xuatDanhSachKhachHang() {
    for (int i = 0; i < soLuongKhachHang; i++) {
        printf("Khach hang %d:\n", i + 1);
        printf("Ho va ten: %s\n", dskh[i].hoVaTen);
        printf("So dien thoai: %s\n", dskh[i].soDienThoai);
        printf("So ve nguoi lon: %d\n", dskh[i].soVeNguoiLon);
        printf("So ve tre em: %d\n", dskh[i].soVeTreEm);
        printf("Ten phim: %s\n", dskh[i].tenPhim);
        printf("Phong chieu: %s\n", dskh[i].phongChieu);
        printf("Xuat chieu: %s\n", dskh[i].xuatChieu);
        printf("Tien phai tra: %d\n", dskh[i].tienPhaiTra);
        printf("\n");
    }
}

// Tinh tien phai tra cho moi khach hang
void tinhTienPhaiTra() {
    for (int i = 0; i < soLuongKhachHang; i++) {
        dskh[i].tienPhaiTra = dskh[i].soVeNguoiLon * 40000 + dskh[i].soVeTreEm * 20000;
    }
}

// Tinh tong doanh thu cua rap phim
int tinhTongDoanhThu() {
    int tongDoanhThu = 0;
    for (int i = 0; i < soLuongKhachHang; i++) {
        tongDoanhThu += dskh[i].tienPhaiTra;
    }
    return tongDoanhThu;
}

// Tinh tong doanh thu cua tung phim
void tinhDoanhThuTungPhim() {
    char phimDaTinh[MAX][100];
    int soPhimDaTinh = 0;

    for (int i = 0; i < soLuongKhachHang; i++) {
        int daTinh = 0;
        for (int j = 0; j < soPhimDaTinh; j++) {
            if (strcmp(dskh[i].tenPhim, phimDaTinh[j]) == 0) {
                daTinh = 1;
                break;
            }
        }

        if (!daTinh) {
            strcpy(phimDaTinh[soPhimDaTinh], dskh[i].tenPhim);
            soPhimDaTinh++;

            int doanhThu = 0;
            for (int j = 0; j < soLuongKhachHang; j++) {
                if (strcmp(dskh[i].tenPhim, dskh[j].tenPhim) == 0) {
                    doanhThu += dskh[j].tienPhaiTra;
                }
            }
            printf("Doanh thu phim %s: %d\n", dskh[i].tenPhim, doanhThu);
        }
    }
}

// Xuat thong tin khach hang dat ve cua phong chieu x va xuat chieu y
void xuatKhachHangTheoPhongVaXuatChieu(char* phong, char* xuat) {
    for (int i = 0; i < soLuongKhachHang; i++) {
        if (strcmp(dskh[i].phongChieu, phong) == 0 && strcmp(dskh[i].xuatChieu, xuat) == 0) {
            printf("Khach hang %d:\n", i + 1);
            printf("Ho va ten: %s\n", dskh[i].hoVaTen);
            printf("So dien thoai: %s\n", dskh[i].soDienThoai);
            printf("So ve nguoi lon: %d\n", dskh[i].soVeNguoiLon);
            printf("So ve tre em: %d\n", dskh[i].soVeTreEm);
            printf("Ten phim: %s\n", dskh[i].tenPhim);
            printf("Phong chieu: %s\n", dskh[i].phongChieu);
            printf("Xuat chieu: %s\n", dskh[i].xuatChieu);
            printf("Tien phai tra: %d\n", dskh[i].tienPhaiTra);
            printf("\n");
        }
    }
}

// Ham so sanh de sap xep theo tien phai tra tang dan
int soSanhTienPhaiTra(const void* a, const void* b) {
    return ((KhachHang*)a)->tienPhaiTra - ((KhachHang*)b)->tienPhaiTra;
}

// Sap xep danh sach khach hang theo tien phai tra tang dan
void sapXepTheoTienPhaiTra() {
    qsort(dskh, soLuongKhachHang, sizeof(KhachHang), soSanhTienPhaiTra);
}

// Ham so sanh de sap xep theo ho ten tang dan
int soSanhHoTen(const void* a, const void* b) {
    return strcmp(((KhachHang*)a)->hoVaTen, ((KhachHang*)b)->hoVaTen);
}

// Sap xep danh sach khach hang theo ho ten tang dan
void sapXepTheoHoTen() {
    qsort(dskh, soLuongKhachHang, sizeof(KhachHang), soSanhHoTen);
}

// Tim khach hang co ho ten "Nguyen Van An" bang Binary Search
int timKhachHang(char* ten) {
    int left = 0, right = soLuongKhachHang - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int res = strcmp(dskh[mid].hoVaTen, ten);
        if (res == 0) {
            return mid;
        }
        if (res < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    char tenFile[] = "khachhang.txt";
    docDanhSachKhachHang(tenFile);
    tinhTienPhaiTra();

    printf("Danh sach khach hang:\n");
    xuatDanhSachKhachHang();

    int tongDoanhThu = tinhTongDoanhThu();
    printf("Tong doanh thu cua rap phim: %d\n", tongDoanhThu);

    printf("Doanh thu cua tung phim:\n");
    tinhDoanhThuTungPhim();

    char phong[20], xuat[20];
    printf("Nhap phong chieu: ");
    scanf("%s", phong);
    printf("Nhap xuat chieu: ");
    scanf("%s", xuat);
    printf("Danh sach khach hang o phong chieu %s va xuat chieu %s:\n", phong, xuat);
    xuatKhachHangTheoPhongVaXuatChieu(phong, xuat);

    sapXepTheoTienPhaiTra();
    printf("Danh sach khach hang sau khi sap xep theo tien phai tra tang dan:\n");
    xuatDanhSachKhachHang();

    sapXepTheoHoTen();
    printf("Danh sach khach hang sau khi sap xep theo ho ten tang dan:\n");
    xuatDanhSachKhachHang();

    char tenTimKiem[] = "Nguyen Van An";
    int viTri = timKhachHang(tenTimKiem);
    if (viTri != -1) {
        printf("Khach hang '%s' duoc tim thay tai vi tri %d:\n", tenTimKiem, viTri + 1);
        printf("Ho va ten: %s\n", dskh[viTri].hoVaTen);
        printf("So dien thoai: %s\n", dskh[viTri].soDienThoai);
        printf("So ve nguoi lon: %d\n", dskh[viTri].soVeNguoiLon);
        printf("So ve tre em: %d\n", dskh[viTri].soVeTreEm);
        printf("Ten phim: %s\n", dskh[viTri].tenPhim);
        printf("Phong chieu: %s\n", dskh[viTri].phongChieu);
        printf("Xuat chieu: %s\n", dskh[viTri].xuatChieu);
        printf("Tien phai tra: %d\n", dskh[viTri].tienPhaiTra);
    }
    else {
        printf("Khong tim thay khach hang '%s'\n", tenTimKiem);
    }

    return 0;
}

