
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//implementing parse method
void Roster::parse(string data) { //for each row of strings
	size_t rhs = data.find(","); // rhs = right hand side of the string
	string studentID = data.substr(0, rhs);

	size_t lhs = rhs + 1; //lhs = left hand side of the string
	rhs = data.find(",", lhs); // starting from lhs
	string firstName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string lastName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string emailAddress = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = stoi(data.substr(lhs, rhs - lhs)); //stoi = string to integer

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int d0 = stoi(data.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int d1 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int d2 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string strDegreeProgram = data.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE; //default case
	//conditional enum
	if (strDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}


	//call add method
	add(studentID, firstName, lastName, emailAddress, age, d0, d1, d2, degreeProgram);
}

//implementation of the add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int d0, int d1, int d2, DegreeProgram degreeProgram) {

	//last index prefix++ increments array 
	int days[3] = { d0, d1, d2 };
	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram); //full constructor
}

//print all to display student information
void Roster::printAll() {
	for (int i = 0; i <= index; i++) Roster::classRosterArray[i]->print(); 
	
}



//determines valid and invalid emails in the student data string
void Roster::printInvalidEmails() {

	bool found = false;
	for (int i = 0; i <= index; i++) {

		string emailAddress = classRosterArray[i]->getEmail();
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) {
			found = true;
			cout << emailAddress << " - is invalid" << endl;
		}

	}
}

//prints average days in course
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID){
			cout << classRosterArray[i]->getStudentID() << ", average days in course is: "
				<< (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3
				<< " day(s)" << endl << endl; // divided by 3 as there are three courses and we only want integer days in this project
		}
		
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) { //made to display students that match a degree program
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print(); //if the index in the array matches the degree program, it will print
	}
	cout << endl;
}


//the student that will be removed where the student's id will come in as a parameter
void Roster::remove(string studentID) {
	bool found = false; //default case where proper studentID is not found
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			if (i < classRosterTable - 1) {
				Student* tmp = classRosterArray[i]; //tmp is a temp variable to swap 
				classRosterArray[i] = classRosterArray[classRosterTable - 1];
				classRosterArray[classRosterTable -1] = tmp;
			}
			index--; //make the last book invisible
		}
		
	}
	if (found) {
		cout << endl;
	}
	else cout << studentID << " not found." << endl;
}


//deconstructor for dynamically allocated array
Roster::~Roster() {
	for (int i = 0; i < classRosterTable; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr; //points to null to prevent crash
	}
};

