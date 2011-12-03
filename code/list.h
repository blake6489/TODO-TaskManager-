//list.h

#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <ctime>
#include <set>
#include <algorithm>
using namespace std;

#ifndef LIST_H_INCLUDE
#define LIST_H_INCLUDE

class activeListClass {
	
	vector<taskClass> list;
	int idCount;
	
	int aptDelay; //for every aptDelay seconds till the meeting, the apt will apear 1 line down in the list
	int workingOn; // item being worked on by uniqueId
	date startTime; 
public:
	activeListClass(int idC=0,int aptD=15*60)
	{
		idCount=idC;
		aptDelay=aptD;
	}
	
	
public:
	taskClass top() { return list[0]; }

	
	vector<taskClass> show(int n=-1) 
	{ 
		vector<taskClass> ret;
		int c=0;
		if (n<0){c=-2147483647;}
		int i=0;
		while(c<n && i<list.size()){
			if(!(list[i].getInactive())){			
				ret.push_back(list[i]);
				++c;
			}
			++i;
		}
		return ret; 
	}
	
	vector<taskClass> showInactive(int n=-1) 
	{ 
		//if n=-1, show all inactive
		vector<taskClass> ret;
		int c=0;
		if (n<0){c=-2147483647;}
		int i=0;
		while(c<n && i<list.size()){
			if((list[i].getInactive())){			
				ret.push_back(list[i]);
				++c;
			}
			++i;
		}
		return ret; 
	}
		
	vector<taskClass> showApt(int n=-1) 
	{ 
		//if n=-1, show all appointments
		vector<taskClass> ret;
		int c=0;
		if (n<0){c=-2147483647;}
		int i=0;
		while(c<n && i<list.size()){
			if(list[i].getApt()){			
				ret.push_back(list[i]);
				++c;
			}
			++i;
		}
		return ret; 
	}
	
	
	vector<taskClass> showTask(int n=-1) 
	{ 
		//if n=-1, show all tasks
		vector<taskClass> ret;
		int c=0;
		if (n<0){c=-2147483647;}
		int i=0;
		while(c<n && i<list.size()){
			if(!(list[i].getInactive()) && !(list[i].getApt())){			
				ret.push_back(list[i]);
				++c;
			}
			++i;
		}
		return ret; 
	}
	
	void push(
		bool apt,
		string name,
		string description,
		string project,
		date dueDate,
		date timeEst,
		int priority = -1,
		int prereq = -1) 
	{ 
		++idCount;
		vector<taskClass>::iterator it;
		taskClass t = taskClass(apt, idCount, name, description, project, dueDate, timeEst, priority, prereq);
		it = list.begin()+priority;
		if(priority>list.size() || priority < 0)
		{
			list.push_back(t);
		}else{
			list.insert(it,t);
		}
	}
	
	
	
	taskClass getById(int i)
	{
		if(i>idCount){return taskClass();}
		for( int n=0; n<list.size(); n++){
			if(list[n].getId()==i){
				return list[n];
			}
		}
		cout<<"*****getbyid problem, not here********"<<endl;
		return taskClass();
		
	}
	

	
	vector<taskClass> showInCorrectOrder()
	{
		//assumes tasks in correct order already
		vector<taskClass> orderedList=showTask();
		vector<taskClass>::iterator it;

		vector<taskClass> apts=showApt();
		double secdiff=0;
		int pos=0;
		time_t now = time(0);
		
		sort (apts.begin(), apts.end());

		for(int i=apts.size()-1; i>=0; --i)
		{
			secdiff=difftime(apts[i].getDueDate_t(),now);
			
			if(secdiff<0){cout<<"***********appointment in the past detected in showInCorrectOrder***********"<<endl;}
			
			pos=(int)(secdiff/aptDelay);
			it = orderedList.begin()+pos;
			
			if(pos>orderedList.size())
			{
				orderedList.push_back(apts[i]);
			}else{
				orderedList.insert(it,apts[i]);
			}
		}
		return orderedList;
	}
	
	
	void workingOnTop()
	{
		time_t now = time(0);
		/*if(workingOn != -1){
			getById(workingOn).setTimeElapse( difftime(startTime.getDate(),now) );
		}*/
		
		workingOn=list[0].getId();
		startTime=date(now);
	}
	
	void timerAdvance()//executed every time someone wants to see the time
	{
		time_t now = time(0);
		taskClass task=getById(workingOn);
		task.setTimeElapse( difftime(startTime.getDate(),now) + task.getTimeElapse().getDate());
		task.setTimeEst( difftime(task.getTimeEst().getDate() , difftime(startTime.getDate(),now) ) );
		startTime=date(now);
	}
	
	//taskClass top() { return list[0]; }



};

#endif