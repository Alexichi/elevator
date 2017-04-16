/*
 * display.c
 * 
 * Copyright 2017 Axel <axel@axel-GP62-6QE>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "display.h"


void init_display(int argc, char **argv, void *d)
{
	/* creation et assemblage widget */
	Widget DrawArea, ButtonQuit;
	
	DrawArea = MakeDrawArea(MAXX, MAXY, redisplay, d);
	ButtonQuit = MakeButton("Quit", quit, d);
	SetDrawArea(DrawArea);
	
	/* Positionnement widgets */ 
	SetWidgetPos(ButtonQuit, PLACE_UNDER, DrawArea, NO_CARE, NULL);
	printf("widgets initialized\n");
	
	/* gestion couleurs */
	GetStandardColors();
	
	/* affichage interface */
	ShowDisplay();
	printf("display initialized \n");
}

void display_update(void)
{
	
}

