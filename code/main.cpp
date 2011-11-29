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
#include "duration.h"
#include "tools/utils.cpp"
#include "task.h"
#include "list.h"



int main (int argc, char* argv[])
{

	

	//time in seconds when appointments move
	int AppointmentDelay = 15*60;


   cout << "The UTC date and time is:"<<    date(111,3,4) << endl;


	activeListClass p;
	p.push(false, "namething1", "descprojectthing", "projectthing", date(100,1,1), duration(1), 0);
	p.push(false, "namething2", "descprojectthing", "projectthing", date(100,6,1), duration(1), 0);
	p.push(false, "namething3", "descprojectthing", "projectthing", date(111,3,1), duration(1), 0);
	
	p.push(true, "namething1", "descprojectthing", "projectthing", date(110,1,2), duration(1), 0);
	p.push(true, "namething2", "descprojectthing", "projectthing", date(111,5,1), duration(1), 0);
	
	p.push(false, "namething3", "descprojectthing", "projectthing", date(110,2,1), duration(1), 0);
	
	cout<<p.top()<<endl;
	
	vector<taskClass> o=p.showInCorrectOrder();

//time_t t(time(NULL));   // current time
//date date(*localtime(&t));  

//std::locale loc("");    // current user locale








	
	string u=fileReadMmap("README");
	



	

	return 0;
}
