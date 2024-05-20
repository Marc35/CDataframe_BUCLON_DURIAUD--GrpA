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

int get_cdataframe_nb_lignes(CDATAFRAME *cdf)
{
    int max=0;
    MAILLON *temp = cdf->head;
    while (temp != NULL)
    {
        int cpt = temp->data->TL;
        if (cpt > max)
        {
            max = cpt;
        }
        temp = temp->next;
    }
    return max;
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
        ENUM_TYPE *type = NULL;
        type = choose_type_col(1);
        insert_col_cdataframe(cdf, type[0], titre, -1);
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
    int index_pos;
    do
    {
        viderBuffer();
        printf("Pressez Entrée sans renseigner de valeur pour finir l'insertion de valeur\n");
        printf("Quelle valeur voulez-vous ajouter dans la colonne %s ?\n", temp->data->titre);
        fgets(rep, 50, stdin);              // On demande a l'utilisateur de rentrer sa valeur qu'on considère toujours comme un str au début
        if(strcmp(rep, "\n") != 0) {
            printf("A quelle position voulez vous insérer votre valeur ? Tapez -1 pour l'insérer a la fin\n");
            scanf(" %d", &index_pos);
            if (strcmp(rep, "NULL") == 0)       // Si il a rentré NULL, il y a pas besoin de convertire cette valeure
            {
                insert_value(col, NULL, index_pos);
            } else    // Sinon on convertie la chaine de caractère rentrée par l'utilisateur dans le type de la colone à laquelle il rajoute une valeur
            {
                if (cast_val(col->colonne_type, val, rep) == 1)
                    if (insert_value(col, val[0], index_pos))
                        printf("Insertion réussi !\n");
                    else
                        printf("L'insertion à échouee\n");
                else
                    printf("Valeur impossible à insérer veuillez rentrer une valeur valide\n");
            }
        }

    }while (strcmp(rep, "\n") != 0);   // On teste pour voir si l'utilisateur rentre un espace pour finir l'insertion
}

