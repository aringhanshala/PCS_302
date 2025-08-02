/* Given a boolean matrix (contains only 0 and 1) of size m * n where each row is sorted, write an algorithm and a program to find which row
  has maximum number of 1's. (Linear time complexity)
*/

/* Time Complexity  : O(n) 
  Space Complexity : O(1)
*/

// Preprocessor
#include<stdio.h>

// Main function
void main(){
    int m, n, flag=0, i, j;     // Variable declaration  
    
    scanf("%d %d", &m, &n);     // Reading the size of matrix
    
    int mat[m][n];     // Declaring size of matrix on runtime
    for(i=0; i<m; i++){
       for(j=0; j<n; j++){
          scanf("%d", &mat[i][j]);     // Reading elements of matrix
       }
    }
    
    i=0, j= 0;
    while(i < n){     // Searching 1 at 0th index of each row
       if(mat[i][j] == 1){     // When found 1 at 0th index of row
          flag=1;
          break;
       }
       else i++;     // Jumping to the next row
    }
    
    if(flag==1) printf("row- %d\n", i+1);     // Printing the row having maximum number of 1's
    else printf("Not Present\n");     // When maximum number of 1's not present
}
