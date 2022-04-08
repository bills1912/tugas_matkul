#include<stdio.h>
#define MAX 1000

int main(){

    double fraDecimal=0.0,dFractional=0.0 ,fraFactor=0.5;
    long int dIntegral = 0,bIntegral=0,bFractional[MAX];
    long int intFactor=1,remainder,i=0,k=0,flag=0;
    char fraBinary[MAX];

    printf("Enter any fractional binary number: ");
    scanf("%s",&fraBinary);
   
    while(fraBinary[i]){
        
         if(fraBinary[i] == '.')
             flag = 1;
         else if(flag==0)
             bIntegral = bIntegral * 10 + (fraBinary[i] -48);
         else
              bFractional[k++] = fraBinary[i] -48;
         i++;
    }
   
    while(bIntegral!=0){
        remainder=bIntegral%10;
        dIntegral= dIntegral+remainder*intFactor;
        intFactor=intFactor*2;
        bIntegral=bIntegral/10;
    }
   
    for(i=0;i<k;i++){
         dFractional  = dFractional  + bFractional[i] * fraFactor;
         fraFactor = fraFactor / 2;
    }

    fraDecimal = dIntegral + dFractional ;

    printf("Equivalent decimal value: %.10f",fraDecimal);
   
    return 0;
}