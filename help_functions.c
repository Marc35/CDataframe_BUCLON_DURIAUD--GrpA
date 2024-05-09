#include "help_functions.h"

int cast_val(COLUMN *col, COL_TYPE **val, char* value)
{
    switch (col->colonne_type) {
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
                if (value[i] >= '0' && value[i] <= '9' || value[i] == '-' || value[i] == '\n')
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

ENUM_TYPE choose_type_col()
{
    ENUM_TYPE type;
    printf("Quel type voulez vous pour votre colonne\n");
    printf("Rentrer :\n 2 : Pour des UNIT\n 3 : Pour des INT\n 4 : Pour des CHAR\n 5 : Pour des FLOAT\n 6 : Pour des DOUBLE\n 7 : Pour des STRING\n Votre choix : ");
    scanf(" %d", &type);
    return type;
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
