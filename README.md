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
        - Description : Permet de retourner le nombre d'occurences d'une valeur de n'importe quelle type dans n'importe quelle colonne, donnée dans l'appel de la fonction.
          Le paramètre is_str sert pour d'autre fonctions internes utilisant cette fonction. 
        - Paramètre : 
        1. Pointeur sur la colonne à étudier
        2. Pointeur sur la valeur à rechercher dans la colonne
        3. Donne si la valeur à rechercher est un string. Sert principalement pour d'autres fonctions.
        - Retourne : Rien

    - _scearch_value :_
        - Appellation : scearch_value(*colonne, postion_valeur)
        - Description : Permet d'aller chercher la valeur présente à une position donnée dans la colonne passée en paramètre. La valeur est directement convertie sous forme de str, et la fonction renvoie l'adresse de la valeur convertir
        - Paramètre :
              1. Pointeur de la colonne ou aller chercher une valeur.
              2. Entier positif donnant l'indice de la valeur à aller chercher. 
        - Retourne : Un pointeur sur une donnée de type char. 
          
    - _nb_supp_val :_
        - Appellation : nb_supp_val(*colonne, *valeur_à_comparer, is_str)
        - Description : Fonction retournant le nombre de valeurs suppérieurs à une autre dans une colonne. Compare les valeurs en les convertissant sous forme de str.
        - Paramètre :
          1. Pointeur sur la colonne à étudier.
          2. Pointeur sur la valeur à comparer dans la colonne
          3. Donne si la valeur à rechercher est un string. Sert principalement pour d'autres fonctions.
        - Retourne : Le nombre de valeurs supérieurs à la valeur donnée en paramètre dans la colonne donnée également en paramètre. 

    - _nb_inf_val :_
        - Appellation : nb_inf_val(*colonne, *valeur_à_comparer, is_str)
        - Description : Fonction retournant le nombre de valeurs inféieurs à une autre dans une colonne. Compare les valeurs en les convertissant sous forme de str.
        - Paramètre :
          1. Pointeur sur la colonne à étudier.
          2. Pointeur sur la valeur à comparer dans la colonne
          3. Donne si la valeur à rechercher est un string. Sert principalement pour d'autres fonctions.
        - Retourne : Le nombre de valeurs inféieurs à la valeur donnée en paramètre dans la colonne donnée également en paramètre.
     
    - _suppr_val_col :_
        - Appellation : suppr_val_col(*colonne, position)
        - Description : Permet de suprimer une valeur dans une colonne avec son indice (ré-allout l'espace et diminue la colonne d'1)
        - Paramètre :
          1. Pointeur sur la colonne sur laquelle supprimer une valeur
          2. Indice de la valeur à supprimer
        - Retourne : Retourne 1 si la valeurs à bien réussie à être supprimé, 0 sinon (si l'indice ne possède pas de valeur)

2. ### **Fonctions de tri des colonnes**
    - _Fonctionalité n°1 :_
        - Appellation : NonImportant()
        - Description : Permet de lister tous les mots non importants soit les mots dont le TFIDF est de 0
        - Paramètre : Rien
        - Retourne : Une liste des mots non importants




     
# Implémentation du CDataFrame
1. ### **Fonctions liées au CDataFrame**

   -> Pour implémenter les fonctions du CDataFrame, nous avons utilisé toutes les fonction déclarés dans liste.h, et données dans la consigne du projet. 

    - _create_cdataframe :_
        - Appellation : create_cdataframe(ENUM_TYPE type, nb_colonnes)
        - Description : Retourne un pointeur sur un CDataFrame personnalisé par l'utilisateur (nb de colonne, position, noms des colonnes, types et valeurs ...)
        - Paramètre :
          1. Type stocké dans les premières colonnes créés dans le CDataFrame
          2. Nombre de colonne à créer pour initialiser le CDataFrame, basé sur le type demande ci-dessus
        - Retourne : Un pointeur sur le CDataFrame créé par l'utilisateur.
          
    - _insert_col_cdataframe :_
        - Appellation : insert_col_cdataframe(*CDataFrame, ENUM_TYPE type, *titre, position_colonne)
        - Description : Permet de créer et insérer une colonne dans un CDataFrame à un indice donné
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel ajouter une colonne
          2. Type des valeurs à stocker dans la nouvelle colonne créée
          3. Titre de la nouvelle colonne à ajouter dans le CDataFrame
          4. Position dans le CDataFrame auquelle ajouter la nouvelle colonne 
        - Retourne : Rien

      - _delete_cdataframe :_
        - Appellation : delete_cdataframe(** CDataFrame)
        - Description : Permet de supprimer un CDataframe, tout en le désalouant intégralement ( colonne par colonne, maillon par maillon...)
        - Paramètre :
          1. Double pointeur du CDataFrame à supprimer
        - Retourne : Rien
       
      - _delete_column_cdatafram :_
        - Appellation : delete_column_cdatafram(*CDataFrame , *char(nom de la colonne) )
        - Description : Permet de supprimer une colonne dans un CDataFrame avec son nom
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Pointeur de type char sur le nom de la colonne à supprimer
        - Retourne : Rien  ( ou affiche 'La colonne n'a pas été trouvé' si aucun nom ne corespondait aux colonnes dans le CDF )
       
      - _get_cdataframe_cols_size :_
        - Appellation : get_cdataframe_cols_size(*CDataFrame)
        - Description : Permet de connaitre le nombre de colonne présentes dans un CDataFrame
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
        - Retourne : Un entier, nombre de colonnes présentes dans le CDataFrame passé en paramètre
          
      - _get_cdataframe_nb_lignes :_
        - Appellation : get_cdataframe_nb_lignes(*CDataFrame )
        - Description : Permet de connaitre le nombre de ligne présentes dans un CDataFrame ( nombre de ligne de la colonne la plus remplis )
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
        - Retourne : Un entier, nombre de ligne du CDataFrame passé en paramètre
       
      - _insert_values_cdataframe :_
        - Appellation : insert_values_cdataframe(*CDataFrame, *titre le la colonne)
        - Description : Permet d'insérer tout type de valeur dans un CDataFrame, dans la colonne spécifié par l'utilisateur. Si le nom de la colonne n'existe pas, la fonction en créée une nouvelle. De plus l'utilisateur peux choisir le la position ou insérer la valeur dans la colonne ( pos '-1' pour l'insérer à la fin ).
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel ajouter une valeur
          2. Pointeur sur le nom de la colonne auquelle l'utilisateur veut ajouter une valeur
        - Retourne : Rien
       
      - _print_cdataframe :_
        - Appellation : print_cdataframe(*CDataFrame, colonne_début, colonne_fin, ligne_début, int ligne_fin)
        - Description : Permet d'afficher un CDataFrame sur un interval de colonnes et de ligne donné par l'utilisateur
        - Paramètre :
          1. Pointeur sur le CDataFrame à afficher
          2. Entier spécifiant la colonne à partir de laquelle commencer l'affichage
          3. Entier spécifiant la colonne à laquelle terminer l'affichage
          4. Entier spécifiant la ligne à partir de laquelle commencer l'affichage
          5. Entier spécifiant la ligne à laquelle terminer l'affichage
        - Retourne : Rien

      - _print_name_col_cdataframe :_
        - Appellation : print_name_col_cdataframe(* CDataFrame, colonne_début, colonne_fin)
        - Description : Permet d'afficher tous les noms de colonnes sur un interval donné par l'utilisateur
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Entier spécifiant l'indice de la colonne à partir duquel commencer l'affichage des noms des colonnes
          3. Entier spécifiant l'indice de la colonne à laquelle terminer l'affichage des noms de colonnes
        - Retourne : Rien

      - _rename_col :_
        - Appellation : rename_col(* CDataFrame, *titre de la colonne)
        - Description : Permet de renomer une colonne dans un CDataFrame
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel renomer une colonne
          2. Pointeur sur le nom de la colonne à aller chercher pour être renommée
        - Retourne : Rien
       
      - _insert_ligne_cdataframe :_
        - Appellation : insert_ligne_cdataframe(* CDataFrame)
        - Description : Permet de créer et insérer une ligne dans un CDataFrame à un indice donné. La ligne peut-être ensuite remplie par l'utilisateur colonne par colonne. Si l'indice donnée est plus grand que le nombre de lignes déja présentes, la fonction l'insère à la fin.
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel ajouter une ligne
        - Retourne : Rien

      - _nb_occu_value_CD :_
        - Appellation : nb_occu_value_CD(* CDataFrame, *valeur à rechercher)
        - Description : Permet de chercher le nombre d'occurence d'une valeur dans un CDataFrame, toute ligne et colonne confondues
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Pointeur sur la valeur (de n'importe quel type) à recherche dans le CDataFrame
        - Retourne : Entier donnant le nombre d'occurence de la valeur passée en paramètre

      - _acces_value_CDataFrame :_
        - Appellation : acces_value_CDataFrame(* CDataFrame, position_colonne, position_ligne)
        - Description : Permet d'aller remplacer une valeur aux indices donnés par l'utilisateur dans un CDataFrame
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel remplacer une valeur
          2. Entier spécifiant la colonne de la valeur à remplacer
          3. Entier spécifiant la ligne de la valeur à remplacer
        - Retourne : Rien
       
      - _nb_sup_value_CD :_
        - Appellation : nb_sup_value_CD(*CDataFrame, *valeur à comparer)
        - Description : Permet de donner le nombre de valeur supérieur à une valeur de n'importe quel type spécifié en paramètre dans un CDataFrame, spécifié également en paramètre
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Pointeur (de n'importe quel type) sur la valeur à comparer
        - Retourne : Entier spécifiant le nombre de valeurs, supérieur à celle entrée en paramètre, trouvées dans le CDataFrame
       
      - _nb_inf_value_CD :_
        - Appellation : nb_inf_value_CD(*CDataFrame, *valeur à comparer)
        - Description : Permet de donner le nombre de valeur inférieur à une valeur de n'importe quel type spécifié en paramètre dans un CDataFrame, spécifié également en paramètre
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Pointeur (de n'importe quel type) sur la valeur à comparer
        - Retourne : Entier spécifiant le nombre de valeurs, inférieur à celle entrée en paramètre, trouvées dans le CDataFrame
       
      - _suppr_ligne_CD :_
        - Appellation : suppr_ligne_CD(*CDataFrame, position_ligne)
        - Description : Permet de supprimer une ligne de valeur au CDataFrame à l'indice voulus
        - Paramètre :
          1. Pointeur sur le CDataFrame auquel supprimer une ligne
          2. Entier spécifiant l'indice de la ligne à supprimer
        - Retourne : Le nombre de valeur supprimées

      - _nb_sup_value_CD :_
        - Appellation : nb_sup_value_CD(*CDataFrame, *valeur à comparer)
        - Description : Permet de donner le nombre de valeur supérieur à une valeur de n'importe quel type spécifié en paramètre dans un CDataFrame, spécifié également en paramètre
        - Paramètre :
          1. Pointeur sur le CDataFrame à étudier
          2. Pointeur (de n'importe quel type) sur la valeur à comparer
        - Retourne : Entier spécifiant le nombre de valeurs, supérieur à celle entrée en paramètre, trouvées dans le CDataFrame   

      
# CDataFrame et fichiers
1. ### **Fonction liées à l'enregistrement/exportation dans des fichiers (.CVS)**

      - _load_from_csv :_
        - Appellation : load_from_csv(*nom_fichier_CDataFrame, ENUM_TYPE *dftype, taille_CDataFrame)
        - Description : Permet d'upload un CDataFrame à partir d'un fichier CSV
        - Paramètre :
          1. Pointeur (char) sur le nom du fichier à partir duquel upload le CDF
          2. Pointeur (ENUM_TYPE) sur le type de valeur auquelles composer le CDataFrame
          3. Entier spécifiant la taille (en colonne) maximum du CDataFrame
        - Retourne : Pointeur sur le CDataFrame upload à partir du fichier donné en paramètre
       
      - _save_into_csv :_
        - Appellation : save_into_csv(*CDataFrame, *nom_fichier)
        - Description : Permet de sauvegarder un CDataFrame dans un fichier CSV dont le nom est donné en paramètre
        - Paramètre :
          1. Pointeur sur le CDataFrame à sauvegarder dans un fichier CSV
          2. Pointeur (char) sur le nom du fichier à utiliser pour sauvegarder le CDataFrame
        (PS: Le fichier utilisé est vidé lors de la sauvegarde, si un CDataFrame était déja sauvegardé celui-ci est écrasé)
        - Retourne : 1 si la sauvegarder c'est bien éffectué, 0 sinon (ouverture du fichier impossible)
       
2. ### **Fonction supplémentaires ('help_functions.c')**

       
      - _choose_type_col :_
        - Appellation : choose_type_col() (PS : fonction destinée pour aérer d'autres fonctions, ne s'appelle pas autrement)
        - Description : Permet à l'utilisateur de choisir un type pour sa colonne (via le type structure ENUM_TYPE)
        - Paramètre :
          Aucun
        - Retourne : Un type ENUM_TYPE donnant le type choisis par l'utilisateur pour sa colonne, son CDataFrame ...
       
      - _viderBuffer :_
        - Appellation : viderBuffer() (PS : fonction destinée pour aérer d'autres fonctions, ne s'appelle pas autrement)
        - Description : Permet de vider le buffer, utile lors de l'utilisation de fonctions liées au CDF
        - Paramètre :
          Aucun
        - Retourne : Rien
          

