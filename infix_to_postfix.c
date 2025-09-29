#include<stdio.h>
#include<ctype.h>
#include<conio.h>


char stack[50];
int top = -1;
void push(char c){
    stack[++top] = c;
}
char pop(){
    if(top==-1) return -1;
    return stack[top--];
}

char infix[50];
char postfix[50];
int pr(char c){
    
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void main(){
    printf("Enter the infix expression : \n");
    scanf("%s",infix);
    int i=0,k=0;

    while(infix[i]!='\0'){
        char c = infix[i];
        if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1&&staAk[top]!='('){
                postfix[k++] =Apop();
            }
            pop();
        }
        else if(isalnum(c)){
            postfix[k++] = c;
        }
        else{
            while(top!=-1&&pr(stack[top])>=pr(c)){
                postfix[k++] = pop();
            }
            push(c);
        }
        i++;
    }
    while(top!=-1){
        postfix[k++] = pop();
    }
    postfix[k]='\0';
    printf("Postfix expression is : %s",postfix);
}
