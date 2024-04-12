#ifndef FINALPROJECT_CD_H
#define FINALPROJECT_CD_H

#include "liste.h"
#include "colonne.h"

typedef list CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);


#endif //FINALPROJECT_CD_H
