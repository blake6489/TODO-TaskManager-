//dates.h
#include <fstream>
#include <utility>		// pair
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include <sys/mman.h>	// for mmap, munmap
#include <sys/stat.h>	//getting filesize
#include <fcntl.h>		// for open, close, write

#ifndef DATES_H_INCLUDE
#define DATES_H_INCLUDE

class date{
	time_t time;
	
public:
	date(){time=0;}
	date(time_t t){time=t;}
	date(int year, int month, int day, int hrs=0, int min=0, int sec=0)
	{
		struct tm storage={sec,min,hrs,day,month,year,0,0,0};
		time=mktime(&storage);
	}
	date(const char *t)
	{
		struct tm storage={0,0,0,0,0,0,0,0,0};
		char *p=NULL;
		time_t retval=0;

        p=(char *)strptime(t,"%d-%b-%Y",&storage);
		if(p==NULL)
		{
			time=0;
			cout<< "***********date(char*) given wrong info***********"<<endl;
		}
		else
		{
			time=mktime(&storage);
		}
	}

public:
	time_t getDate(){return time;}
	
	int getDuration(){return time;}
	
	tm print(){return *localtime(&time);}
};

bool operator< ( date a, date b) {return a.getDuration() < b.getDuration();}

ostream &operator<<(ostream &out, date d)     //output
{
	string ss=asctime(&d.print());
	string s=ss.erase(ss.length()-1,ss.length());
	out<< s;
	return out;
}


#endif
