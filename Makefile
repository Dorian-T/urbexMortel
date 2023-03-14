B_PATH = src/core/building/
B_HEADERS = $(B_PATH)Building.h $(B_PATH)Room.h
B_OBJ = obj/Building.o obj/Room.o

E_PATH = src/core/entity/
E_HEADERS = $(E_PATH)Vector2D.h $(E_PATH)Entity.h $(E_PATH)Player.h
E_OBJ = obj/Vector2D.o obj/Entity.o obj/Player.o

T_PATH = src/txt/
T_HEADERS = $(T_PATH)winTxt.h $(T_PATH)txtGame.h
T_OBJ = obj/winTxt.o obj/txtGame.o

all: bin/tests bin/main_txt

bin/tests: obj/tests.o obj/Room.o $(E_OBJ)
	g++ -g -Wall obj/tests.o obj/Room.o $(E_OBJ) -o bin/tests

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

obj/txtGame.o: $(T_PATH)txtGame.h $(T_PATH)txtGame.cpp src/core/Game.h 
	g++ -g -Wall -c $(T_PATH)txtGame.cpp -o obj/txtGame.o

obj/main_txt.o: src/txt/main_txt.cpp $(T_PATH)winTxt.h $(T_PATH)txtGame.h src/core/Game.h
	g++ -g -Wall -c src/txt/main_txt.cpp -o obj/main_txt.o

bin/main_txt: obj/main_txt.o $(T_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o
	g++ -g -Wall obj/main_txt.o $(T_OBJ) $(E_OBJ) $(B_OBJ) obj/Game.o -o bin/main_txt

clean:
	rm -f obj/*.o

veryclean:
	rm -f bin/*