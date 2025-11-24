#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
} *head = NULL;

struct node* create(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x; p->prev = p->next = NULL;
    return p;
}

void insertEnd(int x) {
    struct node *p = create(x), *t = head;
    if(!head) head = p;
    else {
        while(t->next) t = t->next;
        t->next = p; p->prev = t;
    }
}

void insertLeft(int v, int x) {
    struct node *t = head, *p;
    while(t && t->data != v) t = t->next;
    if(!t) return;
    p = create(x);
    if(t == head) { p->next = head; head->prev = p; head = p; }
    else {
        p->next = t; p->prev = t->prev;
        t->prev->next = p; t->prev = p;
    }
}

void deleteVal(int v) {
    struct node *t = head;
    while(t && t->data != v) t = t->next;
    if(!t) return;
    if(t == head) head = t->next;
    if(t->prev) t->prev->next = t->next;
    if(t->next) t->next->prev = t->prev;
    free(t);
}

void display() {
    struct node *t = head;
    while(t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    int ch, x, v;
    while(1) {
        printf("\n1.Create 2.InsertLeft 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) { scanf("%d", &x); insertEnd(x); }
        else if(ch == 2) { scanf("%d%d", &v, &x); insertLeft(v, x); }
        else if(ch == 3) { scanf("%d", &v); deleteVal(v); }
        else if(ch == 4) display();
        else if(ch == 5) break;
    }
}
