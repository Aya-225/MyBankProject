
#pragma once
#include "Employee.h"

class Admin : public Employee {
private:
    double balance;

public:
    Admin() : balance(0) {}

    Admin(string name, int id, string password, double salary, double balance)
        : Employee(name, id, password, salary), balance(balance) {}

    void setBalance(double newBalance) {
        if (Validation::isValidBalance(newBalance)) balance = newBalance;
        else cout << "Error: Minimum balance must be 1500.\n";
    }

    double getBalance() const { return balance; }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Admin Balance: " << balance << endl;
    }
};
