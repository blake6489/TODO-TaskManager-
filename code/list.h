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

class listClass {
	
	vector<taskClass> list;

public:
	taskClass top() { return list[0]; }

	
	vector<taskClass> show(int n) 
	{ 
		vector<taskClass> ret;
		for(int i=0; i<n; ++i){
			ret.push_back(list[i]);
		}
		return ret; 
	}
	
	vector<taskClass> showActive(int n) 
	{ 
		vector<taskClass> ret;
		int c=0;
		int i=0;
		while(c<n && i<list.size()){
			if(!(list[i].getInactive())){			
				ret.push_back(list[i]);
				++c;
			}
			
			++i
		}
		return ret; 
	}
	
	void add(taskClass t) 
	{  
		list.push_back(t);
		resort();	
	}
	
	
	
	taskClass top() { return list[0]; }



}












#endif
