#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <libsx.h>

void redisplay(Widget, int, int, void *);
void callAscenseur(Widget, void*);
void  ascenceurMontant(void *, XtIntervalId *);
void quit(Widget, void *);


#endif
