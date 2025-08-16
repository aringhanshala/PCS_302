// Stack Implementation using array

// Preprocessors
#include<stdio.h>
#define max_size 100

// Functions declaration
void push(int value, int *top, int stack[]);
void pop(int *top, int stack[]);
int peek(int *top, int stack[]);
void isEmpty(int *top);
void isFull(int *top);
void display(int top, int stack[]);

// Main function
int main(){
    int stack[max_size];
    int top = -1, choice, value, terminate= 0;

    while(terminate == 0){

        // Printing the stack menu
        printf("Stack menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Display\n");
        printf("7. Exit");
        
        printf("\n");
        printf("\n");

        // Asking for the choice
        printf("What you want to do: ");
        scanf("%d", &choice);

        switch(choice){
        
        // Calling push function
        case 1: 
                if(top < max_size -1){
                    printf("Enter value to push: ");
                    scanf("%d", &value);
        
                    push(value, &top, stack);
                }

                else {
                    printf("Stack is full\n");
                    continue;
                }
                break;
        
        // Calling pop function
        case 2: pop(&top, stack);
                break;

        // Calling peek function
        case 3:
                printf("Top element: %d\n", peek(&top, stack));
                printf("\n");
                break;

        // Calling isEmpty function
        case 4: isEmpty(&top);
                break;

        // Calling isFull function
        case 5: isFull(&top);
                break;
        
        // Calling display function
        case 6: display(top, stack);
                break;

        // Exiting from the program
        case 7: printf("Exited from the program");
                terminate= 1;
                break;
        
        // If another choice comes
        default: printf("Invalid selection\n");

        }       
    }
}

// Push function
void push(int value, int *top, int stack[]){
    if(*top == max_size - 1){
        printf("Stack is full\n");
        return;
    }

    ++*top;
    stack[*top] = value;
}

// Pop function
void pop(int *top, int stack[]){
    if(*top == -1){
        printf("Stack is empty\n");
        return;
    } 

    printf("%d is poped\n", stack[*top]);
    printf("\n");
    --*top;
}

// Peek function
int peek(int *top, int stack[]){
    if(*top == -1) return -1;
    return stack[*top];
}

// isEmpty function
void isEmpty(int *top){
    if(*top == -1) printf("Stack is empty\n");
    else printf("Stack is not empty\n");
    printf("\n");
}

// isFull function
void isFull(int *top){
    if(*top == max_size - 1) printf("Stack is full\n");
    else printf("Stack is not full\n");
    printf("\n");
}

// Display function
void display(int top, int stack[]){
    while(top != -1){
        printf("%d ", stack[top]);
        top--;
    }
    printf("\n");
    printf("\n");
}
