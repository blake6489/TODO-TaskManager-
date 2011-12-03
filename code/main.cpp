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

#include "dates.h"

#include "tools/utils.cpp"
#include "task.h"
#include "list.h"
#include "inactivelist.h"



void completed(int i,activeListClass* act, inactiveListClass* in )
{
	taskClass* t = act->getById(i);
	t->setCompleted(true);
	in->push(act->markInactive(i));
}

void inactive(int i,activeListClass* act, inactiveListClass* in )
{
	in->push(act->markInactive(i));
}

int main (int argc, char* argv[])
{
	//time in seconds when appointments move
	//they will be one element down for every one of these

time_t now = time (NULL);

	activeListClass p;
	inactiveListClass inactiveList;
	
	p.push(false, "namething1", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 0);
	p.push(false, "namething6", "descprojectthing", "projectthing", date(now+50000), date((time_t) 500), 0, 1);
	p.push(false, "namething3", "descprojectthing", "projectthing", date(now+9000), date((time_t) 500), 5,2);
	p.push(true, "namething2", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 0);
	p.push(true, "namething4", "descprojectthing", "projectthing", date(now+610), date((time_t) 500), 2);
	p.push(true, "namething7", "descprojectthing", "projectthing", date(now+10030), date((time_t) 500), 1);
	p.push(false, "namething5", "descprojectthing", "projectthing", date(now+98747), date((time_t) 500), 4);
	
	cout<<endl;
	
	vector<taskClass> o=p.show();
	
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	cout<<"**"<<endl;
		
	o=p.showInCorrectOrder();

	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

	cout<<endl;
	
	p.workingOnTop();
	p.timerAdvance();
	o=p.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

	wait(10);
cout<<"**"<<endl;
	p.stopWorkingOnTop();
	p.timerAdvance();
	o=p.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	
	completed(4,&p,&inactiveList);
	
	cout <<"*#4 completed*"<<endl;
	o=inactiveList.show();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	cout <<"**"<<endl;
	o=p.showInCorrectOrder();

	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	
	
	
	string u=fileReadMmap("README");
	
	return 0;
}
