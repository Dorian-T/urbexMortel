#include "Player.h"

#include <assert.h>
#include <iostream>

using namespace std;


// Constructeur :

Player::Player(const Vector2D & P, Skin s, unsigned int health): Entity(P, 2, 1) {
	skin = s;
	hp = health;
	timeInvincible = 0;
	orientation = true;
}


// Accesseurs et mutateurs :

Skin Player::getSkin() const {
	return skin;
}

void Player::setSkin(Skin S) {
	skin = S;
}

bool Player::decreaseHp(unsigned int h) {
	if(timeInvincible == 0) {
		if(hp < h) hp = 0;
		else hp -= h;
		if(hp == 0)
			return false;
		else
			timeInvincible = 20; // a modifier
	}
	return true;
}

unsigned int Player::getHp() {
	return hp;
}

unsigned int Player::getTimeInvincible() {
	return timeInvincible;
}

void Player::decreaseTimeInvincible() {
	timeInvincible--;
}

bool Player::getOrientation() {
	return orientation;
}


// Déplacements :

void Player::up(Building & B) {
	if(standingOnBlock(*B.getCurrentRoom())) {
		Vector2D V;
		V.setX(getPosition().getX());
		if(getPosition().getY() > 1) {
			V.setY(getPosition().getY() - 1);
			int i = isMovePossibleUp(*B.getCurrentRoom(), V);
			if(i == -1) setPosition(V);
			else if(i > 0) decreaseHp(i);
			else if(i == -3) {
				V.setY(V.getY()-2);
				Obstacle o = B.getCurrentRoom()->getObstacle(V);
				if(o == barbedWire) decreaseHp(1);
				if(o == nothing) setPosition(V);
			}
		}
	}
}

int Player::isMovePossibleUp(const Room & R, const Vector2D & V) const {
	Vector2D tete(V.getX(), V.getY() - 1);
	if(tete.getY() > 0) {
		Obstacle o = R.getObstacle(tete);
		if(o == nothing || o == ladder ||o == fakeBlock) return -1;
		else if(o == barbedWire) return 1;
		else if(o == trapdoor) return -3;
	}
	return 0;
}

bool Player::right(Building & B) {
	Vector2D V;
	bool b = true;
	orientation = true;
	V.setY(getPosition().getY());
	V.setX(getPosition().getX() + 1);
	int i = isMovePossibleSide(*B.getCurrentRoom(), V);
	if(i == -1) setPosition(V);
	else if(i > 0) decreaseHp(i);
	else if(i == -2) {
		b = B.finishRoom();
		if(b) setPosition(Vector2D(1, B.getCurrentRoom()->getDimY()-2));
	}
	else if (i == -4) {
		setPosition(V);
		drinkPotion(B);
		B.getCurrentRoom()->setObstacle(V, nothing);
	}
	return b;
}

void Player::left(Building & B) {
	Vector2D V;
	orientation = false;
	V.setY(getPosition().getY());
	if(getPosition().getX() > 1) {
		V.setX(getPosition().getX() - 1);
		int i = isMovePossibleSide(*B.getCurrentRoom(), V);
		if(i == -1) setPosition(V);
		else if(i > 0) decreaseHp(i);
		else if (i == -4) {
			setPosition(V);
			drinkPotion(B);
			B.getCurrentRoom()->setObstacle(V,nothing);
		}
	}
}

int Player::isMovePossibleSide(const Room & R, const Vector2D & V) const {
	if(V.getX() < R.getDimX() && V.getX() > 0) {
		Vector2D tete(V.getX(), V.getY() - 1);
		Obstacle o1 = R.getObstacle(V);
		Obstacle o2 = R.getObstacle(tete);
		if((o1 == nothing || o1 == ladder || o1 == fakeBlock) && (o2 == nothing || o2 == ladder || o2 == fakeBlock)) return -1;
		else if(o1 == barbedWire || o2 == barbedWire) return 1;
		else if(o1 == door && o2 == door) return -2;
		else if (o1 == potion || o2 == potion) return -4;
	}
	return 0;
}

