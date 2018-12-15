Movie-analytics: main.o
	gcc main.o ouvrir_fichier.o -o Movie-analytics

main.o:
	gcc -c main.c

ouvrir_fichier.o:
	gcc -c ouvrir_fichier.c

clean:
	rm *.o Movie-analytics
	echo "mamen"
