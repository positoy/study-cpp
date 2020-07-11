#include <iostream>

class Point2 : public Point {
public:
        Point2() {}
        Point2(int x, int y, int z) : Point{x, y}, z{z} {}
        //  위처럼 list initializer 를 쓰면
        // Point(int x, int y) 부모생성자를 호출하여 x,y를 할당하고
        // 추가로 z를 초기화하는 것과 같은 효과가 있다.
        // 이것이 가능한 이유는 list initializer가 실제 생성자의 함수 본문보다
        // 먼저 실행되기 때문이다.

        // 스마트포인터에서는 initializer에서 멤버객체의 constructor가
        // 호출되도록 하고 그 과정에서 문제가 있을 때에는 exception throw 하여
        // RAII 기능에 의해 객체가 정리되도록 한다.
        ㄴ
        Point2(int x, int y, int z) { Point::Point(x, y); this->z = z; }
};
