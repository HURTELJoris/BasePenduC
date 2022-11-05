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
	int i, c, j = 0, essais, numChoisi, tailleMot = 0;
	int *lettreTrouvee = NULL; // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée

	// Menu Accueil
	printf("Bonjour ! Bienvenu au jeu du pendu !\n\n1 - Mode avec un mot rentrer par un utilisateur\n2 - Mode avec un mot choisis dans un dictionnaire\n\nSaisir votre choix : ");
	scanf("%d", &numChoisi);

	while (numChoisi != 1 && numChoisi != 2)
	{
		printf("Entrer soit 1 ou 2 svp : ");
		scanf("%d", &numChoisi);
	}

	do // On vide le buffer du scanf pour éviter le saut 
	{
		c = getchar();
	} while (c != EOF && c != '\n');

	if (numChoisi == 1)
	{
		// Saisi du mot mystère
		printf("Entrer un mot mystere (En majuscule) : ");
		for (i = 0; i < 100; i++) {

			mot[i] = _getch(); // Recupere la saisie dans notre chaine

			if (mot[i] == 13) // Si entree
			{
				break;
			}

			printf("*");
		}

		mot[i] = '\0'; // Definis la case actuelle comme la derniere de notre chaine

		printf("\n\n");
	}
	else if (numChoisi == 2)
	{
		// Piocher le mot
		printf("Pioche du mot en cours ...\n\n");
		piocherMot(mot);
	}

	// Demander le nombre d'essais
	printf("En combien d essais max voulez-vous trouver le mot mystere ? : ");
	scanf("%d", &essais);

	// Afficher à quoi ressemble le mot piocher
	printf("\nVoici le mot du debut : ");
	for (i = 0; mot[i] != '\0'; i++)
	{
		printf("*");
	}

	tailleMot = strlen(mot); // Taille du mot

	lettreTrouvee = malloc(tailleMot * sizeof(int)); // On alloue dynamiquement le tableau lettreTrouvee (dont on ne connaissait pas la taille au départ)

	for (i = 0; i < tailleMot; i++) // Met le tableau à false (0)
	{
		lettreTrouvee[i] = 0;
	}

	while (essais != 0) // Tant que le nombre d'essais est pas 0
	{
		printf("\n\n\nIl vous reste %d coups a jouer", essais); // Afficher le nombres d'essais restant

		do // On Re vide le buffer du scanf pour éviter le saut
		{
			c = getchar();
		} while (c != EOF && c != '\n');

		printf("\nProposez une lettre (En majuscule) : "); // Rentrer un caractere
		scanf("%c", &charResearch);

		// On parcourt motSecret pour vérifier si la lettre proposée y est
		for (i = 0; mot[i] != '\0'; i++)
		{
			if (charResearch == mot[i]) // Si la lettre y est
			{
				lettreTrouvee[i] = 1; // On met à 1 (vrai) le case du tableau de booléens correspondant à la lettre actuelle
			}
		}

		j = 0;

		printf("\nLe mot donne : ");
		for (i = 0; mot[i] != '\0'; i++)
		{

			if (charResearch == mot[i])
			{
				printf("%c", mot[i]);

				j++;
			}
			else if (lettreTrouvee[i])
			{
				printf("%c", mot[i]);
			}
			else
			{
				printf("*");
			}
		}

		int win = 1;

		for (i = 0; i < tailleMot; i++)
		{
			if (lettreTrouvee[i] == 0)
			{

				win = 0;
			}
		}

		if (win == 1)
		{
			printf("\n\nGagne ! Le mot mystere etait bien : %s\n", mot); // Afficher le mot mystere (Win)
			printf("Pour fermer la fenêtre veuillez appuyer sur une touche ;)\n");
			break;
		}


		if (j == 0)
		{
			essais--;
		}

	}

	if (essais == 0)
	{
		printf("\n\nDommage ! Le mot mystere etait : %s\n", mot); // Afficher le mot mystere
		printf("Pour fermer la fenetre veuillez appuyer sur une touche ;)\n");

	}

	_getch(); // Attente de touche par l'utilisateur

	return 0;
}