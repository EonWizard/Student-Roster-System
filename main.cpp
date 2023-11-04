//main.cpp
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


int main() {
	//external data table
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Bolbi,Stroganofsky,bs02@gmail.com,11,1,8,45,SOFTWARE"
	};

	

	const int studentDataTable = 5;
	Roster classRoster;

	for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
	
	cout << "Displaying all students: " << endl;
	classRoster.printAll();
	
	
	cout << "Displaying invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	//for the average days in course
	for (int i = 0; i < studentDataTable; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl;

	cout << "Removing A3 again:" << endl;
	classRoster.remove("A3");


	cout << "DONE." << endl;
	return 0;
}
