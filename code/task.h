//tasks.h

class taskClass
{
	bool apt;
	int id;
	std::string name;
	std::string description;
	std::string project;
//	date dueDate;
//	date timeEst;
//	date timeElapse;
	int priority;    
    int prereq;
  
public:
  void print() const;
};

 
void taskClass::print() const
{
  cout << id << ";" << name << endl;
}
