//Soit la structure nommée « student » ayant 4 membres représentant respectivement le nom, le prenom, l’adresse et la classe de l’élève.
//L’application qui sera développée permettra de gérer au max 100 élèves.
//Vous devrez utiliser pour ce TP les fonctions fread et fwrite.
//
//Question 0 :
//
//Réaliser le diagramme des cas d’utilisations de ce programme.
//
//Question 1 :
//
//Réaliser en C le programme répondant aux exigences fonctionnelles suivantes(par ordre de priorité).
//
//Exigence fonctionnelle n°1 :
//Les fonctions du programme sont articulées autour d’un menu.
//Exigence fonctionnelle n°2 :
//Une fonction « addStudent » permet de saisir les informations d’un élève.Cette fonction recevra l’adresse 
//de la structure qui est à remplir, le nombre d’élève déjà gérés et retournera le nombre total d’élèves enregistrés après la saisie.
//Exigence fonctionnelle n°3 :
//Une fonction « displayStudent » permet d’afficher les informations de tous les élèves enregistrés.
//Exigence fonctionnelle n°4 :
//Une fonction « saveStudent » permet de sauvegarder toutes les structures dans un fichier dont le nom 
//et le chemin d’accès seront donnés par l’utilisateur dans le programme principal et transmis à cette fonction.
//Exigence fonctionnelle n°5 :
//Une fonction « loadStudent » permet de charger toutes les informations du fichier(dont le nom et le chemin d’accès seront soit 
//donnés par l’utilisateur soit stockés dans un fichier ini au choix) dans un tableau de structures.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    char nom[50];
    char prenom[50];
    char adresse[100];
    char classe[20];
} student;

int addStudent(student* students, int nbE) {

}


int main()
{
	int choix =0;
    int nbE = 0;
    student students[100]; 
    do {
        printf("1. Ajouter un eleves\n");
        printf("2. Afficher les eleves\n");
        printf("3. Sauvegarder les eleves\n");
        printf("4. Charger les eleves\n");
        printf("5. Quitter\n");
        scanf("%d", &choix);
        if (choix < 1 || choix > 5)
        {
            printf("Choix invalide, veuillez reessayer.\n");
		}
        switch (choix)
        {
        case 1:
            break;

        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }while(choix != 5);
}


