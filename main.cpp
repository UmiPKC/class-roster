#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "roster.h"
using namespace std;


int main() {
	string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Umi,Thompson,uthomp1@wgu.edu,20,22,35,42,SOFTWARE"
	};

	cout << "C867: Scripting and Programming Foundations" << endl << "Programming language: C++" << endl << "WGU ID: #001343274" << endl << "Name: Umi Thompson" << endl;
	cout << endl;

	Roster classRoster;
	classRoster.parse(studentData);
	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3"); //should return an error message
	cout << endl;
	
}