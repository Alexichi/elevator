#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsx.h>

typedef struct{
	int etageActuel;
	int etageSouhaite;
	int etageMax;
	int tempo;
	Widget *ZoneDessin;
} Ascenseur;

void init_struct(Ascenseur *);
int getFloorNumber(Widget w);


#endif