void Player::down(Building & B) {
	if(standingOnBlock(*B.getCurrentRoom())) {
		Vector2D V;
		V.setX(getPosition().getX());
		V.setY(getPosition().getY() + 1);
		int i = isMovePossibleDown(*B.getCurrentRoom(), V);
		if(i == -1) {
			setPosition(V);
		}
		else if(i > 0) decreaseHp(i);
		else if (i == -4) {
			setPosition (V);
			drinkPotion(B);
			B.getCurrentRoom()->setObstacle(V,nothing);
		}
	}
}

int Player::isMovePossibleDown(const Room & R, const Vector2D & V) const {
	if(V.getY() < R.getDimY()) {
		Obstacle o = R.getObstacle(V);
		if(o == nothing || o == trapdoor || o == ladder || o == fakeBlock) return -1;
		else if(o == barbedWire) return 1;
		else if (o == potion) return -4;
	}
	return 0;
}

void Player::gravity(const Room & R) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY());
	Obstacle o = R.getObstacle(V);
	if(o != ladder) {
		V.setY(getPosition().getY() + 1);
		int i = isMovePossibleGravity(R, V);
		if(i == -1) setPosition(V);
		else if(i > 0) decreaseHp(i);
	}
}

int Player::isMovePossibleGravity(const Room & R, const Vector2D & V) const {
	if(V.getY() < R.getDimY()) {
		Obstacle o = R.getObstacle(V);
		if(o == nothing || o == fakeBlock) return -1;
		else if(o == barbedWire) return 1;
	}
	return 0;
}

bool Player::standingOnBlock(const Room & R) const {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	Obstacle o = R.getObstacle(V);
	if(o == trapdoor || o == ladder || o == barbedWire || o == block || o == potion || o == ghostBlock)
		return true; 
	V.setY(getPosition().getY());
	o = R.getObstacle(V);
	if(o == ladder)
		return true;
	return false ;
}

void Player::StandingOnGhostBlock(Room & R) {
	if(standingOnBlock(R)) {		
		Vector2D V(getPosition().getX(), getPosition().getY() + 1);
		if(R.getObstacle(V) == ghostBlock)
			R.setObstacle(V, nothing);
	}
}


void Player::drinkPotion(Building & B) {
	unsigned int tt = B.getTotalTime();
	unsigned int tl = B.getTimeLeft();
	if(tl + 300 > tt) tl = tt;
	else tl += 300;
	B.setTimeLeft(tl);
}


void Player::regressionTest() { // a modifier
	cout << endl << "Test de la classe Player" << endl;

	assert(getPosition().getX() == 2 && getPosition().getY() == 3);
	assert(getHeight() == 2 && getWidth() == 1);
	assert(skin == dora), assert(hp == 3); assert(timeInvincible == 0); assert(orientation == true);
	cout << "\tconstructeur parametre : OK" << endl;

	assert(getSkin() == skin);
	cout << "\tgetSkin : OK" << endl;

	setSkin(gadget);
	assert(getSkin() == gadget);
	cout << "\tsetSkin : OK" << endl;

	assert(getHp() == hp);
	cout << "\tgetHp : OK" << endl;

	assert(decreaseHp(1) == true);
	assert(hp == 2);
	assert(timeInvincible == 20);
	decreaseTimeInvincible();
	assert(timeInvincible == 19);
	cout << "\tdecreaseTimeInvincible : OK" << endl;

	assert(decreaseHp(1) == true);
	assert(hp == 2);
	for(unsigned int i = 0; i < 19; i++)
		decreaseTimeInvincible();
	assert(decreaseHp(2) == false);
	assert(hp == 0);
	cout << "\tdecreaseHp : OK" << endl;

	assert(getTimeInvincible() == timeInvincible);
	cout << "\tgetTimeInvincible : OK" << endl;

	assert(getOrientation() == orientation);
	cout << "\tgetOrientation : OK" << endl;

	Building B(PATH_ROOMS + "test.txt");
	B.setTimeLeft(0);
	drinkPotion(B);
	assert(B.getTimeLeft() == 300);
	cout << "\tdrinkPotion : OK" << endl;

	// Les tests des déplacements sont effectués dans tests.cpp

	cout << "Test de la classe Player : OK" << endl;
}