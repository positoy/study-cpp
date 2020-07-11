#include <iostream>

class Mother {
public:
    Mother() {};
    //virtual void printSomething() const;
    virtual void printSomething() const = 0;
};
/****
 make sure that all virtual function that are not pure is defined.
 unless you do this, you will see the infamous error "undefined reference to vtable"
 ****/
//void Mother::printSomething() const {}

class ChildOne : public Mother {
public:
    ChildOne() : localVar{1} {};
    void printSomething() const;
private:
    int localVar;
};
void ChildOne::printSomething() const {
    std::cout << localVar << " - I'm the first child" << std::endl;
}
class ChildTwo : public Mother {
public:
    ChildTwo() : localVar{2} {};
    void printSomething() const;
private:
    int localVar;
};
void ChildTwo::printSomething() const {
    std::cout << localVar << " - I'm the second child" << std::endl;
}
class ChildThree : public Mother {
public:
    ChildThree() : localVar{3} {};
    void printSomething() const;
private:
    int localVar;
};
void ChildThree::printSomething() const {
    std::cout << localVar << " - I'm the third child" << std::endl;
}

int main() {
    Mother* children[3];
    children[0] = new ChildOne();
    children[1] = new ChildTwo();
    children[2] = new ChildThree();

    Mother* mptr;
    for (int i=0; i<3; i++) {
        mptr = children[i];
        mptr->printSomething();
    }
}

