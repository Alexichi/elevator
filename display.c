#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "display.h"
#include "main.h"
#include "data.h"

/*
 * Rôle : initialiser l'interface grapique avec tous les éléments
 * nécessaires à la mise en place de celle-ci
 */
void init_display(int argc, char **argv, void *d)
{
	
	/* creation et assemblage widget */
	ListeBouton l;
	l.lg = 0;
	Widget DrawArea, BoutonQuit, BoutonEtage[NB_ETAGES+1], *adresseBoutonEtagePrecedent;
	Widget BoutonEtagePrecedent;
	char buttonNumber[2] = "0";
	DrawArea = MakeDrawArea(MAXX, MAXY, redisplay, d);
	SetDrawArea(DrawArea);
	for(int i = 0; i <= NB_ETAGES; i++)
	{
		if( i == 0)
		{
			sprintf(buttonNumber, "%d", i);
			BoutonEtage[i] = MakeButton(buttonNumber, callAscenseur, NULL);
			addBouton(&l, BoutonEtage, "0", i);
			printf("[DEBUG]	Adresse Bouton Etage numero %d %#010x\n", i, &BoutonEtage[i]);
			SetWidgetPos(BoutonEtage[i],PLACE_RIGHT, DrawArea, NO_CARE, NULL);
		}
		else
		{
			sprintf(buttonNumber, "%d", i);
			BoutonEtage[i] = MakeButton(buttonNumber, callAscenseur, NULL);
			printf("[DEBUG]	Adresse Bouton Etage numero %d %#010x\n", i, &BoutonEtage[i]);
			addBouton(&l, &BoutonEtage[i], buttonNumber, i);
			SetWidgetPos(BoutonEtage[i] , PLACE_RIGHT, DrawArea, PLACE_UNDER, getBouton(l, i-1));
		}
	}
	BoutonQuit = MakeButton("Quit", quit, NULL);
	printf("[DEBUG]	Adresse BoutonQuit %#010x\n", &BoutonQuit);
	SetWidgetPos(BoutonQuit, PLACE_UNDER, DrawArea, NO_CARE, NULL);
	
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

