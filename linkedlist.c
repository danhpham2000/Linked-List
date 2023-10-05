


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node * next = NULL;
} *first=NULL;




void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void displayR(struct Node *p) {
    if (p!=NULL) {
        displayR(p->next);
        printf("%d\n", p->data);

    }
}

int count(struct Node *p) {
    int c = 0;

    while (p != NULL) {
        p = p->next;
        c++;
    }

    return c;
}

int countR(struct Node * p) {
    if (p != NULL) {
        return countR(p->next) + 1;
    }
    else {
        return 0;
    }
}


int add(struct Node *p) {
    int sum = 0;
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int max(struct Node *p) {
    int maxNum = 0;
    while (p != NULL) {
        if (p->data > maxNum) {
            maxNum = p->data;
        }
        p = p->next;
    }

    return maxNum;
}

int min(struct Node * p) {
    int minNum = 100;
    while (p != NULL) {
        if (p->data < minNum) {
            minNum = p->data;
        }
        p = p->next;

    }
    return minNum;
}

Node * LinearSearch(struct Node *p, int key) {
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

Node * LinearSearchOp(struct Node *p, int key) {
    Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }

        q = p;
        p = p->next;
    }

    return NULL;
}


void InsertAny(struct Node *p, int data, int pos) {
    Node * t = new Node;
    if (pos < 0 || pos > count(p))
    {
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;

    if (pos == 0) {
        t->next = first;
        first = t;
    }

    else {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }


}


void SortedInsert(struct Node *p, int data) {
    Node * t, *q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (first == NULL) {
        first = t;
    }
    else {
        while(p && p->data < data) {
            q = p;
            p = p->next;
        }

        if (p == first) {
            t->next = first;
            first = t;
        }

        else {
            t->next = q->next;
            q->next = t;
        }
    }
}


int DeleteNode(struct Node * p, int pos)
{
    struct Node *q = NULL;
    int x = -1;
    
    if (pos < 1 || pos > count(p))
    {
        return x;
    }
    
    if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
        
    }
}


bool isSorted(struct Node *p)
{
    int x = 0;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return false;
        }
        else {
            x = p->data;
            p = p->next;
        }
    }
    
    return true;
    
}


int main(int argc, const char * argv[]) {

//    int A[] = {3,5,7};
//    create(A, 3);
//
//    displayR(first);
//    printf("There are %d elements in the linked list.\n", count(first));
//    printf("There are %d elements in the linked list.\n", countR(first));
//
//    printf("Sum is %d\n", add(first));
//    printf("The max number is %d\n", max(first));
//    printf("The min number is %d\n", min(first));
//    printf("Linear Search: %p\n", LinearSearch(first, 3));
//    struct Node * temp;
//    temp = LinearSearchOp(first, 10);
//
//    if (temp) {
//        printf("Key found!\n");
//    }
//    else {
//        printf("Key not found\n");
//    }
//    display(first);
//    printf("The first node is now   %d\n", first->data);

    SortedInsert(first, 50);
    SortedInsert(first, 40);
    SortedInsert(first, 70);
    SortedInsert(first, 60);
    InsertAny(first, 30, 0);
    InsertAny(first, 55, 1);
    DeleteNode(first, 1);


    display(first);
    printf("\n");


    return 0;
}


