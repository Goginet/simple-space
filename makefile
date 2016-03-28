APP = bin/test_engine

MAIN.O = build/main.o
GAME.O = build/game.o
GSM.O = build/gsm.o
STATE.O = build/state.o

LIBGAME.A = lib/libgame.a

MAIN.CPP = game/main.cpp
GAME.CPP = engine/src/game.cpp
GSM.CPP = engine/src/gsm.cpp
STATE.CPP = engine/src/state.cpp

all: engine game

game: main.o
	g++ -o $(APP) $(MAIN.CPP) -L lib -lgame

engine: libgame.a

main.o:
	g++ -c -o $(MAIN.O) $(MAIN.CPP)

libgame.a: game.o gsm.o state.o
	ar cr $(LIBGAME.A) $(GAME.O) $(GSM.O) $(STATE.O)

game.o:
	g++ -c -o $(GAME.O) $(GAME.CPP)

gsm.o:
	g++ -c -o $(GSM.O) $(GSM.CPP)

state.o:
	g++ -c -o $(STATE.O) $(STATE.CPP)

clean:
	rm -f build/*

cleanall: clean
	rm -f bin/*
	rm -f lib/*