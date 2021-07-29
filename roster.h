#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

class Roster {
	public:
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
			int daysInCourse2, int DaysInCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeprogram);
		void parse(string studentData[]);
		Roster(); 
		~Roster();
		Student* classRosterArray[5];
	private:
		int parseCounter; //used for parse() and add() so that they both simultaneously go through studentData[] together
		int numStudents = 5;
};

#endif


