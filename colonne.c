#include "colonne.h"
#include <string.h>
COLUMN *create_column(ENUM_TYPE type,char* title)
{
    COLUMN *col = NULL;
    col = (COLUMN*) malloc(sizeof (COLUMN));
    col->titre = title;
    col->TP = 256;
    col->TL = 0;
    col->colonne_type = type;
    col->data = NULL;
    col->index = NULL;
    return col;
}

int insert_value(COLUMN* col, void *value)
{
    if (col->TL == 0)
    {
        col->data = malloc(256 * sizeof (COLUMN));
    }
    if (col->TL == col->TP)
    {
        realloc(col, col->TL + 256);
    }
    switch (col->colonne_type) {
        case UINT:
            col->data[col->TL] = (unsigned int*) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->TL])= *((unsigned int*)value);
            break;
        case INT:
            col->data[col->TL] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->TL])= *((int*)value);
            break;
        case CHAR:
            col->data[col->TL] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->TL])= *((char*)value);
            break;
        case FLOAT:
            col->data[col->TL] = (float *) malloc (sizeof(float ));
            *((float *)col->data[col->TL])= *((float *)value);
            break;
        case DOUBLE:
            col->data[col->TL] = (double *) malloc (sizeof(double ));
            *((double *)col->data[col->TL])= *((double *)value);
            break;
        case STRING:
            col->data[col->TL] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->TL])= *((char*)value);
            break;
            /*
        case STRUCTURE:
            col->data[col->TL] = (void *) malloc (sizeof(void ));
            *((void *)col->data[col->TL])= *((void *)value);
            break;
             */

    }
    col->TL++;
    return 1;
}
