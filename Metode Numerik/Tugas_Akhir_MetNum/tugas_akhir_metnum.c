#include<stdio.h>
#include<math.h>

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

int main(){
      float x[100], f_x[100], x_inter;
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
            case 4:
                  printf("Keluar dari program\n");
                  exit(0);
      }
      return 0;
}