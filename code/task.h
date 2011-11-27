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
private:
	bool inactive;
	bool apt;
	unsigned int id;

	std::string name;
	std::string description;
	std::string project;
	date dueDate;
	date timeEst;
	date timeElapse;
	unsigned int priority;    
    unsigned int prereq;
	  
public:
	bool getInactive() { return inactive; }
	void setInactive(bool i) { inactive = i; }

	bool getApt() { return apt; }
	void setApt(bool i) { apt = i; }

	unsigned int getId() { return id; }
	void setId(unsigned int i) { id = i; }
	////
	std::string getName() { return name; }
	void setName(std::string n) { name = n; }

	std::string getDescription() { return description; }
	void setDescription(std::string d) { description = d; }

	std::string getProject() { return project; }
	void setProject(std::string p) { project = p; }
	////
	date getDueDate() { return dueDate; }
	void setDueDate(date d) { dueDate = d; }

	date getTimeEst() { return timeEst; }
	void setTimeEst(date d) { timeEst = d; }

	date getTimeElapse() { return timeElapse; }
	void setTimeElapse(date d) { timeElapse = d; }
	////
	unsigned int getPriority() { return priority; }
	void setPriority(unsigned int i) { priority = i; }

	unsigned int getPrereq() { return prereq; }
	void setPrereq(unsigned int i) { prereq = i; }
	
};





 ostream &operator<<(ostream &out, taskClass t)     //output
{
	out<< "inactive:" 	<< t.getInactive()<<"\n";
	out<< "apt:" 		<< t.getApt()<<"\n";
	out<< "id:" 		<< t.getId()<<"\n";
	out<< "name:" 		<< t.getName()<<"\n";
	out<< "description:"<< t.getDescription()<<"\n";
	out<< "project:" 	<< t.getProject()<<"\n";
	out<< "dueDate:" 	<< t.getDueDate()<<"\n";
	out<< "timeEst:" 	<< t.getTimeEst()<<"\n";
	out<< "timeElapse:" << t.getTimeElapse()<<"\n";
	out<< "priority:" 	<< t.getPriority()<<"\n";    
    out<< "prereq:" 	<< t.getPrereq()<<"\n";
	return out;
}


#endif

