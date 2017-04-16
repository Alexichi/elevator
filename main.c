/*
 * main.c
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
#include <stdlib.h>
#include <string.h>
#include <libsx.h>
#include "display.h"
#include "data.h"

int main(int argc, char **argv)
{
	Ascenseur ascenseur;
	int nbEtage = 5;

	if (OpenDisplay(argc, argv) == 0) 
	{
		fprintf(stderr, "Can't open display \n");
		return EXIT_FAILURE;
	}
	printf("display openned \n");
	
	init_display(argc, argv, &ascenseur);
	init_struct(&ascenseur, nbEtage);
	MainLoop();
	return 0;
}

