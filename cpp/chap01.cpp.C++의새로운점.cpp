/***
 C++ 특징
 1. 객체지향프로그래밍
 2. 추상화 (절차적추상화 - printf / 데이터추상화 - struct Point {int x, int y};)
 3. 데이터은닉 (은닉된 데이터를 멤버함수를 통해 접근)
 4. 다형성 (추가되는 함수오버로딩과 가려지는 함수오버라이딩 - 상속 후 맘에 안드는 부분만 재정의)
 5. 상속성
 ***/

 // namespace

#include <iostream>

using namespace std;

namespace A {
void callBobby() {
    std::cout << "Hey dude!" << std::endl;
}
}

namespace B{
void callBobby() {
    std::cout << "Hey Bobby!" << std::endl;
}
}

void printout(int something = 10, int something2 = 20);

int tempInteger = 100;

#define MAX(A,B) (A>B?A:B)
inline int inlineMAX(int a, int b) {
    if (a>b) return a;
    return b;
}

int add(int a, int b) { return a+b; }
float add(float a, float b) { return a+b; }

int main()
{
    // namespace
    // namespace를 이용하면 A반의 현수와 B반의 현수를 구별하여 호출할 수 있다.
    A::callBobby();
    B::callBobby();

    // cin, cout은 객체
    // cin 의 멤버함수 get은 인자의 변수에 입력값을 저장한다.
    // cin 에 정의된 >> 연산자는 오버로딩 된 get 함수를 내부적으로 이용하여 변수에 입력값을 저장한다.
    // get 함수의 원형은 다음과 같다. istream& get(char& c)
    // ctrl + z 를 누르면 get 함수는 NULL 값을 리턴한다.
    char ch;
    std::cin.get(ch);
    std::cout << ch;
    std::cin.get(ch); // to flush newline
    std::cout << ch;

    //cin 의 멤버함수 getline은 문자열을 읽을 수 있다.
    // getline 함수의 원형은 다음과 같다. istream& getline(signed char*, int, char = '\n')
    // 파라미터 설명 ; 문자열, 문자열최대길이, 기본값이 개행문자인 char 변수
    char str[20];
    std::cin.getline(str,20);
    std::cout << str << endl;

    // prototype 에서 기본값지정
    printout(100, 200);
    printout(100);
    printout();

    // 전역변수 강제사용 ::variableName
    int tempInteger = 10;
    std::cout << "global temp integer is " << ::tempInteger << std::endl;

    // inline 함수
    // 코드라인 자체가 안으로 들어가기 때문에 호출위치에 박혀있는 효과를 가진다
    // 장점 - 파라미터 사용, 함수처럼 사용, 디버깅 가능
    // 단점 - 코드가 커진다, 길이가 길면 컴파일러는 일반 함수로 취급한다
    int x=10,y=20,m;
    m = MAX(x++,y++);
    std::cout << "using define - x:" << x << ", y:" << y << ", m:" << m << std::endl;
    x=10,y=20;
    m = inlineMAX(x++,y++);
    std::cout << "using inline x:" << x << ", y:" << y << ", m:" << m << std::endl;

    // 함수오버로딩
    int a=10,b=20;
    float fa=0.1, fb=0.2;
    std::cout << add(a,b) << std::endl << add(fa,fb) << std::endl;

    return 0;

}

void printout(int something, int something2) {
    std::cout << something << std::endl;
    std::cout << something2 << std::endl;
}
