#include <iostream>

class BankAccount {
private:
    static double dInterestRate;
    static const double dConstInterestRate;
    double balance;
public:
    static void setInterestRate(const double interestRate) {
        dInterestRate = interestRate;
        // this->dInterestRate = interestRate; - static 멤버함수는 객체 생성 전에 존재하므로 this 포인터를 사용할 수 없다
    }
    // static void setConstInterestRate(const double interestRate) { dConstInterestRate = interestRate; }
    void deposit(const double money) { balance+=money; }
    double withdraw() {
        // double ret = balance*(1+dInterestRate);
        double ret = balance*(1+dInterestRate);
        balance = 0;
        return ret;
     }
};

// static 변수는 꼭 초기화 해줘야 한다. private 노상관
// 헤더 파일에 작성하면 안된다. 왜냐하면 헤더파일이 여러번 포함되면 초기화가 여러번 포함되므로. (아마 progama once 쓰면 될 듯?)
// (근데 직접 해보니, pragma once 가 없으면 이미 클래스의 redefinition으로 컴파일 오류가 나므로 상관 없는것 같음)
// 객체가 생성되지 않더라도, 프로그램의 시작과 동시에 static 멤버변수에 메모리가 할당된다.
// 아래 초기화가 없을 때 undefined reference 링킹에러가 나는 것으로 봐서는 초기화와 동시에 메모리가 할당되는 듯?
double BankAccount::dInterestRate = 0.1;
const double BankAccount::dConstInterestRate = 0.2;

int main()
{
    BankAccount ba1, ba2;

    // 클래스의 static 멤버변수 - 은행의 '이자율'처럼
    //  객체들 사이에서 한가지 값으로 공유되며 전역변수로 취급하지 않아도 된다.
    ba1.setInterestRate(0.03);              // static을 객체에서 접근하는 것은 좋지 않은 방법
    BankAccount::setInterestRate(0.04);     // 명시적으로 '클래스명' 뒤에 영역결정연산자(::)룰 통해 접근해야 한다.

    // static 멤버변수의 접근도 마찬가지
    // ba1.dInterestRate -> BankAccount::dInterestRate

    // ba1.setConstInterestRate(0.03); - 오류 발생! const static 멤버변수는 최초에 한번만 설정할 수 있다.
    ba1.deposit(10000);
    ba2.deposit(20000);
    std::cout << "ba1 balance: " << ba1.withdraw() << std::endl
            << "ba2 balance: " << ba2.withdraw() << std::endl;


}
