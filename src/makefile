Movie-analytics: main.o base.o user.o
	gcc -Wall main.o base.o user.o -o ../Movie-analytics

main.o:
		gcc -c main.c

base.o:
	gcc -c base.c

user.o:
	gcc -c user.c
	
clean:
	rm *.o ../Movie-analytics
