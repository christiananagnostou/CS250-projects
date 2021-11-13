	// GradeBook.cpp : Defines the entry point for the console application.
	//

	#include "stdafx.h"
	#include "GradeBook.h"
	#include <iostream>
	using namespace std;

	int main()
	{
		GradeBook gBook;
		gBook.setCourseName("Math");
		gBook.setCourseInstructorName("Mr.Smith");
		gBook.displayMessage();
		system("pause");
		return 0;
	}
	GradeBook::GradeBook(string name)
	{
		setCourseName(name);
	}
	void GradeBook::setCourseName(string name)
	{
		courseName = name;
	}
	string GradeBook::getCourseName()
	{
		return courseName;
	}
	void GradeBook::setCourseInstructorName(string instructorName)
	{
		courseInstructorName = instructorName;
	}
	string GradeBook::getCourseInstructorName()
	{
		return courseInstructorName;
	}
	void GradeBook::displayMessage()
	{
		cout << "Welcome to the gradebook for\n" << getCourseName() << "!" << endl;
		cout << "This course is presented by:\n" << getCourseInstructorName() << endl;
	}