
#pragma once
#include "Person.h"

class Employee : public Person {
protected:
    double salary;

public:
    Employee() : salary(5000) {}

    Employee(string name, int id, string password, double newSalary) : Person(name, id, password) {
        salary = Validation::isValidSalary(newSalary) ? newSalary : 5000;
    }

    void setSalary(double newSalary) {
        if (Validation::isValidSalary(newSalary)) salary = newSalary;
        else cout << "Error: Minimum salary must be 5000.\n";
    }

    double getSalary() const { return salary; }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Salary: " << salary << endl;
    }
};
