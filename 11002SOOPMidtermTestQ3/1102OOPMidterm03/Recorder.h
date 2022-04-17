#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef vector<pair<string, int>> members; //first=Student name, second=grade

class Student {
public:
	Student();
	Student(string inputname);
	void addGrade(string sub, int point);
	void deleteGrade(string sub);
	void deleteGrade();
	void printGrade();
	string name;
	int id;
	static int count;
	static int idc;
	static vector<string> nameRec;
	vector<pair<string, int>> gradeList;
};

class Class {
public:
	Class();
	void addStudent(Student stu);
	void deleteStudent(Student stu);
	void deleteStudent(string stuName);
	void printNumOfStudent(string subjectName);
	void printNumOfStudent();
	void printAvgScore(string subjectName);
	void printAvgScore();
	void printSubjectInformation(string subjectName);
	void printSubjectInformation();
	void calSub();
	vector<pair<string, members>> allSub; //first=Subject name, second=members
	vector<Student> allStu;
};