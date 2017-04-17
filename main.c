#include <string.h>
#include "display.h"
#include "data.h"
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
	/* Création d'un ascenseur */
	Ascenseur ascenseur;

	if (OpenDisplay(argc, argv) == 0) 
	{
		fprintf(stderr, "Can't open display \n");
		return EXIT_FAILURE;
	}
	printf("display openned \n");
	
	init_display(argc, argv, &ascenseur);
	init_struct(&ascenseur, NB_ETAGES);
	/* Boucle permettant d'afficher constamment l'interface graphique */
	MainLoop();
	return 0;
}

