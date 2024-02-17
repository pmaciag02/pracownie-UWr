#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
int val; //nr polecenia w ktorym powstal wezel
int odw;
struct node *L;
struct node *R;
}Node;



void cons(Node **head, Node *l, Node *r, int n)
{
    *head=malloc(sizeof(Node));
    (*head)->L=l;
    (*head)->R=r;
    (*head)->val=n;
    (*head)->odw=0;
}

void car(Node **head, Node *l)
{
//if(*head==NULL) return;
    (*head)=l->L;
}

void cdr(Node **head, Node *r)
{
//if(*head==NULL) return;
    (*head)=r->R;
}




void dfs(Node *head, int *wynik)
{
    if(head==NULL) return;

    if((head)->odw) return;

    (head)->odw=1;
    dfs((head)->L, wynik);
    dfs((head)->R, wynik);

    (*wynik)++;
}

void dfs2(Node **head)
{
    if(*head==NULL) return;
    if((*head)->odw==0) return;
    (*head)->odw=0;
    dfs2(&(*head)->L);
    dfs2(&(*head)->R);
}


int main()
{

// Node *x=NULL;
// Node *y=NULL;
// Node *z=NULL;
Node *tab[5];
tab[0]=NULL;
tab[1]=NULL;
tab[2]=NULL;

int N, n=0, X=0, Y=0, Z=0, CELLS=0;
//N=getchar();
scanf("%d", &N);
//N-=48;
getchar();
printf("round: 0, x: 0, y: 0, z: 0, cells: 0\n");

//char polecenie[11];
while(N--)
{
     n++;
int znak=getchar();
getchar();//' '
getchar();//':'
getchar();//'='
getchar();//' '
int pol=getchar();
int pol2=getchar();




//scanf(" := %10s", polecenie);


if(pol=='n')
{
getchar();//'l'
getchar();//'l'
getchar();//'\n'
    tab[znak-120]=NULL;
    CELLS=0;
    dfs(tab[0], &CELLS);
    dfs(tab[1], &CELLS);
    dfs(tab[2], &CELLS);
    dfs2(&tab[0]);
    dfs2(&tab[1]);
    dfs2(&tab[2]);
    if(znak=='x')
    {
        X=0;
    }
    else if(znak=='y')
    {
        Y=0;
    }
    else if(znak=='z')
    {
        Z=0;
    }
}
else if(pol2=='o')
{
    getchar();//'n'
    getchar();//'s'
    getchar();//' '
    int pp1=getchar();
    getchar();//' '
    int pp2=getchar();
    getchar();//'\n'

    cons(&tab[znak-120], tab[pp1-120], tab[pp2-120], n);

    CELLS=0;
    dfs(tab[0], &CELLS);
    dfs(tab[1], &CELLS);
    dfs(tab[2], &CELLS);
    dfs2(&tab[0]);
    dfs2(&tab[1]);
    dfs2(&tab[2]);
    if(znak=='x')
    {
        (tab[0]!=NULL)?(X=tab[0]->val):(X=0);
    }
    else if(znak=='y')
    {
        (tab[1]!=NULL)?(Y=tab[1]->val):(Y=0);
    }
    else if(znak=='z')
    {
        (tab[2]!=NULL)?(Z=tab[2]->val):(Z=0);
    }


}
else if(pol2=='a')
{
    getchar();//'r'
    getchar();//' '
    int p1=getchar();
    getchar();//'\n'
    car(&tab[znak-120], tab[p1-120]);
    CELLS=0;
    dfs(tab[0], &CELLS);
    dfs(tab[1], &CELLS);
    dfs(tab[2], &CELLS);
    dfs2(&tab[0]);
    dfs2(&tab[1]);
    dfs2(&tab[2]);
    if(znak=='x')
    {
        (tab[0]!=NULL)?(X=tab[0]->val):(X=0);
    }
    else if(znak=='y')
    {
        (tab[1]!=NULL)?(Y=tab[1]->val):(Y=0);
    }
    else if(znak=='z')
    {
        (tab[2]!=NULL)?(Z=tab[2]->val):(Z=0);
    }
}
else
{
    getchar();//'r'
    getchar();//' '
    int p1=getchar();
    getchar();//'\n'
    cdr(&tab[znak-120], tab[p1-120]);
    CELLS=0;
    dfs(tab[0], &CELLS);
    dfs(tab[1], &CELLS);
    dfs(tab[2], &CELLS);
    dfs2(&tab[0]);
    dfs2(&tab[1]);
    dfs2(&tab[2]);
    if(znak=='x')
    {
        (tab[0]!=NULL)?(X=tab[0]->val):(X=0);
    }
    else if(znak=='y')
    {
        (tab[1]!=NULL)?(Y=tab[1]->val):(Y=0);
    }
    else if(znak=='z')
    {
        (tab[2]!=NULL)?(Z=tab[2]->val):(Z=0);
    }
}
printf("round: %d, x: %d, y: %d, z: %d, cells: %d\n", n, X, Y, Z, CELLS);
}



    return 0;
}

