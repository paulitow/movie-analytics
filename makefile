Movie-analytics: main.o
	gcc main.o -o Movie-analytics

main.o:
	gcc -c main.c


clean:
	rm *.o Movie-analytics
	echo "mamen"
