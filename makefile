All: hormiguero  programa
hormiguero: command.o game_loop.o game.o graphic_engine.o space.o game_reader.o player.o object.o set.o
	@gcc -o hormiguero command.o game_loop.o game.o graphic_engine.o space.o game_reader.o player.o object.o libscreen.a set.o
	
command.o: command.c command.h
	@gcc -c -Wall -ansi -pedantic command.c
	
player.o: player.c player.h types.h object.h
	@gcc -c -Wall -ansi -pedantic player.c

object.o: object.c object.h types.h 
	@gcc -c -Wall -ansi -pedantic object.c
        
game_loop.o: game_loop.c graphic_engine.h game.h command.h game_reader.h
	@gcc -c -Wall -ansi -pedantic game_loop.c
        
game.o: game.c game.h player.h object.h types.h space.h command.h
	@gcc -c -Wall -ansi -pedantic game.c
        
graphic_engine.o: graphic_engine.c libscreen.h graphic_engine.h command.h space.h types.h
	@gcc -c -Wall -ansi -pedantic -ansi -pedantic graphic_engine.c

space.o: space.c space.h object.h types.h set.h
	@gcc -c -Wall -ansi -pedantic space.c

game_reader.o: game_reader.c game.h game_reader.h
	@gcc -c -Wall -ansi -pedantic game_reader.c

set.o:set.c set.h object.o
	@gcc -c -Wall -ansi -pedantic set.c
	
programa: hormiguero
	./hormiguero hormiguero.dat
	
clean: 
	@rm  -f  hormiguero *.o 
