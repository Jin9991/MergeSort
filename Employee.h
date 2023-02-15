#pragma once
#include <string> 
using namespace std;
class Employee
{
private:
	int id;
	int age;
	int year;
	string name;
	string job;

public:
	Employee(string a, int b, int c, string d, int e);
	Employee();

	void pirntState();

	string getName();

	int getId();

	int getAge();

	string getJob();

	int getYear();

	void printResult();

};
