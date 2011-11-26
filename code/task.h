//tasks.h

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

#ifndef TASK_H_INCLUDE
#define TASK_H_INCLUDE

class taskClass
{
public:
	bool apt;
	int id;
	std::string name;
	std::string description;
	std::string project;
	date dueDate;
	date timeEst;
	date timeElapse;
	int priority;    
    int prereq;
  

};

 ostream &operator<<(ostream &out, taskClass t)     //output
{
	out<< "apt:" 		<< t.apt<<"\n";
	out<< "id:" 		<< t.id<<"\n";
	out<< "name:" 		<< t.name<<"\n";
	out<< "description:" << t.description<<"\n";
	out<< "project:" 	<< t.project<<"\n";
	out<< "dueDate:" 	<< t.dueDate<<"\n";
	out<< "timeEst:" 	<< t.timeEst<<"\n";
	out<< "timeElapse:" 	<< t.timeElapse<<"\n";
	out<< "priority:" 	<< t.priority<<"\n";    
    out<< "prereq:" 		<< t.prereq<<"\n";
	return out;
}


#endif

