/* Define a class Person having name as a data member. Inherit two classes Student and
Employee from Person. Student has additional attributes as course, marks and year and
Employee has department and salary. Write display() method in all the three classes to
display the corresponding attributes. Provide the necessary methods to show runtime
polymorphism
*/

#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;

public:
    Person(const string& name) : name(name) {}

    // Virtual function to display person's information
    virtual void display() const {
        cout << "Name: " << name << endl;
    }
};

// Derived class Student inheriting from Person
class Student : public Person {
private:
    string course;
    float marks;
    int year;

public:
    Student(const string& name, const string& course, float marks, int year)
        : Person(name), course(course), marks(marks), year(year) {}

    // Overridden function to display student's information
    void display() const override {
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Employee inheriting from Person
class Employee : public Person {
private:
    string department;
    float salary;

public:
    Employee(const string& name, const string& department, float salary)
        : Person(name), department(department), salary(salary) {}

    // Overridden function to display employee's information
    void display() const override {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Creating objects of Student and Employee classes
    Person* person1 = new Person("John Doe");
    Student* student1 = new Student("Alice", "Computer Science", 85.5, 2023);
    Employee* employee1 = new Employee("Bob", "Engineering", 75000.0);

    // Displaying information using display() method
    cout << "Person's information:" << endl;
    person1->display();
    cout << endl;

    cout << "Student's information:" << endl;
    student1->display();
    cout << endl;

    cout << "Employee's information:" << endl;
    employee1->display();
    cout << endl;

    // Clean up memory
    delete person1;
    delete student1;
    delete employee1;

    return 0;
}
