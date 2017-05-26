#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsx.h>

typedef struct{
	int etageActuel;
	int etageSouhaite[3]; //liste d'attente des étages
	int etageMax;
	int tempo;
	int tempoArret;
	Widget *ZoneDessin;
} Ascenseur;

void init_struct(Ascenseur *);
int getFloorNumber(Widget w);


#endif
