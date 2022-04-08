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
            while (i < N) {
                x = (a + b) / 2;
                result_x = Polynomial(coeff, deg, x);
                printf("|%d.| |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f|, |%.10f  |, |%.10f|\n", 
                        i, a, b, (a + b)/2, result_a, result_b, Polynomial(coeff, deg, (a + b)/2), err);
                if (result_x * result_a > 0) {
                    a = x;
                    result_a = result_x;
                }
                else {
                    b = x;
                    result_b = result_x;
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
    printf("|No|, |x_n|, \t\t\t|F(x_n)|\n");
    while(i < N) {
        result_xn = Polynomial(coeff, deg, x);
        printf("|%d.| |%.10f|, |%.10f|\n", 
                i, x, Polynomial(coeff, deg, x));
        if (fabs(result_xn - x) < TOL)
            break;
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
    while(i < N) {
        
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

    printf("Masukan nilai X_n: ");
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
        if (fabs(x_nplus1 - x_n) < TOL)
            break;
        x_n = x_nplus1;
        i++;
    }
}

int main(){
    float x, coeff[100], y1;
    int deg, i;

    printf("Enter the degree of polynomial equation: ");
    scanf("%d", &deg);

    for (i = 0; i <= deg; i++) {
        printf("Enter the coefficient of x to the power %d: ", i);
        scanf("%f", &coeff[i]);
    }

    // Biseksi(coeff, deg);
    // IterasiSederhana(coeff, deg);
    // IterasiAitken(coeff, deg);
    // RegulaFalsi(coeff, deg);
    // NewtonRaphson(coeff, deg);

    return 0;
}

