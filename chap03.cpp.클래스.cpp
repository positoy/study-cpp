#include <iostream>

class MousePoint {
protected:
    int x, y;
public:
    MousePoint() : x{0}, y{0} {}
    void setPoint(int x, int y);
    void printPoint();
};

void MousePoint:: setPoint(int x, int y) { this->x=x, this->y=y; }
void MousePoint::printPoint() {
    std::cout << "Mouse point : " << x << ", " << y << std::endl;
}

class MousePointLargerScale : public MousePoint {
public:
    MousePointLargerScale() {};
    MousePointLargerScale(int x, int y) { setxy(x,y); }
    inline void setPoint(int x, int y);
    void setx(int x) { this->x=x; }
    void sety(int y) { this->y=y; }
    void setxy(int x, int y) { this->x=x, this->y=y; }
};

inline void MousePointLargerScale::setPoint(int x, int y) { this->x=10*x, this->y=10*y; }

#include <malloc.h>
class PickyClass {
private:
    char* str;
public:
    PickyClass();
    ~PickyClass();
    void setString(const char* str) { this->str = (char*)str; };
    void print();

};

PickyClass::PickyClass() {
    str = (char*)malloc(20);
}

void PickyClass::print() {
    std::cout << str << std::endl;
}

PickyClass::~PickyClass() {
    std::cout << "destructor of PickyClass called." << std::endl;
    free(str);
}

int main()
{
    // 클래스 - 사용자가 정의한 추상데이터 타입
    // C++에서는 구조체도 멤버함수를 가질 수 있다. 다만 접근지정자 (public, private, protected)를
    // 가질 수 없고 모든 멤버함수, 변수가 public으로 접근된다는 점에서 클래스와 차이가 있다.
    // private - private으로 상속, protected - 자신과 자식클래스에서만 접근 가능, public - 모두 접근가능
    // 오직 멤버함수를 통해서만 private 데이터에 접근할 수 있다 - 데이터은닉, 캡슐화
    MousePoint mp;
    mp.setPoint(100,200);
    mp.printPoint();

    // 인라인함수
    // 클래스의 멤버변수도 인라인으로 선언할 수 있다
    MousePointLargerScale mpls;
    mpls.setPoint(100,200);
    mpls.printPoint();

    // 자동인라인 함수
    // 클래스 선언에 정의된 멤버변수는 자동으로 inline 함수가 된다.
    mpls.setx(10);
    mpls.sety(20);
    mpls.printPoint();

    // 구조체 멤버변수 초기화
    struct MousePointStruct { int x, y; };
    struct MousePointStruct mps = {10, 20};
    std::cout << "Mouse Point Struct : " << mps.x << ", " << mps.y << std::endl;

    // 클래스 멤버변수 초기화 방법
    // MousePoint mp2 = {10, 20}; - error occurred! 객체지향의 철학에 정면으로 위배되므로 불가능한 초기화 방법
    MousePointLargerScale mpls2;
    mpls2.setxy(150,250);
    mpls2.printPoint();

    // 생성자
    // 멤버변수로 멤버함수를 원하는 값으로 초기화 할 수 있지만
    // 객체 생성 후 의도치 않은 초기값으로 존재하는 순간이 분명 존재한다!
    // 객체 생성과 동시에 원하는 값으로 초기화하려면 생성자를 사용해야 한다.
    // 사용자정의 생성자를 만드는 순간 기본생성자도 정의해줘야 한다.
    MousePointLargerScale mpls3(15, 25);
    mpls3.printPoint();

    // 소멸자
    // 객체가 제거될 때 처리해줘야 할 일이 있을 때 정의한다.
    // 생성자처럼 오버로딩이 불가능하다
    PickyClass pc;
    pc.setString("set string for PickyClass.");
    pc.print();

    // 포인터에 생성된 객체는 따로 소멸자를 호출하지 않고 프로그램 종료 할 때 메모리 공간에서 삭제된다.
    PickyClass *pc2 = new PickyClass;
    pc2->setString("set string for PickyClass2");
    pc2->print();
    //delete pc2;

    return 0;

}
