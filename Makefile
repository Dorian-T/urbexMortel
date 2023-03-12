B_PATH = src/core/building/

E_PATH = src/core/entity/
E_HEADERS = $(E_PATH)Vector2D.h $(E_PATH)Entity.h $(E_PATH)Player.h
E_OBJ = obj/Vector2D.o obj/Entity.o obj/Player.o

all: bin/tests

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


obj/Room.o: $(B_PATH)Room.h $(B_PATH)Room.cpp $(E_HEADERS)
	g++ -g -Wall -c $(B_PATH)Room.cpp -o obj/Room.o

clean:
	rm -f obj/*.o bin/*