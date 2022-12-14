/*
 * BST.hpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
 */

#ifndef BST_HPP_
#define BST_HPP_
//#include "Phrase.hpp"
#include "TNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class BST {
	friend class Abbr;
	TNode *root;

public:
	BST();
	BST(string s, string l);  // updated
	bool insert(string s, string l);  //updated
	TNode *find(string s);
	void printTreeIO();
	void printTreeIO(TNode *n);
	void printTreePre();
	void printTreePre(TNode *n);
	void printTreePost();
	void printTreePost(TNode *n);
	void clearTree();
	void clearTree(TNode *tmp);
	TNode *removeNoKids(TNode *tmp);
	TNode *removeOneKid(TNode *tmp, bool leftFlag);
	TNode *remove(string s);
	void setHeight(TNode *n);

};






#endif /* BST_HPP_ */
