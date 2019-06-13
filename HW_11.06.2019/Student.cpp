#include "Student.h"

Student::Student()
{
	name = "";
	//grades=?
}

Student::Student(string name)
{
	this->name = name;
}

Student::Student(string name, priority_queue<int> q)
{
	this->name = name;
	this->grades = q;
}

priority_queue<int> Student::getQueue()
{
	return grades;
}

void Student::random(int size)
{
	for (int i = 0; i < size; i++)
		grades.push(rand() % 8+5);
}

ostream & operator<<(ostream & os, Student obj)
{
	os << obj.name << "'s GRADES" << endl;
	Student tmp(obj);
	while (!tmp.grades.empty()) {
		os << tmp.grades.top() << endl;
		tmp.grades.pop();
	}
	
	return os;
}
