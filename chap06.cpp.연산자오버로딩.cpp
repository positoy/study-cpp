#include <iostream>

class Point {
public:
    Point(int x, int y) : x{x}, y{y} {}

    // 1. 연산자오버로딩, friend
    Point operator+(Point& p) { return Point(x+p.x, y+p.y); }
    Point operator+(int i) { return Point(x+i, y+i); }
    friend Point operator+(int i, Point& p) { return Point(i+p.x, i+p.y); }

    // 2. 비교연산자 ==, >, <
    bool operator==(Point& p) {
        if (x==p.x && y==p.y) return true;
        return false;
    }

    // 3. 증감연산자 ++, --
    Point operator++() {
        std::cout << "(++pre)" << std::endl;
        return Point(++x, ++y);
    }
    Point operator++(int) {
        std::cout << "(post++)" << std::endl;
        return Point(x++,y++);
    }
    Point operator--() {
        std::cout << "(--pre)" << std::endl;
        return Point(--x,--y);
    }
    Point operator--(int) {
        std::cout << "(post--)" << std::endl;
        return Point(x--,y--);
    }

    // 4. 출력,입력 <<, >>
    // !! 아래 함수들은 절대로 ostream& istream& 를 리턴해야 한다.
    // guess why
    // istream은 buffer를 인자로 받는 constructor를 사용해야 하기 때문에
    // 기본생성자는 protected 로 막혀있다.
    friend std::ostream& operator<<(std::ostream& os, Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    // 5. 괄호 ()
    int operator()(int x, int y) {
        return x+y;
    }
    int operator()(int x, int y, int z) {
        return x+y+z;
    }
    void printData() {
        std::cout << '(' << x << ',' << y << ')' << std::endl;
    }
private:
    int x;
    int y;
};

int main()
{
    // 1. 연산자오버로딩, friend
    Point p1(10,20);
    Point p2(100,200);
    Point p3 = p1 + p2;
    Point p4 = 10 + p1;
    p3.printData();
    p4.printData();

    // 2. 비교연산자 ==, >, <
    if (p1==p2) std::cout << "same!" << std::endl;
    else std::cout << "not same!" << std::endl;
    if (p1+10 == p4) std::cout << "same!" << std::endl;
    else std::cout << "not same!" << std::endl;

    // 3. 증감연산자 ++, --
    p1.printData();
    Point a = ++p1;
    a.printData();
    p1.printData();
    Point b = p1++;
    b.printData();
    p1.printData();
    Point c = --p1;
    c.printData();
    p1.printData();
    Point d = p1--;
    d.printData();
    p1.printData();

    // 4. 출력입력 <<, >>
    std::cin >> p1;
    std::cout << p1 << std::endl;

    // 5. 괄호 ()
    std::cout << p1(1,2) << std::endl;
    std::cout << p1(1,2,3) << std::endl;
}
