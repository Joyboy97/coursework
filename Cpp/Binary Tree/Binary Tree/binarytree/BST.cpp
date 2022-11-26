/*
 * BST.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
 */


#include "BST.hpp"
#include "TNode.hpp"
#include "Phrase.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s, string l) {
	root = new TNode(s,l);
}

bool BST::insert(string s,string l) {
	 TNode *leaf= new TNode(s,l);
	 TNode *tmp=root;
	 bool t=false;
	 if(root==NULL){
		 root=leaf;
		 //setHeight(tmp);
		 t=true;
	 }else{
		 while(tmp!=NULL){
			if(tmp->data->abbr<s){
				if(tmp->right==NULL){
					tmp->right=leaf;
					leaf->parent=tmp;
					//cout<<"firstr"<<endl;
					tmp=leaf;
					setHeight(tmp);
					t=true;
					break;
				}else
					tmp=tmp->right;
			}else if(tmp->data->abbr>s){
				if(tmp->left==NULL){
					tmp->left=leaf;
					leaf->parent=tmp;
					tmp=leaf;
					setHeight(tmp);
					//cout<<"firstl"<<endl;
					t=true;
					break;
				}else
					tmp=tmp->left;
			}else
				break;
		 }
		 //setHeight(tmp);
	 /*tmp=tmp->parent;
	 if(tmp->data->abbr<s){
		 leaf->parent=tmp;
		tmp->right=leaf;


		t=true;
	 }else if(tmp->data->abbr>s){
		 leaf->parent=tmp;
		tmp->left= leaf;

		t=true;
	 }*/
	 }
	return t;
}

TNode *BST::find(string s) {
	TNode *tmp=root;
	while(tmp!=NULL){
		if(tmp->data->abbr<s){
			tmp=tmp->right;
		}else if(tmp->data->abbr>s){
			tmp=tmp->left;
		}else if(tmp->data->abbr==s){
			break;
		}
	}
	if(tmp!=NULL)
		return tmp;
	else
		return NULL;
}

void BST::setHeight(TNode *tmp) {
//	while(tmp!=root){
//		tmp->parent->height+=1;
//		tmp=tmp->parent;
//	}

	while(tmp!=root){
		if(tmp->parent->right!=NULL&&tmp->parent->left!=NULL){

			if(tmp->height>tmp->parent->left->height){
				tmp->parent->height=tmp->height+1;
				tmp=tmp->parent;
				//cout<<"left not null"<<endl;
			}else{
				tmp->parent->height=tmp->parent->left->height+1;
				tmp=tmp->parent;
			}
		}else if(tmp->parent->right==tmp){
			//cout<<"right not null"<<endl;d
					tmp->parent->height=tmp->height+1;
					tmp=tmp->parent;

		}else if(tmp->parent->left==tmp){
			//cout<<"left not null"<<endl;
			tmp->parent->height+=1;
			tmp=tmp->parent;
		}


	}
//	root=tmp
}
void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
void BST::printTreeIO(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}else {
		printTreeIO(tmp->left);
		tmp->printNode();
		printTreeIO(tmp->right);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}
void BST::printTreePre(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}else {
		tmp->printNode();
		printTreePre(tmp->left);
		printTreePre(tmp->right);
	}
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePost(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}else {
		printTreePost(tmp->left);
		printTreePost(tmp->right);
		tmp->printNode();
	}
}
void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		//tmp->printNode();  // for testing, comment back in
		delete(tmp);
	}
}

TNode *BST::removeNoKids(TNode *tmp) {
	//TNode *rm=find(tmp->data->abbr);
		//cout<<tmp->parent->left->data->abbr<<endl;
		if(tmp->parent->data->abbr>tmp->data->abbr){
			//cout<<tmp->data->abbr+" yuh"<<endl;
			tmp->parent->left=NULL;

		}else if(tmp->parent->data->abbr<tmp->data->abbr){
			tmp->parent->right=NULL;
		}
	return tmp;
}
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {
	if(leftFlag){
		if(tmp->parent->data->abbr>tmp->data->abbr){
			tmp->parent->left=tmp->left;
			tmp->left->parent=tmp->parent;
		}else if(tmp->parent->data->abbr<tmp->data->abbr){
			tmp->parent->right=tmp->left;
			tmp->left->parent=tmp->parent;
		}
	}else{
		if(tmp->parent->data->abbr>tmp->data->abbr){
			tmp->parent->left=tmp->right;
			tmp->right->parent=tmp->parent;
		}else if(tmp->parent->data->abbr<tmp->data->abbr){
			tmp->parent->right=tmp->right;
			tmp->right->parent=tmp->parent;
		}

	}

	return tmp;
}
TNode *BST::remove(string s) {
	TNode *rm=find(s);
	//cout<<rm->data->abbr<<endl;
	if(rm->left==NULL&&rm->right==NULL){
		removeNoKids(rm);
		//setHeight(rm);
	}else if(rm->left==NULL&&rm->right!=NULL){
		//cout<<" yuh right"<<endl;
		removeOneKid(rm, false);
		//setHeight(rm);
	}else if (rm->left==NULL&&rm->right!=NULL){
		removeOneKid(rm, true);
		//setHeight(rm);
		//cout<<" yuh left"<<endl;
	}else{
		TNode *rp=rm;
		//cout<<" else"<<endl;
		rp=rp->left;
		while(rp!=NULL){
			if(rp->right!=NULL){
				rp=rp->right;
				if(rp->right==NULL){
					rm->data->abbr=rp->data->abbr;
					removeNoKids(rp);

					break;
				}
			}
		}
	}

	//setHeight(rm);
	return rm;
}
