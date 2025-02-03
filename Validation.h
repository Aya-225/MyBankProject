
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Validation {
public:
    static bool isValidAlphaName(const string& name) {
        if (name.length() < 5 || name.length() > 20) return false;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    static bool isValidPassword(const string& password) {
        return password.size() >= 8 && password.size() <= 20;
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000;
    }
};
