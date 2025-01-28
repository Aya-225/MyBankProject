#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Validation {
public:
    static bool isvalidAlphaName(const string& name) {
        if (name.length() < 5 || name.length() > 20) {
            return false;
        }
        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    static bool isvalidPassword(const string& password) {
        return password.size() >= 8 && password.size() <= 20;
    }

    static bool isvalidBalance(double balance) {
        return balance >= 1500;
    }

    static bool isvalidSalary(double salary) {
        return salary >= 5000;
    }
};

class person {
protected:
    int id;
    string name;
    string password;

public:
    person() {
        id = 0;
        name = "";
        password = "";
    }

    person(string name, int id, string password) {
        if (Validation::isvalidAlphaName(name)) {
            this->name = name;
        }
        else {
            cout << "Error: Invalid name. Name must be alphabetic and between 5 and 20 characters.\n";
            this->name = "Invalid Name";
        }

        this->id = id;

        if (Validation::isvalidPassword(password)) {
            this->password = password;
        }
        else {
            cout << "Error: Invalid password. Password must be between 8 and 20 characters.\n";
            this->password = "InvalidPass";
        }
    }

    void setname(const string& newname) {
        if (Validation::isvalidAlphaName(newname)) {
            name = newname;
        }
        else {
            cout << "Error: Name must be alphabetic and between 5 and 20 characters.\n";
        }
    }

    void setid(int id) {
        this->id = id;
    }

    void setPassword(const string& newPassword) {
        if (Validation::isvalidPassword(newPassword)) {
            password = newPassword;
        }
        else {
            cout << "Error: Password must be between 8 and 20 characters.\n";
        }
    }

    string getname() {
        return name;
    }
    int getid() {
        return this->id;
    }

    string getpassword() {
        return password;
    }






    void displayInfo() {
        cout << "name = " << name << endl;
        cout << "id = " << id << endl;
        cout << "password  = " << password << endl;




    }


};


class client : public person {

private:
    double balance;
public:
    client() {
        this->balance = 0;

    }
    client(string name, int id, string password, double balance) :person(name, id, password) {

        this->balance = balance;
    }
    void setbalance(double newbalance) {
        if (Validation::isvalidBalance(newbalance)) {
            balance = newbalance;
        }
        else {
            cout << "Invalid balance Minimum balance must be 1500.\n";
        }
    }
    double getbalance() {
        return balance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit succesful \n " << "New Balance : " << balance << endl;
        }
        else {
            cout << "Invalid deposit amount.\n";
        }

    }

    void withdrow(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << " Withdraw is successful" << balance << endl;
        }
        else
            cout << " Withdraw isn't successful" << endl;
    }
    void transferto(double amount, client& b) {
        if (balance >= amount) {
            b.deposit(amount);
            balance -= amount;
            cout << balance << endl;
        }
        else
            cout << "The balance is not enough to transfer" << endl;
    }
    void checkBalance() {
        cout << "balance =  " << balance << endl;

    }


    void displayInfo() {
        person::displayInfo();
        cout << "balance   =" << balance << endl;



    }



};
class Employee : public person {
protected:
    double salary;
public:
    Employee() : salary(5000) {
    }
    Employee(string name, int id, string password, double newSalary) :person(name, id, password)
    {
        salary = newSalary;
    }
    void setSalary(double newSlaray) {
        if (Validation::isvalidSalary(newSlaray)) {
            salary = newSlaray;
            cout << "Salary updated successfully to " << salary << ".\n";

        }
        else {
            cout << "Error the minimum salary must be 5000. \n";

        }
    }
    string getName() {
        return name;
    }
    double getSalary() {
        return salary;
    }
    void displayInfo() {
        person::displayInfo();
        cout << "Salary = " << salary << endl;

    }
};
class Admin :public Employee
{
private:
    double balance;

public:
    Admin() {
        balance = 0;
    }
    Admin(string name, int id, string password, double salary, double balance) :Employee(name, id, password, salary) {
        this->balance = balance;
    }

    void setbalance(double newbalance) {
        if (Validation::isvalidBalance(newbalance)) {
            balance = newbalance;
        }
        else {
            cout << "Invalid balance Minimum balance must be 1500.\n";
        }
    }
    double getBalance() {
        return balance;
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Balance = " << balance << endl;
        cout << "========================================================\n";
    }

};





int main()
{
  cout << "=====CLIENT DETAILS====\n";
    client a("omar", 3223, "as1234", 900), b("ahmed", 33100, "0900ah", 500);
    b.displayInfo();
    a.displayInfo();
    cout << "\n======TRANSFER OPERATION======\n";
    a.transferto(500, b);
    b.displayInfo();
    a.displayInfo();
    cout << "=====EMPLOYEE DETAILS=====\n";
    Employee e("Aya", 23016, "Aya@pass", 7000);
    e.displayInfo();
    e.setSalary(8000);
    e.setSalary(4000);


    cout << "\n=== ADMIN DETAILS ===\n";
    Admin ad("May Admin", 1001, "admin1234", 10000, 6000);
    ad.displayInfo();
}
