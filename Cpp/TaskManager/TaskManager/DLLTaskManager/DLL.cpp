
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numTasks = 0;
		tothrs = 0;
		totmin = 0;
	}
	DLL::DLL(string t, int p, int h, int m){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,p,h,m);
		first = n;
		last = n;
		//cout<<"constructor first " <<first->task->priority<<" Task priority"<<endl;
		numTasks=1;
		tothrs = h;
		totmin = m;
	}

	/***************************************************************************************************/
	/*Part 1																																		*/
	/***************************************************************************************************/

	void DLL::push(string n, int p, int h, int m) {
    // does what you'd think, with a caveat that if the
	//priority isn't 3, it will move the task up to the end of the set of tasks with that priority.
	//In other words, if the priority is 1, it will traverse the list in reverse order until it finds a
	//task with a priority of 1, and insert the new task between the last task with a priority of
	//1 and the first task with a priority of 2
	//it also updates the total time of the list
		//cout<<"Hey push"<<endl;

		//cout<<"what push? first " <<first->task->priority<<" And last "<<last->task->priority<<" Task prioritys"<<endl;

		DNode *r=new DNode(n,p,h,m);

		if(first==NULL&&last==NULL){
			first=r;
			last=r;
		}

		r->prev=last;
		//cout<<"what push?1 _" <<last->task->priority<<" Task priority"<<endl;
		last->next=r;
		//cout<<"what push?2" <<endl;
		last=r;
		//cout<<"what push?3" <<endl;
		first->prev=NULL;
		//<<r->task->priority<<"Task priority"<<endl;

		numTasks+=1;
		//DNode *tmppu=r;
		//changePriority(tmppu->task->tasknum,tmppu->task->priority);


		//if(first!=tmppu){
			//cout<<"Hey push "<<numTasks <<endl;
			//while((tmppu!=NULL&&tmppu->prev!=NULL)&&(tmppu->task->priority<=tmppu->prev->task->priority)){
				//cout<<"Hey push yert"<<numTasks <<endl;
			//	moveUp(tmppu->task->tasknum);

				//tmppu=tmppu->next;
			//}
		//}

		//delete tmp;

		tothrs += h;
		totmin += m;
		//cout<<"Bye push"<<endl;
	}
	Task *DLL::pop() {
	//does what you'd think - make sure to update the total time of the list.
	//Note -this isn’t all that necessary for this particular project, but I
	//kinda had to make you write pop because it’s //fundamental to so much of
	//linked list data type uses (e.g., stack, undo).
		cout<<"Hey pop"<<endl;
		DNode *tmppo=last;
		tothrs -= last->task->hr;
		totmin -= last->task->min;
		Task *t=tmppo->task;
		last=last->prev;
		//delete tmp;
		last->next=NULL;
		numTasks-=1;
		cout<<"bye pop"<<endl;
		return t;
	}

	void DLL::printList() {
		//prints out the entire list, along with the total time necessary to complete all tasks
		//on the list
		//cout<<"Hey print list"<<endl;
		DNode *tmppl=first;
		//int th=0, tm=0;
		//cout<<"what print list?"<<endl;
		while(tmppl!=NULL){
			tmppl->task->printTask();
			tmppl=tmppl->next;
		}

		cout<<"The total time to complete list of tasks is "<<tothrs+totmin/60<<":"<<totmin%60<<endl;

		//cout<<"Bye print list"<<endl;
	}

	void DLL::printList(int p) {
		//print out only all the tasks with a priority of p, along with the total time necessary
		//to complete the tasks with a priority of p
		//cout<<"Hey print listy p"<<endl;
		DNode *tmpplp=first;
				//,*i,*b,*tmpm;
				//tn;
		if(p<4&&p>0){
		while(tmpplp!=NULL){
			if(tmpplp->task->priority==p){
				tmpplp->task->printTask();
			}
			tmpplp=tmpplp->next;
			}
		}else
			cout<<"This priority does not exist"<<endl;
/*
//
//		tmpm=first->next;
//		i=tmpm->next;
//		b=NULL;
//		cout<< "enter task number"<<endl;
//		cin>>tn;
		//cout<< "task "<<tn<<" is "<<b->task->task<<endl;
//		if(tmpm->prev->prev==NULL){
//			cout<< "first  "<<first->task->task<<endl<<endl;
//			cout<< "tmp  "<<tmpm->task->task<<endl;
//
//		}
//		tmpm->prev=b;
//		b->next=tmpm;
//		tmpm->next=NULL;
//		i->prev=NULL;
//		first=i;
//		last=tmpm;
//
//		if(i->next!=NULL&&tmpm->prev!=NULL&&b!=NULL){
//		//cout<< "task "<<tn<<" is "<<b->task->task<<endl;
//		cout<< "task "<<tn<<" is "<<tmpm->next->next->task->task<<endl;
//
//
//		cout<< "task "<<tn<<" is "<<first->next->task->task<<endl;
//		}
 *
 */
		//cout<<"The total time to complete the priority #"<<p<<" tasks is "<<th<<":"<<tm<<endl;
	}

	void DLL::moveUp(int t) {
		// moves task with number tn up one in the list.
	    //If it is at the beginning of the list,
        //it will be moved to the end of the list.
		// NOTE: if this moves a task up before a task with a higher priority (1 is
		// higher priority than 2 - I know the wording is a bit weird), then this
		// changes the priority of the task being moved to that higher priority
		//cout<<"Hey moveup"<<endl;
		DNode *tmpm=first,*b,*a,*i;//move,behind,around,infront
		//int c=0;
		//DNode *tmpu=new DNode();
		//cout<<"printlist: "<<endl;
		//printList();
		//if(t<=numTasks){
			while(tmpm->task->tasknum!=t)
				//cout<<"Hey moveup "<<tmpm->task->task <<" for count"<<++c<<endl;
				tmpm=tmpm->next;


			//if(tmpm->prev==NULL)
				//cout<<"second"<<endl;
			//cout<<"Hey moveup "<<tmpm->task->task <<endl;
			if(tmpm->next==NULL){ //m==last
				//cout<<"move up from last"<<endl;
				if(tmpm->prev!=first){
					b=tmpm->prev->prev;
					//cout<<"m"<<endl;
					b->next=tmpm;
				}

				a=tmpm->prev;

				a->next=tmpm->next;

				tmpm->prev=a->prev;
				a->prev=tmpm;
				tmpm->next=a;



				last=a;



			}else if(tmpm->prev==NULL){//m==first
				//cout<<"move up from first"<<endl;
				i=tmpm->next;
				b=last;

				tmpm->prev=b;
				b->next=tmpm;
				tmpm->next=NULL;
				i->prev=NULL;
				first=i;
				last=tmpm;

			}else if(tmpm->prev==first){//m=second
				//cout<<"move up from second"<<endl;
				a=tmpm->prev;
				i=tmpm->next;

				a->next=i;
				tmpm->next=a;
				a->prev=tmpm;
				i->prev=a;
				tmpm->prev=NULL;
				first=tmpm;
			}else{
				//cout<<"move up from other"<<endl;
				b=tmpm->prev->prev;
				a=tmpm->prev;
				i=tmpm->next;

				b->next=tmpm;
				a->next=i;
				tmpm->next=a;
				a->prev=tmpm;
				tmpm->prev=b;
				i->prev=a;


			}

		//}

		//cout<<"Bye move up"<<endl;

	}

	void DLL::listDuration(int *th, int *tm,int p) {
		// gets the list duration in hours and minutes (passed
		//in as pointers) of a particular priority (so the total time
		//needed to complete all tasks with priority of p)
		// I had you pass in the parameters as pointers for practice.
		DNode *tmpld=first;

		while(tmpld!=NULL){
			if(tmpld->task->priority==p){
				*th+=tmpld->task->hr;
				*tm+=tmpld->task->min;
			}
				tmpld=tmpld->next;
			}
		*th=*th+*tm/60;
		*tm=*tm%60;
		//cout<<*th<<"  "<<*tm<<endl;

	}


	void DLL::moveDown(int tn) {
		//moves task with task number tn down one in the list.
		//If it is at the end of the list, it will move to
		//beginning of the list.
		//NOTE: if this moves a task after a task with a lower priority (again, 3 is
		//a lower priority than 2) then this changes the priority of the task being
		//moved.
		//cout<<"Hey movedown"<<endl;
				DNode *tmpm=first,*b,*a,*i;//move,behind,around,infront
				//int c=0;
					while(tmpm->task->tasknum!=tn)
						//cout<<"Hey movedown "<<tmpm->task->task <<" for count"<<++c<<endl;
						tmpm=tmpm->next;


					//if(tmpm->prev==NULL)
						//cout<<"second"<<endl;
					//cout<<"Hey moveup "<<tmpm->task->task <<endl;
					if(tmpm->next==NULL){ //m==last
						cout<<"move down from last"<<endl;
//						if(tmpm->prev!=first){
//							b=tmpm->prev->prev;
//							cout<<"m"<<endl;
//							b->next=tmpm;
//						}
						b=tmpm->prev;
						i=first;

						tmpm->next=i;
						i->prev=tmpm;
						tmpm->prev=NULL;
						b->next=NULL;
						first=tmpm;
						last=b;



					}else if(tmpm->prev==NULL){//m==first
						cout<<"move down from first"<<endl;
						a=tmpm->next;
						i=tmpm->next->next;

						tmpm->next=i;
						tmpm->prev=a;
						i->prev=tmpm;
						a->prev=NULL;
						a->next=tmpm;
						first=a;


					}else if(tmpm->next==last){//m=second
						cout<<"move down from second"<<endl;
						b=tmpm->prev;
						a=tmpm->next;

						tmpm->next=NULL;
						a->prev=b;
						tmpm->prev=a;
						a->next=tmpm;
						b->next=a;
						last=tmpm;

					}else{
						cout<<"move down from other"<<endl;
						b=tmpm->prev;
						a=tmpm->next;
						i=tmpm->next->next;

						tmpm->next=i;
						tmpm->prev=a;
						a->next=tmpm;
						a->prev=b;
						b->next=a;
						i->prev=tmpm;

					}


				//}

				cout<<"Bye move down"<<endl;

	}

	int DLL::remove(int tn) {
		//removes a task (based on its number) and updates the total time of the list
		//Make sure you link the next to the previous and the previous to the next.  The
		//biggest catch with this method is making sure you test to make sure the node
		//after and/or the node before the node you’re deleting aren’t NULL (i.e., you’re
		//not deleting the first or last node in the list)
		cout<<"hey remove"<<endl;
		DNode *tmpr=first,*b,*i;

		while(tmpr->task->tasknum!=tn)
			tmpr=tmpr->next;
		b=tmpr->prev;
		i=tmpr->next;
		if(tmpr->prev==NULL){//first
			cout<<"remove first"<<endl;
			i->prev=b;
			first=i;
		}else if(tmpr->next==NULL){//last
			cout<<"remove last"<<endl;
			b->next=i;
			last=b;
		}else{
			cout<<"remove "<<endl;
			i->prev=b;
			b->next=i;
		}
		tothrs -= tmpr->task->hr;
		totmin -= tmpr->task->min;
		cout<<"bye remove"<<endl;

		return tmpr->task->tasknum;
	}

	void DLL::changePriority(int tn, int newp) {
		//changes the priority of the task.  This method also moves the task to the end
		//of the set of tasks with
		//that priority.  In other words, if you have the following:
		/*task1, 1, 2:20
		task2, 1, 3:20
		task3, 1, 1:15
		task4, 2, 3:10
		task5, 2, 1:10
		task6, 3, 3:15
		task7, 3, 2:54

		And you change task6’s priority to 1, the resulting list should be:
		task1, 1, 2:20
		task2, 1, 3:20
		task3, 1, 1:15
		task6, 1, 3:15
		task4, 2, 3:10
		task5, 2, 1:10
		task7, 3, 2:54
		*/
		//cout<<"hey change p"<<endl;
		DNode *tmppc=first;
		while(tmppc->task->tasknum!=tn)
				tmppc=tmppc->next;
		if(newp>0&&newp<4){
			tmppc->task->priority=newp;
			if(tmppc->next==NULL){
				moveDown(tmppc->task->tasknum);
			}
			while((tmppc->task->priority>=tmppc->next->task->priority)&&tmppc->task->priority!=3){
				//cout<<"Hey push yert"<<numTasks <<endl;
				moveDown(tmppc->task->tasknum);
			}
			if(tmppc->task->priority==3){
				while(tmppc->next!=NULL)
					moveDown(tmppc->task->tasknum);
			}
		}
		//cout<<"bye change p"<<endl;
	}

	DLL::~DLL(){
		DNode *tmp = first;
		DNode *tmp2 = first->next;
		while (tmp != NULL) {
			delete tmp;
			tmp = tmp2;
			if (tmp != NULL) {
				tmp2 = tmp2->next;
			}
		}
		first = NULL;
		last = NULL;
		numTasks = 0;
		tothrs = 0;
		totmin = 0;
	}

	/******************Optional Helper Methods********************************/
	void DLL::addTime(int h, int m) {
	}

	void DLL::removeTime(int h, int m) {
	}
	/********************End of Optional Helper Methods ********************/
