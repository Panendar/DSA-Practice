#include <stdio.h>

int main(){
    int A[] = {5, 1, 4, 2, 8};
    printf("Unsorted array: ");
    int n= sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int flag =0; // flag to check if any swapping happened
    for(int i=0;i<n-1;i++){
        flag = 0; // reset flag for each outer loop iteration
        for(int j=0;j<n-1-j;j++){
            if(A[j] > A[j+1]){
                int temp =A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag =1;
            }
        }
        if(flag == 0)
            break;
    }

    printf("Sorted array: ");
    for(int i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}