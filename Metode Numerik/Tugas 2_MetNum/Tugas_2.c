#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

float Polynomial(float a[], int degree, float x)
{
    float result = 0;

    for (int i = degree; i >= 0; i--)
    {
        result += a[i] * pow(x, i);
    }
    return result;
}

float Derivative(float a[], int degree, float x)
{
    float result = 0;

    for (int i = degree; i >= 0; i--)
    {
        result += i * a[i] * pow(x, i - 1);
    }
    return result;
}

int Biseksi(float coeff[], int deg) {
    int N;
    float x, a, b, TOL, result_a, result_b, result_x, err;

    printf("Masukan nilai a: ");
    scanf("%f", &a);
    printf("Masukan nilai b: ");
    scanf("%f", &b);

    result_a = Polynomial(coeff, deg, a);
    result_b = Polynomial(coeff, deg, b);

    if ((result_a < 0 && result_b > 0) || (result_a > 0 && result_b < 0)) {
        printf("Masukan nilai TOL: ");
        scanf("%f", &TOL);
        printf("Masukan nilai N: ");
        scanf("%d", &N);

        int i = 1;

        if (result_a * result_b > 0){
            printf("Tidak ada solusi\n");
        } else {
            while (i <= N) {
                x = (a + b) / 2;
                result_x = Polynomial(coeff, deg, x);
                printf("|%d.| |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f  |, |%.10f|\n", 
                        i, a, b, (a + b)/2, result_a, result_b, Polynomial(coeff, deg, (a + b)/2), err);
                err = fabs(b - a);
                if (result_x * result_a > 0) {
                    a = x;
                    result_a = result_x;
                }
                else {
                    b = x;
                    result_b = result_x;
                }
                if (fabs((b - a) / 2) < TOL) {
                    printf("\nNilai akar yang memenuhi: %.10f\n", x);
                    break;
                }
                i++;
            }
        }

    } else {
        printf("\nERROR!! Nilai a dan b harus berbeda tanda!");
    }
}

int IterasiSederhana(float coeff[], int deg) {
    int N, degree;
    float x, TOL, result_xn, err;

    printf("Masukan nilai x_0: ");
    scanf("%f", &x);
    printf("Masukan nilai TOL: ");
    scanf("%f", &TOL);
    printf("Masukan nilai N: ");
    scanf("%d", &N);

    int i = 1;
    printf("|No|, |x_n|, \t|F(x_n)|\n");
    while(i <= N) {
        result_xn = Polynomial(coeff, deg, x);
        printf("|%d.| |%.10f|, |%.10f|\n", 
                i, x, Polynomial(coeff, deg, x));
        if (fabs(result_xn - x) < TOL){
            printf("\nNilai akar yang memenuhi: %.10f\n", x);
            break;
        }
        x = result_xn;
        i++;
        
    }

}

int IterasiAitken(float coeff[], int deg) {
    int N;
    float x, delta_x[10], delta_square_x[10], result_common_iteration[10];

    printf("Masukan nilai x_0: ");
    scanf("%f", &x);
    printf("Masukan nilai N: ");
    scanf("%d", &N);

    int i = 1;
    printf("|No| |delta_x\t|\n");
    while(i <= N) {
        
        result_common_iteration[i] = Polynomial(coeff, deg, x);
        if (i <= 2) {
            delta_x[i] = result_common_iteration[i] - x;
            printf("|%d.| |%.10f|, |%.10f|\n", 
                    i - 1, x, delta_x[i], delta_square_x[i + 1]);
            x = result_common_iteration[i];
        } else {
            printf("|%d.| |%.10f|\n", 
                    i - 1, x, delta_x[i], delta_square_x[i + 1]);
            delta_square_x[i] = delta_x[i-1] - delta_x[i-2];
            printf("\nNilai Delta kuadrat ke %d: %.10f\n", (i - 2), delta_square_x[i]);

            float x3;
            x3 = x - pow(delta_x[i - 1], 2) / delta_square_x[i];
            printf("Nilai dari x_3: %.10f\n", x3);
        }
        i++;
    }

}

