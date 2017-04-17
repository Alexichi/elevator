#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "display.h"


/*
 * Rôle : initialiser l'interface grapique avec tous les éléments
 * nécessaires à la mise en place de celle-ci
 */
void init_display(int argc, char **argv, void *d)
{
	/* creation et assemblage widget */
	Widget DrawArea, ButtonQuit;
	
	DrawArea = MakeDrawArea(MAXX, MAXY, redisplay, d);
	ButtonQuit = MakeButton("Quit", quit, d);
	SetDrawArea(DrawArea);
	
	/* Positionnement widgets */ 
	SetWidgetPos(ButtonQuit, PLACE_UNDER, DrawArea, NO_CARE, NULL);
	printf("widgets initialized\n");
	
	/* gestion couleurs */
	GetStandardColors();
	
	/* affichage interface */
	ShowDisplay();
	printf("display initialized \n");
}

void display_update(void)
{
	
}

