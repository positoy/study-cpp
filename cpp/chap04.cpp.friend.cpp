#include <iostream>

// 내가 친구에게 '넌 내 친구야'라며 통장 비밀번호를 알려준다.
// 친구는 내 통장에서 출금할 수 있게된다.
// 하지만 친구는 '넌 내 친구야'라고 하지 않았으므로 나는 친구의 통장에서 돈을 뺄 수 없다.
class Deposit {
    // 단방향 접근
    friend class FriendDeposit;
public:
    Deposit() : name{"David"}, balance{1000000} {}
private:
    std::string name;
    int balance;
};

class FriendDeposit {
public:
    FriendDeposit(Deposit md) : md{md}{
        std::cout << "friend class constructor called." << std::endl;
        std::cout << "name: " << md.name << std::endl;
        std::cout << "balance: " << md.balance << std::endl;
    }
    void printout() {
        std::cout << "friend class accesses the class." << std::endl;
        std::cout << "name: " << md.name << std::endl;
        std::cout << "balance: " << md.balance << std::endl;
    }
private:
    Deposit &md;
    std::string name;
    int balance;
};

int main()
{
    Deposit md;
    FriendDeposit fd(md);

    fd.printout();
}
