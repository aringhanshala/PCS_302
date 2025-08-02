/* Given an array of non-negative integers, where all numbers occur even number of times except one number which occurs 
  odd number of times. Write an algorithm and a program to find this number.
*/

/* Time Complexity  : O(n) 
  Space Complexity : O(1)
*/

// Preprocessor
#include<stdio.h>

// Main function
void main(){
    int T, n, i;     // Variable declaration

    scanf("%d", &T);     // Reading number of test cases
    printf("\n");

    while(T--){
        scanf("%d", &n);     // Reading size of array

        int arr[n];     // Declaring size of array on runtime
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);     // Reading elements of array
        }

        int x= 0;

        for(i=0; i<n; i++){
            x= x ^ arr[i];     // Using XOR operation with every element in array
        }

        printf("%d\n", x);
        printf("\n");
    }
}
