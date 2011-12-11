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
#include <ctime>
#include <algorithm>
using namespace std;

#ifndef TASK_H_INCLUDE
#define TASK_H_INCLUDE

class taskClass
{
private:
	bool completed;
	bool inactive;
	bool apt;
	int id;

	string name;
	string description;
	string project;
	date dueDate;
	date timeEst;
	date timeElapse;
	int priority;    // this repesents only the initial position of the task in the list before others are added and displace it
    int prereq;
	  
public:
	taskClass(){ //null task
		inactive=false;
		completed=false;
		
		apt=0;
		id=0;
		
		timeElapse=date((time_t) 0);
		priority=0;    
		prereq=0;
	}
	
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
		completed=false;
				
		apt=a;
		id=i;
		
		name=n;
		description=des;
		project=pro;
		dueDate=due;
		timeEst=time;
		timeElapse=date((time_t) 0);
		priority=pri;    
		prereq=pre;
		
	}
	
	
public:
	bool getCompleted() { return completed; }
	void setCompleted(bool i) { completed = i; }
	
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
	time_t getDueDate_t() { return dueDate.getDate(); }
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
	
	string writeOut()
	{
		string oo="";
		
		oo+=" " + convertInt(getInactive()) + "\t";
		oo+=convertInt(getApt()) + "\t";
		oo+=convertInt(getId()) + "\t";
		oo+=getName() + "\t";
		oo+=getDescription() + "\t";
		oo+=getProject() + "\t";
		oo+=convertInt(getDueDate().getDuration())+ "\t";
		oo+=convertInt(getTimeEst().getDuration()) + "\t";
		oo+=convertInt(getTimeElapse().getDuration()) + "\t";
		oo+=convertInt(getPriority()) + "\t";    
		oo+=convertInt(getPrereq());
		
		return oo;
	}
	
	void readIn(string in)
	{

		vector<string> dataIn;
		char * pch;
		char * tmpstr=strdup(in.c_str());
		pch = strtok (tmpstr,"\t");
		while (pch != NULL)
		{
			dataIn.push_back(string(pch));
			pch = strtok (NULL, "\t");
		}

		setCompleted(0);
		setInactive(atoi(dataIn[0].c_str()));

		setApt(atoi(dataIn[1].c_str()));
		setId(atoi(dataIn[2].c_str()));
		
		setName(dataIn[3]);
		setDescription(dataIn[4]);
		setProject(dataIn[5]);
		
		setDueDate((time_t) atoi(dataIn[6].c_str()));
		setTimeEst((time_t) atoi(dataIn[7].c_str()));
		setTimeElapse((time_t) atoi(dataIn[8].c_str()));
		
		setPriority(atoi(dataIn[9].c_str()));
		setPrereq(atoi(dataIn[10].c_str()));
		
		
	}
	
	
	/*void readIn(char * charsIn)
	{
		size_t line;
		size_t last;
		string in=string(charsIn);
		
		setCompleted(0);
				
		line=in.find("\t");
		setInactive(atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setApt(atoi(in.substr(last,line).c_str()));
		last=line+1;

		setId(atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setName(in.substr(last,line));
		last=line+1;

		line=in.find("\t",last);
		setDescription(in.substr(last,line));
		last=line+1;

		line=in.find("\t",last);
		setProject(in.substr(last,line));
		last=line+1;

		line=in.find("\t",last);
		setDueDate((time_t) atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setTimeEst((time_t) atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setTimeElapse((time_t) atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setPriority(atoi(in.substr(last,line).c_str()));
		last=line+1;

		line=in.find("\t",last);
		setPrereq(atoi(in.substr(last,line).c_str()));
		
	}*/
	
	void readInCommand(string in)
	{

		vector<string> dataIn;
		char * pch;
		char * tmpstr=strdup(in.c_str());
		pch = strtok (tmpstr,"\t");
		while (pch != NULL)
		{
			dataIn.push_back(string(pch));
			pch = strtok (NULL, "\t");
		}

		setCompleted(0);
		setInactive(atoi(dataIn[0].c_str()));

		setApt(atoi(dataIn[1].c_str()));
		setId(atoi(dataIn[2].c_str()));
		
		setName(dataIn[3]);
		setDescription(dataIn[4]);
		setProject(dataIn[5]);
		
		setDueDate((time_t) atoi(dataIn[6].c_str()));
		setTimeEst((time_t) atoi(dataIn[7].c_str()));
		setTimeElapse((time_t) atoi(dataIn[8].c_str()));
		
		setPriority(atoi(dataIn[9].c_str()));
		setPrereq(atoi(dataIn[10].c_str()));
		
		
	}

 
	//bool dateCompa( taskClass &a, taskClass &b) {return a.getDueDate() < b.getDueDate();}
};


bool operator< ( taskClass a, taskClass b) {return a.getDueDate() < b.getDueDate();}
//bool operator< ( taskClass a, taskClass b) {return a.getPriority() < b.getPriority();}



/*ostream &operator<<(ostream &out, taskClass t)     //output
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
}*/

ostream &operator<<(ostream &out, taskClass t)     //output
{
out.width(0);
	out<<t.getId()<< ", " << t.getCompleted()<< ", " << t.getInactive()<< ", "<< t.getApt()<< ", "<< t.getName()<< ", "<< t.getDescription()<< ", "<< t.getProject()<< ", "<< t.getDueDate()<< ", "<< t.getTimeEst().getDuration()<< ", "<< t.getTimeElapse().getDuration()<< ", "<< t.getPriority()<< ", "<< t.getPrereq();
	return out;
}


#endif

