/* Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”, design an algorithm and a program to 
   check whether this expression has balanced paranthesis or not.
*/

/* Time Complexity  : O(T*n) 
   Space Complexity : O(1)
*/

// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure declaration
struct stack {
    int size;
    int top;
    char *s;
};

// Functions declaration
void create(struct stack *st, int size);
void push(struct stack *st, char x);
char pop(struct stack *st);
int isEmpty(struct stack *st) ;
int isValidParentheses(char *expr);

// Main function
int main() {
    int T;     // Test case declaration
    char expr[100];     // String declaration

    scanf("%d", &T);     // Read number of test case

    while(T--){
        scanf("%s", expr);     // Read the string
 
        // Checking for valid parentheses
        if(isValidParentheses(expr)) printf("Balanced.\n");
        else printf("Unbalanced.\n");
    }

    return 0;
}

// Create stack function
void create(struct stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->s = (char *)malloc(st->size * sizeof(char));
}

// Push function
void push(struct stack *st, char x) {
    if(st->top == st->size - 1){
        printf("Stack overflow\n");
    } 

    else{
        st->top++;
        st->s[st->top] = x;
    }
}

// Pop function
char pop(struct stack *st) {
    char x = '\0';
    if(st->top == -1){
        printf("Stack underflow\n");
    } 

    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

// IsEmpty function
int isEmpty(struct stack *st) {
    return st->top == -1;
}

// IsValidParentheses function
int isValidParentheses(char *expr) {
    int length = strlen(expr);
    struct stack st;
    create(&st, length);

    for(int i = 0; i < length; i++) {
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&st, expr[i]);
        } 
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if(isEmpty(&st)) {
                return 0; 
            }
            char left = pop(&st);
            char right = expr[i];
            
             if(left=='('){
                 if(right!=')')
                 {
                     return 0;
                 }
             }
             if(left=='['){
                 if(right!=']')
                 {
                     return 0;
                 }
             }
             if(left=='{'){
                 if(right!='}')
                 {
                     return 0;
                 }
             }
        }
    }
    return isEmpty(&st); 
}
