#include "entity/Vector2D.h"
#include "entity/Entity.h"
#include "entity/Player.h"
#include "building/Room.h"
#include "building/Building.h"

int main () {

	Vector2D V;
	V.regressionTest();

	Entity E;
	E.regressionTest();

	Player P;
	P.regressionTest();

	Room R;
	R.regressionTest();

	Building B(10);
	B.regressionTest();

	return 0;
}