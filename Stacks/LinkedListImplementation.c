#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

typedef struct Stack{
    struct ListNode *top;
}Stack;

Stack *createStack(){
    Stack *stk;
    stk = malloc(sizeof(Stack));
    stk->top = NULL;
    return stk;
}

int isEmpty(Stack *stk){
    return(stk->top == NULL);
}

void push(Stack *stk, int data){
    Node *temp;
    temp = malloc(sizeof(Node));
    if(!temp){
        printf("Stack/Heap Overflow. \n");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

int size(Stack *stk){
    int count = 0;
    Node *temp;
    if(isEmpty(stk)){
        return 0;
    }
    temp = stk->top;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int pop(Stack *stk){
    int data;
    Node *temp;
    if(isEmpty(stk)){
        return INT_MIN;
    }
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int peek(Stack *stk){
    if(isEmpty(stk)){
        return INT_MIN;
    }
    return stk->top->data;
}

void deleteStack(Stack *stk){
    Node *temp, *p;
    p = stk->top;
    while(p){
        temp = p->next;
        p = p->next;
        free(temp);
    }
    free(stk);
}
int main(){
    int i =0;
    Stack *s = createStack();

    for(i = 0; i <= 10; i++){
        push(s,i);
    }

    printf("%d is the top element. \n",peek(s));
    printf("Stack size is %d", size(s));

    for(i = 0; i <= 10; i++){
        printf("Popped elemet is %d\n", pop(s));
    }

    if(isEmpty(s)){
        printf("Stack is empty. \n");
    }
    else{
        printf("Stack is not empty. \n");
    }
    deleteStack(s);
    return 0;
}