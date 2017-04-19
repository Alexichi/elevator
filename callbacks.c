#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Rôle : créer une zone colorée et l'afficher dans l'interface graphique
 */
void redisplay(Widget w, int width, int height, void *data)
{
	DrawFilledBox(50, 50, 75, 75); 
}

/*
 * Rôle : Amène l'ascenseur à l'étage demandé
 */
void callAscenseur(Widget w, void *d)
{
	//printf("%s\n", w.label);
}

/*
 * Rôle : Permet de quitter l'application
 */
void quit(Widget w, void *d)
{
	exit(EXIT_SUCCESS);
}
