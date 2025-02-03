#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

int main()
{
   cout << "===== CLIENT DETAILS =====\n";
 Client client1("Omar", 3223, "as1234gg", 9000);
 Client client2("Ahmed", 33100, "0900ahhh", 5000);

 client1.displayInfo();
 client2.displayInfo();

 cout << "\n===== TRANSFER OPERATION =====\n";
 client1.transferTo(2000, client2);

 client1.displayInfo();
 client2.displayInfo();

 cout << "\n===== EMPLOYEE DETAILS =====\n";
 Employee employee("Aya", 23016, "Aya@pass123", 7000);
 employee.displayInfo();

 cout << "\n===== ADMIN DETAILS =====\n";
 Admin admin("May Admin", 1001, "admin1234", 10000, 6000);
 admin.displayInfo();

 return 0;
}
