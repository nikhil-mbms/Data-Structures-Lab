#include<stdio.h>
#include<stdlib.h>

struct N{int v;struct N*n;};
struct N*ts=0,*qs=0,*qe=0;

void sp(int x){
    struct N*t=malloc(sizeof(struct N));
    t->v=x;t->n=ts;ts=t;
}
int spop(){
    if(!ts)return -1;
    int x=ts->v;
    struct N*t=ts;ts=ts->n;free(t);
    return x;
}

void qp(int x){
    struct N*t=malloc(sizeof(struct N));
    t->v=x;t->n=0;
    if(!qs)qs=qe=t;
    else qe->n=t,qe=t;
}
int qpop(){
    if(!qs)return -1;
    int x=qs->v;
    struct N*t=qs;qs=qs->n;free(t);
    if(!qs)qe=0;
    return x;
}

int main(){
    sp(1);sp(2);sp(3);
    printf("%d %d %d\n",spop(),spop(),spop());

    qp(4);qp(5);qp(6);
    printf("%d %d %d\n",qpop(),qpop(),qpop());
}
