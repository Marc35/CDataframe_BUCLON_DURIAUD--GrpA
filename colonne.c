#include "colonne.h"
#include <string.h>
COLUMN *create_column(char* title)
{
    COLUMN *col = NULL;
    col = (COLUMN*) malloc(sizeof (COLUMN));
    col->titre = title;
    col->TP = 256;
    col->TL = 0;
    col->Tab = NULL;
    return col;
}


int insert_value(COLUMN* col, int value)
{
    if(col->TL == 0)
    {
        col->Tab = malloc(256*sizeof(int));
        col->TL = 1;
    }
    else
    {
        if (col->TL == col->TP)
        {
            int *temp = col->Tab;
            if (realloc(temp, col->TL + 256) != NULL)
            {
                col->Tab = temp;
            }
            else
            {
                return 0;
            }
            col->TP += 256;
            col->TL ++;
        }
        else
        {
            col->TL ++;
        }
    }
    col->Tab[col->TL - 1] = value;
    return 1;
}

void delete_column(COLUMN **col)
{
    free((*col)->Tab);
    (*col)->Tab = NULL;
    free(col);
}

void print_col(COLUMN* col)
{
    for(int i=0; i<col->TL; i++)
    {
        printf("[%d] %d\n", i, col->Tab[i]);
    }
}

int nb_occ(COLUMN *col, int x)
{
    int nb=0;
    for (int i=0; i<col->TL; i++)
    {
        if (col->Tab[i] == x)
        {
            nb ++;
        }
    }
    return nb;
}

int give_val(COLUMN *col, int x)
{
    if (x < col->TL)
    {
        return col->Tab[x];
    }
    else
    {
        printf("Il n'y a aucune valeur a la position %d\n(Out of range)\n", x);
        return 0;
    }
}

int supp_x(COLUMN *col, int x)
{
    int nb=0;
    for (int i=0; i<col->TL; i++)
    {
        if (col->Tab[i] > x)
        {
            nb ++;
        }
    }
    return nb;
}

int inf_x(COLUMN *col, int x)
{
    int nb=0;
    for (int i=0; i<col->TL; i++)
    {
        if (col->Tab[i] < x)
        {
            nb ++;
        }
    }
    return nb;
}
