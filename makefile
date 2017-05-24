CC = gcc		# compilateur
CFLAGS = -Wall	-std=gnu99	# les options de compilateur
LDFLAGS = -lsx		# les options pour l'editeur de liens
SRC = main.c callbacks.c display.c data.c	# fichiers sources
PROG = ascenseur		# Nom de l'exe
OBJS = $(SRC:.c=.o) 	# les .o qui en decoulent
.SUFFIXES: .c .o

all: $(PROG)

# etapes de compilation et d'edition de liens

$(PROG): $(OBJS)
	$(CC)  -o $@ $^ $(LDFLAGS)	# $@ la cible $^ toutes les dependances

callbacks.o: callbacks.h data.h main.h display.h
data.o: data.h main.h
display.o: callbacks.h data.h main.h display.h
main.o:   display.h data.h main.h
# le lien entre .o et .c
%.o: %.c
	$(CC) $(CFLAGS) -c $<		# $< derniere dependance

# Pour faire propre

.PHONY: clean
clean: 
	rm -f *.o *~ core $(PROG)
