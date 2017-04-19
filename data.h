#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsx.h>

typedef struct{
	int etageActuel;
	int etageMax;
	Widget ZoneDessin;
} Ascenseur;


typedef struct{
	char *label;
	Widget *adresse;
} EtiquetteBouton;

void init_struct(Ascenseur *n, int);
void getLabel(void);

#endif
