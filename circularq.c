#include<stdio.h>
#include<string.h>
int q[5];
int front = -1;
int rear = -1;
int cap = 5;
void insert(){
    printf("Enter the element to insert : ");
    int e;
    scanf("%d",&e);
    if(front==(rear+1)%cap)
    
    {
        printf("Queue overflow \n") ;
        return;
    }
    
    if(front==-1) front++;
    rear = (rear+1)%cap;
    q[rear] = e;  
}
void delete(){
    if(front==-1){
        printf("Queue underflow \n");
        return ;
    }
    int n;
    n = q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % cap;
    }
    
    printf("%d is deleted \n",n);

}
void display(){
    if(front==-1){
        printf("Queue underflow");
        return ;
    }
    for(int i=front;i!=rear;i=(i+1)%cap){
        printf("%d \n",q[i]);
    }
    printf("%d",q[rear]);
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

