#include <iostream>
#include <vector>

using namespace std;

// =====[ CLASSES ]=====
class Student
{
public:
	Student(string, int, float, float, float);
	string name;
	int id;
	float assessment1;
	float assessment2;
	float assessment3;
};

Student::Student(string n, int i, float a1, float a2, float a3)
{
	name = n;
	id = i;
	assessment1 = a1;
	assessment2 = a2;
	assessment3 = a3;
}

int main()
{
	vector<Student>students = {};

	bool run = true;

	int sNum = 1;

	while (run == true) 
	{
		string sNam = "";
		int sId = 0;
		float sA1 = 0.0f;
		float sA2 = 0.0f;
		float sA3 = 0.0f;

		cout << "\n=====[ STUDENT " << sNum << " ]=====\n\n";

		cout << "Student Name: ";
		cin >> sNam;

		cout << "Student ID: ";
		cin >> sId;

		cout << "Assessment 1 Percentage: ";
		cin >> sA1;

		cout << "Assessment 2 Percentage: ";
		cin >> sA2;

		cout << "Assessment 3 Percentage: ";
		cin >> sA3;

		Student student = Student(sNam, sId, sA1, sA2, sA3);

		students.push_back(student);

		bool addStudent;
		string e;

		cout << "\nDo you want to add another student? (y/n)";
		cin >> e;

		addStudent = (e == "y" && e != "n");
		
		if (addStudent == false) 
		{
			run = false;
		}

		sNum++;
	}

	float a1total = 0;
	float a1average = 0;

	float a2total = 0;
	float a2average = 0;

	float a3total = 0;
	float a3average = 0;

	for (int i = 0; i < students.size(); i++) 
	{
		cout << "\n" << students[i].name << " (ID: " << students[i].id << ") Scored " << students[i].assessment1 << "% for assessment 1, " << students[i].assessment2 << "% for assessment 2 and " << students[i].assessment3 << "% for assessment 3!";
		a1total += students[i].assessment1;
		a2total += students[i].assessment2;
		a3total += students[i].assessment3;
	}

	a1average = a1total / students.size();
	a2average = a2total / students.size();
	a3average = a3total / students.size();

	cout << "\n=====[ TOTALS ]=====\n";
	cout << "\nClasses total score for assessment 1 is " << a1total << "%\nClasses total score for assessment 2 is " << a2total << "%\nClasses total score for assessment 3 is " << a3total << "%";
	cout << "\n=====[ AVERAGES ]=====\n";
	cout << "\nClasses average score for assessment 1 is " << a1average << "%\nClasses average score for assessment 2 is " << a2average << "%\nClasses average score for assessment 3 is " << a3average << "%";
}
