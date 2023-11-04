#pragma once
#ifndef student_h
#define student_h

//student.h
#include <iostream>
//include DegreeProgram enum
#include "degree.h"
//allows for header to use strings
#include<string>
using namespace std;


class Student {
	//variables
public:
	const static int daysInCourseArray = 3;
private:
	string StudentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArray]; //declartaion of array
	DegreeProgram degreeProgram;
public:
	//functions
	string getStudentID(); //example of a accessor
	void setStudentID(string studentID); //example of a mutator 
	string getFirstName() const;
	void setFirstName(string firstName);
	string getLastName() const;
	void setLastName(string lastName);
	string getEmail() const;
	void setEmail(string emailAddress);
	int getAge() const;
	void setAge(int age);
	int* getDaysInCourse() ;
	void setDaysInCourse(int daysInCourse[]); //putting in the array as a parameter
	DegreeProgram getDegreeProgram();
	void setDegreeProgram(DegreeProgram degreeProgram); //parameter of type DegreeProgram

	//constuctor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	
		//define print function
	void print();

	



};
#endif
