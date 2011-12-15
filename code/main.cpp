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

void commandNew(activeListClass* list,vector<string> nArg);
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
	
	time_t now = time (NULL);

	activeListClass activeList;
	inactiveListClass inactiveList;
	
	activeList.readFromFile(&fileReadMmap(actFile));
	inactiveList.readFromFile(&fileReadMmap(inactFile));

	
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
		commands.push_back("move");
		commands.push_back("help");
	
		string firstArg=arg[0];
		std::transform(firstArg.begin(), firstArg.end(), firstArg.begin(), (int(*)(int)) tolower);

		//identify the command number
		int argNum=-1;
		for(int i = 0; i<commands.size(); ++i){	if(firstArg==commands[i]){argNum=i;}}

		vector<taskClass> o;

		switch (argNum)
		{
			case (0)://"new"
				if(activeList.getWorkingOn()!=-1){
					cout<<"**Working! Must stop to make new**"<<endl;
				}else{
					commandNew(&activeList,arg);
				}
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
				if(arg.size()>1){o=activeList.showInCorrectOrder(atoi(arg[1].c_str()));
				}else{o=activeList.showInCorrectOrder();}
				for(int i=0; i<o.size();++i){
					cout<<o[i]<<endl;
				}
				break;
			case (6)://"move"
				if(activeList.getWorkingOn()!=-1){
					cout<<"**Working! Must stop to move**"<<endl;
				}else{
					if(arg.size()>2){activeList.move(atoi(arg[1].c_str()),atoi(arg[2].c_str()));
					}else{cout<<"**Move what to where? 2 arguments required**"<<endl;}
				}
				break;
			case (7)://"help"

				printf("The TODO program tracks the tasks that are entered into it.\n");
				printf("The performance of the program will degrade for large numbers of active items\n");
				printf("At one thousand items, 1 second is needed to finish the operation.\n");
				printf("\n");
				printf("new apt(0/1) name description project due-date time-estimate [priority] [prereq ID]\n");
				printf("    apt is an integer boolean, 1 is an appointment, 0 is a task\n");
				printf("    name, description and project are simple string values. Use single quotes\n     around variable that have spaces in them.\n"); 
				printf("    due-date in MM-DD-YYYY format (03-24-2011). Leading zeros are alowed but not\n     required.\n");
				printf("    time-estimate is the time the task will likely take measured in hours\n");
				printf("    priority is optional. it is the number of elements from the top, with 0\n     being the top.\n");
				printf("    prereq is the ID of the item that is required to precede it.\n");
				printf("start\n    Accumulates time spent on the top task in the list.\n");
				printf("inactivate ID\n    Marks the item with the given ID as inactive and moves it to the inactive\n     list.\n");
				printf("completed\n    Marks the top item in the list as completed and moves it to the inactive\n     list.\n");
				printf("stop\n    Stops accumulating time on the top item in the list.\n");
				printf("show [n]\n    Show the first n elements of the active list. If no number is given the\n     default is all.\n");
				printf("move ID priority\n    Moves the item with the given ID to the location with the given priority\n");
				
				printf("    \n");
				printf("    The files activeList and inactiveList store the tasks and apontment.\n     Modifying these files will change the items in the list. The data is stored\n     in tab delimited text format. \n");
				printf("To modify an entry, edit the activeList or inactiveList files\n");
				printf("\n");
				printf("The file format is 4 integers followed by a table.\n");
				printf("The integers are the ID number of the last item created,\n the rate at which the apointments climb higher on the todo list in seconds,\n the number of the item that is being worked on (this must be the tp item,\n and the Unix epoch time when work started, or when the time worked was last\n calculated.\n");
				printf("The table is layed out in the following manner:\n");
				printf("completed(0/1) inactive(0/1) ID apt(0/1) name description project due-date\n time-estimate priority prereq\n"); 
				printf("\n");
				printf("To make the task show you changes to the list over time due to appointments\n     getting closer make sure to modify your crontab to incude a line similar\n    to this one:\n\t15,30,45,59 * * * * user ./home/user/path/TODO show 10\n     to see changes to the top 10 items every 15 minutes");
				break;
			default:
				cout<< "Command \""<< firstArg <<"\" not recognised\ntry one of these"<<endl;
				for(int i=0; i<commands.size() ; ++i){ cout<< commands.at(i) << endl;}
		}
	
	}//end if(argc>1)
	

	ofstream myfile;
	myfile.open (actFile.c_str());
	myfile << activeList.writeToFile();
	myfile.close();
	
	myfile.open (inactFile.c_str());
	myfile << inactiveList.writeToFile();
	myfile.close();

	return 0;
}


void commandNew(activeListClass* list,vector<string> nArg){
	time_t now = time (NULL);
	
	//set last two optional arguments
	if(nArg.size()<8){nArg.push_back(string("-1")); nArg.push_back(string("-1"));}
	if(nArg.size()<9){nArg.push_back(string("-1"));}
	
	//declare new item on list
	list->push(
		atoi(nArg[1].c_str()),//apt
		
		nArg[2], //name
		nArg[3], //desc
		nArg[4], //proj
		
		date(nArg[5].c_str()), // due
		(time_t) atoi(nArg[6].c_str())*60*60, //time est *3600 to convert to seconds
		
		atoi(nArg[7].c_str()), //priority
		atoi(nArg[8].c_str()) //prereq
		);
}

