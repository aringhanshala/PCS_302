/* Design an algorithm and a program to implement stack using array. The program should implement following stack operations:
   
   a) Create() - create an empty stack
   b) Push(k) - push an element k into the stack
   c) Pop() - pop an element from the stack snd return it
   d) IsEmpty() - check if stack is empty or not
   e) Size() - finds the size of the stack
   f) Print() - prints the contents of stack
*/

// Preprocessors
#include <stdio.h>
#include <stdlib.h> 

// Stack structure
struct stack { 
 int size; 
 int *s; 
 int top; 
}; 

// Function declaration
void create(struct stack *st);
void push(struct stack *st, int x);
int pop(struct stack *st);
int size(struct stack *st);
void display(struct stack st);
void isEmpty(struct stack st);

// Main Function
int main() { 
   struct stack st;     // Structure object declaration
   
   create(&st);     // Creating an empty stack 

   int choice, value;     // Declaring variables

   // Stack menu loop
   do { 
      printf("\nPress:\n1 to push\n2 to pop\n3 to calculate size\n4 to exit\n"); 
      scanf("%d", &choice); 
      switch(choice) { 
         case 1: // Push
                 printf("Enter a value to push: "); 
                 scanf("%d", &value); 
                 push(&st, value); 
                 break; 
                 
         case 2: // Pop
                 pop(&st); 
                 break; 
                 
         case 3: // Size
                 printf("Current stack size: %d\n", size(&st)); 
                 break; 
                 
         case 4: // Exit
                 printf("Exiting...\n"); 
                 break; 
                 
         default: // Wrong choice
                  printf("Invalid choice. Please try again.\n"); 
      } 
   } while(choice != 4); 
   
   free(st.s);   // Free the memory
   return 0; 
}

// Create function
void create(struct stack *st) { 
   printf("Enter the size of the stack: "); 
   scanf("%d", &st->size); 
 
   st->top = -1; 
   st->s = (int *)malloc(st->size * sizeof(int)); 
} 

// Push function
void push(struct stack *st, int x) { 
   if(st->top == st->size - 1) { 
      printf("Stack overflow\n"); 
   }

   else { 
      st->top++; 
      st->s[st->top] = x; 
      printf("%d pushed onto the stack\n", x); 
   } 
}

// Pop function 
int pop(struct stack *st) { 
   int x = -1; 

   if(st->top == -1) { 
      printf("Stack underflow\n"); 
   } 

   else { 
      x = st->s[st->top]; 
      st->top--; 
      printf("%d popped from the stack\n", x); 
   } 
   return x; 
}

// Size function 
int size(struct stack *st) { 
   return st->top + 1; 
} 

// Display function
void display(struct stack st) { 
   printf("Stack elements:\n"); 
   
   for(int i = st.top; i >= 0; i--) { 
      printf("%d\n", st.s[i]); 
   }
}

// isEmpty function
void isEmpty(struct stack st){
   if(st.top == -1) printf("Stack is empty\n");
   else printf("Stack is not empty\n");
   printf("\n");
} 
