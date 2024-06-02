#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Student
{
  string name;
  int score;
};

int main()
{
    vector<Student> students = {
        {"Alice", 95},
        {"Bob", 85},
        {"Alice", 90},
        {"Carol", 75},
        {"Dave", 100}
    };

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name; 
    });

    auto endU = unique(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name == b.name; 
    });
    students.erase(endU, students.end());

    auto max_score_student = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score < b.score;
    });

    vector<Student> excellent_students;
    copy_if(students.begin(), students.end(), back_inserter(excellent_students), [](const Student& student) {
        return student.score >= 90;
    });

    cout << "Студент с наивысшим баллом:" << endl;
    cout << "Имя: " << max_score_student->name << endl;
    cout << "Оценка: " << max_score_student->score << endl;

    cout << "Студенты, сдавшие экзамен на отлично:" << endl;
    for (const auto& [name, score] : excellent_students)
    {
        cout << "Имя: " << name << ", Оценка: " << score << endl;
    }
}