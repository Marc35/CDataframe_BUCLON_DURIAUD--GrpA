#include "cd.h"


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size)
{
    CDATAFRAME *cdf = lst_create_list();

    for (int i=0; i < size; i++)
    {
        char *titre = malloc(50 * sizeof (char));
        printf("\nRentrez le titre de la %dème colonne\n", i+1);
        scanf(" %s", titre);

        insert_col_cdataframe(cdf, cdftype[i], titre, i);
    }
    return cdf;
}

void insert_col_cdataframe(CDATAFRAME *cdf, ENUM_TYPE type, char *titre, int pos_col)
{
    COLUMN *col = create_column(type, titre);
    MAILLON *maille = lst_create_maillon(col);
    if (cdf->head == NULL || pos_col == 0)
    {
        lst_insert_head(cdf, maille);
    }
    else
    {
        if (pos_col == -1)
            lst_insert_tail(cdf, maille);
        else
        {
            int j=0;
            MAILLON *temp = cdf->head;
            for (j; j < pos_col-1; j++)
            {
                if (temp != NULL)
                    temp = temp->next;
                else
                {
                    printf("Il n'y a pas assez de colones dans le CDataframe pour inserer cette colone ou vous le souhaiter. Le programme va donc l'insérer a la fin\n");
                    lst_insert_tail(cdf, maille);
                    return;
                }
            }
            lst_insert_after(cdf, maille, temp);
        }
    }
}

void delete_cdataframe(CDATAFRAME **cdf){
    if ((*cdf)->head == NULL)
    {
        lst_erase(*cdf);
        *cdf = NULL;
        return;
    }
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
}

void delete_column_cdatafram(CDATAFRAME *cdf, char *col_name){
    MAILLON *temp = cdf->head;
    while (temp->next != NULL && strcmp(temp->data->titre, col_name) != 0)
    {
        temp = temp->next;
    }
    if (temp->next == NULL && strcmp(temp->data->titre, col_name) != 0)
    {
        printf("La colonne [%s] n'a pas été trouvée\n", col_name);
    }
    else
    {
        delete_column(&(temp->data));
        lst_delete_MAILLON(cdf, temp);
    }
}

int get_cdataframe_cols_size(CDATAFRAME *cdf)
{
    int cpt=0;
    MAILLON *temp = cdf->head;
    while (temp->next != NULL)
    {

        temp = temp->next;
        cpt++;
    }
    cpt++;
    return cpt;
}

void insert_values_cdataframe(CDATAFRAME *cdf, char *titre)
{
    MAILLON *temp = cdf->head;
    COLUMN* col = NULL;
    // Pour trouver la bonne colone à modifier
    while (strcmp(titre, temp->data->titre)!=0 && temp->next != NULL)
    {
        temp = temp->next;
    }
    // Si on a pas trouver la colone on en crée une nouvelle
    if (strcmp(titre, temp->data->titre)!=0)
    {
        printf("Colonne non trouvé, le programme va donc en créer une du meme nom\n");
        ENUM_TYPE type;
        type = choose_type_col();
        insert_col_cdataframe(cdf, type, titre, -1);
        col = cdf->tail->data;
    }
    // Sinon on met col sur la colonne voulue
    else
    {
        col = temp->data;
    }


    COL_TYPE **val=NULL;
    val = malloc(sizeof (COL_TYPE));

    char rep[50];
    viderBuffer();      // Pour vider le buffer sinon fgets ne marchera pas correctement
    do
    {
        printf("Pressez Entré sans renseigner de valeur pour finir l'insertion de valeur\n");
        printf("Quelle valeur voulez-vous ajouter ?\n");
        fgets(rep, 50, stdin);              // On demande a l'utilisateur de rentrer sa valeur qu'on considère toujours comme un str au début
        if(strcmp(rep, "\n") != 0) {
            if (strcmp(rep, "NULL") == 0)       // Si il a rentré NULL, il y a pas besoin de convertire cette valeure
            {
                insert_value(col, NULL);
            } else    // Sinon on convertie la chaine de caractère rentrée par l'utilisateur dans le type de la colone à laquelle il rajoute une valeur
            {
                if (cast_val(col, val, rep) == 1)
                    insert_value(col, val[0]);
                else
                    printf("Valeur impossible à insérer veuillez rentrer une valeur valide\n");
            }
        }

    }while (strcmp(rep, "\n") != 0);   // On teste pour voir si l'utilisateur rentre un espace pour finir l'insertion
}

void print_cdataframe(CDATAFRAME*cdf, int col_deb, int col_fin, int ligne_deb, int ligne_fin)
{
    if (col_fin == -1)
        col_fin = get_cdataframe_cols_size(cdf);
    for (int i=ligne_deb; i<ligne_fin; i++)
    {
        int j = 0;
        MAILLON *temp = cdf->head;
        for(j; j < col_deb; j++)
        {
            if (temp->next != NULL)
                temp = temp->next;
            else {
                printf("Il n'a pas assez de colonne dans le CDataframe\n");
                return;
            }
        }

        for (j; j<col_fin; j++)
        {
            if (temp->next != NULL || j == col_fin-1)
            {
                char *str;
                str = scearch_value(temp->data, i);
                if (strcmp(str, "Il n'y a pas de valeur à cet emplacement\n") == 0)
                    str = " ";
                printf("[%s][%d] %s\t\t", temp->data->titre, i, str);
                temp = temp->next;
            }
            else
            {
                printf("Il n'y a plus assez de colonnes dans le CDataframe\n");
                break;
            }
        }
        printf("\n");
    }
}

void print_name_col_cdataframe(CDATAFRAME *cdf, int col_deb, int col_fin)
{
    if (col_fin == -1)
        col_fin = get_cdataframe_cols_size(cdf);

    int j = 0;
    MAILLON *temp = cdf->head;
    for(j; j < col_deb; j++)
    {
        if (temp->next != NULL)
            temp = temp->next;
        else {
            printf("Il n'a pas assez de colonne dans le CDataframe\n");
            return;
        }
    }

    for (j; j<col_fin; j++)
    {
        if (temp->next != NULL || j == col_fin-1)
        {
            printf("[%d] %s\n", j, temp->data->titre);
            temp = temp->next;
        }
        else
        {
            printf("Il n'y a plus assez de colonnes dans le CDataframe\n");
            break;
        }
    }
}

void rename_col(CDATAFRAME *cdf, char *titre)
{
    MAILLON *temp = cdf->head;
    while (temp != NULL)
    {
        if (strcmp(titre, temp->data->titre) == 0)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp != NULL)
    {
        char *str = malloc(50 * sizeof (char));
        printf("Quel nouveau titre voulez-vous pour cette colone ?\n");
        scanf(" %s", str);
        temp->data->titre = str;
    }
    else
    {
        printf("Il n'y a pas de colone à ce nom dans le CDataframe\n");
    }
}
