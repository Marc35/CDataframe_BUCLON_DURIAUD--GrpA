#ifndef FINALPROJECT_CD_H
#define FINALPROJECT_CD_H

#include "liste.h"
#include "colonne.h"
#include "help_functions.h"


typedef list CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);
void delete_column_cdatafram(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
void insert_col_cdataframe(CDATAFRAME *cdf, ENUM_TYPE type, char *titre, int pos_col);
void insert_values_cdataframe(CDATAFRAME *cdf, char *titre);
void print_cdataframe(CDATAFRAME*cdf, int col_deb, int col_fin, int ligne_deb, int ligne_fin);
void print_name_col_cdataframe(CDATAFRAME *cdf, int col_deb, int col_fin);
void rename_col(CDATAFRAME *cdf, char *titre);

#endif //FINALPROJECT_CD_H
