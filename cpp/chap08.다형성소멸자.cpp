#include <iostream>

class Parent {
public:
    Parent() { std::cout << "Parent Constructor" << std::endl; }
    //~Parent() { std::cout << "Parent Destructor" << std::endl; }
    virtual ~Parent() { std::cout << "Parent Destructor" << std::endl; }
    /* RAII - Resource Acquisition is Initialization
     * you have to think about deinitialization whenever you code new class */
};

class Child : public Parent {
public:
    Child() { std::cout << "Child Constructor" << std::endl; }
    ~Child() { std::cout << "Child Destructor" << std::endl; }
};

int main()
{
    Parent *pParent = new Child();
    delete pParent;
}

