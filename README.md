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
        - Appellation : print_col(*colonne, 
        - Description : Permet de réduir toutes les majuscules d'un texte en minuscule 
        - Paramètre : une chaine de charactères
        - Retourne : Rien

    - _lower_files :_
        - Appellation : lower_files(directory, end_directory)
        - Description : Mettre le miniscule les fichiers du dossier se trouvant dans le directory et les range dans le dossier end_directory en appellant directement la fonction minimize_text()
        - Paramètre : une chaine de caractère contenant un chemin d'accès vers dossier source et un un chemin d'accès vers un dossier final
        - Retourne : Rien

    - _apostrophe :_
        - Appellation : apostrophe(lettre, l) PS : normalement on ne l'appel pas car elle est juste une composante d'une autre fonction plus particulèrement de supp_SpeCara()
        - Description : Permet le meilleure remplacement de l'apostrphe
        - Paramètre : une chaine de caractère contenant qu'un seul caratère (la lettre qui précède l'apostrophe) et une variable int qui permet dans certain cas le remplacement de l'apostrophe par un traitement de 1 fois sur 2 c'est tel ou tel caractère qui sera utilisé
        - Retourne : Une autre chaine de charactères conteanant elle aussi un seul caractère qui contient la lettre par laquelle sera remplacé l'apostrophe

    - _supp_SpeCara :_
        - Appellation : suppr_SpeCara() PS : normalement on ne l'appel pas car elle est juste une composante d'une autre fonction
        - Description : Permet d'enlever les caractères spéciaux d'un texte comme (', é, è, ù, ...) avec un traitement particulier pour l'apostrophe par l'appel de la fonction apostrophe(). La fonction va réécrire les fichiers qu'elle étudie sans les caractères spéciaux. ATTENTION : la fonction prendra toujours les fichiers du dossier cleaned
        - Paramètre : Rien
        - Retourne : Rien, elle va réécrire les fichiers sans les caractères spéciaux


3. ### **Les fonctionalités**
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

    - _Fonctionalité n°3 :_
        - Appellation : Plus_mot(president)
        - Description : Permet de connaitre le mot le plus dit par un président dans son discours
        - Paramètre : Une chaine de caractère contenant le nom du président souhaité
        - Retourne : Le mot le plus dit par le président en question

    - _Fonctionalité n°4 :_
        - Appellation : who_said(directory, word)
        - Description : Permet de lister tous les président qui ont prononcer un mot voulu et celui qui l'a prononcer le plus
        - Paramètre : une chaine de caractère contenant un chemin d'accès vers le fichier cible et mot, une chaine de caractère contenant le mot que dont on souhaite connaitre le nom des président l'ayant prononcer dans leurs discours
        - Retourne : Une liste des présidents ayant dit ce mot et celui qui l'a prononcer le plus de fois
     
    - _Fonctionalité n°5 :_
        - Appellation : premier_mot(mot)
        - Description : Permet de connaitre le premier président a parler d'un mot voulu. PS : On entend par le premier celui qui dit le moins de mots avant celui rentré par l'utilisateur
        - Paramètre : mot, une cjaine de caractères contenant le mot dont on veut connaitre le premier président a en avoir parler
        - Retourne : Le ou les noms ddes présidents a avoir dit se mot en premier. PS : "les" car il peut y avoir égalité
     
    - _Fonctionalité n°6 :_
        - Appellation : NonImportant6()
        - Description : Permet de lister tous les mots dit par tous les présidents mais qui ne font pas parti des mots banales tels que "je, tu, le, la, il, ...
        - Paramètre : Rien
        - Retourne : Une liste des mots dit par tous les présidents hors mot banals
     
# Fonction Partie 2
1. ### **Dans fonction de base 2**
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
          
    - _intersection :_
        - Appellation : intersection(text, directory)
        - Description : Analyse tous les mots de la question et ne retient que ceux qui sont également présent dans le corpus de document du dossier passé en paramère
        - Paramètre : STR: une chaîne de caractères qui contiendra le texte de la question
                    : STR: Un chemin d'accès vers le répértoire dont on veut analyser l'intersection
        - Retourne : List: Une liste des mots présent et dans la question et dans le corpus de documents
     
    - _compose_matrice :_
        - Appellation : compose_matrice(matrice)
        - Description : Permet d'inverser la matrice d'un corpus de document
        - Paramètre : List: une liste de liste qui contient la matrice des mots du corpus
        - Retourne : List: La meme liste de liste mais inversée

    - _TFIDF_Qestion :_
        - Appellation : TFIDF_Qestion(text, directory, idf_given=False, key_given=False)
        - Description : Calcule pour caque mot de la question son TFIDF
        - Paramètre : STR: une chaîne de caractères qui contiendra le texte de la question
                    : STR: Un chemin d'accès vers le répértoire nétoyé des fichiers du corpus de doc souhaité
                    : Bool: Permet de fournir à l'avance la matrice idf d'un corpus pour réduire la quantité de calcul
                    : Bool: Permet de fournir à l'avance les clés de cette matrice pour réduire la quantité de calcul
        - Retourne : List: une liste de tout les TFIDF des mots de la question
     
    - _norme :_
        - Appellation : norme(vector)
        - Description : Renvoie la norme d'un vecteur en faisant la somme des crrés de ses valeurs et renvoie la racine carré du tout
        - Paramètre : list: Un vecteur 
        - Retourne : int: La norme de ce vecteur
     
    - _scalaire :_
        - Appellation : scalaire(Va, Vb)
        - Description : Renvoie le produit scalaire de 2 vecteurs de même taille
        - Paramètre : list: Un premier vecteur
                    : list: Un deuxieme vecteur de meme taille
        - Retourne : int: La produit scalaire de ces 2 vecteurs
     
    - _similar :_
        - Appellation : similar(matrice_question, matrice, directory)
        - Description : Renvoie une liste de la similarité d'un vecteur avec une liste d'autres vecteurs / Exemple: La similarité de la question avec les différents documents
        - Paramètre : list: Un 1 er vecteur (La matrice TF-IDF de la question)
                    : list: Une liste de vecteur (La matrice TF-IDF du corpus de texte)
        - Retourne : list: Une liste des similarités entre le 1 er vecteur et chaque vecteur dans la liste de vecteurs
     
    - _doc_pertinent :_
        - Appellation : doc_pertinent(matrice_question, directory)
        - Description : Analyse le corpus de documents et donne le documents ayant la plus grande similarité avec la question de l'utilisateur
        - Paramètre : List: une liste de liste qui contient la matrice de la question
                    : STR: Un chemin d'accès vers le répértoire dont on veut analyser le document le plus pertinant
        - Retourne : STR: Le deuxième caractère d'une liste qui est une chaîne de caractèreset qui contient le nom du fichier le plus pertinant
     
    - _most_impo_q :_
        - Appellation : most_impo_q(text, directory)
        - Description : Analyse la question et donne le mot le plus important
        - Paramètre : STR: une chaîne de caractères qui contiendra le texte de la question
                    : STR: Un chemin d'accès vers le répértoire ou la question est posée
        - Retourne : STR: Le nième caractère d'une liste qui contiendra le mot ayant le tfidf le plus élevé d'une question
     
    - _l_most_impo_q :_
        - Appellation : l_most_impo_q(text, directory)
        - Description : Classe les mots de la question du plus important au moins imporants
        - Paramètre : STR: une chaîne de caractères qui contiendra le texte de la question
                    : STR: Un chemin d'accès vers le répértoire ou la question est posée
        - Retourne : List: une liste triée des mots de la question avec comme paramètre de tri leur TFIDF
     
    - _tri_selec :_
        - Appellation : tri_selec(l, m)
        - Description : renvoie une liste trié en fonction d'une liste d'indice / Par exemple : print(tri_selec([2,4,4,2,3,6,8,9,10,0,2,1],["II","IV","IV","II","III","VI","VIII","IX","X","zéro","II","I"])) -> renverra donc les valeurs en chiffres romains trié car la première liste leur fais correspondre à chacun une valeur numérique
        - Paramètre : list: Une list  avec des valeurs qui peuvent être trié par les opérateurs < et >
                    : list: Une liste de meme taile que la premiere que l'on désire trier en fonction de la 1ere
        - Retourne : List: La 2 eme liste trié en fonction de la 2eme
     
    - _respond :_
        - Appellation : respond(text, directory, directory_clean)
        - Description : Renvoie la 1ere phrase contenant le mot avec le plus grand TFIDF de la question dans le document le plus similaire à la question
        - Paramètre : STR: La question de l'utilisateur
                    : STR: le directory dans lequel on doit chercher les documents avant leur modifications
                    : STR: le directory dans lequel on trouve les documents modifié sans majuscule et caractères spéciaux
        - Retourne : STR: La réponse généré par l'algorithme
     
    - _respond_better :_
        - Appellation : respond_better(text, directory, directory_clean)
        - Description : Choisi la phrase la plus similaire à la question en réutilisant la fonction similar créer plus tôt
        - Paramètre : STR: La question de l'utilisateur
                    : STR: le directory dans lequel on doit chercher les documents avant leur modifications
                    : STR: le directory dans lequel on trouve les documents modifié sans majuscule et caractères spéciaux
        - Retourne : STR: La réponse généré par l'algorithme
     
    - _politesse :_
        - Appellation : politesse(mode)
        - Description : Permet d'ajouter et d'afficher les formules de politesses au début dechaque réponses en fonction du premier mot de l'utilisateur
        - Paramètre : STR: Le mode dans lequel on veut appeler la question
        - Retourne : STR: Le deuxième caractère d'une liste qui est une chaîne de caractèreset qui contient le nom du fichier le plus pertinant

    - _reponse_finale :_
        - Appellation : reponse_finale(text, directory, directory_clean)
        - Description : Utilise les formules de politesse et la fonction respond_better pour afficher la réponse à l'utilisateur
        - Paramètre : STR: Une chaîne de caractères qui contiendra le texte de la question
                    : STR: Un chemin d'accès vers le répertoire non cleaned ou la question est posée
                    : STR: Un chemin d'accès vers le répertoire cleaned dans lequel la question est posée
        - Retourne : Dictionnaire: De toutes les formules de politesses contenue dans le fichier Politess.txt => Si le paramètre est "recup"
                   : Rien: juste des prints => Si le mode est "ajout"
     - slit_new :_
        - Appellation : split_new(text,l)
        - Description : Split une chaine de caractères a la maniere du .split()
        - Paramètre : STR: Une chaîne de caractères à split
                    : list: une liste comprenant les valeurs servant d'indice pour savoir où split
        - Retourne : list: La chaine de caractères split aux endroits demandé
