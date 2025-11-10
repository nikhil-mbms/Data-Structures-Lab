#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->val = data;
    return newNode;
}

struct Node* head = NULL;
void insertB(){
    printf("Enter the value of the node : ");
    int data;
    scanf("%d",&data);
    struct Node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;return;
    }
    newNode->next = head;
    head = newNode;
}
void insertE(){
    printf("Enter the value of the node : ");
    int data;
    scanf("%d",&data);
    struct Node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;return;
    }
    struct Node* cur = head;
    while(cur->next)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void insertP(){
    printf("Enter value and position of node : ");
    int data,pos;
    scanf("%d %d",&data,&pos);
    struct Node* dummy = createNode(0);
    dummy->next = head;
   
    struct Node* cur = head;int count = 0;
    while(cur && count<pos-1){
        cur = cur->next;count++;
    }
    struct Node* newNode = createNode(data);
    newNode->next = cur->next;
    cur->next = newNode;
}

void display(){
    struct Node* cur = head;
    while(cur){
        printf("%d ",cur->val);
        cur = cur->next;
    }
}

void main(){
    printf("Enter 1 to insert at beginning,2 to insert at end ,3 to insert at a position and 4 to display\n");
    int choice;

    while(1){
        scanf("%d",&choice);
        if(choice==1) insertB();
        if(choice==2) insertE();
        if(choice==3) insertP();
        if(choice==4) display();
    }
}