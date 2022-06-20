#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float func(float x)
{
    return(1/(1+pow(x,2)));
}

float LagrangeInterpolation(float x[], float f_x[], int n, float x_interpolate)
{
      float f_interpolate = 0;
      int i, j, d;
      printf("Masukan jumlah data: ");
      scanf("%d",&n);

      printf("\n\nMasukan titik kolokasi x dan hasil fungsi f(x) (dipisah dengan Spasi): \n");
      for(i=0; i< n; i++)
      {
            scanf ("%f",&x[i]);
            scanf("%f",&f_x[i]);
      }

      printf("\n\nBerikut parameter x dan f(x) yang diinput:\n\n");
      for(i=0; i< n; i++)
      {
            printf("%0.4f\t%0.7f",x[i],f_x[i]);
            printf("\n");
      }

      printf("Masukan nilai x yang akan diestimasi nilai f(x)-nya: ");
      scanf("%f",&x_interpolate);
      for (i = 0; i < n; i++)
      {
            float L = 1;
            for (j = 0; j < n; j++)
            {
                  if (i != j)
                  {
                        L *= (x_interpolate - x[j]) / (x[i] - x[j]);
                  }
            }
            f_interpolate += L * f_x[i];
      }
      printf("\nHasil estimasi dari titik %0.3f: %0.7f", x_interpolate, f_interpolate);
}

float NewtonForwardDerivative(float x[], int n, float x_diff)
{
      float f[100][100], h, sum = 0.0, term, first_derivative;
      int i, j, index, flag = 0, sign = 1;

      printf("Masukan jumlah data: ");
      scanf("%d",&n);

      printf("\n\nMasukan titik kolokasi x dan hasil fungsi f(x) (dipisah dengan Spasi): \n");
      for(i = 0; i < n; i++)
      {
            scanf ("%f",&x[i]);
            scanf("%f",&f[i][0]);
      }

      printf("\n\nBerikut parameter x dan f(x) yang diinput:\n\n");
      for(i = 0; i < n; i++)
      {
            printf("%0.3f\t%0.7f",x[i],f[i][0]);
            printf("\n");
      }

      printf("\nMasukkan nilai x yang ingin diestimasi nilai turunannya: ");
      scanf("%f", &x_diff);

      for(i = 0; i < n; i++)
      {
            if (fabs(x_diff - x[i]) < 0.0001)
            {
                  index = i;
                  flag = 1;
                  break;
            }
      }
      printf("%d", index);
      if (flag == 0)
      {
            printf("Nilai x yang dimasukkan tidak valid. Keluar dari program!");
            exit(0);
      }

      for(i = 1; i < n; i++)
      {
            for(j = 0; j < n-i; j++)
            {
                  f[j][i] = f[j+1][i-1] - f[j][i-1];
            }
      }

      printf("Berikut daftar hasil selisih: \n");
      for(i = 0; i < n; i++)
      {
            for(j = 0; j < n-i; j++)
            {
                  printf("%0.7f\t",f[j][i]);
                  printf("\n");
            }
      }
      printf("\n");
      h = x[1] - x[0];

      for(i = 1; i < n-index; i++)
      {
            term = f[index][i]/i;
            sum = sum + sign*term;
            sign = -sign;
      }
      first_derivative = sum/h;

      printf("Turunan pertama untuk x = %0.2f is %0.7f", x_diff, first_derivative);
}

