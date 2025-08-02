/* Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a program to find minimum distance 
   between a and b in this array. Minimum distance between any two numbers a and b present in array is the minimum difference 
   between their indices. 
*/

/* Time Complexity  : O(n) 
   Space Complexity : O(1)
*/

// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Main function
void main(){
    int T, n, a, b, i, j, index1 = -1, index2 = -1;     // Variable declaration

    scanf("%d", &T);     // Reading number of test cases
    printf("\n");

    while (T--){
        int dis = INT_MAX;     // Initializing distance between a and b to the maximum integer
        scanf("%d", &n);     // Reading size of array

        int arr[n];     // Declaring size of array on runtime
        for (i = 0; i < n; i++){
            scanf("%d", &arr[i]);     // Reading elements of array
        }

        scanf("%d %d", &a, &b);     // Reading value of a and b

        for (j = 0; j < n; j++){
            if (arr[j] == a)
                index1 = j;
            else if (arr[j] == b)
                index2 = j;

            if (index1 != -1 && index2 != -1){     // Checking if we got both a and b in array
                if (abs(index1 - index2) < dis){     // Checking the current distance b/w a and b is smaller than previous
                    dis = abs(index1 - index2);
                }
            }
        }

        if (dis == INT_MAX)     // When we didn't get the minimum distance
            printf("There is no such minimum distance");     
        else
            printf("%d\n", dis);

        printf("\n");
    }
}