#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

int i = 0;
int octnum[20];
static int j, count;
int bin[40];

int BinerToDecimal(int binerNumber, int decimalNumber, int weight, int temp){
    while(binerNumber != 0){
        temp = binerNumber % 10;
        decimalNumber += temp * pow(2,weight);
        binerNumber = binerNumber / 10;
        weight++;
    }
    return decimalNumber;
};

int DecimalToBiner(int decimalNumber, int binerNumber, int weight, int temp){
    while(decimalNumber != 0){
        temp = decimalNumber % 2;
        binerNumber += temp * pow(10,weight);
        decimalNumber = decimalNumber / 2;
        weight++;
    }
    return binerNumber;
};

int DecimalToOctal(int decimalNumber, int octalNumber, int weight, int temp){
    while(decimalNumber != 0){
        temp = decimalNumber % 8;
        octalNumber += temp * pow(10,weight);
        decimalNumber = decimalNumber / 8;
        weight++;
    }
    return octalNumber;
};

int OctalToDecimal(int octalNumber, int decimalNumber, int weight, int temp){
    while(octalNumber != 0){
        temp = octalNumber % 10;
        decimalNumber += temp * pow(8,weight);
        octalNumber = octalNumber / 10;
        weight++;
    }
    return decimalNumber;
};

void BinaryToOctal(int bin){
    int oct=0, mul=1, count=1, rem;
    while(bin!=0)
    {
        rem = bin%10;
        oct = oct + (rem*mul);
        if(count%3==0)
        {
            octnum[i] = oct;
            mul = 1;
            oct = 0;
            count = 1;
            i++;
        }
        else
        {
            mul = mul*2;
            count++;
        }
        bin = bin/10;
    }
    if(count!=1)
        octnum[i] = oct;
}

void OctalToBinary(int oct)
{
    int dec=0, rem, mul=1;
    while(oct!=0)
    {
        rem = oct%10;
        if(rem>7)
        {
            count++;
            break;
        }
        dec = dec + (rem*mul);
        mul = mul*8;
        oct = oct/10;
    }
    if(count==0)
        while(dec!=0)
        {
            bin[j] = dec%2;
            j++;
            dec = dec/2;
        }
}

int main(){
    int biner, decimal, octal, temp;
    int octalNumber = 0;
    int binerParam = 0;
    int decimalParam = 0;
    int weight = 0;
    
    printf("Masukan angka biner : ");
    scanf("%d",&biner);
    printf("Masukan angka decimal : ");
    scanf("%d",&decimal);
    printf("Masukan angka octal : ");
    scanf("%d",&octal);

    printf("Konversi nilai biner %d ke decimal: %d\n", biner, BinerToDecimal(biner, decimalParam, weight, temp));
    printf("Konversi nilai decimal %d ke biner: %d\n", decimal, DecimalToBiner(decimal, binerParam, weight, temp));
    printf("Koversi nilai decimal %d ke octal: %d\n", decimal, DecimalToOctal(decimal, octalNumber, weight, temp));
    printf("Konversi nilai octal %d ke decimal: %d\n", octal, OctalToDecimal(octal, decimalParam, weight, temp));
    
    BinaryToOctal(biner);
    printf("Konversi nilai biner %d ke octal: ", biner);
    for(i=i; i>=0; i--)
        printf("%d", octnum[i]);
    getch();

    OctalToBinary(octal);
    if(count==0)
    {
        printf("\nKonversi nilai octal %d ke biner: ", octal);
        for(j=(j-1); j>=0; j--)
            printf("%d", bin[j]);
    }
    else
        printf("\nAngka octal %d tidak valid!", octal);

    getch();

    return 0;
}