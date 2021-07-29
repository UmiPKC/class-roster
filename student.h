#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include "degree.h"
using namespace std;

//create Student class
class Student {
	public:	
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		int getStudentAge() const;
		int* getDaysToCompleteArray() const;
		DegreeProgram getDegreeProgram() const;
		void print() const;
		void setStudentID(string newID); //do later
		void setFirstName(string newFirstName);
		void setLastName(string newLastName);
		void setEmail(string newEmail);
		void setStudentAge(int newAge);
		void setDaysToCompleteArray(int newArray[]);
		void setDegreeProgram(DegreeProgram newDegreeProgram);
		Student(string studentID, string firstName, string lastName, string emailAddress,
				int studentAge, int daysInCourse[], DegreeProgram degreeprogram);
		~Student();
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int daysInCourse[3];
		DegreeProgram degreeprogram;
		
};

#endif
