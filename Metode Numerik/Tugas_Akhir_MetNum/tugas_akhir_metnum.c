#include<stdio.h>
#include<math.h>

float LagrangeInterpolation(float x[], float f_x[], int n, float x_interpolate)
{
      float f_interpolate = 0;
      int i, j, d;
      printf("\n\nMasukan jumlah data: ");
      scanf("%d",&n);
      printf("\n\nMasukan nilai dari x dan f(x): \n");
      for(i=0; i< n; i++)
      {
            scanf ("%f",&x[i]);
            scanf("%f",&f_x[i]);
      }
      printf("\n\nThe table you entered is as follows:\n\n");
      for(i=0; i< n; i++)
      {
            printf("%0.7f\t%0.7f",x[i],f_x[i]);
            printf("\n");
      }
      printf("Enter the value of the x to find the respective value of y: ");
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
      return x_interpolate, f_interpolate;
}

int main(){
      float x[100], f_x[100], x_inter;
      int n;
      printf("Aproximasi nilai: %0.7f", LagrangeInterpolation(x, f_x, n, x_inter));
      return 0;
}