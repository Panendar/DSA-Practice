// the operation of INSERTION-SORT on the array A = {31;41;59;26;41;58}
// Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order.
// search for an single element

// ==================================================================================================

// #include <stdio.h>

// int main() {
//     int A[] = {31,41,59,26,41,58};
//     int n = sizeof(A) / sizeof(int);

//     // Insertion Sort
//     for (int i = 1; i < n; i++) {
//         int temp = A[i];
//         int j = i - 1;
//         while (j >= 0 && A[j] > temp) {
//             A[j + 1] = A[j];
//             j--;
//         }
//         A[j + 1] = temp;
//     }

    // Print sorted array (increasing)
//     printf("Sorted array in increasing order: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", A[i]);
//     }
//     printf("\n");

//     // Print sorted array (decreasing)
//     printf("Sorted array in decreasing order: ");
//     for (int i = n - 1; i >= 0; i--) {
//         printf("%d ", A[i]);
//     }
//     printf("\n");

//     // Linear Search
//     printf("\nLinear Search\n");
//     printf("Enter the value you want to find: ");
//     int v;
//     scanf("%d", &v);

//     int found = 0;
//     for (int i = 0; i < n; i++) {
//         if (v == A[i]) {
//             printf("Value %d found at index %d\n", v, i);
//             found = 1;
//             break;
//         }
//     }

//     if (!found) {
//         printf("Value %d not found in the array\n", v);
//     }

//     return 0;
// }


// decreasing order

// #include <stdio.h>
// int main(){
//     int A[] = {31,41,59,26,41,58};
//     int n = sizeof(A)/sizeof(int);

    
//         for (int i=1; i<n;i++){
//             int temp = A[i];
//             int j = i-1;
//             while(j>=0 && A[j]<temp){
//                 A[j+1] = A[j];
//                 j--;
//             }
//             A[j+1] = temp;
//         }

//     for(int i=0;i<n;i++){
//         printf("%d ",A[i]);
//     }   
    
//     return 0;
// }


//  Consider the problem of adding two n-bit binary integers, stored in two n-element
//arrays A and B. The sum of the two integers should be stored in binary form inan .n C1/-element array C. 
//State the problem formally and write pseudocode foradding the two integers.

// Function to convert decimal to binary and store in array

// ========================================================================
// BINARY ADDITION IMPLEMENTATION
// ========================================================================

#include <stdio.h>

// Function to convert decimal to binary and store in array
void decimal_to_binary(int decimal, int binary_array[], int n) {
    // Initialize array with zeros
    for (int i = 0; i < n; i++) {
        binary_array[i] = 0;
    }
    
    // Convert decimal to binary (store from right to left)
    int index = n - 1;
    while (decimal > 0 && index >= 0) {
        binary_array[index] = decimal % 2;
        decimal = decimal / 2;
        index--;
    }
}

// Function to print binary array
void print_binary(int binary_array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", binary_array[i]);
    }
    printf("\n");
}

// Function to add two binary numbers stored in arrays
// A and B are n-element arrays, C is (n+1)-element array to store result
void binary_addition(int A[], int B[], int C[], int n) {
    int carry = 0;
    
    // Add from right to left (least significant bit first)
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + B[i] + carry;
        C[i + 1] = sum % 2;  // Store result bit
        carry = sum / 2;     // Calculate carry
    }
    C[0] = carry;  // Store final carry in the leftmost position
}

int main() {
    // Problem: Adding two n-bit binary integers
    // Input: Two n-element arrays A and B containing binary digits
    // Output: (n+1)-element array C containing the binary sum
    
    printf("=== BINARY ADDITION DEMO ===\n\n");
    
    // Example 1: Adding 10 (1010) + 11 (1011)
    int decimal_A = 10;  // 10 in decimal = 1010 in binary
    int decimal_B = 11;  // 11 in decimal = 1011 in binary
    int n_bits = 4;      // Using 4-bit binary numbers
    
    int binary_A[4], binary_B[4], binary_C[5];  // C needs n+1 bits for overflow
    
    // Convert decimals to binary arrays
    decimal_to_binary(decimal_A, binary_A, n_bits);
    decimal_to_binary(decimal_B, binary_B, n_bits);
    
    printf("Example 1:\n");
    printf("Decimal A = %d, Binary A = ", decimal_A);
    print_binary(binary_A, n_bits);
    
    printf("Decimal B = %d, Binary B = ", decimal_B);
    print_binary(binary_B, n_bits);
    
    // Perform binary addition
    binary_addition(binary_A, binary_B, binary_C, n_bits);
    
    printf("Binary Sum = ");
    print_binary(binary_C, n_bits + 1);
    
    // Convert result back to decimal for verification
    int result_decimal = 0;
    for (int i = 0; i < n_bits + 1; i++) {
        result_decimal = result_decimal * 2 + binary_C[i];
    }
    printf("Decimal Sum = %d (Verification: %d + %d = %d)\n\n", 
           result_decimal, decimal_A, decimal_B, decimal_A + decimal_B);
    
    // Example 2: Adding 15 (1111) + 1 (0001) to show carry overflow
    printf("Example 2 (with carry overflow):\n");
    int decimal_A2 = 15;  // 15 in decimal = 1111 in binary
    int decimal_B2 = 1;   // 1 in decimal = 0001 in binary
    
    int binary_A2[4], binary_B2[4], binary_C2[5];
    
    decimal_to_binary(decimal_A2, binary_A2, n_bits);
    decimal_to_binary(decimal_B2, binary_B2, n_bits);
    
    printf("Decimal A = %d, Binary A = ", decimal_A2);
    print_binary(binary_A2, n_bits);
    
    printf("Decimal B = %d, Binary B = ", decimal_B2);
    print_binary(binary_B2, n_bits);
    
    binary_addition(binary_A2, binary_B2, binary_C2, n_bits);
    
    printf("Binary Sum = ");
    print_binary(binary_C2, n_bits + 1);
    
    int result_decimal2 = 0;
    for (int i = 0; i < n_bits + 1; i++) {
        result_decimal2 = result_decimal2 * 2 + binary_C2[i];
    }
    printf("Decimal Sum = %d (Verification: %d + %d = %d)\n", 
           result_decimal2, decimal_A2, decimal_B2, decimal_A2 + decimal_B2);

    return 0;
}