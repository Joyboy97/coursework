/*
 * MainDLL.cpp
 *
 *  Created on: Mar 10, 2022
 *      Author: winne
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "TaskManager.hpp"
using namespace std;

int main() {
	srand(time(NULL));
	TaskManager *list = new TaskManager("ListofTasks.txt");
}

