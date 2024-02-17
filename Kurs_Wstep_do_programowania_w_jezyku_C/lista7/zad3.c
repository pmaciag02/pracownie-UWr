#include <stdio.h>
#include <stdlib.h>



typedef struct node{
int val;
struct node *next;
}Node;

void init()
{

}

void Insert(Node **head, int p, int x)
{
        Node *current=*head;
        for(int i=0; i<p; i++)
        {
            current=current->next;
        }
        Node *temp_node=current->next;
        current->next=malloc(sizeof(Node));
        current->next->val=x;
        current->next->next=temp_node;
    //int wynik=*head->val;
      //   printf("%d\n", wynik);
}


int Sum(Node **head, int p1, int p2)
{
    Node *current=*head;
    for(int i=0; i<p1; i++)
    {
            current=current->next;
    }
    int wynik=0;
    for(int i=p1; i<=p2; i++)
    {
        wynik+=current->val;
        current=current->next;
    }
    return wynik;
}


void Delete(Node **head, int p)
{
    if(p==0) //head==NULL
    {
        Node *temp_node=*head;
        temp_node=temp_node->next;
        free(*head);
        *head=temp_node;
    }
    else
    {
    Node *current=*head;
        for(int i=0; i<p-1; i++)
        {
            current=current->next;
        }
        Node *temp_node=current->next->next;
        free(current->next);
        current->next=temp_node;
    }
}

int main()
{

Node *head=malloc(sizeof(Node));
head->next=NULL;
head->val=0;


int N, n, p1, p2;
scanf("%d", &N);
getchar();
while(N--)
{
    if((n=getchar())=='I')
    {
        getchar();
        scanf("%d %d", &p1, &p2);
        getchar();
        //printf("%d %d %d\n", n, p1, p2);
         Insert(&head,p1,p2);

        //  Node *current=head;

        // while(current->next!=NULL)
        // {
        //     current=current->next;
        // }
        //   int wynik=current->val;
        //   printf("%d\n", wynik);
    }
    else if(n=='D')
    {
        getchar();
        scanf("%d", &p1);
        getchar();

        Delete(&head,p1);
    }
    else
    {
        getchar();
        scanf("%d %d", &p1, &p2);
        getchar();

        int wynik=Sum(&head,p1,p2);
        printf("%d\n", wynik);

    }
}



    return 0;
}
