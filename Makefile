all: bin/tests

bin/tests: obj/tests.o obj/Vector2D.o obj/Entity.o
	g++ -g -Wall obj/tests.o obj/Vector2D.o obj/Entity.o -o bin/tests

obj/tests.o: src/core/tests.cpp src/core/Vector2D.h src/core/Entity.h
	g++ -g -Wall -c src/core/tests.cpp -o obj/tests.o

obj/Vector2D.o: src/core/Vector2D.cpp src/core/Vector2D.h 
	g++ -g -Wall -c src/core/Vector2D.cpp -o obj/Vector2D.o

obj/Entity.o: src/core/Entity.h src/core/Entity.cpp src/core/Vector2D.h src/core/Room.h
	g++ -g -Wall -c src/core/Entity.cpp -o obj/Entity.o

clean:
	rm -f obj/*.o
	rm -f bin/*