float NumericIntegral(float a, float b, float err[])
{
      float c, midpoint, trapezoidal, simpson, abs_solution;

      printf("Masukan nilai a: ");
      scanf("%f",&a);
      printf("Masukan nilai b: ");
      scanf("%f",&b);

      c = (a + b)/2;

      printf("Masukan solusi absolut dari fungsi: ");
      scanf("%f",&abs_solution);
      printf("\n");

      float MidPoint()
      {
            midpoint = (b - a) * (func(c));
            return midpoint;
      }

      float Trapezoidal()
      {
            trapezoidal = (b - a) * ((func(a) + func(b))/2);
            return trapezoidal;
      }

      float Simpson()
      {
            simpson = (b - a) * ((func(a) + 4*func(c) + func(b))/6);
            return simpson;
      }
      
      printf("Hasil integral numerik dari %0.2f sampai %0.2f dengan metode MidPoint adalah %0.7f\n", a, b, MidPoint());
      printf("Hasil integral numerik dari %0.2f sampai %0.2f dengan metode Trapezoidal adalah %0.7f\n", a, b, Trapezoidal());
      printf("Hasil integral numerik dari %0.2f sampai %0.2f dengan metode Simpson adalah %0.7f\n\n", a, b, Simpson());

      err[0] = fabs(abs_solution - MidPoint());
      err[1] = fabs(abs_solution - Trapezoidal());
      err[2] = fabs(abs_solution - Simpson());

      printf("Nilai absolute error dari setiap metode adalah: \n");
      printf("MidPoint: %0.7f\n", err[0]);
      printf("Trapezoidal: %0.7f\n", err[1]);
      printf("Simpson: %0.7f\n", err[2]);
      printf("\nDari hasil di atas, maka:");
      if(err[0] < err[1] && err[0] < err[2])
      {
            printf("\nMetode MidPoint adalah metode yang paling akurat\n");
      }
      else if(err[1] < err[0] && err[1] < err[2])
      {
            printf("\nMetode Trapezoidal adalah metode yang paling akurat\n");
      }
      else
      {
            printf("\nMetode Simpson 1/3 adalah metode yang paling akurat\n");
      }
}

float TrapezoidalNumericIntegral(float a, float b)
{

}

int main(){
      float x[100], f_x[100], x_inter, x_diff, a, b, err[3];
      int n, num_menu;
      char next, stay;

      Utama:
      system("cls");
      printf("APLIKASI APROKSIMASI FUNGSI, TURUNAN, DAN INTEGRAL DENGAN METODE NUMERIK\n");
      printf("\nPilih menu yang tersedia:\n\n");
      printf("1. Aproksimasi Fungsi dengan Metode Numerik\n");
      printf("2. Aproksimasi Turunan Fungsi dengan Metode Numerik\n");
      printf("3. Aproksimasi Integral Fungsi dengan Metode Numerik\n");
      printf("4. Keluar\n\n");
      printf("Pilih nomor menu: ");
      scanf("%d",&num_menu);
      system("cls");

      switch(num_menu){
            case 1:
                  printf("\n\nAPROKSIMASI FUNGSI DENGAN METODE NUMERIK\n");
                  printf("Metode yang digunakan pada aproksimasi fungsi adalah metode Interpolasi Lagrange\n");
                  printf("Ingin lanjut? (y/n): ");
                  scanf("%s",&next);
                  if(next == 'y'){
                        system("cls");
                        InterpolasiLagrange: 
                        system("cls");
                        LagrangeInterpolation(x, f_x, n, x_inter);

                        printf("\nMau mengulang? (y/n): ");
                        scanf(" %c", &stay);
                        if(stay == 'y'){
                              goto InterpolasiLagrange;
                        } else {
                              goto Utama;
                        }
                  } else {
                        goto Utama;
                  }
                  
                  break;

            case 2:
                  printf("APROKSIMASI TURUNAN FUNGSI DENGAN METODE NUMERIK\n");
                  printf("Metode yang digunakan untuk mengestimasi turunan dari suatu titik kolokasi yaitu\nmenggunakan metode Newton Forward\n");
                  printf("Ingin lanjut? (y/n): ");
                  scanf("%s",&next);
                  if(next == 'y'){
                        system("cls");
                        TurunanNumerik: 
                        system("cls");
                        NewtonForwardDerivative(x, n, x_diff);
                        
                        printf("\nMau mengulang? (y/n): ");
                        scanf(" %c", &stay);
                        if(stay == 'y'){
                              goto TurunanNumerik;
                        } else {
                              goto Utama;
                        }
                  } else {
                        goto Utama;
                  }
                  break;

            case 3:
                  printf("APROKSIMASI INTEGRAL FUNGSI DENGAN METODE NUMERIK\n");
                  printf("Metode yang digunakan untuk menghitung integral dari suatu fungsi adalah metode MidPoint, Trapezoidal, dan Simpson 1/3\n");
                  printf("Ingin lanjut? (y/n): ");
                  scanf("%s",&next);
                  if(next == 'y'){
                        system("cls");
                        IntegralNumerik:
                        system("cls");
                        NumericIntegral(a, b, err);

                        printf("\nMau mengulang? (y/n): ");
                        scanf(" %c", &stay);
                        if(stay == 'y'){
                              goto IntegralNumerik;
                        } else {
                              goto Utama;
                        }
                  } else {
                        goto Utama;
                  }
                  break;

            case 4:
                  printf("Keluar dari program\n");
                  exit(0);
      }
      return 0;
}