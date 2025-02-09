
#pragma once
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
class Parser {
public:
	static vector <string> split(string line) {
		vector <string> result;
		stringstream obj(line);
		string word;
		while (obj >> word) {
			result.push_back(word);
		}
		return result;
     }
	static Client parseToClient(string line) {
		vector <string> data = split(line);
		int id = stoi (data[0]);
		string name = data[1];
		string password = data[2];
		double balance = stod(data[3]);
		return Client( name,id, password, balance);
	}
	static Employee parseToEmployee(string line) {
		vector <string> data = split(line);
		int id = stoi(data[0]);
		string name = data[1];
		string password = data[2];
		double salary = stod(data[3]);
		return Employee(name, id, password, salary);
	}
	static Admin parseToAdmin(string line) {
		vector <string> data = split(line);
		int id = stoi(data[0]);
		string name = data[1];
		string password = data[2];
		double salary = stod(data[3]);
		return Admin (name, id, password, salary);
	}
};
