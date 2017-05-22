#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsx.h>

typedef struct{
	int etageActuel;
	int etageMax;
	Widget ZoneDessin;
} Ascenseur;

void init_struct(Ascenseur *, int);
int getFloorNumber(Widget w);


#endif
