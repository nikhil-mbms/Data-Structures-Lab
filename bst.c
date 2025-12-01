#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int v;
    struct n *l,*r;
}N;

N* c(int x){
    N* t=malloc(sizeof(N));
    t->v=x; t->l=t->r=NULL;
    return t;
}

N* ins(N* r,int x){
    if(!r) return c(x);
    if(x<r->v) r->l=ins(r->l,x);
    else r->r=ins(r->r,x);
    return r;
}

void in(N* r){
    if(r){ in(r->l); printf("%d ",r->v); in(r->r); }
}

void pre(N* r){
    if(r){ printf("%d ",r->v); pre(r->l); pre(r->r); }
}

void post(N* r){
    if(r){ post(r->l); post(r->r); printf("%d ",r->v); }
}

int main(){
    N* r=NULL;
    int x,n; 
    scanf("%d",&n);
    while(n--){ scanf("%d",&x); r=ins(r,x); }
    printf("In: "); in(r);
    printf("\nPre: "); pre(r);
    printf("\nPost: "); post(r);
}
