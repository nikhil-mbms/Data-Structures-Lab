#include<stdio.h>
#include<string.h>
int q[5];
int front = -1;
int rear = -1;
int cap = 5;
void insert(){
    printf("Enter the element to insert : ");
    int ele;
    scanf("%d",&ele);
    if(rear==cap-1)
    
    {
        printf("Queue overflow \n") ;
        return;
    }
    
    else {
        q[++rear]  = ele;
        if(front==-1) front++;
    }    
}
void delete(){
    if(front==-1||front>rear){
        printf("Queue underflow \n");
        return ;
    }
    int del = q[front];
    front++;
    printf("%d is deleted \n",del);

}
void display(){
    if(front==-1||front>rear){
        printf("Queue underflow");
        return ;
    }
    for(int i=front;i<=rear;i++){
        printf("%d \n",q[i]);
    }
}
void main(){
    printf("Enter the opertaion : \n");
    printf("insert,delete or display\n");
    printf("Enter quit to quit\n");
    while(1){
        char choice[20];
         scanf("%s",choice);
         if(strcmp(choice,"quit")==0) break;
         if(strcmp(choice,"insert")==0) insert();
         if(strcmp(choice,"delete")==0) delete();
         if(strcmp(choice,"display")==0) display();
    }


}

