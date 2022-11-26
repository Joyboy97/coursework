/*
 * MainGame.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: winne
 */


#include "Board.hpp"
#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main() {
	srand(time(NULL));
	//set it to false to see the uldr move controls but I did not like them much so i used wasd
	//also the extra credit stuff is in the true version
	Board board('m',"fido", true);
	return 0;
}


