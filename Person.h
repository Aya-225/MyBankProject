
#pragma once
#include "Validation.h"

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person() : id(0), name(""), password("") {}

    Person(string name, int id, string password) : id(id) {
        this->name = Validation::isValidAlphaName(name) ? name : "Invalid Name";
        this->password = Validation::isValidPassword(password) ? password : "InvalidPass";
    }

    void setName(const string& newName) {
        if (Validation::isValidAlphaName(newName)) name = newName;
        else cout << "Error: Invalid name.\n";
    }

    void setId(int id) { this->id = id; }

    void setPassword(const string& newPassword) {
        if (Validation::isValidPassword(newPassword)) password = newPassword;
        else cout << "Error: Invalid password.\n";
    }

    string getName() const { return name; }
    int getId() const { return id; }
    string getPassword() const { return password; }

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nPassword: " << password << endl;
    }
};