int RegulaFalsi(float coeff[], int deg) {
    int N;
    float x_n, x_nplus1, x_asterisk, TOL, result_x_n, result_x_nplus1, result_x_asterisk, err;

    printf("Masukan nilai X_n: ");
    scanf("%f", &x_n);
    printf("Masukan nilai X_n+1: ");
    scanf("%f", &x_nplus1);
    printf("Masukan jumlah iterasi: ");
    scanf("%d", &N);
    printf("Masukan nilai error: ");
    scanf("%f", &err);

    result_x_n = Polynomial(coeff, deg, x_n);
    result_x_nplus1 = Polynomial(coeff, deg, x_nplus1);

    int i = 1;
    while (i <= N){
        x_asterisk = x_n - (result_x_n * (x_nplus1 - x_n)) / (result_x_nplus1 - result_x_n);
        result_x_asterisk = Polynomial(coeff, deg, x_asterisk);
        printf("|%d.| |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f|\n", 
                i, x_n, x_nplus1, result_x_n, result_x_nplus1, x_asterisk, result_x_asterisk);
        if (fabs(result_x_asterisk) < err) {
            printf("\nNilai akar yang memenuhi: %.10f\n", x_asterisk);
            break;
        }
        if (result_x_asterisk * result_x_n > 0) {
            x_n = x_asterisk;
            result_x_n = result_x_asterisk;
        } else {
            x_nplus1 = x_asterisk;
            result_x_nplus1 = result_x_asterisk;
        }
        i++;
    }
}

int NewtonRaphson(float coeff[], int deg) {
    int N;
    float x_n, x_nplus1, TOL;

    printf("Masukan nilai x_n: ");
    scanf("%f", &x_n);
    printf("Masukan jumlah iterasi: ");
    scanf("%d", &N);
    printf("Masukan nilai TOL: ");
    scanf("%f", &TOL);

    int i = 1;
    while(i <= N) {
        x_nplus1 = x_n - Polynomial(coeff, deg, x_n) / Derivative(coeff, deg, x_n);
        printf("|%d.| |%.10f|\n", 
                i, x_n);
        if (fabs(x_nplus1 - x_n) < TOL) {
            printf("\nNilai akar yang memenuhi: %.10f\n", x_nplus1);
            break;
        }
        x_n = x_nplus1;
        i++;
    }
}

