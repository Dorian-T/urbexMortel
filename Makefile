B_PATH = src/core/building/
E_PATH = src/core/entity/

all: bin/tests

bin/tests: obj/tests.o obj/Vector2D.o obj/Entity.o obj/Room.o
	g++ -g -Wall obj/tests.o obj/Vector2D.o obj/Entity.o obj/Room.o -o bin/tests

obj/tests.o: src/core/tests.cpp src/core/Vector2D.h $(E_PATH)Entity.h $(B_PATH)Room.h
	g++ -g -Wall -c src/core/tests.cpp -o obj/tests.o

obj/Vector2D.o: src/core/Vector2D.cpp src/core/Vector2D.h 
	g++ -g -Wall -c src/core/Vector2D.cpp -o obj/Vector2D.o

obj/Entity.o: $(E_PATH)Entity.h $(E_PATH)Entity.cpp src/core/Vector2D.h $(B_PATH)Room.h
	g++ -g -Wall -c $(E_PATH)Entity.cpp -o obj/Entity.o

obj/Room.o: $(B_PATH)Room.h $(B_PATH)Room.cpp $(E_PATH)Entity.h src/core/Vector2D.h
	g++ -g -Wall -c $(B_PATH)Room.cpp -o obj/Room.o

clean:
	rm -f obj/*.o bin/*