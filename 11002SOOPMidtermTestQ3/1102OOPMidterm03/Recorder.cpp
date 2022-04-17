#include "Recorder.h"

using namespace std;

int Student::count = 0;
int Student::idc = 0;
vector<string> Student::nameRec;

Student::Student() {
	id = idc;
	name = "Student";
	name += count + '0';
	nameRec.push_back(name);
	count++;
	idc++;
}

Student::Student(string inputname) {
	string reserv = "Student";
	id = idc;
	auto it = find(nameRec.begin(), nameRec.end(), inputname);
	if (it != nameRec.end()) {
		name = "Student";
		name += count + '0';
		nameRec.push_back(name);
		cout << "Error: The name " << inputname << " exists. Use default name: Student" << count << "." << endl;
		count++;
		idc++;
		return;
	}
	if (inputname.find(reserv) != string::npos) {
		name = "Student";
		name += count + '0';
		nameRec.push_back(name);
		cout << "Error: The name Student is reserved word. Use default name: Student" << count << "." << endl;
		count++;
		idc++;
		return;
	}
	name = inputname;
	nameRec.push_back(inputname);
	idc++;
}

int vFindByStr(string target, vector<pair<string,int>> data) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].first == target) {
			return i;
		}
	}
	return -1;
}

void Student::addGrade(string sub, int point) {
	int findresult = vFindByStr(sub, gradeList);
	if (findresult == -1) { //new subject
		gradeList.push_back(make_pair(sub, point));
		return;
	}
	else {
		gradeList[findresult].second = point;
	}
}

void Student::deleteGrade(string sub) {
	int findresult = vFindByStr(sub, gradeList);
	if (findresult == -1) { //new subject
		cout << "Error: Subject " << sub << " could not be found." << endl;
		return;
	}
	else {
		gradeList.erase(gradeList.begin() + findresult);
	}
}

void Student::deleteGrade() {
	gradeList.clear();
}

void Student::printGrade() {
	cout << "ID: " << id << " Name: " << name << endl;
	if (gradeList.empty()) {
		cout << "Error: Grade could not be found." << endl;
	}
	else {
		for (auto it : gradeList) {
			cout << it.first << " " << it.second << endl;
		}
	}
}

Class::Class(){
	
}
int vfindSubjectStr(string target, vector<pair<string, members>> data) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].first == target) {
			return i;
		}
	}
	return -1;
}

void Class::calSub() {
	for (Student stu : allStu) { //traverse all student data
		for (auto subject : stu.gradeList) { //traverse all subject and grade of the student
			int target = vfindSubjectStr(subject.first, allSub);
			if (target == -1) {
				members temp;
				temp.push_back(make_pair(stu.name, subject.second));
				allSub.push_back(make_pair(subject.first, temp));
				continue;
			}
			else {
				allSub[target].second.push_back(make_pair(stu.name, subject.second));
			}
		}
	}
}

void Class::addStudent(Student stu) {
	for (auto i = allStu.begin(); i != allStu.end(); i++) {
		if (i->name == stu.name) {
			cout << "Error: The student " << stu.name << " is already in the class." << endl;
			return;
		}
	}
	allStu.push_back(stu);
	return;
}

void Class::deleteStudent(Student stu) {
	for (auto i = allStu.begin(); i != allStu.end(); i++) {
		if (i->name == stu.name) {
			allStu.erase(i);
			return;
		}
	}
	cout << "Error: Student " << stu.name << " could not be found." << endl;
	return;
}

void Class::deleteStudent(string stuName)
{
	for (auto i = allStu.begin(); i != allStu.end(); i++) {
		if (i->name == stuName) {
			allStu.erase(i);
			return;
		}
	}
	cout << "Error: Student " << stuName << " could not be found." << endl;
	return;
}

void Class::printNumOfStudent(string subjectName)
{
	this->calSub();
	int it = vfindSubjectStr(subjectName, allSub);
	if (it == -1) {
		cout << "Error: Subject " << subjectName << " could not be found." << endl;
		allSub.clear();
		return;
	}
	else {
		int num = allSub[it].second.size();
		cout << allSub[it].first << ' ' << num << endl;
		allSub.clear();
		return;
	}

}

void Class::printNumOfStudent()
{
	this->calSub();
	for (auto it : allSub) {
		int num = it.second.size();
		cout << it.first << ' ' << num << endl;
	}
	allSub.clear();
	return;
}

void Class::printAvgScore(string subjectName)
{
	this->calSub();
	int it = vfindSubjectStr(subjectName, allSub);
	if (it == -1) {
		cout << "Error: Subject " << subjectName << " could not be found." << endl;
		allSub.clear();
		return;
	}
	else {
		float avg;
		int sum = 0;
		for (auto i = allSub[it].second.begin(); i != allSub[it].second.end(); i++) {
			sum += i->second;
		}
		avg = sum / allSub[it].second.size();
		cout << allSub[it].first << ' ' << avg << endl;
		allSub.clear();
		return;
	}
}

void Class::printAvgScore()
{
	this->calSub();
	for (auto it : allSub) {
		float avg;
		int sum = 0;
		for (auto i = it.second.begin(); i != it.second.end(); i++) {
			sum += i->second;
		}
		avg = sum / it.second.size();
		cout << it.first << ' ' << avg << endl;
	}
	allSub.clear();
	return;
}

void Class::printSubjectInformation(string subjectName)
{
	this->calSub();
	int it = vfindSubjectStr(subjectName, allSub);
	if (it == -1) {
		cout << "Error: Subject " << subjectName << " could not be found." << endl;
		allSub.clear();
		return;
	}
	else {
		cout << "Subject name: " << allSub[it].first << endl;
		int num = allSub[it].second.size();
		cout << "Num of students: " << num << endl;
		for (auto n : allSub[it].second) {
			cout << n.first << ' ' << n.second << endl;
		}
		allSub.clear();
		return;
	}
}

void Class::printSubjectInformation()
{
	this->calSub();
	for (auto it : allSub) {
		cout << "Subject name: " << it.first << endl;
		int num = it.second.size();
		cout << "Num of students: " << num << endl;
		for (auto n : it.second) {
			cout << n.first << ' ' << n.second << endl;
		}
	}
	allSub.clear();
	return;
}
