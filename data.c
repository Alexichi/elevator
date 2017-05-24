#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <assert.h>
#include "data.h"
#include "main.h"

/*
 * Rôle : initialiser l'ascenseur
 */
void init_struct(Ascenseur *d)		// Structure de donnee qui permet de faire transiter les donnees utiles au programme
{
	d->etageActuel = 0;
	d->etageSouhaite = 0;
	d->tempo = TEMPO;
	d->ZoneDessin = NULL;
}

int getFloorNumber(Widget w)		// Renvoie le numero d'etage, le widget w doit etre un bouton cree dans init_display
{
	int i = 0;
	while( BoutonEtage[i] != w)
	{
		i++;
	}
	return i;
}

