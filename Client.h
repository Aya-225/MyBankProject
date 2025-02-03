
#include "Person.h"

class Client : public Person {
private:
    double balance;

public:
    Client() : balance(1500) {}

    Client(string name, int id, string password, double newBalance) : Person(name, id, password) {
        balance = Validation::isValidBalance(newBalance) ? newBalance : 1500;
    }

    void setBalance(double newBalance) {
        if (Validation::isValidBalance(newBalance)) balance = newBalance;
        else cout << "Error: Minimum balance must be 1500.\n";
    }

    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else cout << "Error: Invalid deposit amount.\n";
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) balance -= amount;
        else cout << "Error: Insufficient funds.\n";
    }

    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && balance - amount >= 1500) {
            recipient.deposit(amount);
            balance -= amount;
        }
        else cout << "Error: Cannot transfer. Minimum balance must remain 1500.\n";
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Balance: " << balance << endl;
    }
};
