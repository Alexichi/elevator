#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "display.h"

/*
 * Rôle : créer une zone colorée et l'afficher dans l'interface graphique
 */
void redisplay(Widget w, int width, int height, void *data)
{
	/* Déclaration des longueurs nécessaires au dessin */
	int largeurCageAsc = 80;
	int largeurEtage = MAXX - largeurCageAsc;
	int hauteurEtage = MAXY/(NB_ETAGES+1);
	
	/* Dessin de la cage d'ascenseur */
	DrawBox(0, 0, largeurCageAsc, MAXY);
	
	/* Dessin des Etages */
	for(int i = 0; i < NB_ETAGES; i++){
		DrawBox(largeurCageAsc, i*hauteurEtage, largeurEtage, hauteurEtage);
	}
	
	/* Dessin de l'ascenseur (A redéfinir car il n'est pas relié à la structure ascenseur) */
	DrawFilledBox(5, MAXY - hauteurEtage, largeurCageAsc - 10, hauteurEtage);
}

/*
 * Rôle : Callback permettant normalement de faire monter l'ascenseur
 * Cette fonction est en paramètre de la fonction display_update()
 */
void  ascenceurMontant(void *data, XtIntervalId *id)
{
	
}

/*
 * Rôle : Amène l'ascenseur à l'étage demandé
 */
void callAscenseur(Widget w, void *d)
{
	//printf("%s\n", w.label);
}

/*
 * Rôle : Permet de quitter l'application
 */
void quit(Widget w, void *d)
{
	exit(EXIT_SUCCESS);
}
