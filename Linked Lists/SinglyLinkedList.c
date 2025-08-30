#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}Node;

void print(Node *head){
    Node *cur = head;
    for(cur = head; cur != NULL; cur = cur->next){
        printf("%d -> ",cur->data);
    }
    printf("NULL \n");
}

int length(Node *head){
    int count = 0;
    Node *cur = head;
    for(cur = head;cur != NULL; cur = cur->next){
        count++;
    }
    return count;
}

Node *PushFront(Node *head, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *PushBack(Node *head, int data){
    Node *newNode =malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *cur = head;
     
    if(cur ==NULL){
        head = newNode;
    }
    else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next=newNode;
    }
    return head;
}

Node *Push(Node *head, int data, int n){

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(n==1){
        newNode->next = head;
        return newNode;
    }

    Node *pred = head;
    for(int i = 1; i<n-1 && pred != NULL; i++){
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;
    return head;
}

void PopFront(Node **head){
    if(*head == NULL){
        printf("List is already empty. \n");
        return;
    }
    // Node *temp = *head;
    Node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void PopBack(Node **head){
    Node *tail= *head;
    Node *newTail = NULL;

    if(*head == NULL){
        printf("List is already empty");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    while(tail->next != NULL){
        newTail = tail;
        tail = tail->next;
    }
    newTail->next = NULL;
    free(tail);
}

void Pop(Node **head, int pos){
    int k = 1;
    Node *current = *head;
    Node *prev = NULL;

    if(*head == NULL){
        printf("List is already empty. \n");
        return;
    }

    if(pos == 1){
        *head = (*head)->next;
        free(current);
        return;
    }
    else{
        while((current != NULL) && k < pos){
            k++;
            prev = current;
            current = current->next;
        }
        if(current == NULL){
            printf("OUT OF BOUNDS. \n");
            return;
        }
        else{
            prev->next = current->next;
            free(current);
        }
    }
}

void Delete(Node **head){
    Node *current = *head;
    Node *nextNode = NULL;

    while(current != NULL){
        nextNode = current -> next;
        free(current);
        current = nextNode;
    }
}

int main(){
    Node *head = NULL;
    // Add a few nodes
    head = PushFront(head, 10);
    head = PushBack(head, 30);
    head = Push(head, 20, 2);
    head = PushBack(head, 40);

    print(head);
    printf("Length = %d\n", length(head));

    PopFront(&head);
    print(head);

    PopBack(&head);
    print(head);

    Pop(&head, 2);
    print(head);

    return 0;
}