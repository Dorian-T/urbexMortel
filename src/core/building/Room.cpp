#include "Room.h"
#include "../entity/Vector2D.h"
#include "Building.h"

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <unistd.h>

using namespace std;


Room::Room(const std::string & filename) {
	ifstream file;
	file.open(filename);
	if(file.is_open()) {
		file >> dimX;
		file >> dimY;
		file >> time;
		arrayObstacle.resize(dimX*dimY);
		char tmp;
		for(unsigned int y = 0; y < dimY; y++)
			for(unsigned int x = 0; x < dimX; x++) {
				file >> tmp;
				if(tmp == 'R') {
					arrayRat.push_back(Vector2D(x, y));
					arrayObstacle[y*dimX + x] = nothing;
				}
				else if(tmp == 'S') {
					arraySpider.push_back(Vector2D(x, y));
					arrayObstacle[y*dimX + x] = nothing;
				}
				else
					arrayObstacle[y*dimX + x] = (Obstacle)tmp;
			}
	}
	else
		cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
	file.close();
}

unsigned int Room::getDimX() const {
	return dimX;
}

unsigned int Room::getDimY() const {
	return dimY;
}

Obstacle Room::getObstacle(const Vector2D & V) const {
	assert(V.getY() < dimY && V.getX() < dimX);
	return arrayObstacle[V.getY()*dimX + V.getX()];
}

void Room::setObstacle(const Vector2D & V, Obstacle o) {
	assert(V.getY() < dimY && V.getX() < dimX);
	arrayObstacle[V.getY()*dimX + V.getX()] = o;
}

unsigned int Room::getTime() const {
	return time;
}

unsigned int Room::getNbRat() const {
	return arrayRat.size();
}

Vector2D* Room::getRat(unsigned int i) {
	assert(i < arrayRat.size());
	return &arrayRat[i];
}

unsigned int Room::getNbSpider() const {
	return arraySpider.size();
}

Vector2D* Room::getSpider(unsigned int i) {
	assert(i < arraySpider.size());
	return &arraySpider[i];
}

void Room::regressionTest() {
	cout << endl << "la classe Room" << endl;

	char o1, o2;
	assert(dimX == 6 && dimY == 9);
	assert(arrayObstacle.capacity() == 6*9 && arrayObstacle.size() == 6*9);
	assert(time == 1000);
	ifstream file(PATH_ROOMS + "test.txt");
	file >> o1; file >> o1; file >> o1; file >> o1; file >> o1; file >> o1;
	for(unsigned int y = 0; y < dimY; y++)
		for(unsigned int x = 0; x < dimX; x++) {
			file >> o1;
			o2 = (char) arrayObstacle[y*dimX + x];
			assert(o1 == o2 || (o1 == 'R' && o2 == '.') || (o1 == 'S' && o2 == '.'));
		}
	assert(arrayRat.size() == 1); assert(arrayRat[0].getX() == 1 && arrayRat[0].getY() == 1);
	assert(arraySpider.size() == 1); assert(arraySpider[0].getX() == 2 && arraySpider[0].getY() == 0);
	cout << "\tTest du constructeur depuis un fichier : OK" << endl;

	assert(getDimX() == dimX);
	assert(getDimY() == dimY);
	cout << "\tgetDimX et getDimY : OK" << endl;

	assert(getObstacle(Vector2D(0, 0)) == arrayObstacle[0]);
	cout << "\tgetObstacle : OK" << endl;

	setObstacle(Vector2D(0, 0), ladder);
	assert(getObstacle(Vector2D(0, 0)) == ladder);
	cout << "\tsetObstacle : OK" << endl;

	assert(getTime() == time);
	cout << "\tgetTime : OK" << endl;

	assert(getNbRat() == arrayRat.size());
	cout << "\tgetNbRat : OK" << endl;

	assert(getRat(0)->getX() == arrayRat[0].getX() && getRat(0)->getY() == arrayRat[0].getY());
	cout << "\tgetRat : OK" << endl;

	assert(getNbSpider() == arraySpider.size());
	cout << "\tgetNbSpider : OK" << endl;

	assert(getSpider(0)->getX() == arraySpider[0].getX() && getSpider(0)->getY() == arraySpider[0].getY());
	cout << "\tgetSpider : OK" << endl;

	cout << "la classe Room : OK" << endl;
}