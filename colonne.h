#ifndef PROJECT_COLONNE_H
#define PROJECT_COLONNE_H

#include <stdio.h>
#include <stdlib.h>

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

typedef struct{
    char *titre;
    unsigned int TP;
    unsigned int TL;
    ENUM_TYPE colonne_type;
    COL_TYPE **data;
    unsigned long long int *index;
}COLUMN;

COLUMN *create_column(ENUM_TYPE type, char* title);
int insert_value(COLUMN* col, void *value);
void delete_column(COLUMN **col);

#endif //PROJECT_COLONNE_H
