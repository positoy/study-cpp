#include <iostream>

// rule of thumb
// 경험규칙. 이론에 근거하지 않지만 경험적으로 실용적인 규칙을 말한다.
// 예로 rule of three 가 있다.

// rule of three
// C++ programming에서 멤버포인터객체와 관련된 special function 3개는 언제나 함께 구현되어야 함.
// 만약 그렇지 않으면 암시적으로 정의되지만 문제를 유발하기 쉽다.
// Assignment Operator, Copy Constructor, Destructor

// rule of five
// C++11 에서 추가된 문법에 발맞추어 rule of three는 rule of five로 확장되었다.
// Assignment Operator, Copy Constructor, Destructor, Move Constructor, Move Assignment Operator
// C++ 11에서는 스마트포인터를 이용하여 객체의 생성과 해제를 관리할 수 있다. (unique, shared)

// c 에서는 malloc, free 함수를 이용해서 heap 영역의 메모리를 할당했지만
// c++ 에서는 연산자를 이용한다.
// new, delete 연산자를 이용해서 heap 공간의 메모리를 할당할 수 있다.
// 또, [] 를 함께 이용하여 객체의 배열 메모리를 할당,해제할 수 있다.

class Point {
public:
    Point() { x=y=0; }
    Point(int x, int y) : x{x}, y{y} {}
    int getx() { return x; }
    int gety() { return y; }
private:
    int x,y;
};

class Polygon {
public:
    Polygon() : pointArray{nullptr} {};
    Polygon(int pointNum) : pointNum{pointNum} {
        pointArray = new Point[pointNum];
    }
    // copy constructor
    // 복사생성자와 대입연산자의 차이점
    // 1. 복사생성자는 새로 만들어졌기 때문에 delete 없이 바로 new
    // 2. 복사생성자는 피연산자와 자기 자신을 비교해서 예외처리 할 필요가 없다.
    // 3. return *this 가 필요없다.
    Polygon(Polygon& p) {
        if (pointArray) delete[] pointArray;
        pointNum = p.pointNum;
        pointArray = new Point[pointNum];
        for (int i=0; i<pointNum; i++) pointArray[i] = p.getPoint(i);
    }
    // destructor
    ~Polygon() {
        delete[] pointArray;
    }
    // assignment operator
    Polygon& operator=(Polygon& p) {
        if (this == &p) {
            std::cout << "(operand is same to its lvalue)" << std::endl;
            return *this;
        }
        pointNum = p.pointNum;
        if (pointArray) delete[] pointArray;
        pointArray = new Point[pointNum];
        for (int i=0; i<pointNum; i++) {
            pointArray[i] = p.getPoint(i);
        }
        return *this;
    }
    Point& getPoint(int num) { return pointArray[num]; }

    void printout() {
        std::cout << "points : ";
        for (int i=0; i<pointNum; i++) {

            std::cout << '(' << pointArray[i].getx() << ',' << pointArray[i].gety() << ')';
        }
        std::cout << std::endl;
    };
private:
    int pointNum;
    Point *pointArray;
};

int main()
{
    Polygon circle(0);
    Polygon triangle(3);
    Polygon square(4);

    circle.printout();
    triangle.printout();
    square.printout();

    // 1. 대입연산자
    std::cout << std::endl << "Assignment Constructor!!" << std::endl;

    triangle = square; // 만약 대입연산자가 없다면? 소멸자가 없다면?
    triangle.printout();

    circle = triangle = square; // 만약 대입연산자가 없다면?
    circle.printout();

    // 2. 복사생성자
    std::cout << std::endl << "Copy Constructor!!" << std::endl;

    Polygon newpoly(triangle);
    newpoly.printout();

    Polygon newpoly2 = triangle;
    newpoly2.printout();

    // 3. 소멸자
    // 만약 대입연산자가 없다면 멤버포인터는 복사되고
    // scope가 종료될 때 두 번 해제되어 runtime 에러가 발생한다.
}
