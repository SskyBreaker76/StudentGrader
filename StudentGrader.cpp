#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =====[ CLASSES ]=====
class Student
{
public:
	Student(string, string, float, float, float);
	string name;
	string id;
	float assessment1;
	float assessment2;
	float assessment3;
};

Student::Student(string n, string i, float a1, float a2, float a3)
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
		system("cls");
		string sNam = "";
		string sId = "";
		float sA1 = 0.0f;
		float sA2 = 0.0f;
		float sA3 = 0.0f;

		cout << "\n=====[ STUDENT " << sNum << " ]=====\n\n";

		cout << "Student Name: ";
		getline(cin >> ws, sNam);

		cout << "Student ID: ";
		cin >> sId;

		a1Percent:
		cout << "Assessment 1 Percentage: ";
		cin >> sA1;

		if (sA1 > 100 || sA1 < 0) 
		{
			cout << "Students grade must be between 0 and 100!\n";
			goto a1Percent;
		}

		a2Percent:
		cout << "Assessment 2 Percentage: ";
		cin >> sA2;

		if (sA2 > 100 || sA2 < 0)
		{
			cout << "Students grade must be between 0 and 100!\n";
			goto a1Percent;
		}

		a3Percent:
		cout << "Assessment 3 Percentage: ";
		cin >> sA3;

		if (sA3 > 100 || sA3 < 0)
		{
			cout << "Students grade must be between 0 and 100!\n";
			goto a1Percent;
		}

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

	system("cls");

	float a1total = 0;
	float a1average = 0;

	float a2total = 0;
	float a2average = 0;

	float a3total = 0;
	float a3average = 0;

	string ht;
	string ha;
	float highestTotal = 0.0;
	float highestAverage = 0.0;

	for (int i = 0; i < students.size(); i++) 
	{
		cout << "\n" << students[i].name << " (ID: " << students[i].id << ") Scored " << students[i].assessment1 << "% for assessment 1, " << students[i].assessment2 << "% for assessment 2 and " << students[i].assessment3 << "% for assessment 3!";
		a1total += students[i].assessment1;
		a2total += students[i].assessment2;
		a3total += students[i].assessment3;

		float total = students[i].assessment1 + students[i].assessment2 + students[i].assessment3;

		cout << "\n\n" << students[i].name << " got " << total << " marks total!";
		cout << "\n" << students[i].name << " got an average mark of " << (students[i].assessment1 + students[i].assessment2 + students[i].assessment3 / 3) << "%\n";

		if (total > highestTotal) 
		{
			highestTotal = total;
			ht = students[i].name;
		}

		if (total / 3 > highestAverage) 
		{
			highestAverage = total / 3;
			ha = students[i].name;
		}

		system("pause");
		system("cls");
	}

	a1average = a1total / students.size();
	a2average = a2total / students.size();
	a3average = a3total / students.size();

	cout << "\n=====[ TOTALS ]=====\n";
	cout << "\nClasses total score for assessment 1 is " << a1total << "\nClasses total score for assessment 2 is " << a2total << "\nClasses total score for assessment 3 is " << a3total;
	cout << "\n=====[ AVERAGES ]=====\n";
	cout << "\nClasses average score for assessment 1 is " << a1average << "%\nClasses average score for assessment 2 is " << a2average << "%\nClasses average score for assessment 3 is " << a3average << "%";
	cout << "\n=====[ ADDITIONAL INFORMATION ]=====\n";
	cout << "\n" << ht << " got the highest total mark of " << highestTotal;
	cout << "\n" << ha << " got the highest average mark of " << highestAverage << "%";
}
