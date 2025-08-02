/* Given a matrix of size n * n containing positive integers, write an algorithm and a program to rotate the  
   elements of matrix in clockwise direction.
*/

/* Time Complexity  : O(n^2) 
   Space Complexity : O(1)
*/

// Preprocessor
#include<stdio.h>

// Main function
void main(){
   int n, col=0, row=0;     // Variables declaration
   
   scanf("%d", &n);     // Reading the size of matrix
   
   int mat[n][n];     // Declaring size of matrix on runtime
   
   int last_col= n, last_row= n;     // Variables declaration
   
   // Reading elements of matrix
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         scanf("%d", &mat[i][j]);     
      }
   }
   
   printf("\n");     // New line
   
   // Traversing in spiral matrix
   while(row< last_row && col< last_col){
   
      int prev= mat[row+1][col];     // Variable declaration
   
      if(row +1 == last_row || col+1 == last_col) break;     // Condition for odd size martix    
      
      // Traversing from col to last col
      for(int i= col; i< last_col; i++){
         int cur= mat[row][i];
         mat[row][i]= prev;
         prev= cur;
      }
      row++;
      
      // Traversing from row to last row
      for(int i= row; i< last_row; i++){
         int cur= mat[i][last_col-1];
         mat[i][last_col-1]= prev;
         prev= cur;
      }
      last_col--;
      
      // Traversing from last col to col
      for(int i= last_col-1; i>= col; i--){
         int cur= mat[last_row-1][i];
         mat[last_row-1][i]= prev;
         prev= cur;
      }
      last_row--;
      
      // Traversing from last row to row
      for(int i= last_row-1; i>= row; i--){
         int cur= mat[i][col];
         mat[i][col]= prev;
         prev= cur;
      }
      col++;
      
   }
   
   // Printing the elements of resultant matrix
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         printf("%d ", mat[i][j]);     
      }
      printf("\n");
   }
   
}
