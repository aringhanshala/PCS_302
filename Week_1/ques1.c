// Given an array of integers, write an algorithm and a program to left rotate the array by specific number of elements. 

/* Time Complexity  : O(n) 
   Space Complexity : O(1)
*/

// Preproscessor
#include <stdio.h>


// Function declaration
int reverse(int arr[], int start, int end);


// Main function
void main(){
    int T, n, target, i;     // Variable declaration

    scanf("%d", &T);     // Reading number of test cases
    printf("\n");

    while (T--){
        scanf("%d", &n);     // Reading size of array

        int arr[n];     // Declaring size of array on runtime
        for (i = 0; i < n; i++){
            scanf("%d", &arr[i]);     // Reading elements of array
        }

        scanf("%d", &target);     // Reading the target along which array will be rotated

        reverse(arr, 0, target - 1);     // Reversing 1st window
        reverse(arr, target, n - 1);     // Reversing 2nd window
        reverse(arr, 0, n - 1);          // Reversing whole array

        for (i = 0; i < n; i++){      // Printing the rotated array
            printf("%d ", arr[i]);
        }

        printf("\n");
        printf("\n");
    }
}


// Reverse function defination
int reverse(int arr[], int start, int end){
    int temp;     // Variable declaration

    while (start <= end){     // Reversing elements of array
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++, end--;
    }
}