#include "callbacks.h"
#include <stdlib.h>

/*
 * Rôle : créer une zone colorée et l'afficher dans l'interface graphique
 */
void redisplay(Widget w, int width, int height, void *data)
{
	DrawFilledBox(50, 50, 75, 75); 
}

/*
 * Rôle : Permet de quitter l'application
 */
void quit(Widget w, void *d)
{
	exit(EXIT_SUCCESS);
}
