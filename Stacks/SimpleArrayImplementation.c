#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Stack{
    int top;
    int capacity;
    int *array; 
}Stack;

Stack *createStack(int capacity){
    Stack *S = malloc(sizeof(Stack));
    if(!S){
        printf("Stack couldn't be created. \n");
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int)); //(s->capacity x 4 bytes)
    if(!S->array){
        return NULL;
    }
    return S;
}

int size(Stack *S){
    return (S->top + 1);
}

int isFull(Stack *S){  //not used directly
    return (size(S) == S->capacity);
}

int isEmpty(Stack *S){
    return (S->top == -1);
}

void push(Stack *S, int data){
    if(isFull(S)){
        printf("Stack OverFlow. \n");
        return;
    }
    else{
        S->top = S->top + 1;     
        int index = S->top;      
        S->array[index] = data;  // Place the new data at the new top

        // S->array[++S->top] = data;
        printf("%d pushed into stack. \n", data);
    }
}

int pop(Stack *S){
    if(isEmpty(S)){
        printf("Stack UnderFlow. \n");
        return INT_MIN;
    }
    int popped = S->array[S->top--];
    printf("%d popped from stack. \n", popped);
    return popped;
}

int peek(Stack *S){
    if(isEmpty(S)){
        printf("Stack UnderFlow. \n");
        return INT_MIN;
    }
    else{
        return(S->array[S->top]);
    }
}

void deleteStack(Stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
    free(S);
    }
}

void display(Stack *S){

    if(isEmpty(S)){
        printf("Stack is empty.\n");
        return;
    }

    printf("\nStack elements (bottom to top): ");
    for(int i = 0; i <= S->top; i++){
        printf("%d ", S->array[i]);
    }
    printf("\n");
}

int main(){
    int capacity = 15;
    Stack *Stk = createStack(capacity);

    push(Stk,1);
    push(Stk,3);
    push(Stk,5);
    push(Stk,7);
    push(Stk,9);
    push(Stk,11);
    push(Stk,13);
    push(Stk,15);
    push(Stk,17);
    push(Stk,19);

    display(Stk);

    pop(Stk);
    display(Stk);

    printf("Top element is %d\n",peek(Stk));
    printf("Size of stack is %d\n", size(Stk));

    if(isEmpty(Stk)){
        printf("Stack is empty. \n");
    }
    else{
        printf("Stack is not empty. \n");
    }
    
    deleteStack(Stk);

    return 0;
}