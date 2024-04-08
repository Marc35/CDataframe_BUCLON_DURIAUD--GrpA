#include "colonne.h"

COLUMN *create_column(ENUM_TYPE type,char* title)
{
    COLUMN *col = NULL;
    col = (COLUMN*) malloc(sizeof (COLUMN));
    if (col != NULL)
    {
        col->titre = title;
        col->TP = 256;
        col->TL = 0;
        col->colonne_type = type;
        col->data = NULL;
        col->index = NULL;
    }
    return col;
}

int insert_value(COLUMN* col, void *value)
{
    if (col->TL == 0)
    {
        col->data = malloc(256 * sizeof (COLUMN));
        if (col->data == NULL)
        {
            return 0;
        }
    }
    if (col->TL == col->TP)
    {
        COL_TYPE **temp;
        temp = realloc(col->data, col->TL + 256);
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            col->data = temp;
        }
    }
    if (value == NULL)
    {
        col->data[col->TL] = NULL;
    }
    else
    {
        switch (col->colonne_type) {
            case UINT:
                col->data[col->TL] = (unsigned int *) malloc(sizeof(unsigned int));
                *((unsigned int *) col->data[col->TL]) = *((unsigned int *) value);
                break;
            case INT:
                col->data[col->TL] = (int *) malloc(sizeof(int));
                *((int *) col->data[col->TL]) = *((int *) value);
                break;
            case CHAR:
                col->data[col->TL] = (char *) malloc(sizeof(char));
                *((char *) col->data[col->TL]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->TL] = (float *) malloc(sizeof(float));
                *((float *) col->data[col->TL]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->TL] = (double *) malloc(sizeof(double));
                *((double *) col->data[col->TL]) = *((double *) value);
                break;
            case STRING:
                col->data[col->TL] = (char *) malloc(sizeof(char));
                strcpy((char *) col->data[col->TL], (char *) value);
                break;
            /*
        case STRUCTURE:
            col->data[col->TL] = (void *) malloc (sizeof(void ));
            *((void *)col->data[col->TL])= *((void *)value);
            break;
             */
        }
    }
    col->TL++;
    return 1;
}

void delete_column(COLUMN **col)
{
    for (int i=0; i < (*col)->TL; i++)
    {
        free((*col)->data[i]);
    }
    free((*col)->data);
    (*col)->data = NULL;
    (*col)->titre = NULL;
    (*col)->index = NULL;
    free(*col);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size, void *val)
/**
* @brief: Convert a value into a string
* @param1: Pointer to the column
* @param2: Position of the value in the data array
* @param3: The string in which the value will be written
* @param4: Maximum size of the string
*/
{
    void *to_find;
    if (val == NULL)
        to_find = col->data[i];
    else
    {
        to_find = val;
    }
    if (col->data[i] == NULL)
    {
        strcpy(str, "NULL");
    }
    else
    {
        switch (col->colonne_type) {

            case UINT:
                snprintf(str, size, "%d", *((unsigned int*)to_find));
                break;

            case INT:
                snprintf(str, size, "%d", *((int*)to_find));
                break;

            case CHAR:
                snprintf(str, size, "%c", *((char*)to_find));
                break;

            case FLOAT:
                snprintf(str, size, "%f", *((float *)to_find));
                break;

            case DOUBLE:
                snprintf(str, size, "%lf", *((double *)to_find));
                break;

            case STRING:
                strcpy(str, (char *) to_find);
                break;
        }
    }
}

void print_col(COLUMN* col)
{
    for(int i=0; i<col->TL; i++)
    {
        char str[5];
        convert_value(col, i, str, 5, NULL);
        printf("[%d] %s\n", i, str);
    }
}

int nb_occ(COLUMN *col, void *x)
{
    int nb=0;
    char str[5];
    char val[5];
    convert_value(col, 0, val, 5, x);
    for (int i=0; i<col->TL; i++)
    {
        convert_value(col, i, str, 5, NULL);
        if (strcmp(val, str) == 0)
        {
            nb++;
        }
    }
    return nb;
}

char* scearch_value(COLUMN *col, int pos_value)
{
    char *str = malloc(25 * sizeof (char));

    if (pos_value < col->TL)
    {
        convert_value(col, pos_value, str, 75, NULL);
        return str;
    }
    else
    {
        //strcpy(str, erreur);
        return "impossible a trouver car la colonne comporte moins de valeurs";
    }
}
