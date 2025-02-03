
#pragma once
#include "Admin.h"
#include <vector>

class Abstraction {
public:
    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;
    virtual vector<Client> getAllClients() const = 0;
    virtual vector<Employee> getAllEmployees() const = 0;
    virtual vector<Admin> getAllAdmins() const = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};
