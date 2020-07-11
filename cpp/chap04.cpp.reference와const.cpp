#include <iostream>
#include "include/util.hpp"

class MousePoint {
private:
    int x,y;
public:
    void setx(int x) { this->x=x; }
    void sety(int y) { this->y=y; }
    int getx() { return x; }
    int gety() { return y; }
    void setxy(int x, int y) { this->x=x, this->y=y; }
    void print();
    void nothing() const {}
    MousePoint(int x, int y) { setxy(x,y); }
    MousePoint(){}
};

void MousePoint::print() {
    std::cout << x << ", " << y << std::endl;
}

class Rect {
private:
    MousePoint rectPoint[2];
public:
    Rect(MousePoint p1, MousePoint p2) { this->rectPoint[0] = p1, this->rectPoint[1] = p2; }
    void print();
};

void Rect::print() {
    std::cout << "p1: " << this->rectPoint[0].getx() << ", " << this->rectPoint[0].gety() << std::endl;
    std::cout << "p2: " << this->rectPoint[1].getx() << ", " << this->rectPoint[1].gety() << std::endl;
}

void setZeroPointToMousePointByValue(MousePoint mp) {
    mp.setxy(0,0);
}

void setZeroPointToMousePointByReference(MousePoint &mp) {
    mp.setxy(0,0);
}

MousePoint& setMousePointWithAnother(MousePoint& mp1, MousePoint mp2) {
    mp1 = mp2;
    return mp1;
}

class ClassForConstKeyword {
private:
    int x,y;
public:
    ClassForConstKeyword() : x(100), y(200) {}
    void setMemberVariablesZero();
    // void setMemberVariablesZero() const;
    void printMemberVariables() const;
};

void ClassForConstKeyword::setMemberVariablesZero() {
    this->x=0, this->y=0;
}

void ClassForConstKeyword::printMemberVariables() const {
    std::cout << "x: " << this->x << std::endl
            << "y: " << this->y << std::endl;
}

int main()
{
    // 객체배열 생성과 초기화
    MousePoint mpArr[3] = { MousePoint(10,20), MousePoint(100,200), MousePoint(1000,2000) };
    for (int a=0; a<3; a++) mpArr[a].print();

    // 객체포인터
    MousePoint *mpPtr = &mpArr[0];
    mpPtr->print();
    MousePoint *mpPtr2 = new MousePoint(1,2);
    mpPtr2->print();

    // this 포인터
    // 객체는 멤버변수의 블록은 별도로 갖고 멤버함수의 메모리 블록은 공유한다
    // 멤버함수의 입장에서 내부적으로 멤버변수를 사용하면 어느 객체의 멤버변수인지 알 수 없기 때문에
    // this 포인터로 멤버변수를 호출한 객체가 특정되어야 한다.

    // 그런데, 정말? 나는 각 객체가 static 으로 선언 된 멤버함수만 공유하는 건 줄 알았는데?
    // 아니네. print 내부의 static count 변수가 각 객체에서 호출할 때마다 차례로 증가함
    for (int a=0; a<3; a++) mpArr[a].print();


    Util::setBigTitle("SET BY VALUE vs SET BY REFERENCE");
    // 전달인자가 개체인 함수

    // ** 기본 자료형의 값 전달
    // mpPtr->setxy(a,b);   - a,b는 실매개변수
    // MousePoint::setxy(int na, int nb) { ... }    - na,nb는 형식매개변수
    // 실매개변수와 형식매개변수는 각자의 메모리에 존재한다

    // 객체에 대한 값 전달 방식
    // ** MousePoint에 기본생성자가 없으면 아래 객체 생성은 오류가 발생한다.
    MousePoint mp1(10,10), mp2(20,20);
    Rect r2(mp1, mp2);
    r2.print();

    // ** MousePoint에 기본생성자가 없으면 아래 객체 생성은 오류가 발생한다.
    Rect r(MousePoint(10,10), MousePoint(20,20));
    r.print();

    // 값에 의한 전달
    setZeroPointToMousePointByValue(mp1);
    mp1.print();

    // 레퍼런스 전달
    setZeroPointToMousePointByReference(mp1);
    mp1.print();

    // 객체복사 레퍼런스 사용!!!


    // 객체간의 복사 (멤버변수가 복사 된다)
    mp1.setxy(123,123);
    mp2.setxy(456,456);
    mp1 = mp2;
    mp1.print();

    // 객체간의 복사 함수
    // by reference 를 사용하지 않으면 복사되지 않는다
    mp1.setxy(123,123);
    mp2.setxy(456,456);
    setMousePointWithAnother(mp1, mp2); // MousePoint &mp1 = mp1, MousePoint &mp2 = mp2;
                                        // reference는 변수 명은 두개지만 결국 같은 메모리주소를 공유한다
                                        // 프로토타입이 setMousePointWithAnother(MousePoint mp1, MousePoint mp2) 라면 정상 복사되지 않는다
    mp1.print();
    mp1 = setMousePointWithAnother(mp1 ,mp2);   // 리턴타입 MousePoint - 리턴할 때 새로운 메모리 생성
    mp2 = setMousePointWithAnother(mp1, mp2);   // 리턴타입 MousePoint& - 기존의 메모리 공간 반환하므로 공간,시간 절약


    Util::setBigTitle("const Member Function and const Object");

    // 1. const 멤버함수
    // 멤버함수에 const 키워드를 사용해서 명시적으로 동작의 영향범위를 보여줄 수 있고 컴파일 단계에서 실수를 방지 할 수 있다.
    // constructor, destructor 는 언제나 멤버변수에 접근하므로 const 를 사용할 수 없다
    ClassForConstKeyword cfck;
    cfck.setMemberVariablesZero();
    cfck.printMemberVariables();

    // const 객체
    const MousePoint pt1(100,200);
    MousePoint pt2(1000,2000);
    // pt1 = pt2; 컴파일에러발생
    // pt1.setxy(1,2); 컴파일에러발생

    // const 객체는 '명시적인' const 멤버함수만 사용할 수 있다.
    // pt1.print(); print 함수가 멤버변수를 조작하지 않음에도 불구하고 컴파일에러 발생
    // const 함수를 선언했는데 그 함수에 const 멤버함수가 없으면 무용지물이 된다.
    pt1.nothing();












}
