/*
 * hashedmap.cpp
 *
 *  Created on: Apr 28, 2022
 *      Author: winne
 */

#include "hashedmap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

hashedmap::hashedmap(bool hash1, bool coll1) {
	//cout<<"create map"<<endl;
	mapSize = 100;
	numKeys = 0;
	hashfn = hash1;
	collfn = coll1;
	map = new hashNode *[mapSize];
	for (int i = 0; i < mapSize; i++)
		map[i] = NULL;
	hashcoll = 0;
	collisions = 0;
	//cout<<"done map"<<endl;
}
void hashedmap::addKeyValue(string k, string v) {
	//cout<<"add value"<<endl;
	int index=getIndex(k);
	if (numKeys==0) {
		map[index]=new hashNode(k, v);
		first = k;
		numKeys++;
		//cout<<"first value"<<endl;
	}else if (map[index] == NULL) {
		//cout<<"new value"<<endl;
		map[index] = new hashNode(k, v);
		numKeys++;

	}else if (map[index]!=NULL&&map[index]->keyword == k) {
		//cout<<"same value "<<map[index]->keyword<<endl;
		bool different=true;
		for(int z=0;z<map[index]->currSize;z++){
			//cout<<"same val loop"<<endl;
			if(map[index]->values[z]==v){
				different=false;
				break;
			}
		}
		if(different){
			map[index]->addValue(v);
		}

	}else  if (map[index]!=NULL&&map[index]->keyword != k) {
		collisions++;
		numKeys++;

		if (collfn){
			//cout<<"collision value"<<endl;
			map[coll1(index, index, k)] = new hashNode(k, v);
		}else
			map[coll2(0, 0, k)] = new hashNode(k, v);

	}
	//cout<<"numkeys "<<numKeys<<"mapSize "<<mapSize<<" yer "<<(double)numKeys/(double)mapSize<<endl;
	if ((double)numKeys/(double)mapSize>=.7)
		reHash();
	//cout<<"done add"<<endl;
}
int hashedmap::getIndex(string k) {
	int index;
	if (hashfn)
		index = calcHash1(k);
	else
		index = calcHash2(k);
	//cout<<"out indy"<<endl;

	return index;
}

int hashedmap::calcHash2(string k) {
//	//myarrayhash
//	//cout<<"in calc2 "<<endl;
//	int i= 0,n,a[3],c=0;
//	unsigned int l=0;
//	if(k.size()>2){
//		for(l= 0;l<(k.size()/3) * 3; l++) {
//			//cout << "i=" << i << endl;
//			n = (int)k[l];
//			c = 0;
//			//cout << n << " [";
//			for (int d = 0; d < 3; d++) {
//				c += n % 10;
//				n /= 10;
//				//cout << c << " ";
//			}
//			//cout<<"] "<<l% 3 << " " << l << endl;
//			a[l % 3] = c;
//			if (l % 3 == 2)
//				i += a[0] * (a[1] + 1) + ((int)a[1] / a[2] * 10);
//			//cout << "i=" << i << endl;
//		}
//
//		//cout<<"Ya "<<k.size()%l<<endl;
//	}
//	//cout << l << endl;
//	l = k.size() - l;
//	//cout << l << " " << k.size() << endl;
//	if (l == 2) {
//		//cout << k[k.size() - l + 1] << "=" << (int)k[k.size() - l + 1] << " " << k[k.size() - l] << "=" << (int)k[k.size() - l + 1] << endl;
//		i +=(int) k[k.size() - l + 1] * (k[k.size() - l] + 1) + (k[k.size() - l] / k[k.size() - l + 1] * 10);
//		//i+=(int)k[c]%200;
//	}
//	else if (l == 1) {
//		//cout << k[k.size() - l] << "=" << (int)k[k.size() - l] << endl;
//		i += (int)k[k.size() - l];
//		//cout << "i=" << i << endl;
//	}
	//square +1 hash
	int i = 0;
		for (unsigned int l = 0; l < k.size(); l++)
			i += k[l]*k[l]+l;
	if (map[i % mapSize] != NULL)
		hashcoll++;

	return i % mapSize;
}
int hashedmap::calcHash1(string k) {
	//cout<<"in calc1 "<<endl;
	int i = 0;
	for (unsigned int l = 0; l < k.size(); l++)
		i += k[l];
	//cout<<"out calc1 "<<endl;
	if (map[i % mapSize] != NULL)
			hashcoll++;

	return i % mapSize;

}
void hashedmap::getClosestPrime() {
	int c = 2;
	bool p = false;
	while (!p) {
		for (c = 2; c < mapSize; c++) {
			if (mapSize % c == 0) {
				break;
			}
		}
		if (c == mapSize)
			p = true;
		else
			mapSize++;
	}
}
void hashedmap::reHash() {
	//int f=getIndex(first);
	int oldmapSize = mapSize;
	mapSize *= 2;
	int z;
	getClosestPrime();
	hashNode** tmp = map;
	map = new hashNode*[mapSize];
	for (int i = 0; i < mapSize; i++)
		map[i] = NULL;
	for (int i = 0; i < oldmapSize; i++) {
		if (tmp[i] != NULL){
			z=getIndex(tmp[i]->keyword);
			if(map[z]==NULL){
				for(int j =0;j<tmp[i]->currSize;j++){
					addKeyValue(tmp[i]->keyword, tmp[i]->values[j]);
				}
			}
		}
	}
	delete tmp;
}
int hashedmap::coll1(int h, int i, string k) {
//	//probe coll

	if (map[i] != NULL) {
		if (i == mapSize)
			i = 0;
		//cout<<"hey i "<<i+1<<" keyword "<<map[i]->keyword<<" index "<<h<<endl;
		return coll1(h, 1+i, k);

	}
	else
		return i % mapSize;
//		while(map[i]!=NULL&&h<mapSize){
//			i++;
//			if(i==mapSize)
//				i=0;
//			if(map[i]!=NULL)
//				h++;
//		}
//		return i;
}
int hashedmap::coll2(int h, int i, string k) {
	//quadratic probing

	for (unsigned int r = 0; r < k.size(); r++)
		h += k[r];
	//while(map[i + h % mapSize] != NULL)

	if (map[i + h % mapSize] != NULL)
		return coll2(h, pow(i, i), k);
	else
		return h + i % mapSize;
}

void hashedmap::printMap() {
	cout << "In printMap()" << endl;
	int i;
	for (i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize; j++) {
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;

		}
	}
//	int z=getIndex(first);
//	cout <<z<<endl;
//	for(int i=0;i<mapSize;i++){
//		if(map[i]!=NULL){
//			if(map[i]->keyword==first){
//				cout<<i<<" first"<<endl;
//			}
//		}
//	}
//
//	//for(int t=0;t<map[z]->currSize;t++)
//	if(map[z]==NULL){
//		cout<<"y null "<<mapSize<<" numkeys "<<numKeys<<endl;
//	}
//		//cout <<endl<<map[z]->values[0]<< endl;
}


