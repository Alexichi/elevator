#include <string.h>
#include "display.h"
#include "data.h"
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
	/* Création d'un ascenseur */
	Ascenseur ascenseur;
	if(argc <= 1)
	{
		printf("MAX FLOOR UNSPECIFIED, EXITING... \n");
		return EXIT_SUCCESS;
	}
	else
	{
		sscanf(argv[1], "%d", &(ascenseur.etageMax)); // conversion char -> int pour stocker le nombre d'etages
	}
	if (OpenDisplay(argc, argv) == 0) 
	{
		fprintf(stderr, "Can't open display \n");
		return EXIT_FAILURE;
	}
	printf("display openned \n");
	init_struct(&ascenseur);					// Initialisation de la structure ascenseur
	init_display(argc, argv, &ascenseur);		// Creation des Widgets et DrawArea
	display_update(&ascenseur);					// Fonction permettant de déplacer l'ascenseur
	
	/* Boucle permettant d'afficher constamment l'interface graphique */
	MainLoop();
	return 0;
}

