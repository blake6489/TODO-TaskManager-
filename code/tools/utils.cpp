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
#include <sstream>
using namespace std;

#include <sys/mman.h>	// for mmap, munmap
#include <sys/stat.h>	//getting filesize
#include <fcntl.h>		// for open, close, write

#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE

//returns string of file
string fileRead(const string file)
{
	string line;
	string out;

	ifstream myfile (file.c_str());
	if (myfile.is_open())
	{
		while (! myfile.eof() )
		{
			getline (myfile,line);
			out+=line;
		}
		myfile.close();
	}

	else cout << "Unable to open file:"<< file << endl; 

	return out;
}

//returns string of file
//should be better that other read method
string fileReadMmap(string file)
{

//struct from sys/stat.h
	struct stat results;
	int len;
    if (stat(file.c_str(), &results) == 0)
        len=results.st_size;
    else
        cout<<"In fileRead: error getting file size"<<endl;

	// OPEN THE FILE
    int fd = open(file.c_str(), O_RDONLY );
    if (fd == -1){
    	cout<<"In fileRead: error opening file"<<endl;
        return "";
    }
   	// MAP THE FILE
    void * addr = mmap((void *)0, len, PROT_READ , MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED){
    	cout<<"In fileRead: error mapping file"<<endl;
		return "";
    }

    char * p = (char *)addr;  // Get the memory as a char array

	//return a string
	string out;
	out.resize(len);
	for (int i = 0; i < len; ++i)
		out[i]=p[i];

    munmap(addr, len);  // Unmap memory
    close(fd);          // Close file

	return out;
}

//takes string and delimiter
//returns vector of the chopped up strings 
vector<string> stringToVector(string s, string searchString){
	int length=s.length();
	int pos=0;
	int pos2=1;
	vector<string> vec;
	int entrycount=0;
	int entrylimit=10000;
	int stringlimit=entrylimit*300;
	//string searchString =".txt";
	while(length>pos && entrycount<entrylimit){
		pos2=s.find(searchString,pos)+searchString.length();
		string entry=s.substr(pos,pos2-pos);
		vec.push_back(entry);
		//cout<<entry<<" p:"<<pos<<" p2:"<<pos2<<" line:"<<linecount<<endl;
		pos=pos2;
		++entrycount;
	}
	return vec;
}

//delimiterA separates elements of a pair
//delimiterB separates pairs
//unlike nonpair version, the delimiters are removed after found
vector<pair<string,string> > stringToVectorPair(string s, string delimiterA, string delimiterB){
	int length=s.length();
	cout<<length<<endl;
	int pos=0;
	int pos2=1;
	int pos3=2;
	vector<pair<string,string> > vec;
	pair<string,string> entry;
	int entrycount=0;
	int entrylimit=10000;
	int stringlimit=entrylimit*300;
	while(length>pos && entrycount<entrylimit){
		pos2=s.find(delimiterA,pos);		//end of first part
		if(pos2==-1){break;}				//end of entries
		entry.first=s.substr(pos,pos2-pos);

		pos2=pos2+delimiterA.length();		//begining of next part
		pos3=s.find(delimiterB,pos2);
		entry.second=s.substr(pos2,pos3-pos2);

		vec.push_back(entry);

		//cout<<entry.first<<"~"<<entry.second<<" p:"<<pos<<" p2:"<<pos2<<" p3:"<<pos3<<" line:"<<entrycount<<endl;
		pos=pos3;
		++entrycount;
	}
	return vec;
}

////itoa
char* itoa(int val, int base=10){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

////
string convertInt(int number)
{
   stringstream ss (stringstream::in | stringstream::out);//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void stringToVector(vector<string> v, int p, string d){
	
}

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


#endif
