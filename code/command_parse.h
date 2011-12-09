//command_parse.h
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

#ifndef PARSER_H_INCLUDE
#define PARSER_H_INCLUDE

void commandNew(activeListClass* list,vector<string> arg);

void parser(inactiveListClass* inactiveList, activeListClass* activeList, vector<string> arg)
{

	time_t now = time (NULL);
	
	vector<string> commands;
	commands.push_back("new");
	commands.push_back("working");
	commands.push_back("inactivate");
	commands.push_back("completed");
	commands.push_back("stop");
	commands.push_back("show");
	commands.push_back("export");
	commands.push_back("help");
		
	string firstArg=arg[0];
	std::transform(firstArg.begin(), firstArg.end(), firstArg.begin(), (int(*)(int)) tolower);
	cout<<firstArg<<endl;
	
	int argNum=-1;
	for(int i = 0; i<commands.size(); ++i){	if(firstArg==commands[i]){argNum=i;}}
	if(argNum==-1){	cout<< "Command \""<< firstArg <<"\" not recognised"<<endl;}
	
	vector<taskClass> o;
	
	switch (argNum)
	{
		case (0)://"new"
			commandNew(activeList,arg);
			break;
		case (1)://"working"

			break;
		case (2)://"inactivate"

			break;
		case (3)://"completed"

			break;
		case (4)://"stop"

			break;
		case (5)://"show"
			o=activeList->show();
			for(int i=0; i<o.size();++i){
				cout<<o[i]<<endl;
			}
			break;
		case (6)://"export"

			break;
		case (7)://"help"
			for(int i=0; i<commands.size() ; ++i){ cout<< commands.at(i) << endl;}
			break;
			
			
		default:
			cout<< "Command \""<< firstArg <<"\" not recognised"<<endl;
	}
}

void commandNew(activeListClass* list,vector<string> arg){
	time_t now = time (NULL);
	
	list->push(false, "namething1", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 0);
	list->push(false, "namething6", "descprojectthing", "projectthing", date(now+50000), date((time_t) 500), 0);
	list->push(false, "namething3", "descprojectthing", "projectthing", date(now+9000), date((time_t) 500), 2 , 1);
	list->push(true, "namething2", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 3 );
	list->push(true, "namething4", "descprojectthing", "projectthing", date(now+610), date((time_t) 500), 4);
	list->push(true, "namething7", "descprojectthing", "projectthing", date(now+10030), date((time_t) 500), 4);
	list->push(false, "namething5", "descprojectthing", "projectthing", date(now+98747), date((time_t) 500), 4);

}

#endif
