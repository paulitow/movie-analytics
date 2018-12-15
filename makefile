Movie-analytics: main.o fichier.o
	gcc main.o fichier.o -o Movie-analytics

main.o:
		gcc -c main.c

ouvrir_fichier.o:
	gcc -c fichier.c

clean:
	rm *.o Movie-analytics
