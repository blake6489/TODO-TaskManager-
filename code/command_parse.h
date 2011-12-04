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

void parser(vector<string> arg)
{

	for(int i=0; i<arg.size();++i){
		cout<<arg[i]<<endl;
	}
	
	string firstArg=arg[0];
	std::transform(firstArg.begin(), firstArg.end(), firstArg.begin(), (int(*)(int)) tolower);
	cout<<firstArg<<endl;
	





}

#endif
