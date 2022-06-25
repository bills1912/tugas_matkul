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
      int i, j, d, num_point;
      printf("Masukan jumlah data: ");
      scanf("%d",&n);

      printf("\n\nMasukan titik kolokasi x dan hasil fungsi f(x) (antara nilai x dan f(x) dipisahkan dengan Spasi): \n");
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

      printf("\nMasukan jumlah titik yang ingin diestimasi: ");
      scanf("%d", &num_point);

      printf("Masukan nilai x yang akan diestimasi nilai f(x)-nya: ");
      scanf("%f",&x_interpolate);
      for (i = 0; i < num_point; i++)
      {
            float L = 1;
            for (j = 0; j < num_point; j++)
            {
                  if (i != j)
                  {
                        L *= (x_interpolate - x[j]) / (x[i] - x[j]);
                  }
            }
            f_interpolate += L * f_x[i];
      }

      switch(num_point){
            case 2:
                  printf("\nNilai estimasi f(%0.3f) untuk dua titik: %0.7f",x_interpolate, f_interpolate);
                  break;
            
            case 3:
                  printf("\nNilai estimasi f(%0.3f) untuk tiga titik: %0.7f",x_interpolate, f_interpolate);
                  break;
            
            case 5:
                  printf("\nNilai estimasi f(%0.3f) untuk lima titik: %0.7f",x_interpolate, f_interpolate);
                  break;
      }
}

float DiferensiasiDuaTitik(float f_x[], float x[], int n, float x_differ) 
{
      printf("APROKSIMASI TURUNAN NUMERIK DENGAN DUA TITIK\n\n");
      float h, selisihMaju, selisihMundur; 
      int i, pilihan;

      printf("Masukkan nilai h: ");
      scanf("%f", &h);

      printf("Masukan x yang akan diaproksimasi turunannya: ");
      scanf("%f", &x_differ);

      printf("Pilihan rumus: \n");
      printf("1. Aproksimasi Turunan Dua Titik dengan Selisih Maju\n");
      printf("2. Aproksimasi Turunan Dua Titik dengan Selisih Mundur\n");
      printf("\nMasukan pilihan rumus: ");
      scanf("%d", &pilihan);

      switch(pilihan){
            case 1:
                  selisihMaju = (func(x_differ + h) - func(x_differ))/h;
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan selisih maju adalah: %0.7f", x_differ, selisihMaju);
                  break;
            case 2:
                  selisihMundur = (func(x_differ) - func(x_differ - h))/h;
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan selisih mundur adalah: %0.7f", x_differ, selisihMundur);
                  break;
      }

}

float DiferensiasiTigaTitik(float f_x[], float x[], int n, float x_differ) 
{
      printf("APROKSIMASI TURUNAN NUMERIK DENGAN TIGA TITIK\n\n");
      float h, diferTigaTitik; 
      int i, pilihan;

      printf("Masukkan nilai h: ");
      scanf("%f", &h);

      printf("Masukan x yang akan diaproksimasi turunannya: ");
      scanf("%f", &x_differ);

      printf("Pilihan rumus: \n");
      printf("1. Aproksimasi Turunan Tiga Titik dengan Psi yang Berada di antara (x0 - h) s/d (x0 + h)\n");
      printf("2. Aproksimasi Turunan Tiga Titik dengan Psi yang Berada di antara x0 s/d (x0+2h)\n");
      printf("\nMasukan pilihan rumus: ");
      scanf("%d", &pilihan);

      switch(pilihan){
            case 1:
                  diferTigaTitik = (func(x_differ + h) - func(x_differ - h))/(2*h);
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan psi yang berada di antara (x0 - h) s/d (x0 + h) adalah: %0.7f", x_differ, diferTigaTitik);
                  break;
            case 2:
                  diferTigaTitik = (-3*func(x_differ) + 4*func(x_differ + h) - func(x_differ + 2*h))/(2*h);
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan psi yang berada di antara x0 s/d (x0 + 2h) adalah: %0.7f", x_differ, diferTigaTitik);
                  break;
      }

}

float DiferensiasiLimaTitik(float f_x[], float x[], int n, float x_differ) 
{
      printf("APROKSIMASI TURUNAN NUMERIK DENGAN LIMA TITIK\n\n");
      float h, diferLimaTitik; 
      int i, pilihan;

      printf("Masukkan nilai h: ");
      scanf("%f", &h);

      printf("Masukan x yang akan diaproksimasi turunannya: ");
      scanf("%f", &x_differ);

      printf("Pilihan rumus: \n");
      printf("1. Aproksimasi Turunan Lima Titik dengan Psi yang Berada di antara (x0 - 2h) s/d (x0 + 2h)\n");
      printf("2. Aproksimasi Turunan LIma Titik dengan Psi yang Berada di antara x0 s/d (x0 + 4h)\n");
      printf("\nMasukan pilihan rumus: ");
      scanf("%d", &pilihan);

      switch(pilihan){
            case 1:
                  diferLimaTitik = (func(x_differ - 2*h) - 8*func(x_differ - h) + 8*func(x_differ + h) - func(x_differ + 2*h))/(12*h);
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan psi yang berada di antara (x0 - 2h) s/d (x0 + 2h) adalah: %0.7f", x_differ, diferLimaTitik);
                  break;
            case 2:
                  diferLimaTitik = (-25*func(x_differ) + 48*func(x_differ + h) - 36*func(x_differ + 2*h) + 16*func(x_differ + 3*h) - 3*func(x_differ + 4*h))/(12*h);
                  printf("Hasil aproksimasi turunan dari titik %0.3f dengan psi yang berada di antara x0 s/d (x0 + 4h) adalah: %0.7f", x_differ, diferLimaTitik);
                  break;
      }

}

