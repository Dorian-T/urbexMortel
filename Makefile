E_PATH = src/core/entity/
E_HEADERS = $(E_PATH)Vector2D.h $(E_PATH)Entity.h $(E_PATH)Player.h
E_OBJ = obj/Vector2D.o obj/Entity.o obj/Player.o

B_PATH = src/core/building/
B_HEADERS = $(B_PATH)Building.h $(B_PATH)Room.h
B_OBJ = obj/Building.o obj/Room.o

T_PATH = src/txt/
T_HEADERS = $(T_PATH)winTxt.h $(T_PATH)gameTxt.h
T_OBJ = obj/winTxt.o obj/gameTxt.o

S_PATH = src/sfml/
S_HEADERS = $(S_PATH)gameSFML.h
S_OBJ = obj/gameSFML.o obj/mainSFML.o
SFML_O = -I/usr/include/SFML 
SFML_E = -lsfml-graphics -lsfml-window -lsfml-system


all: bin/tests bin/mainTxt bin/mainSFML


# tests

bin/tests: obj/tests.o $(E_OBJ) $(B_OBJ)
	g++ -g -Wall obj/tests.o $(E_OBJ) $(B_OBJ) -o bin/tests

obj/tests.o: src/core/tests.cpp $(B_PATH)Room.h $(E_HEADERS)
	g++ -g -Wall -c src/core/tests.cpp -o obj/tests.o


# Entity

obj/Vector2D.o: $(E_PATH)Vector2D.cpp $(E_PATH)Vector2D.h 
	g++ -g -Wall -c $(E_PATH)Vector2D.cpp -o obj/Vector2D.o

obj/Entity.o: $(E_PATH)Entity.h $(E_PATH)Entity.cpp $(E_PATH)Vector2D.h $(B_PATH)Room.h
	g++ -g -Wall -c $(E_PATH)Entity.cpp -o obj/Entity.o

obj/Player.o: $(E_PATH)Player.h $(E_PATH)Player.cpp $(E_PATH)Entity.h
	g++ -g -Wall -c $(E_PATH)Player.cpp -o obj/Player.o


# building 

obj/Building.o: $(B_PATH)Building.h $(B_PATH)Building.cpp $(B_PATH)Room.h 
	g++ -g -Wall -c $(B_PATH)Building.cpp -o obj/Building.o

obj/Room.o: $(B_PATH)Room.h $(B_PATH)Room.cpp $(E_HEADERS)
	g++ -g -Wall -c $(B_PATH)Room.cpp -o obj/Room.o


# autre

obj/Game.o: src/core/Game.h src/core/Game.cpp $(B_HEADERS) $(E_HEADERS)
	g++ -g -Wall -c src/core/Game.cpp -o obj/Game.o


# txt

obj/winTxt.o: $(T_PATH)winTxt.h $(T_PATH)winTxt.cpp 
	g++ -g -Wall -c $(T_PATH)winTxt.cpp -o obj/winTxt.o

obj/gameTxt.o: $(T_PATH)gameTxt.h $(T_PATH)gameTxt.cpp $(T_PATH)winTxt.h src/core/Game.h $(E_PATH)Vector2D.h
	g++ -g -Wall -c $(T_PATH)gameTxt.cpp -o obj/gameTxt.o

obj/mainTxt.o: src/txt/mainTxt.cpp $(T_PATH)winTxt.h $(T_PATH)gameTxt.h src/core/Game.h
	g++ -g -Wall -c src/txt/mainTxt.cpp -o obj/mainTxt.o

bin/mainTxt: obj/mainTxt.o $(T_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o
	g++ -g -Wall obj/mainTxt.o $(T_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o -o bin/mainTxt


# sfml

obj/gameSFML.o: $(S_PATH)gameSFML.h $(S_PATH)gameSFML.cpp src/core/Game.h $(E_PATH)Vector2D.h
	g++ -g -Wall -c $(S_PATH)gameSFML.cpp -o obj/gameSFML.o $(SFML_O)

obj/PlayerSFML.o: $(S_PATH)mainSFML.h $(S_PATH)mainSFML.cpp $(E_PATH)Player.h $(B_PATH)Building.h
	g++ -g -Wall -c $(S_PATH)PlayerSFML.cpp -o obj/PlayerSFML.o $(SFML_O)

obj/mainSFML.o: $(S_PATH)mainSFML.cpp $(S_HEADERS) src/core/Game.h $(E_PATH)Vector2D.h
	g++ -g -Wall -c $(S_PATH)mainSFML.cpp -o obj/mainSFML.o $(SFML_O)

bin/mainSFML: obj/mainSFML.o $(S_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o
	g++ -g -Wall -o bin/mainSFML $(S_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o $(SFML_E)


clean:
	rm -f obj/*.o

veryclean: clean
	rm -f bin/*