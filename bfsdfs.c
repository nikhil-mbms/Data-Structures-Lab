#include<stdio.h>

int n;

int g[10][10];

int v[10];

void bfs(int s){

 int q[10], f=0, r=0;

 for(int i=0;i<n;i++) v[i]=0;

 q[r++] = s;

 v[s] = 1;

 while(f<r){

 int x = q[f++];

 printf("%d ",x);

 for(int i=0;i<n;i++){

 if(g[x][i] && !v[i]){

 v[i] = 1;

 q[r++] = i;

 }

 }

 }

 printf("\n");

}

void dfs(int s){

 v[s] = 1;

 for(int i=0;i<n;i++){

 if(g[s][i] && !v[i])

 dfs(i);

 }

}

int main(){

 int s, c=1;

 scanf("%d",&n);

 for(int i=0;i<n;i++)

 for(int j=0;j<n;j++)

 scanf("%d",&g[i][j]);

 scanf("%d",&s);

 bfs(s);

 for(int i=0;i<n;i++) v[i]=0;

 dfs(0);

 for(int i=0;i<n;i++){
if(!v[i]){

 c=0;

 break;

 }

 }

 if(c) printf("Connected\n");

 else printf("Not Connected\n");

 return 0;

}
