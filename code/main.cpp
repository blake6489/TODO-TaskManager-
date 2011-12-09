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
//#include "command_parse.h"

void commandNew(activeListClass* list,vector<string> arg);
void completed(activeListClass* act, inactiveListClass* in )
{
	taskClass* t = act->getById(act->getWorkingOn());
	t->setCompleted(true);
	in->push(act->markInactive(act->getWorkingOn()));
}

void inactive(int i,activeListClass* act, inactiveListClass* in )
{
	in->push(act->markInactive(i));
}
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
int main (int argc, char* argv[])
{
	string actFile="activeList";
	string inactFile="inactiveList";
	
	//string aaa=fileReadMmap(actFile);
	//string iii=fileReadMmap(inactFile);

time_t now = time (NULL);

	activeListClass activeList;
	inactiveListClass inactiveList;
	

	activeList.readFromFile(fileReadMmap(actFile));
	inactiveList.readFromFile(fileReadMmap(inactFile));

	
	//vector<taskClass> o=activeList.show();
	//for(int i=0; i<o.size();++i){
		//cout<<o[i]<<endl;
	//}
///////////////
	vector<string> arg;
	if(argc>1){
		for(int i=1; i<argc; ++i){	arg.push_back(string(argv[i]));	}

		vector<string> commands;
		commands.push_back("new");
		commands.push_back("start");
		commands.push_back("inactivate");
		commands.push_back("completed");
		commands.push_back("stop");
		commands.push_back("show");
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
				commandNew(&activeList,arg);
				break;
			case (1)://"start"
				if(activeList.getWorkingOn()!=-1){
					cout<<"**working already**"<<endl;
				}else{
					activeList.workingOnTop();
					cout<<"Working"<<endl;
				}
				break;
			case (2)://"inactivate"
				if(activeList.getWorkingOn()!=-1){
					cout<<"**working already**"<<endl;
				}else{
					if(arg.size()>1){inactive(atoi(arg[1].c_str()),&activeList,&inactiveList);
					}else{cout<<"**Which item to mark inactive?**"<<endl;}
				}
				break;
			case (3)://"completed"
				if(activeList.getWorkingOn()==-1){
					cout<<"**not working on anything**"<<endl;
				}else{
					completed(&activeList,&inactiveList);
				}
				break;
			case (4)://"stop"
				if(activeList.getWorkingOn()==-1){
					cout<<"**not working on anything**"<<endl;
				}else{
					activeList.stopWorkingOnTop();
				}
				break;
			case (5)://"show"
				//if length is given, print that many items
				if(arg.size()>1){o=activeList.show(atoi(arg[1].c_str()));
				}else{o=activeList.show();}
				for(int i=0; i<o.size();++i){
					cout<<o[i]<<endl;
				}
				break;
			case (6)://"help"
				for(int i=0; i<commands.size() ; ++i){ cout<< commands.at(i) << endl;}
				break;
			default:
				cout<< "Command \""<< firstArg <<"\" not recognised"<<endl;
		}
	
	
	
	}//end if(args exist)
	
	//o=activeList.show(25);
	//for(int i=0; i<o.size();++i){
		//cout<<o[i]<<endl;
//	}
	/*for(int i=0; i<3000; ++i){
		activeList.push(false, "namething5", "descprojectthing", "projectthing", date(now+98747), date((time_t) 500), 4);
	}*/
	/*activeList.push(false, "namething1", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 0);
	activeList.push(false, "namething6", "descprojectthing", "projectthing", date(now+50000), date((time_t) 500), 0);
	activeList.push(false, "namething3", "descprojectthing", "projectthing", date(now+9000), date((time_t) 500), 2 , 1);
	activeList.push(true, "namething2", "descprojectthing", "projectthing", date(now+100), date((time_t) 500), 3 );
	activeList.push(true, "namething4", "descprojectthing", "projectthing", date(now+610), date((time_t) 500), 4);
	activeList.push(true, "namething7", "descprojectthing", "projectthing", date(now+10030), date((time_t) 500), 4);
	activeList.push(false, "namething5", "descprojectthing", "projectthing", date(now+98747), date((time_t) 500), 4);
*/
	/*
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

	wait(5);

cout <<"*stop working - timeradvance - correct order*"<<endl;
	activeList.stopWorkingOnTop();
	activeList.timerAdvance();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}
	*/
	
//cout <<"*#5 completed*"<<endl;
	//completed(14,&activeList,&inactiveList);
/*
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
	
cout <<"*workingontop - corrent order*"<<endl;
	activeList.workingOnTop();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

	wait(5);
	
cout <<"*workingontop again ### fails - corrent order*"<<endl;
	activeList.workingOnTop();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}

	wait(5);

cout <<"*stop working - correct order*"<<endl;
	activeList.stopWorkingOnTop();
	activeList.timerAdvance();
	o=activeList.showInCorrectOrder();
	for(int i=0; i<o.size();++i){
		cout<<o[i]<<endl;
	}	
	
	
	
	//string u=fileReadMmap("README");
*/

	ofstream myfile;
	myfile.open ("activeList");
	myfile << activeList.writeToFile();
	myfile.close();
	

	//o=inactiveList.show();
	//for(int i=0; i<o.size();++i){
		//cout<<o[i]<<endl;
//	}
	myfile.open ("inactiveList");
	myfile << inactiveList.writeToFile();
	myfile.close();

	return 0;
}


void commandNew(activeListClass* list,vector<string> arg){
	time_t now = time (NULL);
	
	vector<string> dataIn=arg;
for(int i=0; i<arg.size();++i){
		cout<<arg[i]<<endl;
	}

if(dataIn.size()<7){dataIn[7]=-1;}
if(dataIn.size()<8){dataIn[8]=-1;}

	list->push(
		atoi(dataIn[1].c_str()),//apt
		
		dataIn[2], //name
		dataIn[3], //desc
		dataIn[4], //proj
		
		(time_t) atoi(dataIn[5].c_str()), // due
		(time_t) atoi(dataIn[6].c_str()), //time est
		
		atoi(dataIn[7].c_str()), //priority
		atoi(dataIn[8].c_str()) //prereq
		);

}

