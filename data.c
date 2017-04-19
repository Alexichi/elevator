#include <stdio.h>
#include <libsx.h>
#include "data.h"

/*
 * Rôle : initialiser l'ascenseur
 */
void init_struct(Ascenseur *d, int nbEtage)
{
	d->etageActuel = 0;
	d->etageMax = nbEtage;
	d->ZoneDessin = NULL;
}


void getLabel(void)
{
	
}
