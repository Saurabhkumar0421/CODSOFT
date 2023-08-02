#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> studentNames;
    vector<double> grades;
    string name;
    double grade;

    cout << "Welcome to the Student Grade Management System!" << endl;

    char addAnother;
    do {
        cout << "\nEnter student name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter grade for " << name << ": ";
        cin >> grade;

        studentNames.push_back(name);
        grades.push_back(grade);

        cout << "Do you want to add another student? (y/n): ";
        cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    int numStudents = studentNames.size();
    if (numStudents == 0) {
        cout << "\nNo student data entered. Exiting program.\n";
        return 0;
    }

    double totalGrades = 0.0;
    double highestGrade = grades[0];
    double lowestGrade = grades[0];

    for (double grade : grades) {
        totalGrades += grade;
        if (grade > highestGrade)
            highestGrade = grade;
        if (grade < lowestGrade)
            lowestGrade = grade;
    }

    double averageGrade = totalGrades / numStudents;

    cout << "\nStudent Grade Summary:" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": " << grades[i] << endl;
    }
    cout << "-----------------------" << endl;
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}
