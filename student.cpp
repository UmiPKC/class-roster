#include<iostream>
#include<string>
#include "student.h"
using namespace std;

string Student::getStudentID() const {
	return this->studentID;
}

string Student::getFirstName() const {
	return this->firstName;
}

string Student::getLastName() const {
	return this->lastName;
}

string Student::getEmail() const {
	return this->emailAddress;
}

int Student::getStudentAge() const {
	return this->studentAge;
}

int* Student::getDaysToCompleteArray() const {
	int completeArray[3] = { this->daysInCourse[0], this->daysInCourse[1], this->daysInCourse[2] };
	return completeArray;
}

DegreeProgram Student::getDegreeProgram() const {
	return this->degreeprogram;
}

void Student::print() const {
	string degreeProgramString; //convert degreeprogram into string
	if (getDegreeProgram() == SOFTWARE) {
		degreeProgramString = "SOFTWARE";
	}

	else if (getDegreeProgram() == NETWORK) {
		degreeProgramString = "NETWORK";
	}

	else if (getDegreeProgram() == SECURITY) {
		degreeProgramString = "SECURITY";
	}

	int* daysInCourse = getDaysToCompleteArray();

	cout << this->studentID << "\t First Name: " << getFirstName() << "\t Last Name: " << getLastName() << "\t Age: " << getStudentAge()
			<< "\t daysInCourse: " << "{" << daysInCourse[0] << " " << daysInCourse[1] << " " << daysInCourse[2] << "}" << " Degree Program: " << degreeProgramString << endl;
}

void Student::setStudentID(string newID) {
	this->studentID = newID;
	cout << "Successfully changed Student ID." << endl;
}

void Student::setFirstName(string newFirstName) {
	this->firstName = newFirstName;
	cout << "Successfully changed first name." << endl;
}

void Student::setLastName(string newLastName) {
	this->lastName = newLastName;
	cout << "Successfully changed last name." << endl;
}

void Student::setEmail(string newEmail) {
	this->emailAddress = newEmail;
	cout << "Successfully changed email address." << endl;
}

void Student::setStudentAge(int newAge) {
	this->studentAge = newAge;
	cout << "Successfully changed age." << endl;
}

void Student::setDaysToCompleteArray(int newArray[]) {
	this->daysInCourse[0] = newArray[0];
	this->daysInCourse[1] = newArray[1];
	this->daysInCourse[2] = newArray[2];
	cout << "Successfully changed daysInCourse." << endl;
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
	this->degreeprogram = newDegreeProgram;
	cout << "Successfully changed degree program." << endl;
}

Student::Student(string conStudentID, string conFirstName, string conLastName, string conEmailAddress,
	int conStudentAge, int conDaysInCourse[], DegreeProgram conDegreeprogram) {
	studentID = conStudentID;
	firstName = conFirstName;
	lastName = conLastName;
	emailAddress = conEmailAddress;
	studentAge = conStudentAge;
	daysInCourse[0] = conDaysInCourse[0];
	daysInCourse[1] = conDaysInCourse[1];
	daysInCourse[2] = conDaysInCourse[2];
	degreeprogram = conDegreeprogram;
}

Student::~Student() {

}