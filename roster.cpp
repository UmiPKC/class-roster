#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "roster.h"
using namespace std;



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
				int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[parseCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}

void Roster::remove(string studentID) {
	cout << "Removing " << studentID << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "Student " << studentID << " was not found." << endl;
		}

		else if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

void Roster::printAll() { //loop through array and use Student::print() for each student
	cout << "Displaying all students: " << endl;
	for (int i = 0; i < numStudents; ++i) { 
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
		else {   //if classRosterArray[i] == nullptr, skip it and continue going through rest of the array
			continue;
		}
		cout << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int* avgArrayPtr;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			avgArrayPtr = classRosterArray[i]->getDaysToCompleteArray();
			int arrayAverage = (avgArrayPtr[0] + avgArrayPtr[1] + avgArrayPtr[2]) / 3;
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << ", averages " << arrayAverage << " days in a course." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		string emailCheck = classRosterArray[i]->getEmail();
		if (emailCheck.find(' ') != string::npos) {
			cout << emailCheck << " - no spaces allowed." << endl;
		}

		else if (emailCheck.find('.') == string::npos) {
			cout << emailCheck << " - missing a period." << endl;
		}

		else if (emailCheck.find('@') == string::npos) {
			cout << emailCheck << " - missing an @ symbol." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {

	string degreeProgramString; //convert degreeprogram into string
	if (degreeprogram == SOFTWARE) {
		degreeProgramString = "SOFTWARE";
	}

	else if (degreeprogram == NETWORK) {
		degreeProgramString = "NETWORK";
	}

	else if (degreeprogram == SECURITY) {
		degreeProgramString = "SECURITY";
	}
	cout << "Showing students in degree program: " << degreeProgramString << endl;

	for (int i = 0; i < 5; ++i) {
		DegreeProgram checkDegree;
		checkDegree = classRosterArray[i]->getDegreeProgram();
		if (checkDegree == degreeprogram) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}

void Roster::parse(string studentArray[]) {
	for (int i = 0; i < numStudents; ++i) {
		string my_str = studentArray[i];
		vector<string> result;
		DegreeProgram degree;
		istringstream s_stream(my_str);

		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}

		//if-else turning result.at(8) into its proper DegreeProgram value
		if (result.at(8) == "SECURITY") {
			degree = SECURITY;
		}

		else if (result.at(8) == "NETWORK") {
			degree = NETWORK;
		}

		else if (result.at(8) == "SOFTWARE") {
			degree = SOFTWARE;
		}


		this->add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stoi(result.at(5)), stoi(result.at(6)), stoi(result.at(7)), degree);
		parseCounter = parseCounter + 1;
	}
}

Roster::Roster() {
	classRosterArray[4] = {};
	parseCounter = 0;
	numStudents = 5;
}

Roster::~Roster() { //releasing array of new Student pointers
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