int main(){
    system("cls");
    float x, coeff[100], y1;
    int deg, j, no_menu;
    char next, stay;
    
    Utama:
    system("cls");
    printf("SELAMAT DATANG DI APLIKASI ALGORITMA PENCARIAN SOLUSI DARI POLINOM\n\n");
    printf("Pilih menu yang tersedia:\n");
    printf("1. Metode Biseksi\n");
    printf("2. Metode Iterasi Sederhana\n");
    printf("3. Metode Iterasi Aitken\n");
    printf("4. Metode Regula Falsi\n");
    printf("5. Metode Newton Raphson\n");
    printf("6. Keluar\n\n");
    printf("Masukan nomor menu: ");
    scanf("%d", &no_menu);
    system("cls");

    switch (no_menu) {
        case 1:
            printf("ALGORITMA BISEKSI\n\n");
            printf("Ketentuan dari algoritma ini antara lain:\n");
            printf("1. User memasukan langsung nilai batas bawah (a) dan batas atas (b);\n");
            printf("2. User memasukan nilai toleransi (TOL) secara manual;\n");
            printf("3. User memasukan nilai iterasi (N); dan\n");
            printf("4. User memasukan secara manual fungsi polinomial yang ingin diketahui solusinya.\n\n");
            printf("Untuk contoh implementasi, silahkan gunakan polinomial berikut: x^3 + x^2 - 3x - 3\n");
            printf("Masukan nilai a: 1, nilai b: 2\n");
            printf("Masukan nilai TOL: 0.0001\n");
            printf("Silahkan diingat input polinom, a, b, dan TOL nya.\n\n");

            printf("Lanjut ke implementasi? (y/n): ");
            scanf(" %c", &next);
            if (next == 'y') {
                system("cls");
                Biseksi:
                system("cls");
                printf("Masukan derajat polinom: ");
                scanf("%d", &deg);
                for (j = 0; j <= deg; j++) {
                    printf("Masukan nilai koefisien setiap x pangkat %d: ", j);
                    scanf("%f", &coeff[j]);
                }

                Biseksi(coeff, deg);

                printf("Mau ulangi? (y/n): ");
                scanf(" %c", &stay);
                if (stay == 'y')
                    goto Biseksi;
                else
                    goto Utama;
            } else {
                goto Utama;
            }
            break;

        case 2:
            printf("ALGORITMA ITERASI SEDERHANA\n\n");
            printf("Ketentuan dari algoritma ini antara lain:\n");
            printf("1. User memasukan secara manual nilai x awal;\n");
            printf("2. User memasukan nilai toleransi (TOL) secara manual;\n");
            printf("3. User memasukan nilai iterasi (N); dan\n");
            printf("4. User memasukan secara manual fungsi polinomial yang ingin diketahui solusinya.\n\n");
            printf("Untuk contoh implementasi, silahkan gunakan polinomial berikut: 2/7(x^3 - 1)\n");
            printf("Masukan nilai x awal: 1\n");
            printf("Silahkan diingat input polinom dan x nya.\n\n");
            printf("NOTE: Jika koefisien polinomial berbentuk pecahan, jangan lupa mengubahnya menjadi bilangan desimal\ndengan angka signifikan yang sesuai dengan ketentuan pada soal.");
            
            printf("\nLanjut ke implementasi? (y/n): ");
            scanf(" %c", &next);
            if (next == 'y') {
                system("cls");
                IterasiSederhana:
                system("cls");
                printf("Masukan derajat polinom: ");
                scanf("%d", &deg);
                for (j = 0; j <= deg; j++) {
                    printf("Masukan nilai koefisien setiap x pangkat %d: ", j);
                    scanf("%f", &coeff[j]);
                }

                IterasiSederhana(coeff, deg);

                printf("Mau ulangi? (y/n): ");
                scanf(" %c", &stay);
                if (stay == 'y')
                    goto IterasiSederhana;
                else
                    goto Utama;
            } else {
                goto Utama;
            }
            break;

        case 3:
            printf("ALGORITMA ITERASI AITKEN\n\n");
            printf("Ketentuan dari algoritma ini antara lain:\n");
            printf("1. User memasukan secara manual nilai x_0;\n");
            printf("2. User memasukan secara manual jumlah iterasi (N);\n");
            printf("3. User memasukan secara manual derajat polinomial; dan\n");
            printf("4. User memasukan secara manual fungsi polinomial yang ingin diketahui solusinya.\n\n");
            printf("Untuk contoh implementasi, silahkan gunakan polinomial berikut: (x^2 + 8)/6\n");
            printf("Masukan nilai x_0: 1\n");
            printf("Masukan jumlah iterasi: 4\n");
            printf("Silahkan diingat input polinom dan x nya.\n\n");
            printf("NOTE: Jika koefisien polinomial berbentuk pecahan, jangan lupa mengubahnya menjadi bilangan desimal\ndengan angka signifikan yang sesuai dengan ketentuan pada soal.");
            
            printf("\nLanjut ke implementasi? (y/n): ");
            scanf(" %c", &next);
            if (next == 'y') {
                system("cls");
                IterasiAitken:
                system("cls");
                printf("Masukan derajat polinom: ");
                scanf("%d", &deg);
                for (j = 0; j <= deg; j++) {
                    printf("Masukan nilai koefisien setiap x pangkat %d: ", j);
                    scanf("%f", &coeff[j]);
                }

                IterasiAitken(coeff, deg);

                printf("Mau ulangi? (y/n): ");
                scanf(" %c", &stay);
                if (stay == 'y')
                    goto IterasiAitken;
                else
                    goto Utama;
            } else {
                goto Utama;
            }
            break;

        case 4:
            printf("ALGORITMA REGULA FALSI\n\n");
            printf("Ketentuan dari algoritma ini antara lain:\n");
            printf("1. User memasukan secara manual nilai x_n;\n");
            printf("2. User memasukan secara manual nilai x_n+1;\n");
            printf("3. User memasukan secara manual jumlah iterasi (N);\n");
            printf("4. User memasukan secara manual nilai error (EPSILON); dan\n");
            printf("5. User memasukan secara manual fungsi polinomial yang ingin diketahui solusinya.\n");
            printf("Untuk contoh implementasi, silahkan gunakan polinomial berikut: x^3 - 7x + 1\n");
            printf("Masukan nilai x_n: 2.5, x_n+1: 2.6\n");
            printf("Silahkan diingat input polinom, x_n, dan x_n+1 nya.\n\n");
            printf("NOTE: Jika koefisien polinomial berbentuk pecahan, jangan lupa mengubahnya menjadi bilangan desimal\ndengan angka signifikan yang sesuai dengan ketentuan pada soal.");
            
            printf("\nLanjut ke implementasi? (y/n): ");
            scanf(" %c", &next);
            if (next == 'y') {
                system("cls");
                RegulaFalsi:
                system("cls");
                printf("Masukan derajat polinom: ");
                scanf("%d", &deg);
                for (j = 0; j <= deg; j++) {
                    printf("Masukan nilai koefisien setiap x pangkat %d: ", j);
                    scanf("%f", &coeff[j]);
                }

                RegulaFalsi(coeff, deg);

                printf("Mau ulangi? (y/n): ");
                scanf(" %c", &stay);
                if (stay == 'y')
                    goto RegulaFalsi;
                else
                    goto Utama;
            } else {
                goto Utama;
            }
            break;

        case 5:
            printf("ALGORITMA NEWTON-RAPHSON\n\n");
            printf("Ketentuan dari algoritma ini antara lain:\n");
            printf("1. User memasukan secara manual nilai x_n;\n");
            printf("2. User memasukan secara manual jumlah iterasi (N);\n");
            printf("3. User memasukan secara manual derajat polinomial; dan\n");
            printf("4. User memasukan secara manual fungsi polinomial yang ingin diketahui solusinya.\n\n");
            printf("Untuk contoh implementasi, silahkan gunakan polinomial berikut: x^3 - x - 1\n");
            printf("Masukan nilai x_n: 1.5\n");
            printf("Silahkan diingat input polinom dan x_n nya.\n\n");
            printf("NOTE: Jika koefisien polinomial berbentuk pecahan, jangan lupa mengubahnya menjadi bilangan desimal\ndengan angka signifikan yang sesuai dengan ketentuan pada soal.");
            
            printf("\nLanjut ke implementasi? (y/n): ");
            scanf(" %c", &next);
            if (next == 'y') {
                system("cls");
                NewtonRaphson:
                system("cls");
                printf("Masukan derajat polinom: ");
                scanf("%d", &deg);
                for (j = 0; j <= deg; j++) {
                    printf("Masukan nilai koefisien setiap x pangkat %d: ", j);
                    scanf("%f", &coeff[j]);
                }

                NewtonRaphson(coeff, deg);

                printf("Mau ulangi? (y/n): ");
                scanf(" %c", &stay);
                if (stay == 'y')
                    goto NewtonRaphson;
                else
                    goto Utama;
            } else {
                goto Utama;
            }
            break;

        case 6:
            exit(0);

    }
    return 0;
}

