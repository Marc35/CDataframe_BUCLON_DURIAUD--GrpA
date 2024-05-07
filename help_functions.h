#ifndef CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H
#define CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H

#include "colonne.h"

ENUM_TYPE choose_type_col();
int cast_val(COLUMN *col, COL_TYPE **val, char* value);
void viderBuffer();

#endif //CDATAFRAME_BUCLON_DURIAUD__GRPA_MAIN_HELP_FUNCTIONS_H
