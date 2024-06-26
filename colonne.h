#ifndef FINALPROJECT_COLONNE_H
#define FINALPROJECT_COLONNE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prog_test();

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
    int valid_index;
    int sort_dir;
}COLUMN;


COLUMN *create_column(ENUM_TYPE type,char* title);
int insert_value(COLUMN* col, void *value, int ind_pos);
void delete_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size, void *val);
void print_col(COLUMN* col);
int nb_occ(COLUMN *col, void *x, int is_str);
char* scearch_value(COLUMN *col, int pos_value);
int nb_supp_val(COLUMN *col, void *x, int is_str);
int nb_inf_val(COLUMN *col, void *x, int is_str);
int suppr_val_col(COLUMN *col, int pos);

#endif //FINALPROJECT_COLONNE_H
