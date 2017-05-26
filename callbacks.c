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
	
	/* Bouton extérieur de l'ascenseur */
	
	
	/* Dessin de l'ascenseur */
	DrawFilledBox(5, MAXY - hauteurEtage*((d->etageActuel)+1), largeurCageAsc - 10, hauteurEtage);
}

/*
 * Rôle : Callback permettant de faire monter/descendre l'ascenseur
 * Cette fonction est en paramètre de la fonction display_update()
 */

void ascenseurMontant(void *data)
{
	Ascenseur *d = (Ascenseur *)data;
	redisplay(*(d->ZoneDessin), MAXX, MAXY, data);		// on rappelle la fonction de dessin pour mettre a jour la position d'ascenseur
	//printf("%d \n", d->etageActuel);
	/* Ici on va faire monter ou descendre l'ascenseur par etape 
	 * Le -1 étant la référence mais nous ne voulons pas que l'ascenceur aille à -1 on ajoute la deuxième condition 
	 */
	if( (d->etageActuel != d->etageSouhaite[0]) && (d->etageSouhaite[0] != (-1)))
	{ 
		//printf("non\n");
		if( d->etageSouhaite[0] > d->etageActuel)
		{
			d->etageActuel = d->etageActuel + 1;
		}
		else
		{
			d->etageActuel = d->etageActuel - 1;
		}
		AddTimeOut(d->tempo, &ascenseurMontant, data); // on rappelle la fonction addtimeout pour remettre a jour l'interface graphique
	}
	/* Nous sommes a l'étage souhaité */
	else
	{
		/* si un étage est en attente on le prend */
		if(d->etageSouhaite[1] != -1)
		{
			d->etageSouhaite[0] = d->etageSouhaite[1];
			d->etageSouhaite[1] = d->etageSouhaite[2];
			d->etageSouhaite[2] = -1;
		}
		/* On attend un peu plus longtemps que d'habitude pour laisser le temps aux personnes de sortir */
		AddTimeOut(d->tempoArret, &ascenseurMontant, data);
	}
}

/*
 * Rôle : Appel l'ascenseur à l'étage demandé
 */
void callAscenseur(Widget w, void *d)			
{
	Ascenseur *data = (Ascenseur *)d;			
	int numeroEtage = getFloorNumber(w);
	for(int i = 0; i<3; i++){
		if(data->etageSouhaite[i] == -1){
			data->etageSouhaite[i] = numeroEtage;		// On stock la consigne dans la structure 
			i = 5; //Pour sortir de la boucle
		}
	}
}

/*
 * Rôle : Permet de quitter l'application
 */
void quit(Widget w, void *d)
{
	exit(EXIT_SUCCESS);
}
