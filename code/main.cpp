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
#include "boost/date_time/gregorian/gregorian.hpp"
#include <set>
#include <algorithm>
using namespace std;

#include "tools/utils.cpp"
#include "task.h"
#include "list.h"



int main (int argc, char* argv[])
{
    using namespace boost::gregorian;

	//time in seconds when appointments move
	int AppointmentDelay = 15*60;

	listClass p;
	p.add(false, "namething1", "descprojectthing", "projectthing", date(2000,1,1), date(2001,2,2), 0);
	p.add(false, "namething2", "descprojectthing", "projectthing", date(2000,2,1), date(2001,2,2), 0);
	p.add(false, "namething3", "descprojectthing", "projectthing", date(2000,3,1), date(2001,2,2), 0);
	
	//cout<<p.top()<<endl;
	
	vector<taskClass> o=p.showActive();
	for(int i=0;i<o.size();++i)
	{
		cout <<o[i]<<endl;
	}



	
	string u=fileReadMmap("README");
	date d2(2002,2,16);
	date d1(2002,2,18);
	

	

	return 0;
}
