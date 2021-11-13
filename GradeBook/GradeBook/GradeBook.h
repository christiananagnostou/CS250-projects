#pragma once
#include <string>
using namespace std;

class GradeBook		//class definition
{
public:
	GradeBook(string);
	void setCourseName(string);
	string getCourseName(void){return courseName;}
	void setCourseInstructorName(string);
	string getCourseInstructorName(void){return courseInstructorName;}
	void displayMessage();

	GradeBook(){ courseName = "0"; }
	GradeBook(){ courseInstructorName = "0"; }
	GradeBook(string courseName){ courseName = "Math"; }
	GradeBook(string courseInstructorName){ courseInstructorName = "Mr. Smith"; }
private:
	string courseName;
	string courseInstructorName;
};

