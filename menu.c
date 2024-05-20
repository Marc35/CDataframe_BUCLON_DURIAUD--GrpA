#include "menu.h"

void menu()
{
    // Pour le choix num 0
    int choix_0 = -1;

    // 1er boucle de choix
    while (choix_0 != 0)
    {
        // Pour le choix num 0
        printf("1 : Operer uniquement sur des colonnes\n2 : Operer sur un CDataframe\n");
        scanf(" %d", &choix_0);
        switch (choix_0) {
            case 1: {
                // déclaration d'une colonne et de son titre
                COLUMN *col = NULL;
                char *titre = NULL;
                // Pour le choix num 1
                int choix_1 = -1;

                // 2eme boucle de choix
                while (choix_1 != 0)
                {
                    // Pour le choix num 1
                    printf("Que voulez vous faire ?\n");
                    printf("\n\nQuelle fonction voulez vous tester ? \n => Entrez '1' pour creer une colonne \n => Entrez '2' pour inserer une ou plusieurs valeurs dans la colonne precedemment creee \n => Entrez '3' pour supprimer la colonne precedement creee \n => Entrez '4' pour connaitre la valeur a un indice donne dans la colonne \n => Entrez '5' pour afficher les valeurs d'une colonne \n => Entrez '6' pour afficher le nombre d'occurence d'une valeur dans une colonne \n => Entrez '7' pour afficher le nombre de valeur au dessus d'une valeur donnee dans une colonne \n => Entrez '8' pour afficher le nombre de valeur en dessous d'une valeur donnee dans une colonne \n => Entrez '0' pour retourner au menu principal \n\n Valeur entree  :  \n");
                    scanf(" %d", &choix_1);
                    switch (choix_1) {
                        // créer une colonne
                        case 1: {
                            if (col == NULL) {
                                titre = get_title();
                                if (titre != NULL)
                                    col = create_column(choose_type_col(1)[0], titre);
                                else
                                    printf("Vous n'avez pas rentre de titre valide\n");
                            }
                            else {
                                char rep[3];
                                printf("Vous avez deja cree une colonne voulez-vous vraiment la remplacer ? (oui/non)\n");
                                scanf(" %s", rep);
                                if (rep[0] == 'o') {
                                    delete_column(&col);
                                    titre = get_title();
                                    if (titre != NULL)
                                        col = create_column(choose_type_col(1)[0], titre);
                                    else
                                        printf("Vous n'avez pas rentre de titre valide\n");
                                } else
                                    printf("vous avez garder votre ancienne colonne\n");
                            }
                            if (col == NULL)
                                printf("La colonne n'a pas pu etre creer veuilez reessayer\n");
                            else
                                printf("La colonne a etee cree avec succes\n");
                            break;
                        }

                        // Ajouter une valeur dans une colonne
                        case 2: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else
                            {
                                int position;               // Position d'insertion
                                char val_utilisateur[100];  // Valeur rentrée par l'utilisateur en str
                                COL_TYPE **val=NULL;        // Permet de stoker la valeur après convertion
                                val = malloc(sizeof (COL_TYPE));
                                do {
                                    // Choix de la valeur
                                    printf("Quelle valeur voulez vous inserer ? (pressez entree sans mettre de valeur pour terminer l'insertion)\n");
                                    viderBuffer();      // Pour pas qu'il y ai de problème avec le fgets
                                    fgets(val_utilisateur, 100, stdin);
                                    // Insertion de la valeur
                                    if (strcmp(val_utilisateur, "\n") != 0) {
                                        // Choix de la position
                                        printf("A quelle position voulez-vous ajouter votre valeur ? (tapez -1 pour l'inserer par defaut a la fin)\n");
                                        scanf(" %d", &position);
                                        if (strcmp(val_utilisateur, "NULL") == 0)       // Si il a rentré NULL, il y a pas besoin de convertire cette valeure
                                        {
                                            insert_value(col, NULL, position);
                                        } else    // Sinon on convertie la chaine de caractère rentrée par l'utilisateur dans le type de la colone à laquelle il rajoute une valeur
                                        {
                                            if (cast_val(col->colonne_type, val, val_utilisateur) == 1) {
                                                if (insert_value(col, val[0], position))
                                                    printf("Valeur inseree avec succes\n");
                                            }
                                            else
                                                printf("Valeur impossible a inserer veuillez rentrer une valeur valide\n");
                                        }
                                    }
                                } while (strcmp(val_utilisateur, "\n") != 0);
                            }
                            break;
                        }

                        // Supprimer une colonne
                        case 3: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else
                            {
                                delete_column(&col);
                                printf("La colonne a ete supprimee\n");
                            }

                            break;
                        }

                        // Convertir une valeur d'une colonne en str et l'afficher
                        case 4: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else
                            {
                                int index_value;
                                char valeur_convertie[100];
                                do {
                                    printf("Quelle est la position a laquelle vous souhaiter connaitre la valeur ?\n");
                                    printf("Il y a actuellement %d valeurs dans la colonne. L'indice de la première valeur est 0\n", col->TL);
                                    scanf(" %d", &index_value);
                                }while (index_value >= col->TL);
                                convert_value(col, index_value, valeur_convertie, 100, NULL);
                                printf("La valeur a l'indice %d est %s\n", index_value, valeur_convertie);
                            }
                            break;
                        }

                        // Afficher une colonne de manière trié ou non
                        case 5: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else
                            {
                                char rep_tri[3];
                                printf("Voulez vous afficher la colonne de manière triee ?(oui/non)\n");
                                scanf(" %s", rep_tri);
                                if (rep_tri[0] == 'o')
                                    print_col_by_index(col);
                                else
                                    print_col(col);
                            }
                            break;
                        }

                        // Connaitre le nombre d'occurences d'une valeur donnée
                        case 6: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            char rep_val_recherche[100];
                            printf("De quelle valeur voulez vous connaitre le nombres d'occurences ?\n");
                            scanf(" %s", rep_val_recherche);
                            nb_occ(col, rep_val_recherche, 1);
                            break;
                        }

                        // Connaitre le nb d'occurences de valeur au dessus
                        case 7: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else {
                                char val_dessus[50];
                                int nb_val_dessus;
                                printf("De quelle valeur souhaitez vous connaitre le nombre de valeurs existantes au dessus ?\n");
                                scanf(" %s", val_dessus);
                                nb_val_dessus = nb_supp_val(col, val_dessus, 1);
                                printf("Il y a %d valeurs au dessus de %s dans la colonne\n", nb_val_dessus,
                                       val_dessus);
                            }
                            break;
                        }

                        // Connaitre le nb d'occurences de valeurs au dessous
                        case 8: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else {
                                char val_dessous[50];
                                int nb_val_dessous;
                                printf("De quelle valeur souhaitez vous connaitre le nombre de valeurs existantes en dessous ?\n");
                                scanf(" %s", val_dessous);
                                nb_val_dessous = nb_inf_val(col, val_dessous, 1);
                                printf("Il y a %d valeurs en dessous de %s dans la colonne\n", nb_val_dessous, val_dessous);
                            }
                            break;
                        }

                        // Suprimer une valeur dans une colonne
                        case 9: {
                            if (col == NULL) {
                                printf("Vous n'avez pas cree de colonne precedemment. Veuillez en creer une avant d'executer cette action\n");
                            }
                            else
                            {
                                int indice_pos_suppr;
                                printf("Quel est l'indice de la colonne que vous souhaitez supprimer ?\n");
                                scanf(" %d", &indice_pos_suppr);
                                if (suppr_val_col(col, indice_pos_suppr) == 0)
                                    printf("Il n'y a pas de valeur a cet indice\n");
                                else
                                    printf("Suppression effectuee\n");
                            }
                            break;
                        }

                        default:
                            break;
                    }
                    printf("Pressez entrée pour continuer\n");
                    viderBuffer();
                    getchar();
                }

                break;
            }


            case 2: {
                // déclaration d'un CDataframe
                CDATAFRAME *cdf = NULL;

                // Pour le choix num 1
                int choix_2 = -1;

                // 2eme boucle de choix
                while (choix_2 != 0)
                {
                    printf("Que voulez vous faire ?\n\n");
                    printf("\n\n => Entrez '1' pour creer un CDataframe \n => Entrez '2' pour insérer une colonne dans le CDataframe \n => Entrez '3' pour ajouter des valeurs à une colonne à partir de son titre \n => Entrez '3' pour supprimer une colonne d'un CDataframe \n => Entrez '4' pour connaitre le nombre de colonnes d'un CDataframe \n => Entrez '5' pour afficher tout ou une partie du CDataFrame \n => Entrez '6' pour supprimer un CDataframe  \n => Entrez '7' pour changer le titre d'une colonne\n => Entrez '8' pour afficher les titre des colonnes du CDataFrame \n => Entrez '9' pour connaitre le nombre de ligne d'un CDataframe  \n => Entrez '10' pour insérer une ligne au CDataframe  \n => Entrez '11' pour savoir si une valeur est présente dans le CDataframe \n => Entrez '12' pour accéder/remplacer une valeur à des indices donnés \n => Entrez '13' pour connaitre le nombre d'occurence d'une valeur donnee dans le CDataFrame \n => Entrez '14' pour connaitre le nombre de valeurs suppérieures a une valeur donnee dans le CDataFrame \n => Entrez '15' pour connaitre le nombre de valeurs inférieures a une valeur donnee dans le CDataFrame \n => Entrez '16' pour sauvegarder le CDataframe dans un fichier csv \n => Entrez '17' pour resituer un CDataframe a partir d'un fichier csv \n => Entrez '18' pour affichier les colonnes du CDataframe triees \n => Entrez '0' pour retourner au menu principal \n\n Valeur entree  :  \n");
                    scanf(" %d", &choix_2);

                    switch (choix_2) {
                        // Creation d'un CDataframe
                        case 1: {
                            if (cdf == NULL)
                            {
                                int nb_col;
                                printf("Combien de colonne voulez vous pour votre CDataframe ?\n");
                                scanf(" %d", &nb_col);
                                cdf = create_cdataframe(choose_type_col(nb_col), nb_col);
                                if (cdf == NULL)
                                    printf("La création a echouee\n");
                                else
                                    printf("Le CDataframe a ete cree avec succees\n");
                            }
                            else
                            {
                                char rep_remplacement[3];
                                printf("Vous avez déja un CDataframe. Voulez vous vraiment le remplacer ? (oui/non)\n");
                                scanf(" %s", rep_remplacement);
                                if (rep_remplacement[0] == 'o')
                                {
                                    delete_cdataframe(&cdf);
                                    int nb_col;
                                    printf("Combien de colonne voulez vous pour votre CDataframe ?\n");
                                    scanf(" %d", &nb_col);
                                    cdf = create_cdataframe(choose_type_col(nb_col), nb_col);
                                    if (cdf == NULL)
                                        printf("La création a echouee\n");
                                    else
                                        printf("Le CDataframe a ete cree avec succees\n");
                                }
                            }
                            break;
                        }

                        // Ajouter une colonne au CDataframe
                        case 2: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int pos_col_inseree_cdf;
                                char titre_col_inseree[50];
                                printf("Quel titre voulez vous pour votre nouvelle colonne ?\n");
                                scanf(" %s", titre_col_inseree);
                                ENUM_TYPE type = choose_type_col(1)[0];
                                printf("A quelle position dans le CDataframe voulez vous inserer votre colonne ?\n (La première colonne est a la position 0 et vous pouvez taper -1 pour l'inserer directement a la fin du cdf)\n");
                                scanf(" %d", &pos_col_inseree_cdf);
                                insert_col_cdataframe(cdf, type, titre_col_inseree, pos_col_inseree_cdf);
                            }
                            break;
                        }

                        // Ajouter des valeurs dans une colonne du CDataframe
                        case 3: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char titre_col_cdf[50];
                                printf("Quelle est le titre de la colonne dont vous souhaiter ajouter des valeurs ? (appuiez 2 fois sur entrée)\n");
                                viderBuffer();
                                scanf(" %s", titre_col_cdf);
                                insert_values_cdataframe(cdf, titre_col_cdf);
                            }
                            break;
                        }

                        // Connaitre le nombre de colonne d'un CDataframe
                        case 4: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int nb_col_cdf = get_cdataframe_cols_size(cdf);
                                printf("Il y a %d colonnes dans le CDataframe\n", nb_col_cdf);
                            }
                            break;
                        }

                        // Afficher le CDataframe
                        case 5: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int col_deb_affichage, col_fin_affichage, ligne_deb_affichage, ligne_fin_affichage;
                                printf("A partir de quelle colonne souhaitez vous afficher le CDataframe ? (1er colonne a la position 0)\n");
                                scanf(" %d", &col_deb_affichage);
                                printf("Jusqu'a quelle colonne voulez vous afficher le CDataframe ? (Pour aller jusqu'a la fin tapez -1)\n");
                                scanf(" %d", &col_fin_affichage);
                                printf("A partir de quelle ligne souhaitez vous afficher le CDataframe ? (1er ligne a la position 0)\n");
                                scanf(" %d", &ligne_deb_affichage);
                                printf("Jusqu'a quelle ligne voulez vous afficher le CDataframe ? (Pour aller jusqu'a la fin tapez -1)\n");
                                scanf(" %d", &ligne_fin_affichage);
                                print_cdataframe(cdf, col_deb_affichage, col_fin_affichage, ligne_deb_affichage, ligne_fin_affichage);
                            }
                            break;
                        }

                        // Supprimer un cdf
                        case 6: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                delete_cdataframe(&cdf);
                                if (cdf == NULL)
                                    printf("La suppression a ete correctement effectuee\n");
                                else
                                    printf("La suppression a echouee\n");
                            }
                            break;
                        }

                        // Changer le titre d'une colonne
                        case 7: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char titre_col_to_rename[50];
                                printf("Quel est le titre de la colonne que vous souhaitez renomer ?\n");
                                scanf(" %s", titre_col_to_rename);
                                rename_col(cdf, titre_col_to_rename);
                            }
                            break;
                        }

                        // Afficher que les titres des colonnes d'un cdf
                        case 8: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int col_deb_affichage, col_fin_affichage;
                                printf("A partir de quelle colonne souhaitez vous afficher les titres ? (1er colonne a la position 0)\n");
                                scanf(" %d", &col_deb_affichage);
                                printf("Jusqu'a quelle colonne voulez vous afficher les titres ? (Pour aller jusqu'a la fin tapez -1)\n");
                                scanf(" %d", &col_fin_affichage);
                                print_name_col_cdataframe(cdf, col_deb_affichage, col_fin_affichage);
                            }
                            break;
                        }

                        // Connaitre le nombre de lignes d'un cdf
                        case 9: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int nb_lignes_cdf = get_cdataframe_nb_lignes(cdf);
                                printf("Il y a %d lignes dans le CDataframe\n", nb_lignes_cdf);
                            }
                            break;
                        }

                        // Rajouter une ligne de valeur au cdf
                        case 10: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                insert_ligne_cdataframe(cdf);
                            }
                            break;
                        }

                        // Savoir si une valeur est présente dans le cdf
                        case 11: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int dico;
                                printf("Voulez verifier l'existence d'une valeur quelque soit sont type (par exemple 5 et '5' serons considerees comme la meme valeur) ou voulez vous verifier son existence uniquement dans son type avec une recherche dichotomique ? (0/1)\n");
                                scanf(" %d", &dico);
                                if (dico == 0) {
                                    char valeur_presente[50];
                                    int valeur_est_presente;
                                    printf("De quelle valeur voulez vous tester l'existence ?\n");
                                    scanf(" %s", valeur_presente);
                                    valeur_est_presente = nb_occu_value_CD(cdf, valeur_presente);
                                    if (valeur_est_presente > 0)
                                        printf("La valeur est présente dans le CDataframe\n");
                                    else
                                        printf("La valeur n'est pas présente dans le Cdataframe\n");
                                }
                                else
                                {
                                    COL_TYPE **val=NULL;
                                    val = malloc(sizeof (COL_TYPE));
                                    char valeur_presente[50];
                                    ENUM_TYPE type_val;
                                    printf("De quelle valeur voulez vous tester l'existence ?\n");
                                    scanf(" %s", valeur_presente);
                                    printf("De quel type est votre valeur ? \n");
                                    printf("Rentrer :\n 2 : Pour des UNIT\n 3 : Pour des INT\n 4 : Pour des CHAR\n 5 : Pour des FLOAT\n 6 : Pour des DOUBLE\n 7 : Pour des STRING\n Votre choix : ");
                                    scanf(" %d", &type_val);
                                    cast_val(type_val, val, valeur_presente);
                                    if (search_value_cdf(cdf, val[0], type_val))
                                        printf("La valeur est présente dans le CDataframe\n");
                                    else
                                        printf("La valeur n'est pas présente dans le Cdataframe\n");
                                }
                            }
                            break;
                        }

                        // Remplacer une valeur du cdf avec des indices donnés
                        case 12: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int indice_col, indice_ligne;
                                printf("Quel est l'indice de la colonne ou se trouve la valeur a remplacer ? (1er colonne a la position 0)\n");
                                scanf(" %d", &indice_col);
                                printf("Quel est l'indice de la ligne ou se trouve la valeur a remplacer ? (1er ligne a la position 0)\n");
                                scanf(" %d", &indice_ligne);
                                acces_value_CDataFrame(cdf, indice_col, indice_ligne);
                            }
                            break;
                        }

                        // Nombre d'occurences d'une valeur
                        case 13: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char valeur_occurence[50];
                                int valeur_nb_occurences;
                                printf("De quelle valeur voulez vous connaitre le nombre d'occurences ?\n");
                                scanf(" %s", valeur_occurence);
                                valeur_nb_occurences = nb_occu_value_CD(cdf, valeur_occurence);
                                printf("Il y a %d occurences de la valeur %s dans le CDataframe\n", valeur_nb_occurences, valeur_occurence);
                            }
                            break;
                        }

                        // Nombres de valeurs suppérieures
                        case 14: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char valeur_pour_supp[50];
                                int nb_val_supp;
                                printf("De quelle valeur souhaitez vous connaitre le nombre de valeurs supperieures dans le CDataframe ?\n");
                                scanf(" %s", valeur_pour_supp);
                                nb_val_supp = nb_sup_value_CD(cdf, valeur_pour_supp);
                                printf("Il y a %d valeurs supperieures a %s dans le CDataframe\n", nb_val_supp, valeur_pour_supp);
                            }
                            break;
                        }

                        // Nombres de valeurs inférieures
                        case 15: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char valeur_pour_inf[50];
                                int nb_val_inf;
                                printf("De quelle valeur souhaitez vous connaitre le nombre de valeurs supperieures dans le CDataframe ?\n");
                                scanf(" %s", valeur_pour_inf);
                                nb_val_inf = nb_inf_value_CD(cdf, valeur_pour_inf);
                                printf("Il y a %d valeurs supperieures a %s dans le CDataframe\n", nb_val_inf, valeur_pour_inf);
                            }
                            break;
                        }

                        // Sauvegarder un cdf dans un fichier csv
                        case 16: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                char titre_fichier_csv[50];
                                printf("Quel titre voulez vous pour votre fichier csv ? (ne pas oublier de mettre .csv a la fin)\n");
                                scanf(" %s", titre_fichier_csv);
                                if (save_into_csv(cdf, titre_fichier_csv))
                                    printf("La sauvegarde c'est correctement effectuee\n");
                                else
                                    printf("Sauveragde impossible\n");
                            }
                            break;
                        }

                        // Restitution d'un cdf a partir d'un csv
                        case 17: {
                            if (cdf != NULL)
                            {
                                char rep_remplacer_cdf_load[3];
                                printf("Vous avez déja un CDataframe voulez vous vraiment le remplacer ? (oui/non)\n");
                                scanf(" %s", rep_remplacer_cdf_load);
                                if (rep_remplacer_cdf_load[0] == 'o')
                                {
                                    char titre_fichier_load[50];
                                    printf("Quel est le titre du fichier a charger ? (ne pas oublier de mettre .csv a la fin)\n");
                                    scanf(" %s", titre_fichier_load);
                                    cdf = load_from_csv(titre_fichier_load);
                                }
                                else
                                    printf("Le CDataframe n'a pas été remplacer\n");
                            }
                            else
                            {
                                char titre_fichier_load[50];
                                printf("Quel est le titre du fichier a charger ? (ne pas oublier de mettre .csv a la fin)\n");
                                scanf(" %s", titre_fichier_load);
                                cdf = load_from_csv(titre_fichier_load);
                            }
                            break;
                        }

                        // Pour afficher toutes colonnes de manière triées
                        case 18: {
                            if (cdf == NULL)
                            {
                                printf("Vous n'avez pas creer de CDataframe. Veuillez en creer un avant d'effectuer cette action\n");
                            }
                            else
                            {
                                int col_deb, col_fin;
                                printf("A partir de quelle colonne souhaitez vous afficher le CDataframe ? (1er colonne a la position 0)\n");
                                scanf(" %d", &col_deb);
                                printf("Jusqu'a quelle colonne voulez vous afficher le CDataframe ? (Pour aller jusqu'a la fin tapez -1)\n");
                                scanf(" %d", &col_fin);
                                printf_cdf_by_index(cdf, col_deb, col_fin);
                            }
                            break;
                        }

                        default:
                            printf("Veuillez rentrer une valeur valide\n");

                    }
                    printf("Pressez entrée pour continuer\n");
                    setvbuf(stdin, NULL, _IONBF, 0);
                    getchar();
                }

                break;
            }
            case 0:
                printf("Aurevoir !\n");
                break;

        }
    }

}
