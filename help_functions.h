#ifndef CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H
#define CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H

#include "menu.h"

 ENUM_TYPE* choose_type_col(int nb);
int cast_val(ENUM_TYPE type, COL_TYPE **val, char* value);
void viderBuffer();
int compare_any_types(void *a, void *b, ENUM_TYPE type);
void sort_insersion(COLUMN *col);
int partition(COLUMN *col, int g, int d);
void quicksort(COLUMN *col, int g, int d);
void inverse_sort(COLUMN *col);
char *get_title();
int is_comparable(char *value, ENUM_TYPE type);
char* get_str_type(ENUM_TYPE type);
ENUM_TYPE get_type_with_str(char type);

#endif //CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H
