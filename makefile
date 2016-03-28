APP = bin/test_engine

GAME.O = build/game.o
GSM.O = build/gsm.o
STATE.O = build/state.o

MAIN.O = build/main.o
FIRST_STATE.O = build/first_state.o
SECOND_STATE.O = build/second_state.o

LIBGAME.A = lib/libgame.a

GAME.CPP = engine/GSM/src/game.cpp
GSM.CPP = engine/GSM/src/gsm.cpp
STATE.CPP = engine/GSM/src/state.cpp

MAIN.CPP = src/game/main.cpp
FIRST_STATE.CPP = src/states/src/first_state.cpp
SECOND_STATE.CPP = src/states/src/second_state.cpp

all: engine game

game: main.o first_state.o second_state.o
	g++ -o $(APP) $(MAIN.O) $(FIRST_STATE.O) $(SECOND_STATE.O) -L lib -lgame -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c -o $(MAIN.O) $(MAIN.CPP)

first_state.o:
	g++ -c -o $(FIRST_STATE.O) $(FIRST_STATE.CPP)

second_state.o:
	g++ -c -o $(SECOND_STATE.O) $(SECOND_STATE.CPP)

engine: libgame.a

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
