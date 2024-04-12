#ifndef FINALPROJECT_LISTE_H
#define FINALPROJECT_LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colonne.h"

/**
* Un maillon d'une liste
*/
typedef struct maillon {
    COLUMN *data;
    struct maillon *prev;
    struct maillon *next;
} MAILLON;
/**
* Une liste
*/
typedef struct list_ {
    MAILLON *head;
    MAILLON *tail;
} list;

/**
* création d'un noeud
*/
MAILLON *lst_create_maillon(void *dat);
/**
* crée la liste et retourne un pointeur sur cette dernière
*/
list *lst_create_list();
/**
* Supprime tous les éléments de la liste lst
*/
void lst_erase(list * lst);
/**
* supprimer la liste
*/
void lst_delete_list(list * lst);
/**
* Insère pnew au début de la liste lst
*/
void lst_insert_head(list * lst, MAILLON * pnew);
/**
* Insère pnew à la fin de la liste lst
*/
void lst_insert_tail(list * lst, MAILLON * pnew);
/**
* Insère l'élément pnew juste après ptr dans la liste lst
*/
void lst_insert_after(list * lst, MAILLON * pnew, MAILLON * ptr);
/**
* Supprime le premier élément de la liste
*/
void lst_delete_head(list * lst);
/**
* Supprime le dernier élément de la liste
*/
void lst_delete_tail(list * lst);
/**
* Supprime le MAILLON pointé par ptr
*/
void lst_delete_MAILLON(list * lst, MAILLON * ptr);
/**
* retourne le premier node s'il existe sinon NULL
*/
MAILLON *get_first_node(list * lst);
/**
* retourne le denier node s'il existe sinon NULL
*/
MAILLON *get_last_node(list * lst);
/**
* retourne le node suivant
*/
MAILLON *get_next_node(list * lst, MAILLON * MAILLON);

#endif //FINALPROJECT_LISTE_H
