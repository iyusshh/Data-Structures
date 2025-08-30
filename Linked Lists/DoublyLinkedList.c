#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
}Node;

void print(Node *head) {
    Node *current = head;
    printf("NULL <- ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL)
            printf(" <-> ");

        current = current->next;
    }
    printf(" -> NULL\n");
}

void PushFront(Node **head, int data){
    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory Allocation error. \n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void PushBack(Node **head, int data){
    Node *newNode =  malloc(sizeof(Node));

    if(newNode== NULL){
        printf("Memory Allocation Failed. \n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *tail = *head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
}

void Push(Node **head, int data, int pos){
    int current = 1;
    Node *temp, *newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if(!newNode){
        printf("Memory Allocation Failed. \n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(pos == 1){
        newNode->next = *head;
        if(*head){
            (*head)->prev = newNode;
        }
    *head = newNode;
    return;
    }

    temp = *head;
    while(current < pos-1 && temp != NULL){
        temp = temp->next;
        current++;
    }

    if(temp == NULL){
        printf("Desired position doesn't exist. \n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    
    if(temp->next){
        temp->next->prev = newNode; //jump to pos+1 and put prev= newnode
    }
    temp->next = newNode;
}

void PopFront(Node **head){
    Node *temp;
    if(!*head){
        printf("List is already empty. \n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    if(*head){
        (*head)->prev = NULL;
    }
    free(temp);
}

void PopBack(Node **head){
    Node *current, *temp;
    if(!*head){
        printf("List is already empty. \n");
        return;
    }
    temp=current=*head;
    if(!current->next){
        free(current);
        *head = NULL;
        return;
    }

    while(current->next){
        current = current->next;
    }
    temp = current->prev;
    temp ->next = NULL;
    free(current);
}

void Pop(Node **head, int pos){
    Node *temp, *temp2;
    int current = 1;
    if(!*head){
        printf("List is already empty. \n");
        return;
    }
    temp = *head;
    if(pos == 1){
        *head = (*head)->next;
        if(*head){
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while(current<pos && temp != NULL){
        temp = temp->next;
        current++;
    }
    if(temp == NULL){
        printf("Desired Position does not exist. \n");
        return;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    if(temp->next){
        temp->next->prev = temp2;
    }
    free(temp);
}

int main(){

    Node *head = NULL;

    PushFront(&head, 20);
    PushFront(&head, 10);
    PushBack(&head, 40);
    PushBack(&head, 50);
    Push(&head, 30, 3);

    print(head);

    PopFront(&head);
    PopBack(&head);
    print(head);

    Pop(&head, 2);
    print(head);

    return 0;
}