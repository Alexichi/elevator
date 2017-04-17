#include <stdio.h>
#include <libsx.h>
#include "data.h"

/*
 * Rôle : initialiser l'ensemble ascenseur/immeuble
 */
void init_struct(Ascenseur *d, int nbEtage)
{
	d->etageActuel = 0;
	d->etageMax = 0;
	d->ZoneDessin = NULL;
}

