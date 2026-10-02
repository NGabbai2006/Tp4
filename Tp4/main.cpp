//Exercice 1
//Objectif :
//Vous écrirez une fonction échange qui échange les valeurs des deux variables
//entières qui lui sont transmises en argument.
//
//
//Contraintes :
//Ces deux variables, déclarées dans le main, seront affichées avant et après l’appel à la fonction échange dans le programme principal.

#include <stdio.h>

int echange(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int main()
{
	int a = 69;
	int b = 6777777;
	printf("valeur 1 : %d, valeur 2 : %d\n", a, b);
	echange(&a, & b);
	printf("valeur 1 : %d, valeur 2 : %d\n", a, b);
}


