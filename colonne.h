#ifndef PROJECT_COLONNE_H
#define PROJECT_COLONNE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *titre;
    int TP;
    int TL;
    int *Tab;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int nb_occ(COLUMN *col, int x);
int give_val(COLUMN *col, int x);
int supp_x(COLUMN *col, int x);
int inf_x(COLUMN *col, int x);


#endif //PROJECT_COLONNE_H
