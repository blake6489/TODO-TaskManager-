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

	taskClass p;
	p.setId(5);
	
	
	

	
	string u=fileReadMmap("README");
	date d2(2002,2,16);
	date d1(2002,2,18);
	

	

	return 0;
}
