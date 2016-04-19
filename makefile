APP = bin/test_engine

GAME.O = build/game.o
GSM.O = build/gsm.o
STATE.O = build/state.o

MAIN.O = build/main.o
FIRST_STATE.O = build/first_state.o
FIFTH_STAGE.O = build/fifth_stage.o
GROUND.O = build/ground.o
ROCKET.O = build/Rocket.o

ROCKET_NASA_SLS.O = build/RocketNasaSls.o
FOURTH_STAGE.O = build/FourthStage.o
THIRD_STAGE.O = build/ThirdStage.o
SECOND_STAGE.O = build/SecondStage.o
FIRST_STAGE_LEFT.O = build/FirstStageLeft.o
FIRST_STAGE_RIGHT.O = build/FirstStageRight.o
BODY.O = build/Body.o
ROCKET_SEGMENT.O = build/RocketSegment.o
CREATE_GROUND.O = build/CreateGround.o
BIG_BODY.O = build/BigBody.o
DRAW_BACKGROUND.O = build/DrawBackground.o

LIBGAME.A = lib/libgame.a

GAME.CPP = engine/game.cpp
GSM.CPP = engine/GSM/src/gsm.cpp
STATE.CPP = engine/GSM/src/state.cpp

MAIN.CPP = src/main.cpp
FIRST_STATE.CPP = src/states/FirstState.cpp
CREATE_GROUND.CPP = src/states/CreateGround.cpp
DRAW_BACKGROUND.CPP = src/states/DrawBackground.cpp


ROCKET_NASA_SLS.CPP = src/rockets/RocketNasaSls.cpp
FOURTH_STAGE.CPP = src/rockets/FourthStage.cpp
THIRD_STAGE.CPP = src/rockets/ThirdStage.cpp
SECOND_STAGE.CPP = src/rockets/SecondStage.cpp
FIRST_STAGE_LEFT.CPP = src/rockets/FirstStageLeft.cpp
FIRST_STAGE_RIGHT.CPP = src/rockets/FirstStageRight.cpp
BODY.CPP = src/bodyes/Body.cpp
BIG_BODY.CPP = src/bodyes/BigBody.cpp
ROCKET_SEGMENT.CPP = src/bodyes/RocketSegment.cpp

all: engine game

game: main.o \
			first_state.o \
			rocket_nasa_sls.o \
			fourth_stage.o \
			third_stage.o \
			second_stage.o \
			first_stage_left.o \
			first_stage_right.o \
			body.o \
			rocket_segment.o \
			create_ground.o \
			big_body.o \
			draw_background
	g++ -o $(APP) $(MAIN.O) $(FIRST_STATE.O) $(ROCKET_NASA_SLS.O) \
				 $(FOURTH_STAGE.O) $(THIRD_STAGE.O) $(SECOND_STAGE.O) \
				 $(FIRST_STAGE_LEFT.O) $(FIRST_STAGE_RIGHT.O) $(BODY.O) \
				 $(ROCKET_SEGMENT.O)  $(BIG_BODY.O) $(CREATE_GROUND.O) \
				 $(DRAW_BACKGROUND.O) \
				 -L lib -lgame -lBox2D -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c -o $(MAIN.O) $(MAIN.CPP)

draw_background:
	g++ -c -o $(DRAW_BACKGROUND.O) $(DRAW_BACKGROUND.CPP)

create_ground.o:
	g++ -c -o $(CREATE_GROUND.O) $(CREATE_GROUND.CPP)

big_body.o:
	g++ -c -o $(BIG_BODY.O) $(BIG_BODY.CPP)


first_state.o:
	g++ -c -o $(FIRST_STATE.O) $(FIRST_STATE.CPP)

rocket_nasa_sls.o:
	g++ -c -o $(ROCKET_NASA_SLS.O) $(ROCKET_NASA_SLS.CPP)

fourth_stage.o:
	g++ -c -o $(FOURTH_STAGE.O) $(FOURTH_STAGE.CPP)

third_stage.o:
	g++ -c -o $(THIRD_STAGE.O) $(THIRD_STAGE.CPP)

second_stage.o:
	g++ -c -o $(SECOND_STAGE.O) $(SECOND_STAGE.CPP)

first_stage_left.o:
	g++ -c -o $(FIRST_STAGE_LEFT.O) $(FIRST_STAGE_LEFT.CPP)

first_stage_right.o:
	g++ -c -o $(FIRST_STAGE_RIGHT.O) $(FIRST_STAGE_RIGHT.CPP)

body.o:
	g++ -c -o $(BODY.O) $(BODY.CPP)

rocket_segment.o:
	g++ -c -o $(ROCKET_SEGMENT.O) $(ROCKET_SEGMENT.CPP)


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
