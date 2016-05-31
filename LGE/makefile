LIB = build/liblge-game-manager.a

GAME.O = build/Game.o
GSM.O = build/GSM.o
STATE.O = build/State.o
BUTTON.O = build/Button.o

GAME.CPP = src/GameManager/Game.cpp
GSM.CPP = src/GameManager/GSM.cpp
STATE.CPP = src/GameManager/State.cpp
BUTTON.CPP = src/GameManager/Button.cpp


game_manager: game.o gsm.o state.o button.o
	ar cr ${LIB} ${GAME.O} ${GSM.O} ${STATE.O} ${BUTTON.O}
	rm build/*.o

game.o:
	g++ -c -o ${GAME.O} ${GAME.CPP}

gsm.o:
	g++ -c -o ${GSM.O} ${GSM.CPP}

state.o:
	g++ -c -o ${STATE.O} ${STATE.CPP}

button.o:
	g++ -c -o ${BUTTON.O} ${BUTTON.CPP}

clean:
	rm build/*.o

cleanall:
	rm build/*
