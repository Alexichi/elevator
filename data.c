#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <assert.h>
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

int longueur(ListeBouton d)
{
	return d.lg;
}

void addBouton(ListeBouton *d, Widget *w, char *l, int r)
{
	assert( (r >= 0) && (r <= longueur(*d)+1) );
	ListeBouton q;
	q.tete = malloc( sizeof(struct noeud) );
	(q.tete)->label = l;
	(q.tete)->adresse = w;
	if( r == 0 )
	{
		(q.tete)->boutonSuivant = (*d).tete;
		(*d).tete = q.tete;
		(*d).lg++;
	}
	else
	{
		ListeBouton p = *d;
		for(int i = 1; i < r; i++)
		{
			p.tete = (p.tete)->boutonSuivant;
		}
		(q.tete)->boutonSuivant = (p.tete)->boutonSuivant;
		(p.tete)->boutonSuivant = q.tete;
		(*d).lg++;
	}
}

Widget getBouton(ListeBouton d, int r)
{
	assert( (r >= 0) && (r <= longueur(d)) );
	for(int i = 0; i < r; i++)
	{
		d.tete = (d.tete)->boutonSuivant;
	}
	return *((d.tete)->adresse);
}

char* getLabel(ListeBouton d, Widget *w)
{
	ListeBouton q = d;
	while( (q.tete)->adresse != w )
	{
		q.tete = (q.tete)->boutonSuivant;
	}
	return (q.tete)->label;
}
