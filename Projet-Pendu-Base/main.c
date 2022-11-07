#define _CRT_SECURE_NO_WARNINGS

#include "dico.h"	// Pour utiliser le dictionnaire de mots
#include <stdio.h> // Pour printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(int argc, char ** argv)
{
	//--------------------------------------------------
	// Exemple d'utilisation du dictionnaire de mot : 
	char mot[100], charResearch;
	int i, c, lettreestdanslemot = 0, coups, numChoisi, tailleMot = 0;
	int *lettreTrouvee = NULL; // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée

	// Menu Accueil
	printf("Bienvenu dans le Pendu !\n\n");
	


	// Piocher le mot
	piocherMot(mot);
	

	// Demander le nombre d'essais
	printf("En combien de coups voulez-vous essayer trouver le mot mystere ? : ");
	scanf("%d", &coups);

	// Afficher à quoi ressemble le mot piocher
	printf("\nVoici le mot du debut : ");
	for (i = 0; mot[i] != '\0'; i++)
	{
		printf("*");
	}

	tailleMot = strlen(mot); // Taille du mot

	lettreTrouvee = malloc(tailleMot * sizeof(int)); // On alloue dynamiquement le tableau lettreTrouvee (dont on ne connaissait pas la taille au départ)

	for (i = 0; i < tailleMot; i++) // Met le tableau à false (0), de ce fait, chaque lettre du mot sera représentée de base par une étoile *
	{
		lettreTrouvee[i] = 0;
	}

	while (coups != 0) // Tant qu'il y a encore des coups à jouer.
	{
		printf("\n\n\nIl vous reste %d coups a jouer", coups); // Afficher le nombres de coups restant.

		do // On Re vide le buffer du scanf pour éviter le saut.
		{
			c = getchar();
		} while (c != EOF && c != '\n');

		printf("\nProposez une lettre (En majuscule) : "); // Rentrer le caractère voulu pour essayer de trouver le mot mystère.
		scanf("%c", &charResearch);

		// On parcourt le mot mystère pour vérifier si la lettre proposée y est.
		for (i = 0; mot[i] != '\0'; i++)
		{
			if (charResearch == mot[i]) // Si la lettre y est.
			{
				lettreTrouvee[i] = 1; // On met à 1 (vrai) à la case du tableau de booléens correspondant à la lettre actuelle, ce qui va par la suite, permettre d'afficher la lettre au lieu d'une étoile * lors de l'affichage du mot.
			}
		}


		printf("\nLe mot donne : ");
		// Ceci va permettre l'affichage du mot.
		for (i = 0; mot[i] != '\0'; i++) 
		{

			if (charResearch == mot[i])
			{
				printf("%c", mot[i]); // Si la lettre y est.

				lettreestdanslemot++; // On ajoute 1 lettreestdanslemot, ce qui donne 1 (vrai).
			}
			else if (lettreTrouvee[i])  // Sinon si la variable lettreTrouvee est à 1 (vrai) sur la lettre (i).
			{
				printf("%c", mot[i]); // On écrit la lettre (i).
			}
			else
			{
				printf("*"); // Sinon (si variable lettreTrouvee est à autre chose que 1 (vrai), c'est à dire 0 (faux) On écrit une étoile *.
			}
		}

		int win = 1; // Variable déterminant la victoire du joueur. De base mise sur 1 (vrai).

		for (i = 0; i < tailleMot; i++) // Cet algorithme va vérifier si chaque lettre est bien trouvée. Si non, on met win à faux.
		{
			if (lettreTrouvee[i] == 0)
			{

				win = 0; 
			}
		}

		if (win == 1) // Si win est toujours à 1 (vrai), alors on a gagné.
		{
			printf("\n\nGagne ! Le mot mystere etait bien : %s\n", mot);
			printf("Pour fermer la fenetre, veuillez appuyer sur une touche ;)\n");
			break;
		}


		if (lettreestdanslemot == 0) // Si la lettre choisie n'est pas dans le mot.
		{
			coups--; // On retire un coup au joueur.
		}

	}

	if (coups == 0) // Si le joueur n'a plus de coups, alors c'est perdu !
	{
		printf("\n\nDommage ! Le mot mystere etait : %s\n", mot); 
		printf("Pour fermer la fenetre, veuillez appuyer sur une touche ;)\n");

	}

	_getch(); // Attente de touche par l'utilisateur

	return 0;
}