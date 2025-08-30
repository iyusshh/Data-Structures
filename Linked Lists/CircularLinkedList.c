#include<stdio.h>
#include<stdlib.h>

typedef struct CLLNode{
    int data;
    struct CLLNode *next;
}Node;

int length(Node *head){
    Node *current = head;
    int count = 0;
    if(!head){
        return 0;
    }
    do{
        current = current->next;
        count++;
    }while(current != head);
    return count;
}

void Print(Node *head){
    Node *current = head;
    if(!head){
        return;
    }
    do{
        printf("%d -> ",current->data);
        current = current->next;
    }while(current != head);
    printf("\n");
}

void PushBack(Node **head, int data){
    Node *current;
    Node *newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed. \n");
        return;
    }

    newNode->data = data;
    newNode->next = newNode;

    if(!*head){
        *head = newNode;
        return;
    }
    
    current = *head;
    while(current->next != *head){
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
}

void PushFront(Node **head, int data){
    Node *current;
    Node *newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed. \n");
        return;
    }

    newNode->data = data;
    newNode->next = newNode;

    if(!*head){
        *head = newNode;
        return;
    }

    current = *head;
    while(current->next != *head){
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void PopBack(Node **head){
    Node *tail = *head;
    Node *newTail = NULL;

    if(!*head){
        printf("List is already empty. \n");
        return;
    }

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }

    while(tail->next != *head){
        newTail = tail;
        tail = tail->next;
    }
    newTail->next = tail->next;
    free(tail);

}

void PopFront(Node **head){
    Node *temp = *head;
    Node *current = *head;

    if(!*head){
        printf("List is already empty. \n");
        return;
    }

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }

    while(current->next != *head){
        current = current->next;
    }
    *head = (*head)->next;
    current->next = *head;
    free(temp);
}

int main() {
    Node *head = NULL; 

    PushFront(&head, 20);
    PushFront(&head, 10);
    PushBack(&head, 30);
    PushBack(&head, 40);

    Print(head);

    PopBack(&head);
    Print(head);
    PopFront(&head);
    Print(head);

    printf("length of CLL is : %d\n", length(head));

    PopFront(&head);
    printf("length of CLL is : %d\n", length(head));

    PopBack(&head);
    printf("length of CLL is : %d\n", length(head));


    return 0;
}
