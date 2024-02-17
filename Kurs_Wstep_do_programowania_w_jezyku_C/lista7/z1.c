#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Patryk Maciąg, 331542, lista 7, zad.1.




typedef struct node{
char *val;
struct node *next;
}Node;

void Init(Node **head)
{
    *head=NULL;
}


void Insert(Node **head, int p, char *x) //p=0 to przód listy, p=1 to tył listy
{
    
        Node *current=*head;
        
       
            if((*head)==NULL)
            {
            current=malloc(sizeof(Node));
            current->next=current;
            char *sn=malloc(strlen(x)+1);
            strcpy(sn,x);
            current->val=sn;
            *head=current;
            }
            else
            {
                if(p==1)
                {
                    while(current->next!=(*head))
                    {
                        current=current->next;
                    }
                    Node *temp_node=current;
            current->next=malloc(sizeof(Node));
            current->next->next=*head;
            char *sn=malloc(strlen(x)+1);
            strcpy(sn,x);
            current->next->val=sn;
            return;
                }
              Node *temp_node=current;
            current=malloc(sizeof(Node));
            current->next=temp_node;
            char *sn=malloc(strlen(x)+1);
            strcpy(sn,x);
            current->val=sn;

            
           
            temp_node=current;
            current=current->next;
            while(current->next!=*head)
            {
                current=current->next;
            } 
            current->next=temp_node;
            *head=temp_node;
            
            }

       
}







bool Empty(Node **head)
{
    if(*head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


char *Delete(Node **head)
{
     if(*head==NULL)
     {
         printf("Pusta lista.\n");
         char *wynik=NULL;
         return wynik;
     }
     else
     {
         Node *current=*head;
        
        Node *temp_node=*head;
       
        char *wynik=current->val;
        
    
        if(current==current->next)
        {
            free(*head);
            *head=NULL;
            return wynik;
        }

        while(current->next!=(*head))
        {
            current=current->next;
        }
        current->next=(*head)->next;
        temp_node=(*head)->next;
        free(*head);
        *head=temp_node;
        return wynik;
     }
}

int main()
{
    printf("Wczytano słowo Ala na początek listy, słowo ma na koniec, pobrano słowo z początku listy, dodano kota na początek.\n");
    Node *head;
    Init(&head);


    int p;
    
    char napis[100];
    
    //scanf("%99s %d", napis, &p); 
    //p=0 to przód listy, p=1 to tył listy
    strcpy(napis,"Ala");
    p=0;
    Insert(&head,p,napis);


    //scanf("%99s %d", napis, &p);
    strcpy(napis,"ma");
    p=1;
    Insert(&head,p,napis);


    char *wynik=Delete(&head);
     if(wynik!=NULL) printf("Pierwsze słowo na liście: %s\n", wynik);



    //scanf("%99s %d", napis, &p);
    strcpy(napis,"kota");
    p=0;
    Insert(&head,p,napis);

        
        
    wynik=Delete(&head);
    if(wynik!=NULL) printf("Drugie słowo na liście: %s\n", wynik);



    wynik=Delete(&head);
    if(wynik!=NULL) printf("Trzecie słowo na liście: %s\n", wynik);



    wynik=Delete(&head);
    if(wynik!=NULL) printf("Czwarte słowo na liście: %s\n", wynik);




    return 0;
}