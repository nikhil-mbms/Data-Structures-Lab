#include<stdio.h>

int ht[20];

int m;

void insert(int k){

 int i = k % m;

 int s = i;

 while(ht[i] != -1){

 i = (i + 1) % m;

 if(i == s){

 printf("Hash Table Full\n");

 return;

 }

 }

 ht[i] = k;

 printf("Inserted %d at %d\n",k,i);

}

void display(){

 for(int i=0;i<m;i++){

 if(ht[i] == -1)

 printf("%d : Empty\n",i);

 else

 printf("%d : %d\n",i,ht[i]);

 }

}

int main(){

 int n,k;

 scanf("%d%d",&m,&n);

 for(int i=0;i<m;i++) ht[i] = -1;

 for(int i=0;i<n;i++){

 scanf("%d",&k);

 insert(k);
}

 display();

 return 0;

}
