# Présentation du projet :
    Création d'un CDataframe sous forme de liste doublement chainées contenant des colonnes dans chaque maillons.
    Ce CDataframe peut contenir des colonnes de tous les types possibles avec comme contrainte un seul type par colonne.
    On a également implementé des fonctions avancées permettant la manipulation des colonnes.

# Execution et liens:
 - Lancer le fichier main.c et suivez les instructions
 - Lien vers le projet : https://github.com/Marc35/CDataframe_BUCLON_DURIAUD--GrpA

# Fonctions liées aux colonnes :
1. ### **Création et affichage de colonnes**
    - _create_column :_
        - Appellation : create_column(ENUM_TYPE type, *titre)
        - Description : Permet de créer une colonne, tout en configurant les valeurs qu'elles contriendra ainsi que son titre.
        - Paramètre :
            1. Type ENUM_TYPE contenant le type de valeur qui seront contenues dans la colonne (int, char, double ... )
            2. Un pointeur de type char pointant sur le titre à associer à la colonne créée
        - Retourne : Un pointeur sur la colonne créée par la fonction avec les attribus voulus
          
    - _insert_value :_
        - Appellation : insert_value(*colonne, *valeur, position)
        - Description : Permet d'ajouter une valeur donné en paramètre à une colonne donnée en paramètre, et ceci à l'indice voulu également donné en paramètre 
        - Paramètre :
            1. Le pointeur sur la colonne dont on veut ajouter une valeur
            2. Un pointeur de type void pointant la valeur à ajouter dans la colonne
            3. L'indice auquel on veut ajouter la valeur dans la colonne. Mettre '-1' permet d'ajouter la valeur directement à la fin
        - Retourne : Rien
   
    - _delete_column :_
        - Appellation : delete_column(**colonne)
        - Description : Permet de supprimer une colonne en libérant toute la mémoire prise par celle-ci
        - Paramètre :
              1. Un double pointeur sur la colonne à supprimer et sur l'espace à libérer 
        - Retourne : Rien

    - _convert_value :_
        - Appellation : convert_value(*colonne, entier_positif, *variable_à_remplir, taille_max, *valeur_à_convertir)
        - Description : Permet de convertir en une chaine de caractère n'importe quelle donnée de n'importe quelle type (pratique pour l'affichage de colonne). La donnée à convertir peut-être donnée soit dans une colonne à un indice donnée soit directement avec le pointeur *valeur_à_convertir
        - Paramètre :
             1. Pointeur sur la colonne dont récupérer la valeur à convertir. Si ce pointeur vaut NULL, la fonction convertis la donnée donnée en paramètre 5
             2. Indice positif de la valeur à récupérer dans la colonne et à convertir en str.
             3. Pointeur sur la variable de type char ou la valeur à convertir va se retrouver.
             4. Taille maximum que peut prendre la valeur à convertir. (en fonction de la place alloué à la variable précédente)
             5. Pointeur sur n'importe quelle valeur qui est convertie si le premier pramètre vaut NULL 
        - Retourne : Rien

    - _print_col :_
        - Appellation : print_col(*colonne)
        - Description : Permet d'afficher l'entièreté des valeurs d'une colonne, avec les indices des valeurs et le nom de la colonne
        - Paramètre :
              1. Pointeur sur la colonne à afficher 
        - Retourne : Rien

    - _nb_occ :_
        - Appellation : nb_occ(*colonne, *valeur_à_rechercher, is_str)
        - Description : Permet
        - Paramètre : une chaine de caractère contenant un chemin d'accès vers dossier source et un un chemin d'accès vers un dossier final
        - Retourne : Rien

    - _scearch_value :_
        - Appellation : scearch_value(*colonne, postion_valeur)
        - Description : Permet d'aller chercher la valeur présente à une position donnée dans la colonne passée en paramètre. La valeur est directement convertie sous forme de str, et la fonction renvoie l'adresse de la valeur convertir
        - Paramètre :
              1. Pointeur de la colonne ou aller chercher une valeur.
              2. Entier positif donnant l'indice de la valeur à aller chercher. 
        - Retourne : Un pointeur sur une donnée de type char. 
          
    - _supp_SpeCara :_
        - Appellation : suppr_SpeCara() PS : normalement on ne l'appel pas car elle est juste une composante d'une autre fonction
        - Description : Permet d'enlever les caractères spéciaux d'un texte comme (', é, è, ù, ...) avec un traitement particulier pour l'apostrophe par l'appel de la fonction apostrophe(). La fonction va réécrire les fichiers qu'elle étudie sans les caractères spéciaux. ATTENTION : la fonction prendra toujours les fichiers du dossier cleaned
        - Paramètre : Rien
        - Retourne : Rien, elle va réécrire les fichiers sans les caractères spéciaux


2. ### **Fonctions de tri des colonnes**
    - _Fonctionalité n°1 :_
        - Appellation : NonImportant()
        - Description : Permet de lister tous les mots non importants soit les mots dont le TFIDF est de 0
        - Paramètre : Rien
        - Retourne : Une liste des mots non importants

    - _Fonctionalité n°2 :_
        - Appellation : highest_tfidf(directory)
        - Description : Permet de donner le mots qui a le TFIDF le plus élever de tous les mots de tous les documents contenu dans le dossier passé en paramètre
        - Paramètre : une chaine de caractère contenant un chemin d'accès vers le dossier souhaité PS : établi par défaud sur le dossier cleaned
        - Retourne : Le mot avec le TFIDF le plus élevé


     
# Implémentation du CDataFrame
1. ### **Fonctions liées au CDataFrame**
    - _tokenisation :_
        - Appellation : tokenisation(text)
        - Description : Minimize le texte passé en paramètre et enlève de celui-ci tout les caractères spéciaux
        - Paramètre : STR: une chaîne de caractères contenant une phrase
        - Retourne : list: une liste contenant chaque mot du texte sans accent, ni majuscules, ni ponctuation
          
    - _regr :_
        - Appellation : regr(l, sep)
        - Description : Change une liste de mot en une chaine de caractères
        - Paramètre : List: une liste contenant des chaines de caractères
                    : STR: Une chaîne de caractère qui ne contiendra un caractère qui fera office de séparateur
        - Retourne : STR: une chaîne de caractères qui contiendra tout les mots de la liste avec entre chacun un caractère donné
          

      
# CDataFrame et fichiers
1. ### **Fonction liées à l'enregistrement/exportation dans des fichiers (.CVS)**
