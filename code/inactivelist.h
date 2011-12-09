//inactivelist.h

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

#ifndef INACTIVELIST_H_INCLUDE
#define INACTIVELIST_H_INCLUDE

class inactiveListClass {
	
	vector<taskClass> list;
	
public:
	inactiveListClass()
	{

	}
	
	
public:
	
	vector<taskClass> show(int n=-1) 
	{ 
		vector<taskClass> ret;
		if(n==-1){n=list.size();}
		for(int i=0 ; i<n ; ++i){
			ret.push_back(list[i]);
		}
		return ret; 
	}
	

	void push(taskClass t) 
	{ 
		list.push_back(t);
	}
	
	taskClass* getById(int i)
	{
		for( int n=0; n<list.size(); n++){
			if(list[n].getId()==i){
				return &(list[n]);
			}
		}
		cout<<"*****getbyid problem, not here********"<<endl;
		return &(taskClass());
		
	}
	
	string writeToFile()
	{
		string file="inactivelist";
		
		
		
	}
	
	string readFromFile()
	{
		string file="inactivelist";
		
		
		
		
	}

};

#endif
