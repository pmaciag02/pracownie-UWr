#include <stdio.h>
#include <stdlib.h>


typedef struct node *List;
List Init();
List addNumber(int n, List L);
List addSublist(List subL, List L);
void print(List L);
List mergeL(List l1, List l2);
List flat(List L);

