#include <iostream>
#include <cstring>

// name
class Employee {
public:
    Employee(){}; // 어떻게 사용하지 못하도록 막을 수 있을까?
    Employee(const char *pname) { this->setName(pname); };
    void setName(const char *pname) { name = new char[strlen(pname)+1]; strcpy(name, pname); };
    const char* getName() const { return name; }
    virtual double getPayCheck() const = 0;
    virtual void information() const = 0;
private:
    char *name;
};

// salary
class Regular : public Employee {
public:
    Regular(const char* name, const double salary) : Employee(name), salary{salary} {};
    void setSalary(const double dsalary) { salary = dsalary; }
    double getSalary() const { return salary; }
    double getPayCheck() const;
    void information() const;
private:
    double salary;
};
double Regular::getPayCheck() const {
    return salary;
}
void Regular::information() const {
    std::cout << "Regular" << std::endl;
    std::cout << "name: " << this->getName() << std::endl;
    std::cout << "earning: " << this->getPayCheck() << std::endl;
}

// wage, workingHours
class Temporary : public Employee {
public:
    Temporary(const char* name, const double wage, unsigned int workingHours) : Employee(name), wage{wage}, workingHours{workingHours} {};
    void setWage(const double dwage) { wage = dwage; }
    double getWage() { return wage; }
    void setWorkingHours(const unsigned int iworkingHours) { workingHours = iworkingHours; }
    double getPayCheck() const;
    void information() const;
private:
    double wage;
    unsigned int workingHours;
};
double Temporary::getPayCheck() const {
    return wage*workingHours;
}
void Temporary::information() const {
    std::cout << "Temporary" << std::endl;
    std::cout << "name: " << this->getName() << std::endl;
    std::cout << "earning: " << getPayCheck() << std::endl;
}

// sales incentive
// class SalesPerson : public Regular {
class SalesPerson : public virtual Regular {
public:
    SalesPerson(const char* name, const double salary, const double sale_incentive, const unsigned int sale_number)
        : Regular(name, salary), sale_incentive{sale_incentive}, sale_number{sale_number} {};
    void setSaleIncentive(double dsale_incentive) { sale_incentive = dsale_incentive; }
    double getSaleIncentive() const { return sale_incentive; }
    void setSaleNumber(unsigned int isale_number) { sale_number = isale_number; }
    unsigned int getSaleNumber() const { return sale_number; }
    double getPayCheck() const;
    void information() const;
private:
    double sale_incentive;
    unsigned int sale_number;
};
double SalesPerson::getPayCheck() const {
    return Regular::getPayCheck() + getSaleIncentive() * getSaleNumber();
}
void SalesPerson::information() const {
    std::cout << "SalesPerson" << std::endl;
    std::cout << "name: " << this->getName() << std::endl;
    std::cout << "earning: " << this->getPayCheck() << std::endl;
}

// administrative incentive
//class Manager : public Regular {
class Manager : public virtual Regular {
public:
    Manager(const char* name, const double salary, const double admin_incentive)
        : Regular(name, salary), admin_incentive{admin_incentive} {};
    void setAdminIncentive(const double dadmin_incentive) { admin_incentive = dadmin_incentive; }
    double getAdminIncentive() const { return admin_incentive; }
    double getPayCheck() const;
    void information() const;
private:
    double admin_incentive;
};
double Manager::getPayCheck() const {
    return Regular::getPayCheck() + getAdminIncentive();
}
void Manager::information() const {
    std::cout << "Manager" << std::endl;
    std::cout << "name: " << this->getName() << std::endl;
    std::cout << "earning: " << this->getPayCheck() << std::endl;
}

// salesmanager : combination of salesperson and manager
class SalesManager : public SalesPerson, Manager {
public:
    SalesManager(const char* name, const double salary, const double sale_incentive, const unsigned int sale_number, const double admin_incentive)
        /* should i call all constructors? */
        : SalesPerson(name, salary, sale_incentive, sale_number), Manager(name, salary, admin_incentive), Regular(name, salary) {};
    double getPayCheck() const;
    void information() const;
};
double SalesManager::getPayCheck() const {
    /* Regular base is now ambiguous. Because SalesManager has two instances of Regular
     * (one from SalesPerson, the other from Manager */
    //return getSalary() + getSaleIncentive()*getSaleNumber() + getAdminIncentive();
    return Regular::getPayCheck() + getSaleIncentive()*getSaleNumber() + getAdminIncentive();
    //return SalesPerson::getPayCheck() + Manager::getPayCheck() - Regular::getPayCheck();
}
void SalesManager::information() const {
    std::cout << "SalesManager" << std::endl;
    std::cout << "name:" << this->getName() << std::endl;
    std::cout << "earning:" << this->getPayCheck() << std::endl;
}

int main()
{
    Employee *regular = new Regular("Regular Ahn", 40000);
    Employee *temporary = new Temporary("Temp Ahn", 11, 70);

    regular->information();
    temporary->information();

    Employee *salesPerson = new SalesPerson("Salesperson Ahn", 50000, 1000, 30);
    Employee *manager = new Manager("Manager Ahn", 60000, 20000);

    salesPerson->information();
    manager->information();

    std::cout << std::endl << std::endl;
    Employee *salesManager = new SalesManager("SalesManager", 70000, 1000, 40, 20000);
    salesManager->information();


}

