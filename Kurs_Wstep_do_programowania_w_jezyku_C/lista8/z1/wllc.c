#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wllc.h"


typedef struct node{
bool isNumber;
int number;
struct node *sublist;
struct node *next;
}Node;

List Init()
{
    List L=malloc(sizeof(Node));
    L->isNumber=0;
    L->number=0;
    L->sublist=NULL;
    L->next=NULL;

    return L;
}


List addNumber(int n, List L)
{
    List current=malloc(sizeof(Node));
    current->isNumber=1;
    current->number=n;
    current->sublist=NULL;

    (L->isNumber || L->sublist!=NULL)?(current->next=L):(current->next=NULL);

    L=current;

       return L;
}

List addSublist(List subL, List L)
{
    List l=malloc(sizeof(Node));
    l->isNumber=0;
    l->number=0;//?
    l->sublist=subL;
    l->next=L;

    return l;
}

void print(List L)
{
    putchar('[');
    if(L->sublist!=NULL)
        {
            print(L->sublist);
            if(L->next->next!=NULL) printf(", ");
            L=L->next;
        }
    if(L->isNumber)
    {
    printf("%d", L->number);

    while(L->next!=NULL)
    {
        L=L->next;
        if(L->isNumber)
        {
            printf(", ");
            printf("%d", L->number);
        }
        if(L->sublist!=NULL)
        {
            printf(", ");
            print(L->sublist);
        }
    }
    }
    if(L->sublist!=NULL)
        {
            print(L->sublist);
            if(L->next->next!=NULL) printf(", ");
            L=L->next;
        }

    putchar(']');
}










List flat(List L)
{

List head=malloc(sizeof(Node));
    head->isNumber=0;
    head->number=0;
    head->sublist=NULL;
    head->next=NULL;
    List L2=head;
//List head=L2;

    //putchar('[');
    if(L->sublist!=NULL)
        {
       // L2=malloc(sizeof(Node));
        L2->sublist=NULL;
        //List temp=head;
        L2=flat(L->sublist);
        //head=temp;
        while(L2->next!=NULL)
        {
        L2=L2->next;
        }
            //print(L->sublist);
            //if(L->next->next!=NULL) printf(", ");
            L=L->next;
             L2->next=malloc(sizeof(Node));
        L2=L2->next;
        L2->isNumber=0;
    L2->number=0;
    L2->sublist=NULL;
    L2->next=NULL;
        }
    if(L->isNumber)
    {
   // printf("%d", L->number);
   // L2=malloc(sizeof(Node));
   L2->isNumber=1;
   L2->number=L->number;
    while(L->next!=NULL)
    {
        L=L->next;
        L2->next=malloc(sizeof(Node));
        L2=L2->next;
        L2->isNumber=0;
    L2->number=0;
    L2->sublist=NULL;
    L2->next=NULL;
        if(L->isNumber)
        {
            //printf(", ");
           // printf("%d", L->number);
            L2->isNumber=1;
            L2->number=L->number;
        }
        if(L->sublist!=NULL)
        {
            //printf(", ");
            //print(L->sublist);
            L2=flat(L->sublist);
        }
    }
    }
    if(L->sublist!=NULL)
        {
            //print(L->sublist);
            L2=flat(L->sublist);
            while(L2->next!=NULL)
        {
        L2=L2->next;
        }
            //if(L->next->next!=NULL) printf(", ");
            L=L->next; //?

        }

    //putchar(']');
    //printf("%d ",head->number);
    return head;
}


