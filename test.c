#include "colonne.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * 1 - create column
 * 2 - Insert value in column
 * 3 - Delete column
 * 0 - Test for all functions
 */

 int execute ()
 {
  int choice = 0;
  char* title = (char*) malloc(50 * sizeof(char));
  int new_value;
  COLUMN * test = NULL;
  while (choice != 4) {
      printf("Quelle fonction voulez vous tester ? \n => Entrez '1' pour creer une colonne \n => Entrez '2' pour inserer une valeur dans la colonne precedemment creee \n => Entrez '3' pour supprimer la colonne precedement creee \n => Entrez '4' pour sortir du testeur \n\n Valeur entree  :  ");
      scanf("%d", &choice);
      char c2 = getchar();

      switch (choice) {
          case 1:
              printf("\nEntrez le nom de la colonne que vous voulez creer : ");
              gets(title);
              test = create_column(INT, "ceciestunnomdecolonne");
              printf("\nLa colonne a bien ete creee  ! ");
              break;
          case 2:
              printf("\nEntrez la valeur que vous souhaitez ajouter a la colonne precedemment creee \n Valeur a ajouter : ");
              scanf("%d", &new_value);
              insert_value(test, &new_value);
              printf("La valeur a bien ete ajoutee ! \n\n");
              break;

          case 3:
              printf("\nLa colonne precedemment creee va etre supprimee !");
              printf("\n \n Etat du pointeur de la colonne : %p\n\n", test);
              delete_column(&test);
              break;
          case 0:
              break;
          case 4:
              printf("Aurevoir !");
              break;
          default:
              printf("Entree incomprise.");
              break;
         }
    }
    return 0;

}