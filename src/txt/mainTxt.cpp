#include "winTxt.h"
#include "gameTxt.h"
#include "../core/Game.h"

#include <time.h>
#include <iostream>

using namespace std;

int chooseDifficulty() {
	int diff;
	cout<<"Choisissez la difficulté :"<<endl;
	cout<<"1. Facile"<<endl;
	cout<<"2. Moyen"<<endl;
	cout<<"3. Difficile"<<endl;
	cin>>diff;
	return diff;
}

int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	unsigned int d = chooseDifficulty();
	Game ga;
	if (d==1)
	{
		ga.getBuilding()->setTimetot(ga.getBuilding()->getTimetot()*20);
	}
	else if (d==2)
	{
		ga.getBuilding()->setTimetot(ga.getBuilding()->getTimetot()*15);
	}
	else if (d==3)
	{
		ga.getBuilding()->setTimetot(ga.getBuilding()->getTimetot()*10);
	}
	txtLoop(ga);
    termClear();
	if(ga.getPlayer()->getHp()==0 || ga.getBuilding()->getTimetot()==0) cout << "T'es mort, nul !" << endl ;
	else cout << "Bravo ! T'es pas nul." << endl ;
	return 0;
}
