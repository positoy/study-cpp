#include <iostream>

// c 에서는 malloc, free 함수를 이용해서 heap 영역의 메모리를 할당했지만
// c++ 에서는 연산자를 이용한다.
// new, delete 연산자를 이용해서 heap 공간의 메모리를 할당할 수 있다.
// 또, [] 를 함께 이용하여 객체의 배열 메모리를 할당,해제할 수 있다.

class MousePoint {
public:
    MousePoint() : x{1},y{2}{};
    MousePoint(int x, int y) : x{x}, y{y} {};
    void printPosition();
private:
    int x, y;
};

void MousePoint::printPosition() {
    std::cout << "position:" << x << "," << y << std::endl;
}

int main()
{

    // 1. 동적메모리(heap) 할당의 필요성
    int nLength;
    std::cin >> nLength;
    // int array[nLength]; - nLength는 컴파일타임(stack)에 미정이므로 불가능 (g++에서는 extension으로 가능하게 돼있다)

    // 2. new,delete - 기본데이터형
    int *pBuffer = new int[nLength];
    for (int i=0; i<nLength; i++) {
        pBuffer[i] = i*10;
        std::cout << ' ' << pBuffer[i];
    }
    std::cout << std::endl;
    delete[] pBuffer;

    // 3. new,delete - 객체
    MousePoint *pMp = new MousePoint(10,20);
    pMp->printPosition();
    delete pMp;

    // 4. new,delete - 객체배열 (기본생성자필요)
    MousePoint *pMparr = new MousePoint[nLength];
    for (int i=0; i<nLength; i++) {
        pMparr[i].printPosition();
    }
    std::cout << std::endl;
    delete[] pMparr;

    // 5. new,delete - 객체포인터배열
    MousePoint *pMparr2[10];
    for (int i=0; i<10; i++) {
        pMparr2[i] = new MousePoint(i*10+1, i*100+1);
        pMparr2[i]->printPosition();
        delete pMparr2[i];
    }
    std::cout << std::endl;

    // 4번과 5번을 잘 비교해야한다.
    // 4번은 포인터타입, [] index 연산자가 붙으면 포인터가 아니라 즉시 객체가 된다.
    // 따라서 .으로 접근
    // 5번은 더블포인터타입, [] index 연산자가 붙어도 여전히 포인터이므로
    // ->으로 접근
}
