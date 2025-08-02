/* Given a matrix of size n * n, where every row and every column is sorted in increasing order. Write an algorithm and a program to find
   wheather the given key element is present in the matrix or not.(Liner time Complexity)
*/

/* Time Complexity  : O(n) 
   Space Complexity : O(1)
*/

// Preprocessor
#include<stdio.h>

// Main function
void main(){
    int n, target, flag=0, i, j;     // Variable declaration  
    
    scanf("%d", &n);     // Reading the size of square matrix
    
    int mat[n][n];     // Declaring size of matrix on runtime
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          scanf("%d", &mat[i][j]);     // Reading elements of matrix
       }
    }
    
    scanf("%d", &target);     // Reading the target that will be search in matrix
    
    i=0, j= n-1;
    while(i < n && j >= 0){     // Searching the target in the matrix
       if(mat[i][j] == target){
          flag=1;
          break;
       }
       else if(mat[i][j] > target) j--;     // Searching in the row from backward
       else i++;     // Jumping to the next row
    }
    
    if(flag==1) printf("Present\n");     // When target found
    else printf("Not Present\n");     // When target not found in the matrix
}
