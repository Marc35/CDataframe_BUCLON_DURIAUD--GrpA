#include "help_functions.h"

int cast_val(ENUM_TYPE type, COL_TYPE **val, char* value)
{
    switch (type) {
        case UINT:
            for (int i=0; i< strlen(value); i++)
            {
                if (value[i] >= '0' && value[i] <= '9' || value[i] == '\n')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            val[0] = (unsigned int *) malloc(sizeof(unsigned int));
            *((unsigned int *) val[0]) = strtoul(value, NULL, 10);
            break;
        case INT:
            for (int i=0; i< strlen(value); i++)
            {
                if (value[i] >= '0' && value[i] <= '9' || value[i] == '-' || value[i] == '\n')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            val[0] = (int *) malloc(sizeof(int));
            *((int *) val[0]) = atoi(value);
            break;
        case CHAR:
            val[0] = (char *) malloc(sizeof(char));
            *((char *) val[0]) = *((char *) value);
            break;
        case FLOAT:
            for (int i=0; i< strlen(value); i++)
            {
                if (value[i] >= '0' && value[i] <= '9' || value[i] == '-' || value[i] == '.' || value[i] == '\n')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            val[0] = (float *) malloc(sizeof(float));
            *((float *) val[0]) = atof(value);
            break;
        case DOUBLE:
            for (int i=0; i< strlen(value); i++)
            {
                if (value[i] >= '0' && value[i] <= '9' || value[i] == '-' || value[i] == '.' || value[i] == '\n')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            val[0] = (double *) malloc(sizeof(double));
            *((double *) val[0]) = strtod(value, NULL);
            break;
        case STRING:
            val[0] = (char *) malloc(sizeof(char));
            value[strlen(value) - 1] = '\0';
            strcpy((char *) val[0], (char *) value);
            break;
    }
    return 1;
}

char *get_title() {
    char *titre = malloc(50 * sizeof(char));
    if (titre != NULL) {
        printf("Quel titre voulez vous ?\n");
        scanf(" %s", titre);
        return titre;
    }
    else
        return NULL;
}

ENUM_TYPE* choose_type_col(int nb)
{
    ENUM_TYPE *type = malloc(nb * sizeof (ENUM_TYPE));
    for (int i=0; i < nb; i++) {
        printf("Quel type voulez vous pour votre colonne\n");
        printf("Rentrer :\n 2 : Pour des UNIT\n 3 : Pour des INT\n 4 : Pour des CHAR\n 5 : Pour des FLOAT\n 6 : Pour des DOUBLE\n 7 : Pour des STRING\n Votre choix : ");
        scanf(" %d", &type[i]);
    }
    return type;
}

char* get_str_type(ENUM_TYPE type)
{
    char *type_str = malloc(sizeof (char));
    switch (type) {
        case UINT:
            strcpy(type_str, "2");
            break;
        case INT:
            strcpy(type_str, "3");
            break;
        case CHAR:
            strcpy(type_str, "4");
            break;
        case FLOAT:
            strcpy(type_str, "5");
            break;
        case DOUBLE:
            strcpy(type_str, "6");
            break;
        case STRING:
            strcpy(type_str, "7");
            break;
    }
    return type_str;
}

ENUM_TYPE get_type_with_str(char type)
{
    switch (type) {
        case '2':
            return UINT;
        case '3':
            return INT;
        case '4':
            return CHAR;
        case '5':
            return FLOAT;
        case '6':
            return DOUBLE;
        case '7':
            return STRING;
    }
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int compare_any_types(void *a, void *b, ENUM_TYPE type)
{
    switch (type) {
        case UINT:
            return (*(unsigned int*)a > *(unsigned int*)b) - (*(unsigned int*)a < *(unsigned int*)b);
        case INT:
            return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
        case CHAR:
            return (*(char*)a > *(char*)b) - (*(char*)a < *(char*)b);
        case FLOAT:
            return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
        case DOUBLE:
            return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
        case STRING:
            return strcmp((char*)a, (char*)b);
        default:
            return 0;
    }
}

int is_comparable(char *value, ENUM_TYPE type)
{
    int is_str = 0;
    for (int i=0; i< strlen(value); i++)
    {
        if (value[i] >= '0' && value[i] <= '9' || value[i] == '-' || value[i] == '.' || value[i] == '\n')
        {
            continue;
        }
        else
        {
            is_str = 1;
        }
    }
    if (is_str == 0 && type != CHAR && type != STRING)
        return 1;
    else
        if (is_str == 1 && (type == CHAR || type == STRING))
            return -1;
        else
            return 0;

}

void sort_insersion(COLUMN *col)
{
    if (col->index == NULL)
        return;
    for (int i=1; i < col->TL; i++)
    {
        int k = col->index[i];
        int j = i-1;
        while (j >= 0 && compare_any_types(col->data[col->index[j]], col->data[k], col->colonne_type) == 1)
        {
            col->index[j+1] = col->index[j];
            j--;
        }
        col->index[j+1] = k;
    }
}

int partition(COLUMN *col, int g, int d)
{
    int pivot = col->index[d];
    int i = g - 1;
    for (int j = g; j < d; j++)
    {
        if (compare_any_types(col->data[col->index[j]], col->data[pivot], col->colonne_type) != 1)
        {
            i++;
            int s = col->index[i];
            col->index[i] = col->index[j];
            col->index[j] = s;
        }
    }
    int s = col->index[i + 1];
    col->index[i + 1] = col->index[d];
    col->index[d] = s;
    return i + 1;
}

void quicksort(COLUMN *col, int g, int d)
{
    if (col->index == NULL)
        return;
    if (g < d)
    {
        int pi = partition(col, g, d);
        quicksort(col, g, pi - 1);
        quicksort(col, pi + 1, d);
    }
}

void inverse_sort(COLUMN *col)
{
    if (col->index == NULL)
        return;
    int deb = 0;
    int fin = col->TL - 1;
    int temp;
    while(deb < fin)
    {
        temp = col->index[deb];
        col->index[deb] = col->index[fin];
        col->index[fin] = temp;
        deb++;
        fin--;
    }
}
