#include <iostream>
#include <cstring>

/***************
 Employee
 ***************/
class Employee {
public:
	Employee() : name{nullptr}, addr{nullptr} {};
	Employee(const char *pname, const char *paddr) { setName(pname); setAddr(paddr); };
	void setName(const char *pname) { name = new char[strlen(pname)+1]; strcpy(name, pname); }
	void setAddr(const char *paddr) { addr = new char[strlen(paddr)+1]; strcpy(addr, paddr); }
	virtual void displayInfo() const;
protected:
	char *name;
	char *addr;
};

void Employee::displayInfo() const {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Addr: " << this->addr << std::endl;
}
/***************
 Regular
 ***************/
class Regular : public Employee {
public:
	Regular() : salary{0} {};
	Regular(const char *pname, const char *paddr, const double dsalary) : Employee(pname,paddr), salary{dsalary} {};
	void displayInfo();
private:
	double salary;
};

void Regular::displayInfo() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Addr: " << this->addr << std::endl;
	std::cout << "salary: " << this->salary << std::endl;
}
/***************
 Temporary
 ***************/
class Temporary : public Employee {
public:
	Temporary() : wage{0}, days{0} {};
	Temporary(const char *pname, const char *paddr, const double dwage, const double idays) : Employee(pname,paddr), wage{dwage}, days{idays} {};
	void displayInfo();
private:
	double wage;
	double days;
};

void Temporary::displayInfo() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Addr: " << this->addr << std::endl;
	std::cout << "monthlyPay: " << this->wage * this->days << std::endl;
}
/***************
 Company
 ***************/
class Company {
public:
	Company();
	void displayEmployees();
private:
	Employee *employees[10];
};

Company::Company() {
	employees[0] = new Employee("Andy", "positoy@gmail.com");
	employees[1] = new Regular("Chris", "chris@clinter.com",9000);
	employees[2] = new Temporary("David", "david@samsung.com", 200, 20);
	employees[3] = new Employee("Andy", "positoy@gmail.com");
	employees[4] = new Regular("Chris", "chris@clinter.com",9000);
	employees[5] = new Temporary("David", "david@samsung.com", 200, 20);
	employees[6] = new Temporary("David", "david@samsung.com", 200, 20);
	employees[7] = new Employee("Andy", "positoy@gmail.com");
	employees[8] = new Regular("Chris", "chris@clinter.com",9000);
	employees[9] = new Temporary("David", "david@samsung.com", 200, 20);
};

void Company::displayEmployees() {
	for (int i=0; i<10; i++)
		employees[i]->displayInfo();
}

int main()
{
	Company cmp;
	cmp.displayEmployees();

}
	
