APP = "build/simple-space"

PLANET.O = build/Planet.cpp
MAIN.O =build/SimpleSpace.o

MAIN.CPP = src/SimpleSpace.cpp
PLANET.CPP = src/Planets/Planet.cpp

all:
	g++ -o ${APP} ${MAIN.CPP} ${PLANET.CPP} -L ../LGE/build -llge-game-manager -lsfml-audio -lsfml-graphics -lsfml-window -lBox2D -lsfml-system -std=c++11

main.o:
	g++ -o ${MAIN.O} ${MAIN.CPP} -std=c++11

planets.o:
	g++ -o ${PLANET.O} ${PLANET.CPP} -std=c++11
