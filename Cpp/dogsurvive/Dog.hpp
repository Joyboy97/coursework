/*
 * DogClass.h
 *
 *  Created on: Feb 25, 2022
 *      Author: winne
 */

#ifndef DOG_HPP_
#define DOG_HPP_
#include <iostream>
#include <string.h>
using namespace std;
class Dog{
	string name; // for the dog's name
	int strength; //for the dog's current strength
	int x; // the x coordinate of where the dog is currently on the board
	int y; // the y coordinate of where the dog is currently on the board

public:
	friend class Board;
	Dog(string n);
	Dog();
	bool changeStrength(int);
	void die(); //die message when strength at or below 0
	void printDog(); // prints out info about dog
	void won(); //won message for when dog is at end of evil forest
	void reset(); //resets dog for restarting a new game

};

#endif /* DOG_HPP_ */
