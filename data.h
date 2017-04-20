#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsx.h>

typedef struct{
	int etageActuel;
	int etageMax;
	Widget ZoneDessin;
} Ascenseur;


struct noeud{
	char *label;
	Widget *adresse;
	struct noeud *boutonSuivant;
};

typedef struct
{
	struct noeud *tete;
	int lg;
} ListeBouton;

void init_struct(Ascenseur *n, int);
char* getLabel(ListeBouton, Widget*);
int longueur(ListeBouton);
void addBouton(ListeBouton*, Widget*, char*, int); 
Widget getBouton(ListeBouton, int);

#endif
