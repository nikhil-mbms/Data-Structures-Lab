#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->val = data;
    return newNode;
}

void insert(){
    printf("Enter the value to insert : ");
    int data;
    scanf("%d",&data);
    if(!head){
        head = createNode(data);return;
    }
    struct Node* cur = head;
    struct Node* newNode = createNode(data);
    while(cur->next){
        cur = cur->next;
    }
    cur->next = newNode;
}

void dB(){
    if(!head){
        printf("Underflow");
        return;
    }
    if(!head->next){
        head = NULL;
        return;
    }
    head = head->next;

}

void dE(){
    if(!head){
        printf("Underflow");
        return;
    }
    if(!head->next){
        head = NULL;
        return;
    }
    struct Node* cur = head;
    while(cur->next->next){
        cur = cur->next;
    }
    cur->next = NULL;
}

void dP(){
    if(!head){
        printf("Underflow");
        return;
    }
    printf("Enter the position : ");
    int p;
    scanf("%d",&p);
    int i = 0;
    struct Node* cur = head;
    struct Node* dummy =  createNode(0);
    dummy->next = head;
    struct Node* prev = dummy;
    while(cur && i!=p){
        cur = cur->next;
        prev = prev->next;
        i++;
    }
    if(i<p){
        printf("Position %d does not exist",p);return;
    }
    prev->next = cur->next;
    if(p==0) {
        if(!head->next){
            head = NULL;
        }
        else{
            head = dummy->next;
        }
    }
}

void display(){
    if(!head){
        printf("Underflow");
        return;
    }
    struct Node* cur = head;
    while(cur){
        printf("%d ",cur->val);
        cur = cur->next;
    }    
}
void main(){
    int choice;
    printf("Enter 1 to insert, 2 to delete at beginning, 3 to delete at end, 4 to delete at a position and 5 to display\n");

    while(1){
        scanf("%d",&choice);
        if(choice==1) insert();
        if(choice==2) dB();
        if(choice==3) dE();
        if(choice==4) dP();
        if(choice==5) display();
    }
}