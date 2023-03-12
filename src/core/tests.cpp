#include "Vector2D.h"
#include "entity/Entity.h"
#include "building/Room.h"

#include <iostream> // provisoir
#include <fstream>
#include <string.h>
using namespace std;

int main () {

	Vector2D V;
	V.regressionTest();

	Entity E;
	E.regressionTest();

	Room R("data/room1.txt");
	for(int i = 0; i < R.getDimY(); i++) {
		for(int j = 0; j < R.getDimX(); j++) {
			cout << R.getObstacle(Vector2D(j,i)) << " ";
		}
		cout << endl;
	}

	return 0;
}