/*
 * DogClass.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: winne
 */


#include "Dog.hpp"
#include <iostream>
#include <string.h>
using namespace std;

Dog::Dog(string n) {
	// TODO Auto-generated constructor stub
	name=n;
	strength=50;
	x=0;
	y=0;
}

Dog::Dog() {
	// TODO Auto-generated destructor stub
	name="Connor";
	strength=50;
	x=0;
	y=0;
}
bool Dog::changeStrength(int amt){
	strength+=amt;
	//cout<<amt<<" the amt"<<endl;
	printDog();
	if(strength<=0){
		die();
		return false;
	}else
		return true;
}
void Dog::die(){
	if(strength<=0)
		cout<<"*Dying animal noise*"<<endl<<name<<"'s race is run :^("<<endl;
}
void Dog::printDog(){
		cout<<"This pet's name is "<<name<<endl<<"Its strength is "<<strength<<endl;
}
void Dog::won(){
	cout<<name<<" wins!!!"<<endl;
}
void Dog::reset(){
	strength=50;
	x=0;
	y=0;
}



