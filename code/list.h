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
#include <set>
#include <algorithm>
using namespace std;

#include "boost/date_time/gregorian/gregorian.hpp"
using namespace boost::gregorian;

#ifndef LIST_H_INCLUDE
#define LIST_H_INCLUDE

class activeListClass {
	
	vector<taskClass> list;
	int idCount;

public:
	listClass()
	{
		idCount=0;
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
			if((list[i].getInactive())){			
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
		taskClass t = taskClass(apt, idCount, name, description, project, dueDate, timeEst, priority, prereq);
		list.push_back(t);
	}
	
	vector<taskClass> reSort()
	{
		vector<taskClass> tasks=showTask();
		vector<taskClass> apts=showApt();
		
	
	
	
	}
	
	//how?
	void makeInactive(){}
	
	
	
	//taskClass top() { return list[0]; }



};












#endif
