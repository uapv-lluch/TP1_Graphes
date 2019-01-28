/**
 * 
 * Boucle ;
 * Chaine augmentante 
 * Si je trouve quelque chose 
 * Incrément
 * Grace à incrément, je met à jour la matrice f avec flotmax
 * je retourne sur chaine augmentante
 * 
 *
 * */

/**
 * ch = tableau . Index = sommet, valeur = sommet qui a permi d'atteindre le sommet
 * increment lit ch pour incrémenter chaque sommet de la valeur minimale de capacité. Si ch contient -1 à destination, c'est qu'il n'y a plus de chaine augmentante. 
 * increment lit la chaine une premiere fois, il verifie la valeur minimale et la retourne
 * fonction de mise à jour lit la chaine, l'incrément à effectuer et l'effectuer dans les cases correspondantes de la matrice F (matrice de flots)
 * possibilité de fonction "vérfiersens" qui va chercher dans la matrice des capacités une valeur strictement supérieure à 0 pour deux index donné (i, j) et determine le sens i vers j ou j vers i.
 * 
 * 
 * Main : 
 * Définition des constantes 
 * s = 0
 * t = 5
 * n = 6 (pour les matrices)
 * c[n][n] // Matrice de capacité
 * f[n][n] // Matrice de flots
 * ch[n] // Chaine augmentante
 * Initialisation de la matrice de flots à 0
 * Initialisation de la matrice de capacité avec les valeurs du graphes // Voir celle du cours.
 * 
 * 
 * Booléen stop == False
 * Lancement de la boucle de recherche de flot maximum Tant que stop == False
 * 
 * * chaineaugmentante(ch, c, f, s ,t )
 * * * * chaineaugmentante modifie directement ch pour y insérer les valeurs des sommets qui composent la chaine. Voir au dessus.
 * * * * par défaut, ch a ses valeurs à -1
 * * * * s'appuie sur un tableau local visites[n], initialisé à 0, les sommets visités (index) prennent la valeur 1.
 * * On teste ch[t] 
 * * * * Si t==-1 -> stop == True
 * * * * Sinon 
 * * * * * * Incrément(ch, c, f, s ,t)
 * * * * * * Augmenterflot(incrément,ch, c, f, s, t)
 * * * * * * flotmax += Incrément.