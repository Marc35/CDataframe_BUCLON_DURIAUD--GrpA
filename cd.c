#include "cd.h"


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size)
{
    char *titre = malloc(50 * sizeof (char));
    printf("\nRentrez le titre de la première colonne\n");
    scanf(" %s", titre);

    CDATAFRAME *cdf = lst_create_list();

    COLUMN *col = create_column(cdftype[0], titre);
    MAILLON *maille = lst_create_maillon(col);
    lst_insert_head(cdf, maille);

    MAILLON *temp = cdf->head;
    for (int i=1; i < size; i++)
    {
        char *titre_remp = malloc(50 * sizeof (char));
        printf("\nRentrez le titre de la %dème colonne\n", i+1);
        scanf(" %s", titre_remp);

        COLUMN *remp = create_column(cdftype[i], titre_remp);
        maille = lst_create_maillon(remp);
        lst_insert_tail(cdf, maille);

        temp = temp->next;
    }
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf){
    MAILLON* maillon = (*cdf)->head;
    MAILLON * maillon_suivant = maillon->next;
    MAILLON *temp = NULL;
    while(maillon_suivant != NULL){
        temp = maillon_suivant;
        maillon_suivant = maillon_suivant->next;
        delete_column(&(maillon->data));
        lst_delete_MAILLON(*cdf, maillon);
        maillon = temp;
    }
    lst_erase(*cdf);
    *cdf = NULL;
    cdf = NULL;
}
