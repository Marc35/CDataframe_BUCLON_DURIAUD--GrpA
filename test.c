#include "colonne.h"
#include "cd.h"

/**
 * 1 - Creer une colonne
 * 2 - Insérer une valeur dans une colonne
 * 3 - Supprimer une colonne
 * 4 - Convertir une valeur d'une colonne en string
 * 5 - Afficher les valeurs d'une colonne
 * 6 - Connaitre le nombres d'occurences d'une valeur donnée dans la conlonne
 * 7 - Connaitre la valeur rangé a un indice donné dans une colonne
 * 8 - Donne le nombre de valeur au dessus d'un numéro de valeur donné par l'utilisateur
 * 9 - Donne le nombre de valeur en dessous d'un numéro de valeur donné par l'utilisateur
 * 10 - Permet de créer (initialiser) un CDataFrame
 * 11 - Permet de supprimer un CDataFrame
 * 12 - Supprime la colonne d'un CDataFrame. L'utilisateur donne le nom de la colonne à supprimer
 * 13 - Permet de connaitre le nombre de colonne d'un CDataFrame
 * 0 - Sortie du programme de test
 */

void prog_test()
{
    //int check;g
    int choice=-1, choice_1 = -1, choice_2 = -2;
    char* title = (char*) malloc(50 * sizeof(char));
    char new_value[50];
    printf("Hello word 2");
    COLUMN * test = NULL;
    CDATAFRAME * test_cdf = NULL;
    ENUM_TYPE cdfType[] = {INT, FLOAT, CHAR, STRING};
    while (choice != 0) {
        printf("\n\nDans quelle catégorie de fonction voulez vous aller ? \n => Entrez '1' pour accéder aux fonctions en rapport aux colonnes\n => Entrez '2' pour les fonction en rapport au CDataFrame\n => Entrez '0' pour sortir du programme de test \n\n Valeur entree  :  \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while(choice_1 !=0){
                    printf("\n\nQuelle fonction voulez vous tester ? \n => Entrez '1' pour creer une colonne \n => Entrez '2' pour inserer une valeur dans la colonne precedemment creee \n => Entrez '3' pour supprimer la colonne precedement creee \n => Entrez '4' pour convertir une valeur d'une colonne en string \n => Entrez '5' pour afficher les valeurs d'une colonne \n => Entrez '6' pour afficher le nombre d'occurence d'une valeur dans une colonne \n => Entrez '7' pour connaitre la valeur a un indice donné dans la colonne \n => Entrez '8' pour afficher le nombre de valeur au dessus d'une valeur donnee dans une colonne \n => Entrez '9' pour afficher le nombre de valeur en dessous d'une valeur donnee dans une colonne \n => Entrez '0' pour retourner au menu principal \n\n Valeur entree  :  \n");
                    scanf("%d", &choice_1);
                    switch (choice_1) {
                       case 1:
                           printf("\nEntrez le nom de la colonne que vous voulez creer : ");
                           scanf(" %s", title);
                           test = create_column(STRING, title);
                           printf("\nLa colonne a bien ete creee  ! \n");
                           break;
                       case 2:
                           if (test == NULL)
                           {
                               printf("Vous n'avez créer de colonne le programme va donc en créer une\n");
                               test = create_column(STRING, "colonne de remplacement");
                           }
                           printf("\nEntrez la valeur que vous souhaitez ajouter a la colonne precedemment creee \n Valeur a ajouter : ");
                           scanf(" %s", new_value);
                           insert_value(test, new_value);
                           printf("La valeur a bien ete ajoutee ! \n\n");
                           break;
                       case 3:
                           if (test == NULL)
                           {
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de lma supprimer");
                               test = create_column(STRING, "colonne de remplacement");
                           }
                           printf("\nLa colonne precedemment creee va etre supprimee !");
                           printf("\n \n Etat du pointeur de la colonne : %p\n", test);
                           delete_column(&test);
                           printf("Nouv Etat du pointeur de la col : %p\n\n", test);
                           test = NULL;
                           break;
                       case 4:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           int val_num = 0;
                           do {
                               printf("\nEntrez le numéro de la valeur dans la colonne que vous souhaitez convertire en str : \n");
                               printf("Il y a actuellement %d valeur dans la colonne\n", test->TL);
                               scanf("%d", &val_num);
                           }
                           while(val_num > test->TL);
                           char convert_str[25];
                           convert_value(test, val_num, convert_str, 25, NULL);
                           printf("\nLa valeur à bien été convertie ! C'est : %s\n", convert_str);
                           break;
                       case 5:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           printf("\nAffichage de la colonne :\n");
                           print_col(test);
                           break;
                       case 6:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           int val;
                           printf("Quelle valeur voulez vous rechercher ??\n");
                           scanf(" %d", &val);
                           int occ = nb_occ(test, &val);
                           printf("Il ya %d occurences de la valeur %d dans la colonne\n", occ, val);
                           break;
                       case 7:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           int pos=-1;
                           printf("De quel indice de la colonne boulez vous connaitre la valeur ?\n");
                           printf("La colonne contient %d valeurs\n", test->TL);
                           scanf(" %d", &pos);
                           printf("La valeur a la position %d est %s\n", pos, scearch_value(test, pos));
                           break;
                       case 8:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           printf("A partir de quelle valeur voules-vous rechercher les valeurs suppérieurs ?\n");
                           int nb_vals_supp;
                           scanf(" %d", &nb_vals_supp);
                           int return_supp_val = nb_supp_val(test, &nb_vals_supp);
                           printf("\nIl y  a %d valeur(s) au dessus de la valeur numéro %d\n", return_supp_val, nb_vals_supp);
                           break;
                       case 9:
                           if(test == NULL){
                               printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                               test = create_column(STRING, "colonne de remplacement");
                               insert_value(test, new_value);
                           }
                           printf("A partir de quelle valeur voules-vous rechercher les valeurs inférieures ?\n");
                           int nb_vals_inf;
                           scanf(" %d", &nb_vals_inf);
                           int return_inf_val = nb_inf_val(test, &nb_vals_inf);
                           printf("\nIl y  a %d valeur en dessous de la valeur numéro %d\n", return_inf_val, nb_vals_inf);
                           break;
                       case 0:
                           printf("Retour au menu principal !\n");
                           break;
                       default:
                           printf("Entrée incomprise !\n");
                           break;

                    }

                }
                break;

            case 2:
                while(choice_2 != 0) {
                    printf("\n\n => Entrez '1' pour creer un CDataframe \n => Entrez '2' pour supprimer un CDataframe \n => Entrez '3' pour supprimer une colonne d'un CDataframe \n => Entrez '4' pour connaitre le nombre de colonnes d'un CDataframe \n => Entrez '0' pour retourner au menu principal \n\n Valeur entree  :  \n");
                    scanf("%d", &choice_2);
                    switch (choice_2) {

                        case 1:
                            test_cdf = create_cdataframe(cdfType, 4);
                            break;
                        case 2:
                            if (test_cdf == NULL) {
                                printf("La fonction va créer un CDataframe car vous n'en n'avez pas créé\n");
                                test_cdf = create_cdataframe(cdfType, 4);
                            }
                            delete_cdataframe(&test_cdf);
                            printf("Supprimer avec succés\n");
                            break;
                        case 3:
                            if (test_cdf == NULL) {
                                printf("La fonction va créer un CDataframe car vous n'en avais pas crée\n");
                                test_cdf = create_cdataframe(cdfType, 4);
                            }
                            printf("Quelle est le nom de la colonne que vous souhaiter supprimer ?\n");
                            scanf(" %s", title);
                            delete_column_cdatafram(test_cdf, title);
                            break;
                        case 4:
                            if (test_cdf == NULL) {
                                printf("La fonction va créer un CDataframe car vous n'en avais pas crée\n");
                                test_cdf = create_cdataframe(cdfType, 4);
                            }
                            int nb_col = get_cdataframe_cols_size(test_cdf);
                            printf("Le CDataframe contient actuellement %d colonnes.\n", nb_col);
                            break;
                        case 5:
                            if (test_cdf == NULL) {
                                printf("La fonction va créer un CDataframe car vous n'en avais pas crée\n");
                                test_cdf = create_cdataframe(cdfType, 4);
                            }
                            print_cdataframe(test_cdf, 0, -1, 0, 3);
                            break;
                        case 6:
                            if (test_cdf == NULL) {
                                printf("La fonction va créer un CDataframe car vous n'en avais pas crée\n");
                                test_cdf = create_cdataframe(cdfType, 4);
                            }
                            char titre[100];
                            printf("Donnez le titre de la colonne auquelle vous voulez ajouter la valeur ! \n");
                            scanf(" %s", titre);
                            insert_values_cdataframe(test_cdf, titre);
                            break;
                        case 7:
                            printf("De quelle colone voulez-vous changer le titre ?\n");
                            scanf(" %s", titre);
                            rename_col(test_cdf, titre);
                            break;
                        default:
                            printf("Entrée incomprise !");
                            break;
                        case 0:
                            printf("Retour au menu principal !\n");
                            break;
                    }

                }
                break;
            case 0:
                printf("Aurevoir !\n");
                break;
            default:
                printf("Entrée incomprise !\n");
                break;
        }
    }
}
