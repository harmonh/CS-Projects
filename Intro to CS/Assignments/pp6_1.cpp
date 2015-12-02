/*********************************************************************************
**Program: pp6_1.cpp
**Author: Holly Harmon
**Description: Grading program following a grading policy and returning a student's
grade based on two quizes, a midterm, and a final.
**Input: Student's grades
**Output: Record of students scores, their average numeric score for the course
and their letter grade.
*********************************************************************************/

#include <iostream>
using namespace std;

struct StudentRecords
{
	double quiz1; //10 points
	double quiz2; //10 points - 25% for both
	double midtermExam; //100 points - 25%
	double finalExam; //100 points - 50%
	int courseAveScore;
	char letterGrade;
};

void student_scores(StudentRecords& student);
void grade_calculations(StudentRecords& student);
void print_student_records(StudentRecords student);

int main ()
{
	StudentRecords studentOne;
	
	student_scores(studentOne);
	grade_calculations(studentOne);
	print_student_records(studentOne);

	return 0;

}

void student_scores(StudentRecords& student)
{
	cout << "Student score on Quiz 1 (out of 10 possible points): ";
	cin >> student.quiz1;
	cout << "Student score on Quiz 2 (out of 10 possible points): ";
	cin >> student.quiz2;
	cout << "Student score on Midterm Exam (out of 100 possible points): ";
	cin >> student.midtermExam;
	cout << "Student score on Final Exam (out of 100 possible points): ";
	cin >> student.finalExam;
}

void grade_calculations(StudentRecords& student)
{
	double quiz_per;
	double midterm_per;
	double final_per;
	double quiz_weighted;
	double midterm_weighted;
	double final_weighted;
	double weightedGrade;

	student.courseAveScore = (student.quiz1 + student.quiz2 + student.midtermExam + student.finalExam);
	quiz_per = (student.quiz1 + student.quiz2) / 20;
	midterm_per = student.midtermExam / 100;
	final_per = student.finalExam / 100;
	
	quiz_weighted = (quiz_per * .25) * 100;
	midterm_weighted = (midterm_per * .25) * 100;
	final_weighted = (final_per * .50) * 100;
	weightedGrade = quiz_weighted + midterm_weighted + final_weighted;
	
	if(weightedGrade >= 90)
	{
		student.letterGrade = 'A';
	}
	else if(weightedGrade >= 80) {
		student.letterGrade = 'B';
	}
	else if(weightedGrade >= 70) {
		student.letterGrade = 'C';
	}
	else if(weightedGrade >= 60) {
		student.letterGrade = 'D';
	}
	else {
		student.letterGrade = 'F';
	}
}

void print_student_records(StudentRecords student)
{
	cout << "Quiz 1 Score: " << student.quiz1 << "/10\n";
	cout << "Quiz 2 Score: " << student.quiz2 << "/10\n";
	cout << "Midterm Exam Score: " << student.midtermExam << "/100\n";
	cout << "Final Exam Score: " << student.finalExam << "/100\n";
	cout << "Numeric Score for Entire Course: " << student.courseAveScore << "/220\n";
	cout << "Final Letter Grade for Course: " << student.letterGrade << endl;
}