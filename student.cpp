//student.cpp
#include "student.h" //don't use ;

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	//assigning this pointers to declare new variables
	this->StudentID = studentID; //this allows a field to be assign to a parameter
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;

}

//return each getter
string Student::getStudentID()  {
	return this->StudentID;
}
string Student::getFirstName() const {
	return this->firstName;
}
string Student::getLastName() const {
	return this->lastName;
}
string Student::getEmail()const {
	return this->emailAddress;
}
int Student::getAge() const {
	return this->age;
}
int* Student::getDaysInCourse() {
	return this->daysInCourse;
}
DegreeProgram Student::getDegreeProgram(){
	return this->degreeProgram;
}

//setters
void Student::setStudentID(string studentID) {
	this->StudentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i]; //[i] is for a paticular position
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << this->getStudentID() << "	" //points to the student ID
	 << this->getFirstName() << "	"
	 << this->getLastName() << "	"
	 << this->getEmail() << "	{"
	 << this->getDaysInCourse()[0] << ","
	 << this->getDaysInCourse()[1] << ","
	 << this->getDaysInCourse()[2] << "}	"
	 << degreeProgramStrings[this->getDegreeProgram()] << endl; //allows it to print out strings
}
//no deconstuctor necessary in this case, but it is a good habit to include