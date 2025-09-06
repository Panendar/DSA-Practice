#include <stdio.h>
int main(){
    int A[] = {7,10,4,3,20,15};
    int n = sizeof(A)/sizeof(int);
    
    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    for(int i=0;i<n-1;i++){
        int min =i;
        for(int j=i+1;j<n;j++){  
            if(A[j]<A[min]){
                min =j;
            }
        }
        if(min!=i){
            int temp =A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}