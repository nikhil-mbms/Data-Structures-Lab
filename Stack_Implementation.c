#include<stdio.h>
#include<conio.h>
#include<string.h>

void push();
void pop();
void display();
int SIZE = 5;
int arr[5];
int top = -1;
void main(){
    
    printf("Enter your choice \n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. display\n");
    while(1){
        printf("Enter your choice : \n");
        char str[10];
        scanf("%s",str);
        if(strcmp("pop",str)==0){
            pop();
        }
        else if(strcmp(str,"push")==0){
            push();
        }
        else if(strcmp(str,"display")==0){
            display();
        }
        else{
            printf("Wrong entry\n");
        }
    }

}

void push(){
    if(top == SIZE-1){
        printf("Stack is full\n");
        return;
    }
    printf("Enter the number to push : \n");
    int n;
    scanf("%d",&n);
    top++;
    arr[top] = n;
}

void pop(){
    if(top==-1){
        printf("Stack is empty cannot pop\n");
        return;
    }
    printf("The popped value is %d \n",arr[top]);
    top--; 
    
}
void display(){
    if(top==-1){
        printf("No elements to display\n");
        return;
    }
    printf("Elements are : \n");
    for(int i = top;i>=0;i--){
        printf("%d \n",arr[i]);
    }
}
