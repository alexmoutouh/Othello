othello: main.o display.o game.o init.o menu.o handle.o score.o 
	gcc -g -Wall -o othello main.o init.o display.o game.o menu.o handle.o score.o

handle.o: init.h display.h game.h menu.h handle.h score.h
	gcc -g -c -Wall handle.c 
main.o: main.c 
	gcc -g -c -Wall main.c 

menu.o: menu.c menu.h
	gcc -g -c -Wall menu.c

game.o: game.c game.h 
	gcc -g -c -Wall game.c

display.o: display.c display.h 
	gcc -g -c -Wall display.c

init.o: init.c init.h 
	gcc -g -c -Wall init.c

score.o: score.c score.h
	gcc -g -c -Wall score.c

clean:	
	rm *.o
