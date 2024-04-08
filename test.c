#include "colonne.h"

/**
 * 1 - create column
 * 2 - Insert value in column
 * 3 - Delete column
 * 4 - Convertir une valeur d'une colonne en string
 * 5 - Afficher les valeurs d'une colonne
 * 0 - Test for all functions
 */

void prog_test()
{
    //int check;
    int choice=-1;
    char* title = (char*) malloc(50 * sizeof(char));
    int new_value=0;
    printf("Hello word 2");
    COLUMN * test = NULL;
    while (choice != 0) {
        printf("\n\nQuelle fonction voulez vous tester ? \n => Entrez '1' pour creer une colonne \n => Entrez '2' pour inserer une valeur dans la colonne precedemment creee \n => Entrez '3' pour supprimer la colonne precedement creee \n => Entrez '4' pour convertir une valeur d'une colonne en string \n => Entrez '5' pour afficher les valeurs d'une colonne \n => Entrez '0' pour sortie du programme de test \n\n Valeur entree  :  ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Au revoir !");
                break;
            case 1:
                printf("\nEntrez le nom de la colonne que vous voulez creer : ");
                scanf(" %s", title);
                test = create_column(INT, title);
                printf("\nLa colonne a bien ete creee  ! \n");
                break;
            case 2:
                if (test == NULL)
                {
                    printf("Vous n'avez créer de colonne le programme va donc en créer une\n");
                    test = create_column(INT, "colonne de remplacement");
                }
                printf("\nEntrez la valeur que vous souhaitez ajouter a la colonne precedemment creee \n Valeur a ajouter : ");
                scanf("%d", &new_value);
                insert_value(test, &new_value);
                printf("La valeur a bien ete ajoutee ! \n\n");
                break;
            case 3:
                if (test == NULL)
                {
                    printf("Vous n'avez créer de colonne le programme va donc en créer une avant de lma supprimer");
                    test = create_column(INT, "colonne de remplacement");
                }
                printf("\nLa colonne precedemment creee va etre supprimee !");
                printf("\n \n Etat du pointeur de la colonne : %p\n\n", test);
                delete_column(&test);
                test = NULL;
                break;
            case 4:
                if(test == NULL){
                    printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                    test = create_column(INT, "colonne de remplacement");
                    insert_value(test, &new_value);
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
                    test = create_column(INT, "colonne de remplacement");
                    insert_value(test, &new_value);
                }
                printf("\nAffichage de la colonne :\n");
                print_col(test);
                break;
            case 6:
                if(test == NULL){
                    printf("Vous n'avez créer de colonne le programme va donc en créer une avant de la rechercher");
                    test = create_column(INT, "colonne de remplacement");
                    insert_value(test, &new_value);
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
                    test = create_column(INT, "colonne de remplacement");
                    insert_value(test, &new_value);
                }
                int pos=-1;
                printf("Quelle valeur voulez vous rechercher ??\n");
                printf("La colonne contient %d valeurs\n", test->TL);
                scanf(" %d", &pos);
                printf("La valeur a la position %d est %s\n", pos, scearch_value(test, pos));
                break;
            default:
                printf("Entrée incomprise !");
                break;
        }
    }
}
