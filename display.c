#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "display.h"
#include "main.h"


/*
 * Rôle : initialiser l'interface grapique avec tous les éléments
 * nécessaires à la mise en place de celle-ci
 */
void init_display(int argc, char **argv, void *d)
{
	
	/* creation et assemblage widget */
	Widget DrawArea, ButtonQuit, ButtonEtage[NB_ETAGES+1];
	
	DrawArea = MakeDrawArea(MAXX, MAXY, redisplay, d);
	ButtonEtage[NB_ETAGES] = MakeButton("1", callAscenseur, NULL);
	SetWidgetPos(ButtonEtage[NB_ETAGES],PLACE_RIGHT, DrawArea, NO_CARE, NULL);
	for(int i = NB_ETAGES-1; i >= 0; i--){
		ButtonEtage[i] = MakeButton("0", callAscenseur, NULL);
		SetWidgetPos(ButtonEtage[i], PLACE_RIGHT, DrawArea, PLACE_UNDER, ButtonEtage[i+1]);
	}
	ButtonQuit = MakeButton("Quit", quit, NULL);
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

