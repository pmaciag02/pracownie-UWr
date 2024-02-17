#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>


//Patryk Maciąg, 331542, lista 10, zad.1 (dla samych permutacji)


GtkWidget *button, *numer, *text, *grid;
char *opis, t[20]="Permutacja nr: 1";
int perm[100], n, licznik=0, koniec=0;

bool next_perm(int n, int perm[n])
{
    if(n==1) return 1;
    int dalej=0;
    for(int i=1; i<=n; i++)
    {
        if(perm[i]!=i)
        {
            dalej=1;
            break;
        }
    }
    if(!dalej)return 0;

    if(perm[n]==n)
    {
        if(next_perm(n-1, perm))
        {
        for(int i=n; i>1; i--)
        {
            perm[i]=perm[i-1];
        }
        perm[1]=n;
        }
    }
    else
    {
        for(int i=1; i<n; i++)
    {
        if(perm[i]==n)
        {
        perm[i]=perm[i+1];
        perm[i+1]=n;
        break;
        }
    }
        return 1;
    }
return 1;
}

static void dalej(GtkWidget *widget,gpointer data)
{
if(koniec)gtk_main_quit();
licznik++;

opis="Permutacja:";
gtk_label_set_text(GTK_LABEL(numer), opis);

for(int i=0; i<n; i++)
{
 for(int j=0; j<n; j++)
 {
 if(perm[j+1]==(i+1))
 {
 opis="X";
 }
 else
 {
 opis="O";
 }
 button = gtk_grid_get_child_at(GTK_GRID(grid), j, i);
 gtk_label_set_text(GTK_LABEL(button), opis);
 }
}


if(!next_perm(n, perm))
{
    opis="Ostatnia permutacja:";
    gtk_label_set_text(GTK_LABEL(numer), opis);
    koniec=1;
}
}



int main(int argc,char *argv[])
{
if(argc<2)
{
    fprintf(stderr, "Użycie: %s <liczba naturalna n (rozmiar szachiwnicy nxn)>\n", argv[0]);
    exit(2);
}

n=atoi(argv[1]);

for(int i=0; i<n; i++)
{
    perm[i+1]=n-i;
}
licznik=0;

gtk_init(&argc, &argv);

GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"GTK - tylko permutacje (z przecięciami)");
gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
gtk_container_set_border_width(GTK_CONTAINER(window), 50);

g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);

GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
gtk_container_add(GTK_CONTAINER(window), box1);




opis="Pusta plansza";
numer=gtk_label_new(opis);
gtk_box_pack_start(GTK_BOX(box1), numer, TRUE, TRUE, 10);





grid = gtk_grid_new();

gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);



opis="O";

for(int i=0; i<n; i++)
{
 for(int j=0; j<n; j++)
 {
 button = gtk_label_new(opis);
 gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
 }
}
GtkWidget *button2 = gtk_button_new_with_label("Następna");
g_signal_connect(G_OBJECT(button2), "clicked",G_CALLBACK(dalej), NULL);
gtk_box_pack_start(GTK_BOX(box1), button2, TRUE, FALSE, 10);


gtk_widget_show_all(window);
gtk_main();


return 0;
}