float NewtonForwardDerivative(float x[], int n, float x_diff)
{
      float f[100][100], h, sum = 0.0, term, first_derivative;
      int i, j, index, flag = 0, sign = 1;

      printf("Masukan jumlah data: ");
      scanf("%d",&n);

      printf("\n\nMasukan titik kolokasi x dan hasil fungsi f(x) (antara nilai x dan f(x) dipisahkan dengan Spasi): \n");
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
      for(i = 1; i < n; i++)
      {
            for(j = 1; j < n-i; j++)
            {
                  printf("%0.7f\t", f[i][j]);
            }
            printf("\n");
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

      printf("Masukan solusi absolut dari fungsi (arctan(b) - arctan(a)): ");
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

int main(){
      float x[100], f_x[100], x_inter, x_diff, a, b, err[3];
      int n, num_menu, pilihan, method;
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
                  printf("APROKSIMASI FUNGSI DENGAN METODE NUMERIK\n");
                  printf("Metode yang digunakan pada aproksimasi fungsi adalah metode Interpolasi Lagrange\n");
                  printf("\nIngin lanjut? (y/n): ");
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
                  printf("\nIngin lanjut? (y/n): ");
                  scanf("%s",&next);
                  if(next == 'y'){
                        system("cls");
                        TurunanNumerik:
                        system("cls");
                        printf("PILIH JENIS APROKSIMASI\n");
                        printf("1. Aproksimasi Turunan dengan Fungsi yang Diketahui\n");
                        printf("2. Aproksimasi Turunan dengan Fungsi yang Tidak Diketahui\n");
                        printf("3. Kembali ke Menu Utama\n");
                        printf("\nPilih nomor menu: ");
                        scanf("%d",&pilihan);
                        system("cls");
                        switch(pilihan){
                              case 1:
                                    system("cls");
                                    FungsiDiketahui:
                                    system("cls");
                                    printf("APROKSIMASI TURUNAN NUMERIK DENGAN FUNGSI YANG DIKETAHUI\n");
                                    printf("\nPilih Metode yang diinginkan:\n");
                                    printf("1. Aproksimasi Turunan Numerik dengan Dua Titik\n");
                                    printf("2. Aproksimasi Turunan Numerik dengan Tiga Titik\n");
                                    printf("3. Aproksimasi Turunan Numerik dengan Lima Titik\n");
                                    printf("4. Kembali ke Menu Sebelumnya\n");
                                    printf("\nPilih nomor menu: ");
                                    scanf("%d",&method);
                                    system("cls");
                                    switch(method){
                                          case 1:
                                                system("cls");
                                                TurunanNumerikDuaTitik:
                                                system("cls");
                                                DiferensiasiDuaTitik(f_x, x, n, x_diff);
                                                printf("\nMau mengulang? (y/n): ");
                                                scanf(" %c", &stay);
                                                if(stay == 'y'){
                                                      goto TurunanNumerikDuaTitik;
                                                } else {
                                                      goto FungsiDiketahui;
                                                }
                                                break;
                                          case 2:
                                                system("cls");
                                                TurunanNumerikTigaTitik:
                                                system("cls");
                                                DiferensiasiTigaTitik(f_x, x, n, x_diff);
                                                printf("\nMau mengulang? (y/n): ");
                                                scanf(" %c", &stay);
                                                if(stay == 'y'){
                                                      goto TurunanNumerikTigaTitik;
                                                } else {
                                                      goto FungsiDiketahui;
                                                }
                                                break;
                                          case 3:
                                                system("cls");
                                                TurunanNumerikLimaTitik:
                                                system("cls");
                                                DiferensiasiLimaTitik(f_x, x, n, x_diff);
                                                printf("\nMau mengulang? (y/n): ");
                                                scanf(" %c", &stay);
                                                if(stay == 'y'){
                                                      goto TurunanNumerikLimaTitik;
                                                } else {
                                                      goto FungsiDiketahui;
                                                }
                                                break;
                                          case 4:
                                                goto TurunanNumerik;
                                                break;
                                    }
                                    break;
                              case 2:
                                    system("cls");
                                    FungsiTidakDiketahui:
                                    system("cls");
                                    printf("APROKSIMASI TURUNAN NUMERIK DENGAN FUNGSI YANG DIKETAHUI\n");
                                    printf("Pada metode ini, kita menggunakan metode Newton Forward\n");
                                    NewtonForwardDerivative(x, n, x_diff);
                                    printf("\nMau mengulang? (y/n): ");
                                    scanf(" %c", &stay);
                                    if(stay == 'y'){
                                          goto FungsiTidakDiketahui;
                                    } else {
                                          goto TurunanNumerik;
                                    }
                                    break;
                              case 3:
                                    goto Utama;
                                    break;
                        } 
                  } else {
                        goto Utama;
                  }
                  break;

            case 3:
                  printf("APROKSIMASI INTEGRAL FUNGSI DENGAN METODE NUMERIK\n");
                  printf("Metode yang digunakan untuk menghitung integral dari suatu fungsi adalah metode MidPoint, Trapezoidal, dan Simpson 1/3\n");
                  printf("\nIngin lanjut? (y/n): ");
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