#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "display.h"
#include "main.h"
#include "data.h"
#include <stdlib.h>

/*
 * Rôle : initialiser l'interface grapique avec tous les éléments
 * nécessaires à la mise en place de celle-ci
 */
void init_display(int argc, char **argv, void *d)
{
	
	/* creation et assemblage widget */
	Ascenseur* data = d;
	Widget DrawArea, BoutonQuit;
	char buttonNumber[2] = "0";
	
	BoutonEtage = realloc(BoutonEtage, data->etageMax + 1); // Agrandis la taille du tableau de widget en fonction du nombre d'etage
	DrawArea = MakeDrawArea(MAXX, MAXY, redisplay, d); 		// Creation de la zone de dessin
	data->ZoneDessin = &DrawArea;							// Stockage de l'adresse de la zone dessin dans la structure
	SetDrawArea(DrawArea);
	for(int i = 0; i <= data->etageMax; i++)				// creation des widgets bouton pour l'appel de l'ascenseur
	{
		if( i == 0)
		{
			sprintf(buttonNumber, "%d", i);
			BoutonEtage[i] = MakeButton(buttonNumber, callAscenseur, data);
			SetWidgetPos(BoutonEtage[i],PLACE_RIGHT, DrawArea, NO_CARE, NULL);
		}
		else
		{
			sprintf(buttonNumber, "%d", i);
			BoutonEtage[i] = MakeButton(buttonNumber, callAscenseur, data);
			SetWidgetPos(BoutonEtage[i] , PLACE_RIGHT, DrawArea, PLACE_UNDER, BoutonEtage[i-1]);
		}
	}
	BoutonQuit = MakeButton("Quit", quit, NULL);
	SetWidgetPos(BoutonQuit, PLACE_UNDER, DrawArea, NO_CARE, NULL);
	
	printf("widgets initialized\n");
	
	/* gestion couleurs */
	GetStandardColors();
	
	/* affichage interface */
	ShowDisplay();
	printf("display initialized \n");
}


/*
 * Rôle : déplacer l'ascenseur
 */
void display_update(void* d)
{
	Ascenseur *data = (Ascenseur *)d;
	AddTimeOut(data->tempo, &ascenseurMontant, d);	// On appelle la fonction ascenseurMontant lorsque la tempo est terminee
}

