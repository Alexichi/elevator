#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "display.h"
#include "data.h"

/*
 * Rôle : créer une zone colorée et l'afficher dans l'interface graphique
 */
void redisplay(Widget w, int width, int height, void *data)
{
	Ascenseur *d = (Ascenseur *)data;
	/* Déclaration des longueurs nécessaires au dessin */
	int largeurCageAsc = 80;
	int largeurEtage = MAXX - largeurCageAsc;
	int hauteurEtage = MAXY/(d->etageMax +1);
	
	ClearDrawArea();
	/* Dessin de la cage d'ascenseur */
	DrawBox(0, 0, largeurCageAsc, MAXY);
	
	/* Dessin des Etages */
	for(int i = 0; i < d->etageMax; i++){
		DrawBox(largeurCageAsc, i*hauteurEtage, largeurEtage, hauteurEtage);
	}
	
	/* Dessin de l'ascenseur (A redéfinir car il n'est pas relié à la structure ascenseur) */
	DrawFilledBox(5, MAXY - hauteurEtage*((d->etageActuel)+1), largeurCageAsc - 10, hauteurEtage);
}

/*
 * Rôle : Callback permettant normalement de faire monter l'ascenseur
 * Cette fonction est en paramètre de la fonction display_update()
 */

void ascenseurMontant(void *data)
{
	Ascenseur *d = (Ascenseur *)data;
	redisplay(*(d->ZoneDessin), MAXX, MAXY, data);		// on rappelle la fonction de dessin pour mettre a jour la position d'ascenseur
	if( d->etageActuel != d->etageSouhaite) // Ici on va faire monter ou descendre l'ascenseur par etape
	{
		if( d->etageSouhaite > d->etageActuel)
		{
			d->etageActuel = d->etageActuel + 1;
		}
		else
		{
			d->etageActuel = d->etageActuel - 1;
		}
	}
	AddTimeOut(d->tempo, &ascenseurMontant, data); // on rappelle la fonction addtimeout pour remettre a jour l'interface graphique
}

/*
 * Rôle : Amène l'ascenseur à l'étage demandé
 */
void callAscenseur(Widget w, void *d)			
{
	Ascenseur *data = (Ascenseur *)d;			
	int numeroEtage = getFloorNumber(w);
	data->etageSouhaite = numeroEtage;			// On stock la consigne dans la structure 
}

/*
 * Rôle : Permet de quitter l'application
 */
void quit(Widget w, void *d)
{
	exit(EXIT_SUCCESS);
}
