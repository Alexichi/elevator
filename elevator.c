#include <stdio.h>
#include "callbacks.h"

void init_display(int argc, char **argv, void *d)
{
	/* Création widgets */
	
	Widget buttonQuit = MakeButton("Quit", quit, NULL);
	
	/* Assemblage (positionnement) des widgets */
	SetWidgetPos(buttonQuit, NO_CARE, NULL, NO_CARE, NULL);
	
	/* pour gérer les couleurs */
	GetStandardColors();
	
	/* pour afficher l'interface */
	ShowDisplay();
}

int main (int argc, char **argv)
{
	if(OpenDisplay(argc, argv) == 0){
		fprintf(stderr, "Can't open display\n");
		return EXIT_FAILURE;
	}
	
	init_display(argc, argv, NULL);
	MainLoop();
	return EXIT_SUCCESS;
}
