APP = bin/test_engine

MAIN.O = build/main.o
GAME.O = build/game.o
GSM.O = build/gsm.o
WINDOW.O = build/window.o

LIBGAME.A = lib/libgame.a

MAIN.CPP = game/main.cpp
GAME.CPP = engine/src/game.cpp
GSM.CPP = engine/src/gsm.cpp
WINDOW.CPP = engine/src/window.cpp

all: engine game

game: main.o
	g++ -o $(APP) $(MAIN.CPP) -L lib -lgame

engine: libgame.a

main.o:
	g++ -c -o $(MAIN.O) $(MAIN.CPP)

libgame.a: game.o gsm.o window.o
	ar cr $(LIBGAME.A) $(GAME.O) $(GSM.O) $(WINDOW.O)

game.o:
	g++ -c -o $(GAME.O) $(GAME.CPP)

gsm.o:
	g++ -c -o $(GSM.O) $(GSM.CPP)

window.o:
	g++ -c -o $(WINDOW.O) $(WINDOW.CPP)

clean:
	rm -f build/*

cleanall: clean
	rm -f bin/*
	rm -f lib/*
