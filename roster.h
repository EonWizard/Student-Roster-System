#pragma once
//roster.h
#ifndef roster_h
#define roster_h

#include <iostream>
#include "student.h"
using namespace std;

class Roster {
public:
	int index = -1; //to increment starting at 0 instead of 1
	const static int classRosterTable = 5;
	Student* classRosterArray[classRosterTable]; //(not dynamically declared)

public:

	//implement parse, add, and printAll

	//define parse method - goes through comma delimited strings and gets student data
	void parse(string data);

	//define add method 
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int d0, int d1, int d2, DegreeProgram degreeProgram);


	//define the printAll function to print student data
	void printAll();

	//define printDegreeProgarm that prints student information for a degree program based on the enum type
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//define printInvalidEmails which determines if email is valid and print any invalid emails
	void printInvalidEmails();

	//define average days in course to print a student's average days in the three courses
	void printAverageDaysInCourse(string studentID);

	//define remove method for removing students from the roster
	void remove(string studentID);

	~Roster(); //deconstuctor 


};
#endif