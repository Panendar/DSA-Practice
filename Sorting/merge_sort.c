#include <stdio.h>
void merge(int A[],int left,int mid, int right){
    int i = left;
    int j= mid+1;
    int k = left;
    int B[100];
    while(i<=mid && j<=right){
        if(A[i]<=A[j]){
            B[k] =A[i];
            i++, k++;
        }
        else{
            B[k] =A[j];
            j++,k++;
        }
    }
    if(i>mid){
        while(j<=right){
            B[k] = A[j];
            j++,k++;
        }
    }
    else{
        while(i<=mid){
            B[k] = A[i];
            i++,k++;
        }
    }
    // Copy the merged data back to original array
    for(int p = left; p <= right; p++){
        A[p] = B[p];
    }
}
int A[] = {38, 27, 43, 3, 9, 82, 10};


int merge_sort(int A[], int left, int right){
    if(left< right){
        int mid = (left+right)/2;
        merge_sort(A,left, mid);
        merge_sort(A,mid+1,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("Original array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    merge_sort(A, 0, n-1);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}