void print_cdataframe(CDATAFRAME*cdf, int col_deb, int col_fin, int ligne_deb, int ligne_fin)
{
    if (col_fin <= -1)
        col_fin = get_cdataframe_cols_size(cdf);
    if (ligne_fin <= -1)
        ligne_fin = get_cdataframe_nb_lignes(cdf);
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

void printf_cdf_by_index(CDATAFRAME*cdf, int col_deb, int col_fin)
{
    if (col_fin <= -1)
        col_fin = get_cdataframe_cols_size(cdf);

    MAILLON *cpt = cdf->head;
    for (int k=0; k < col_fin; k++)
    {
        sort(cpt->data, 0);
        cpt = cpt->next;
    }

    for (int i=0; i< get_cdataframe_nb_lignes(cdf); i++)
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
                if (i >= temp->data->TL) {
                    str = " ";
                    printf("[%s][%lld] %s\t\t", temp->data->titre, i, str);
                }
                else {
                    str = scearch_value(temp->data, temp->data->index[i]);
                    printf("[%s][%lld] %s\t\t", temp->data->titre, temp->data->index[i], str);
                }
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
    if (col_fin <= -1)
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

void insert_ligne_cdataframe(CDATAFRAME *cdf)
{
    MAILLON *temp = cdf->head;
    int pos_lig;
    printf("A quelle position voulez vous insérer cette nouvelle ligne ?\n");
    scanf(" %d", &pos_lig);
    char rep[50];

    COL_TYPE **val=NULL;

    if (pos_lig >= get_cdataframe_nb_lignes(cdf))
    {
        printf("Il n'y a pas assez de lignes dans le CDataframe, le programme va donc l'insérer à la fin \n");
        pos_lig = -1;
    }
    viderBuffer();
    while (temp != NULL)
    {
        val = malloc(sizeof (COL_TYPE));
        printf("Quelle valeur voulez vous insérer dans la colonne [%s] ?\n", temp->data->titre);
        fgets(rep, 50, stdin);
        if (strcmp(rep, "NULL") == 0)       // Si il a rentré NULL, il y a pas besoin de convertire cette valeur
        {
            insert_value(temp->data, NULL, pos_lig);
        } else    // Sinon on convertie la chaine de caractère rentrée par l'utilisateur dans le type de la colone à laquelle il rajoute une valeur
        {
            if (cast_val(temp->data->colonne_type, val, rep) == 1) {
                insert_value(temp->data, val[0], pos_lig);
            }
            else
                printf("Valeur impossible à insérer veuillez rentrer une valeur valide\n");
        }
        free(val[0]);
        free(val);
        //val[0] = NULL;
        val = NULL;
        temp = temp->next;
    }
}

int nb_occu_value_CD(CDATAFRAME *cdf, char* value){
    MAILLON *temp_maillon = cdf->head;
    COLUMN *temp_col = NULL;
    int nb_occurence = 0;
    while(temp_maillon != NULL) {
        temp_col = temp_maillon->data;
        nb_occurence += nb_occ(temp_col, value, 1);
        temp_maillon = temp_maillon->next;
    }
    return nb_occurence;
}

void acces_value_CDataFrame(CDATAFRAME* cdf, int pos_col, int pos_ligne){
    MAILLON* search_col = cdf->head;
    COLUMN* col_value = NULL;
    if(pos_col > get_cdataframe_cols_size(cdf) || pos_ligne > get_cdataframe_nb_lignes(cdf)){
        printf("\nLa valeur recherché n'existe pas dans le CDataFrame ! \n");
    }
    else
    {
        for(int i = 0; i < pos_col; i++){
            search_col = search_col->next;
        }
        col_value = search_col->data;
        printf("\nLa valeur pointée est %s . \nVoulez-vous la remplacer ? (oui/non)\n", scearch_value(col_value, pos_ligne));
        char user_answer[3];
        scanf(" %s", user_answer);
        if(user_answer[0] == 'o'){
            char* new_value = malloc(100*sizeof(char));
            COL_TYPE **val=NULL;
            val = malloc(sizeof (COL_TYPE));
            do{
                 printf("Quelle est la nouvelle valeur que vous souhaitez entrer ?\n");
                 scanf(" %s", new_value);
            }while(cast_val(col_value->colonne_type, val, new_value) == 0);
            col_value->data[pos_ligne] = val[0];
        }
    }
}

int nb_inf_value_CD(CDATAFRAME *cdf, char* value){
    MAILLON *temp_maillon = cdf->head;
    COLUMN *temp_col = NULL;
    int nb_occurence = 0;
    while(temp_maillon != NULL) {
        temp_col = temp_maillon->data;
        nb_occurence += nb_inf_val(temp_col, value, 1);
        temp_maillon = temp_maillon->next;
    }
    return nb_occurence;
}

int nb_sup_value_CD(CDATAFRAME *cdf, char* value){
    MAILLON *temp_maillon = cdf->head;
    COLUMN *temp_col = NULL;
    int nb_occurence = 0;
    while(temp_maillon != NULL) {
        temp_col = temp_maillon->data;
        nb_occurence += nb_supp_val(temp_col, value, 1);
        temp_maillon = temp_maillon->next;
    }
    return nb_occurence;
}

int suppr_ligne_CD(CDATAFRAME *cdf, int pos)
{
    int cpt=0;
    MAILLON *temp = cdf->head;
    while (temp != NULL)
    {
        if (pos >= get_cdataframe_nb_lignes(cdf))
            return 0;
        else {
            if (suppr_val_col(temp->data, pos))
                cpt++;
            temp = temp->next;
        }
    }
    return cpt;
}

CDATAFRAME* load_from_csv(char *file_name)
{
    char line[1000];
    char *data = NULL;

    FILE *fichier = fopen(file_name, "r");
    if (fichier == NULL)
    {
        printf("Ouverture impossible\n");
        return NULL;
    }

    // Pour le nombre de colonnes
    int size;
    fgets(line, sizeof(line), fichier);
    data = strtok(line,";");
    size = (int)data[0] - 48;   // 48 en ASCII = la position de 0

    // Pour les types
    ENUM_TYPE *types = malloc(size * sizeof (ENUM_TYPE));
    fgets(line, sizeof(line), fichier);
    data = strtok(line,";");
    for (int i=0; i < size; i++)
    {
        types[i] = get_type_with_str(*data);
        data = strtok(NULL, ";");
    }

    CDATAFRAME *cdf = lst_create_list();
    MAILLON *temp=NULL;
    COLUMN *col = NULL;

    // Pour les titres
    fgets(line, sizeof(line), fichier);
    data = strtok(line,";");
    for (int i=0; i < size; i++)
    {
        col = create_column(types[i], data);
        temp = lst_create_maillon(col);
        lst_insert_tail(cdf, temp);
        data = strtok(NULL, ";");
    }

    temp = cdf->head;
    COL_TYPE **val=NULL;
    val = malloc(sizeof (COL_TYPE));

    // Pour les valeurs
    while (fgets(line, sizeof(line), fichier))
    {
        data = strtok(line,";");
        while(temp != NULL) {
            if (strcmp(data, " ") != 0) {
                cast_val(temp->data->colonne_type, val, data);
                insert_value(temp->data, val[0], -1);
            }
            data = strtok(NULL,";");
            temp = temp->next;
        }
        printf("\n");
        temp = cdf->head;
    }
    return cdf;
}

int save_into_csv(CDATAFRAME *cdf, char *file_name)
{
    FILE *fichier = fopen(file_name, "w");
    if (fichier == NULL)
    {
        printf("Ouverture impossible\n");
        return 0;
    }

    MAILLON *temp = cdf->head;
    char str[100];

    // Boucle pour le nombre de colonnes
    char nb_col = '0';
    while (temp != NULL)
    {
        nb_col++;
        temp = temp->next;
    }
    fputc(nb_col, fichier);
    fprintf(fichier, "\n");
    temp = cdf->head;   // On remet temp sur la tete du cdf

    // Boucle pour les types
    while (temp != NULL)
    {
        fputs(get_str_type(temp->data->colonne_type), fichier);
        fputc(';', fichier);
        temp = temp->next;
    }
    fprintf(fichier, "\n");
    temp = cdf->head;   // On remet temp sur la tete du cdf

    // Boucle pour écrire els titres
    while (temp != NULL) {
        fputs(temp->data->titre, fichier);
        fputc(';', fichier);
        temp = temp->next;
    }
    fprintf(fichier, "\n");
    temp = cdf->head;   // On remet temp sur la tete du cdf

    // Boucle pour écrire les valeurs
    for (int i=0; i< get_cdataframe_nb_lignes(cdf); i++)
    {
        while (temp != NULL) {
            if (i < temp->data->TL) {
                convert_value(temp->data, i, str, 100, NULL);
                fputs(str, fichier);
            }
            else
            {
                fputc(' ', fichier);
            }
            fputc(';', fichier);
            temp = temp->next;
        }
        fprintf(fichier, "\n");
        temp = cdf->head;
    }
    fclose(fichier);
    return 1;
}

void sort(COLUMN* col, int sort_dir)
{
    if (col->index != NULL) {
        switch (col->valid_index) {
            case 1:
                break;
            case -1:
                sort_insersion(col);
                break;
            case 0:
                quicksort(col, 0, col->TL - 1);
                break;
        }
        if (sort_dir == 1)
            inverse_sort(col);
        col->valid_index = 1;
    }
}

void print_col_by_index(COLUMN *col)
{
    if (col->index == NULL)
    {
        printf("Cette colonne ne possède pas d'index\n");
        return;
    }
    if (col->valid_index != 1)
        sort(col, 0);
    for (int i=0; i < col->TL; i++)
    {
        char str[50];
        convert_value(col, col->index[i], str, 50, NULL);
        printf("[%d] %s\n", i, str);
    }
}

void erase_index(COLUMN *col)
{
    if (col->index != NULL)
    {
        free(col->index);
        col->index = NULL;
    }
}

int check_index(COLUMN *col)
{
    if (col->index != NULL)
        return 1;
    else
        return 0;
}

int search_value_in_column(COLUMN *col, void *val)
{
    if (check_index(col))
    {
        sort(col, 0);
        int g = 0, d = col->TL - 1, m;
        while(g <= d)
        {
            m = (d + g) / 2;
            if(compare_any_types(col->data[col->index[m]], val, col->colonne_type) == 0)
                return 1;
            if(compare_any_types(col->data[col->index[m]], val, col->colonne_type) == 1) {
                d = m - 1;
            }
            else {
                g = m + 1;
            }
        }
        return 0;
    }
    else
        return 0;
}

int search_value_cdf(CDATAFRAME *cdf, void *val, ENUM_TYPE type)
{
    MAILLON *temp = cdf->head;
    for (int i=0; i < get_cdataframe_cols_size(cdf); i++)
    {
        if (temp->data->colonne_type == type)
        {
            if (search_value_in_column(temp->data, val))
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}


















