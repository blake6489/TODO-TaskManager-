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
using namespace std;

#include "tools/utils.cpp"
#include "task.h"



int main (int argc, char* argv[])
{
	taskClass p;
	p.print();
	

	return 0;
}
