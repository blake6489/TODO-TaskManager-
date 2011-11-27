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
	int id;

	string name;
	string description;
	string project;
	date dueDate;
	date timeEst;
	date timeElapse;
	int priority;    
    int prereq;
	  
public:
	taskClass(
		bool a,
		int i,
		string n,
		string des,
		string pro,
		date due,
		date time,
		int pri = -1,
		int pre = -1)
	{
		inactive=false;
		
		apt=a;
		id=i;
		
		name=n;
		description=des;
		project=pro;
		dueDate=due;
		timeEst=time;
		timeElapse=date(1500,1,1);
		priority=pri;    
		prereq=pre;
		
	}
	
	
	
public:
	bool getInactive() { return inactive; }
	void setInactive(bool i) { inactive = i; }

	bool getApt() { return apt; }
	void setApt(bool i) { apt = i; }

	int getId() { return id; }
	void setId(int i) { id = i; }
	////
	string getName() { return name; }
	void setName(string n) { name = n; }

	string getDescription() { return description; }
	void setDescription(string d) { description = d; }

	string getProject() { return project; }
	void setProject(string p) { project = p; }
	////
	date getDueDate() { return dueDate; }
	void setDueDate(date d) { dueDate = d; }

	date getTimeEst() { return timeEst; }
	void setTimeEst(date d) { timeEst = d; }

	date getTimeElapse() { return timeElapse; }
	void setTimeElapse(date d) { timeElapse = d; }
	////
	int getPriority() { return priority; }
	void setPriority(int i) { priority = i; }

	int getPrereq() { return prereq; }
	void setPrereq(int i) { prereq = i; }
	
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

