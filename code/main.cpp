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

	activeListClass activeList;
	inactiveListClass inactiveList;
	
	activeList.push(false, "namething1", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 0);
	activeList.push(false, "namething6", "descprojectthing", "projectthing", date(now+50000), date((time_t) 500), 0);
	activeList.push(false, "namething3", "descprojectthing", "projectthing", date(now+9000), date((time_t) 500), 2 , 1);
	activeList.push(true, "namething2", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 3 );
	activeList.push(true, "namething4", "descprojectthing", "projectthing", date(now+610), date((time_t) 500), 4);
	activeList.push(true, "namething7", "descprojectthing", "projectthing", date(now+10030), date((time_t) 500), 4);
	activeList.push(false, "namething5", "descprojectthing", "projectthing", date(now+98747), date((time_t) 500), 4);
	
cout <<"*4 tasks and 3 apointments added*"<<endl;
	
	vector<taskClass> o=activeList.show();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

cout <<"*correct order*"<<endl;
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

cout <<"*workingontop - timer advance - corrent order*"<<endl;
	
	activeList.workingOnTop();
	activeList.timerAdvance();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

	wait(10);

cout <<"*stop working - timeradvance - correct order*"<<endl;
	activeList.stopWorkingOnTop();
	activeList.timerAdvance();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	
cout <<"*#5 completed*"<<endl;
	completed(5,&activeList,&inactiveList);

cout <<"*show inactive list*"<<endl;
	o=inactiveList.show();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

cout <<"*show in correct order - active*"<<endl;
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

cout <<"*move #7 to pos 3 - show in correct order*"<<endl;	
	activeList.move(7,3);
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	

cout <<"*move #3 to pos 1 - show in correct order ### should fail*"<<endl;	
	activeList.move(3,1);
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	
	
	
	
	string u=fileReadMmap("README");
	
	return 0;
}
