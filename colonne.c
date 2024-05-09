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

int insert_value(COLUMN* col, void *value, int ind_pos)
{
    if (ind_pos <= -1 || ind_pos > col->TL)
    {
        ind_pos = col->TL;
    }
    if (col->TL == 0)
    {
        col->data = malloc(256 * sizeof (COL_TYPE));
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
                for (int i=col->TL; i>ind_pos; i--)
                {
                    *((unsigned int *) col->data[i]) = *((unsigned int *) col->data[i-1]);
                }
                *((unsigned int *) col->data[ind_pos]) = *((unsigned int *) value);
                break;
            case INT:
                col->data[col->TL] = (int *) malloc(sizeof(int));
                for (int i=col->TL; i>ind_pos; i--)
                {
                    *((int *) col->data[i]) = *((int *) col->data[i-1]);
                }
                *((int *) col->data[ind_pos]) = *((int *) value);
                break;
            case CHAR:
                col->data[col->TL] = (char *) malloc(sizeof(char));
                for (int i=col->TL; i>ind_pos; i--)
                {
                    *((char *) col->data[i]) = *((char *) col->data[i-1]);
                }
                *((char *) col->data[ind_pos]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->TL] = (float *) malloc(sizeof(float));
                for (int i=col->TL; i>ind_pos; i--)
                {
                    *((float *) col->data[i]) = *((float *) col->data[i-1]);
                }
                printf("test0\n");
                *((float *) col->data[ind_pos]) = *((float *) value);
                printf("test1\n");
                break;
            case DOUBLE:
                col->data[col->TL] = (double *) malloc(sizeof(double));
                for (int i=col->TL; i>ind_pos; i--)
                {
                    *((double *) col->data[i]) = *((double *) col->data[i-1]);
                }
                *((double *) col->data[ind_pos]) = *((double *) value);
                break;
            case STRING:
                col->data[col->TL] = (char *) malloc(sizeof(char));
                for (int i=col->TL; i>ind_pos; i--)
                {
                    strcpy((char *) col->data[i], (char *) col->data[i-1]);
                }
                strcpy((char *) col->data[ind_pos], (char *) value);
                break;
        }
    }
    col->TL++;
    return 1;
}

void delete_column(COLUMN **col)
{
    if ((*col)->data != NULL)
    {
        for (int i=0; i < (*col)->TL; i++)
        {
            free((*col)->data[i]);
        }
    }
    free((*col)->data);
    (*col)->data = NULL;
    (*col)->titre = NULL;
    (*col)->index = NULL;
    free(*col);
    *col = NULL;
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
    {
        to_find = col->data[i];
    }
    else
    {
        to_find = val;
    }
    if (to_find == NULL)
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
        char str[50];
        convert_value(col, i, str, 5, NULL);
        printf("[%d] %s\n", i, str);
    }
}

int nb_occ(COLUMN *col, void *x, int is_str)
{
    int nb=0;
    char str[5];
    char val[5];
    if (is_str == 0)
        convert_value(col, 0, val, 5, x);
    else
        strcpy(val, x);
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
        return "Il n'y a pas de valeur à cet emplacement\n";
    }
}

int nb_supp_val(COLUMN *col, void *x, int is_str)
{
    int nb=0;
    char str[5];
    char val[5];
    if (is_str == 0)
        convert_value(col, 0, val, 5, x);
    else
        strcpy(val, x);
    for (int i=0; i<col->TL; i++)
    {
        convert_value(col, i, str, 5, NULL);
        if (strcmp(str, val) > 0)
        {
            nb++;
        }
    }
    return nb;
}

int nb_inf_val(COLUMN *col, void *x, int is_str)
{
    int nb=0;
    char str[5];
    char val[5];
    if (is_str == 0)
        convert_value(col, 0, val, 5, x);
    else
        strcpy(val, x);
    for (int i=0; i<col->TL; i++)
    {
        convert_value(col, i, str, 5, NULL);
        if (strcmp(str, val) < 0)
        {
            nb++;
        }
    }
    return nb;
}

int suppr_val_col(COLUMN *col, int pos)
{
    if (pos >= col->TL)
    {
        return 0;
    }
    else
    {
        for (int i=pos; i < col->TL-1; i++)
        {
            if (col->colonne_type == STRING)
                strcpy(col->data[i], col->data[i+1]);
            else
                *col->data[i] = *col->data[i+1];
        }
        free(col->data[col->TL-1]);
        col->TL--;
        return 1;
    }
}

