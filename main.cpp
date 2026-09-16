#include <iostream>
#include <string>

using namespace std;

// Базовий клас
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void showPersonInfo() const {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
    }
};

// Учень успадковується від людини
class Learner : public Person {
protected:
    string school;

public:
    Learner(string name, int age, string school)
        : Person(name, age) {
        this->school = school;
    }

    void showLearnerInfo() const {
        showPersonInfo();
        cout << "Заклад освіти: " << school << endl;
    }
};

// Школяр успадковується від учня
class Schoolchild : public Learner {
private:
    int grade;

public:
    Schoolchild(string name, int age, string school, int grade)
        : Learner(name, age, school) {
        this->grade = grade;
    }

    void showSchoolchildInfo() const {
        showLearnerInfo();
        cout << "Клас: " << grade << endl;
    }
};

// Студент успадковується від учня
class Student : public Learner {
private:
    int course;

public:
    Student(string name, int age, string school, int course)
        : Learner(name, age, school) {
        this->course = course;
    }

    void showStudentInfo() const {
        showLearnerInfo();
        cout << "Курс: " << course << endl;
    }
};

int main() {
    Schoolchild schoolchild(
        "Іван",
        14,
        "Гімназія №1",
        9
    );

    Student student(
        "Олена",
        19,
        "Університет",
        2
    );

    cout << "Школяр:" << endl;
    schoolchild.showSchoolchildInfo();

    cout << endl;

    cout << "Студент:" << endl;
    student.showStudentInfo();

    return 0;
}