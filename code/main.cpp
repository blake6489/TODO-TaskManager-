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



int main (int argc, char* argv[])
{

	

	//time in seconds when appointments move
	//they will be one element down for every one of these


	time_t now = time(0);
	cout << "The UTC date and time is:"<<    date(now) << endl;


	activeListClass p;
	p.push(false, "namething1", "descprojectthing", "projectthing", date(111,10,29,5), date((time_t) 1), 0);
	p.push(false, "namething6", "descprojectthing", "projectthing", date(111,11,6), date((time_t) 1), 0);
	p.push(false, "namething3", "descprojectthing", "projectthing", date(111,11,1), date((time_t) 1), 0);
	
	p.push(true, "namething2", "descprojectthing", "projectthing", date(now+100), date((time_t) 1), 0);
	p.push(true, "namething4", "descprojectthing", "projectthing", date(now+3600*2), date((time_t) 1), 0);
	
	p.push(false, "namething5", "descprojectthing", "projectthing", date(111,11,4), date((time_t) 1), 0);
	
	cout<<p.top()<<endl;
	
	vector<taskClass> o=p.showInCorrectOrder();

cout.width(150);
for(int i=0; i<o.size();++i){
cout<<o[i]<<endl;
}

//time_t t(time(NULL));   // current time
//date date(*localtime(&t));  

//std::locale loc("");    // current user locale








	
	string u=fileReadMmap("README");
	



	

	return 0;
}
