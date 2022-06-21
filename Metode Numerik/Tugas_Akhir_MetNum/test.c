#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int i, j, n;

    printf("Masukan jumlah data: ");
    scanf("%d", &n);

    for(i = 1; i < n; i++){
        for(j = 0; j < i; ++j){
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}