//Objectif:
//
//Soit un tableau tab, qui contient au max 100 entiers rangés dans l’ordre croissant et qui sera initialisé par l’utilisateur OU généré pseudo
//- aléatoirement(un des deux au choix), vous réaliserez un programme qui recherche une valeur(donnée par l’utilisateur) dans ce tableau.
//
//
//Contraintes :
//	La méthode de recherche par dichotomie vous est imposée.
//	Si la valeur est trouvée vous affichez sa position dans le tableau sinon vous affichez un message d’erreur.
//	Vous devrez créer trois fonctions :
//
//Une pour l’initialisation(qui insérera les valeurs que donnent l’utilisateur de manière à ce que le tableau soit rangé dans l’ordre croissant),
//Une pour la recherche(qui recherchera la valeur donnée par l’utilisateur dans le tableau en utilisant la méthode de recherche par dichotomie),
//Une pour l’affichage(qui affiche le tableau et si la valeur donnée par l’utilisateur est présente ou non dans ce dernier et si oui donne son index dans le tableau).
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void initialisation(int* tab, int* taille)
{
	while (*taille < 1 || *taille > 100);
	{
		printf("Entrez la taille du tableau (max 100) : ");
		scanf("%d", taille);

	}

	int nb;
	for (int i = 0; i < *taille; i++)
	{
		printf("Entrez la valeur %d : ", i + 1);
		scanf("%d", &nb);
		int j = i - 1;
		while (j >= 0 && tab[j] > nb)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = nb;
	}
}

int recherche(int* tab, int taille, int valeur)
{
	int deb = 0;
	int fin = taille - 1;
	int mid = 0;
	while (deb <= fin){
		mid =(deb + fin) / 2;
		if (tab[mid] == valeur) {
			return mid;
		}
		else if (tab[mid] < valeur) {
			deb = mid + 1;
		}
		else {
			fin = mid - 1;
		}
	}
	
	return -1;
}

void affichage(int* tab, int taille, int valeur, int index)
{
	printf("\n[");
	for (int i = 0; i < taille; i++) {
		printf("%d", tab[i]);
		if (i < taille - 1)
			printf(", ");
	}
	printf("]");
	printf("\nvaleur recherche : %d", valeur);
	if (index == -1) {
		printf("\nerreur : la valeur recherche n'est pas dans le tableau");
	}
	else {
		printf("\nvaleur trouve, elle se trouve à la position : %d ", index + 1);
	}
	

}

int main()
{
	int tab[100];
	int taille, valeur, index;
	initialisation(tab, &taille);
	printf("Entrez la valeur a rechercher : ");
	scanf("%d", &valeur);
	index = recherche(tab, taille, valeur);
	affichage(tab, taille, valeur, index);

	return 0;
}

