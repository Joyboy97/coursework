/*
 * BoardClass.cpp
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

Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	while (keepPlaying) {
		string cat="no";
		cout <<endl<< "Dog Survival!!"<<endl<<" Do you need a game description?"<<endl;
		cin>>cat;
		if (cat == "yes" || cat == "Yes" || cat == "Y" ||cat == "y")
			cout<<"Description:"<<endl<<"In this game you will put your dog to the test by running it through a maze!!"<<endl<<"Be weary this is no ordinary maze!!!"<<endl<<"You must get your dog from the left to the right end exit of the maze to win!!"<<endl<<"But be careful with your moves, your dog only has so much energy!!"<<endl<<"Traps(T) and walls( | , _ ) will take from your energy but food will boost it!!"<<endl<<"Set the difficulty to v for a surprise also known as extra credit worthy pizzaz XD" << endl<<"Are you ready for this?"<<endl<<endl;
		cout << "What level of difficulty do you want (e, m, h, or v)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		endx = rand() % size;
		starty = 0;
		endy = size-1;
		mydog.x = startx;
		mydog.y = starty;
		if(level=='v'){
			cout << "You have entered 2 player mode!!"<<endl<<"Choose your challenger!!" << endl<<"This is a verses mode, you will be trying to escape a dog's worst enemy!!"<<endl<<"A Cat(C)!!!"<<endl<<"Name your adversary: ";
			cin >> cat;
			mycat.name=cat;
			while(startx==endx){
				startx = rand() % size;
				endx = rand() % size;
			}
			mydog.x = startx;
			mycat.x = startx;
			mycat.y = endy;
			mycat.changeStrength(-30);
		}
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		playGame();
		cout << "Play again? " << endl;
		string s = "no";
		cin>>s;
		if (s == "yes" || s == "Yes" || s == "Y" ||s == "y") {
			keepPlaying = true;
			mydog.reset();
			if(level=='v')
				mycat.reset();
		}
		else {
			cout <<"Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
}
void Board::playGame() {
	bool play = true;
	while (play) {
			if(level=='v')
				cout << mydog.name<<"'s ";
			if(debug)
				cout << "Move (w, s, a, d) "<<endl;
			else
				cout << "Move (u, d, l, r) "<<endl;
			char c;
			cin >> c;
			play = moveDog(c);
			printBoard();
			if(level=='v'&&mydog.strength>0){
				cout << mycat.name<<"'s Move (o, l, k, ;)"<<endl;
				cin >> c;
				play = moveDog(c);
				printBoard();
			}
	}
}
void Board::addFood() {

		int f,rx,ry;
		if(level=='e')
			f=size;
		else if(level=='m')
			f=size-2;
		else if(level=='h')
			f=size-4;
		else
			f=size;
		for(int i=0;i<f;i++){
			while(board[ry][rx]!=' '){
				rx=rand()%size;
				ry=rand()%size;
			}
		board[ry][rx]='F';
		}
}
void Board::addTraps() {
	if(debug){
		int t,rx,ry;
		if(level=='e')
			t=size-10;
		else if(level=='m')
			t=size-8;
		else if(level=='h')
			t=size-6;
		for(int i=0;i<t;i++){
			while(board[ry][rx]!=' '){
				rx=rand()%size;
				ry=rand()%size;
			}
		board[ry][rx]='T';
		}
	}
}
void Board::boardConfig() {
	int vw=size/5,hw=(size/5)*2,rx=0,ry=0,r,w;
	if(level=='e')
		w=9;
	else if(level=='m')
		w=13;
	else if(level=='h')
		w=16;
	else
		w=14;

	for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				board[i][j]=' ';
				}
			}


		for(int i=0;i<vw;i++){
			rx=rand()%size;
			while(rx%2==0)
					rx=rand()%size;
			for(int j=0;j<w;j++){
				ry=rand()%size;
			if(board[ry][rx]==' ')
				board[ry][rx]='|';
			}
		}

		for(int i=0;i<hw;i++){
				r=rand()%size;
				while(ry==r||r%2==1)
					r=rand()%size;
				ry=r;
				for(int j=0;j<w;j++){
					rx=rand()%size;
					if(board[ry][rx]==' ')
						board[ry][rx]='_';
				}
			}
		board[startx][starty]='D';
		board[endx][endy]='E';
		if(level=='v'){
			temp=board[startx][endy];
			board[startx][endy]='C';
		}
}
void Board::printBoard() {
//	mydog.printDog();
//	if(debug){
//		for(int i=0;i<size+1;i++){
//					for(int j=0;j<size;j++){
//						if(i==0||i==size){
//							cout<<" _";
//						}else if(j==0){
//							cout<<"| "<<board[i-1][j]<<" ";
//						}else if(board[i][j]=='D')
//							cout<<"->"<<board[i-1][j];
//						else if(board[i][j]=='E')
//							cout<<board[i-1][j]<<"->";
//						else
//							cout<<board[i-1][j]<<" ";
//					}
//					cout<<"|"<<endl;
//				}
//
//	}else{
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
					if(board[i][j]=='E')
						cout<<board[i][j]<<"<< Escape here";
					else
					cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	//}
}
bool Board::moveDog(char c) {
	string s;
	bool t;
	//"Move (u, d, l, r) "
	//Move(w,s,a,d)
	if(!debug){
		if(c=='r'){

		//cout<<c<<" this is c"<<endl;
		if(mydog.y+1<size){
			board[mydog.x][mydog.y]=' ';
			mydog.y++;
		}
		//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
	}else if(c=='l'){
		//cout<<c<<" this is c"<<endl;
		if(mydog.y-1>0){
			board[mydog.x][mydog.y]=' ';
			mydog.y--;
		}
		//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
	}else if(c=='u'){
		//cout<<c<<" this is c"<<endl;
		if(mydog.x-1>0){
			board[mydog.x][mydog.y]=' ';
			mydog.x--;
		}
		//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
	}else if(c=='d'){
		//cout<<c<<" this is c"<<endl;
		if(mydog.x+1<size){
			board[mydog.x][mydog.y]=' ';
			mydog.x++;
		}
		//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
	}
	}else if(debug){
		if(c=='d'){

				//cout<<c<<" this is c"<<endl;
				if(mydog.y+1<size){
					board[mydog.x][mydog.y]=' ';
					mydog.y++;

				}
				//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
			}else if(c=='a'){
				//cout<<c<<" this is c"<<endl;
				if(mydog.y-1>0){
					board[mydog.x][mydog.y]=' ';
					mydog.y--;
				}
				//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
			}else if(c=='w'){
				//cout<<c<<" this is c"<<endl;
				if(mydog.x-1>0){
					board[mydog.x][mydog.y]=' ';
					mydog.x--;
				}
				//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
			}else if(c=='s'){
				//cout<<c<<" this is c"<<endl;
				if(mydog.x+1<size){
					board[mydog.x][mydog.y]=' ';
					mydog.x++;
				}
				//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
			}
	}
	if(level=='v'){
		board[mycat.x][mycat.y]=temp;
		if(c=='k'){
			//cout<<c<<" this is c"<<endl;
			if(mycat.y-1>0){
				temp=board[mycat.x][mycat.y-1];
				mycat.y--;
				if(mycat.strength>0){
					board[mycat.x][mycat.y]='C';
					mycat.changeStrength(-1);
				}
			}
			//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
		}else if(c==';'){
				//cout<<c<<" this is c"<<endl;
			if(mycat.y+1<size){
				temp=board[mycat.x][mycat.y++];
				mycat.y++;
				if(mycat.strength>0){
					board[mycat.x][mycat.y]='C';
					mycat.changeStrength(-1);
				}
			}
			//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
		}else if(c=='k'){
			//cout<<c<<" this is c"<<endl;
			if(mycat.x+1<size){
				temp=board[mycat.x+1][mycat.y];
				mycat.x++;
				if(mycat.strength>0){
					board[mycat.x][mycat.y]='C';
					mycat.changeStrength(-1);
				}
			}
			//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
		}else if(c=='o'){
			//cout<<c<<" this is c"<<endl;
			if(mycat.x-1>0){
				temp=board[mycat.x-1][mycat.y];
				mycat.x--;
				if(mycat.strength>0){
					board[mycat.x][mycat.y]='C';
					mycat.changeStrength(-1);
				}
			}
			//cout<<board[mydog.x][mydog.y]<<" cor ("<<mydog.x<<","<<mydog.y<<")"<<endl;
		}
	}

	if(board[mydog.x][mydog.y]=='F'){
		board[mydog.x][mydog.y]='D';
		t=mydog.changeStrength(rand()%15+2);
	}
	else if(board[mydog.x][mydog.y]=='T'){
		board[mydog.x][mydog.y]='D';
		t= mydog.changeStrength(-(rand()%15+2));
	}
	else if(board[mydog.x][mydog.y]=='_'||board[mydog.x][mydog.y]=='|'){
		cout<<"would you like to break this wall?"<<endl;
		cin>>s;
			if(s=="Yes"||s=="yes"||s=="y"){
				board[mydog.x][mydog.y]='D';
				t=mydog.changeStrength(-wallStrength);
			}else{
				board[mydog.x][mydog.y]='D';
				t=mydog.changeStrength(-1);
			}
	}
	else if(board[mydog.x][mydog.y]==' '){
		board[mydog.x][mydog.y]='D';
		t=mydog.changeStrength(-2);
	}

	else if(mydog.x==0||mydog.y==0||mydog.x==size||mydog.y==size){
		//cout<<"cant move coor "<<"("<<mydog.x<<","<<mydog.y<<")"<<endl;
		t=true;
	}else if(board[mydog.x][mydog.y]=='C'){
		board[mydog.x][mydog.y]='D';
		t= mydog.changeStrength(-mycat.strength);
	}else if(board[mydog.x][mydog.y]=='E'){
		mydog.won();
		t=false;
	}
	if(level=='v'&&mycat.strength>0&&mydog.strength<=0){
		mycat.won();
		t=false;
	}
	return t;
//		else{v

//		cout<<" sum aint right "<<endl;
//		return false;
//	}
}

