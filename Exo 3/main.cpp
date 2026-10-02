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
#include <string.h>

typedef struct
{
    char nom[100];
    char prenom[100];
    char adresse[100];
    char classe[100];
} student;

void ecrit(char* msg) {
    fgets(msg, 100, stdin);
    msg[strcspn(msg, "\n")] = '\0';
 
}

int addStudent(student* students,int taille) {
    if (taille >= 100) {
        printf("Nombre maximum d'eleves atteint.\n");
        return taille;
    }
    printf("Eleve %d:\n", taille + 1);
    printf("Nom: ");
    ecrit(students->nom);
    printf("Prenom: ");
    ecrit(students->prenom);
    printf("Adresse: ");
    ecrit(students->adresse);
    printf("Classe: ");
    ecrit(students->classe);
    taille +=1;
    return taille;
}

void displayStudent(student* students, int taille) {
    if (taille == 0) {
        printf("Aucun eleve enregistre.\n");
        return;
	}
    for (int i = 0; i < taille; i++) {
        printf("Eleve %d:\n", i + 1);
        printf("Nom: %s  ", students[i].nom);
        printf("Prenom: %s  ", students[i].prenom);
        printf("Adresse: %s  ", students[i].adresse);
        printf("Classe: %s  ", students[i].classe);
    }
}

void saveStudent(student* students, int taille, const char* chemin) {
	if (strcmp(chemin, "default") == 0) { // permet de verif sans faire de boucle si le chemin est default ou nop 
		chemin = "eleves"; 
	}
    FILE* fichier = fopen(chemin, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour ecriture.\n");
        return;
    }
    fwrite(students, sizeof(student), taille, fichier);
    fclose(fichier);
    printf("Eleves sauvegardes avec succes.\n");
}

int loadStudent(student* students, const char* chemin) {
	int taille = 0;
    if (strcmp(chemin, "default") == 0) {
        chemin = "eleves";
    }
    FILE* fichier = fopen(chemin, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour lecture.\n");
        return 0;
	}
	taille = fread(students, sizeof(student), 100, fichier);
    fclose(fichier);
	printf("total d'eleves charges : %d\n", taille);
    return taille; //reset la taille donc meme si il reste des anciens eleves dans le tableau apres le chargement du fichier , 
    //ils ne seront plus accessible et supprime par la suite
}

int main()
{
	int choix =0;
    student students[100]= {0}; 
    int taille = 0;
	char chemin[1000];
    do {
        printf("1. Ajouter un eleves\n");
        printf("2. Afficher les eleves\n");
        printf("3. Sauvegarder les eleves\n");
        printf("4. Charger les eleves\n");
        printf("5. Quitter\n");
		scanf("%d%*c", &choix); // %*c permet de del \n ou autre du scanf comme ca pas de skip 

        if (choix < 1 || choix > 5)
        {
            printf("Choix invalide, veuillez reessayer.\n");
		}
        switch (choix)
        {
        case 1:
			taille = addStudent(&students[taille], taille);
            break;

        case 2:
            displayStudent(students, taille);
            break;
        case 3:
            printf("\nEntrez le chemin du fichier pour sauvegarder les eleves ou tapez 'default' pour utiliser le chemin par defaut : ");
			ecrit(chemin);
			saveStudent(students, taille, chemin);
            break;
        case 4:
            printf("\nEntrez le chemin du fichier pour load votre fichier avec vos eleves ou tapez 'default' si c'est le chemin que vous avez utiliser pour enregistrer : ");
            ecrit(chemin);
			taille= loadStudent(students, chemin);
            break;
        }
    }while(choix != 5);
}


