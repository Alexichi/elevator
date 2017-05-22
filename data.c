#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <assert.h>
#include "data.h"
#include "main.h"

/*
 * Rôle : initialiser l'ascenseur
 */
void init_struct(Ascenseur *d, int nbEtage)
{
	d->etageActuel = 1;
	d->etageMax = nbEtage;
	d->ZoneDessin = NULL;
}

int getFloorNumber(Widget w)
{
	int i = 0;
	char label[2];
	while( BoutonEtage[i] != w)
	{
		i++;
	}
	return i;
}

