#include <iostream>
#include <string>

/*
 * 1. 템플릿클래스
 * 2. 템플릿함수
 * 3. 템플릿클래스+변수
 * 4. 템플릿클래스2개이상
 */

/* template class */
template<class T>
class CStack {
public:
    CStack(int size) {
        v = p = new T[sz = size];
    }
    void push(T item);
    T pop(void);
private:
    T* v;
    T* p;
    int sz;
};
template<class T>
void CStack<T>::push(T item) {
    if (p-v >= sz) return;
    *p++ = item;
}
template<class T>
T CStack<T>::pop(void) {
    if (p-v == 0) return nullptr;
    return *--p;
}

/* template function */
template<class T>
T max(T a, T b) {
    return a>b?a:b;
}

/* template class with a variable */
template<class T, int i>
class SizeDefinedCStack {
public: 
    SizeDefinedCStack() : ptr{0}, sz{i} {};
    void push(T item) { if(ptr>=sz) return; stack[ptr++]=item; }
    T pop(void) { if(ptr<=0) return nullptr; return stack[--ptr]; }
private:
    T stack[i];
    int sz;
    int ptr;
};

/* more than 2 template variable */
template<class X, class Y>
class WhichOneBigger {
public:
    WhichOneBigger(X x, Y y) : x{x}, y{y} {};
    X getBigger();
private:
    X x;
    Y y;
};
template<class X, class Y>
X WhichOneBigger<X,Y>::getBigger() {
    return x;
}

int main()
{
    CStack<std::string> stringStack(10);
    char hello[2] = {'a'};
    for (int i=0; i<10; i++) {
        stringStack.push(hello);
        hello[0]++;
    }
    for (int i=0; i<10; i++) {
        auto pValue = stringStack.pop();
        /* how can I handle error here? */
        std::cout << pValue << std::endl;
    }

    std::cout << max(10000,20000) << std::endl;

    /* stack wtih i size defined */
    SizeDefinedCStack<std::string, 10> dcstack;
    char yello[2] = {'a'};
    for (int i=0; i<10; i++) {
        dcstack.push(yello);
        yello[0]++;
    }

    for (int i=0; i<10; i++) {
        auto pValue = dcstack.pop();
        std::cout << pValue << std::endl;
    }

    WhichOneBigger<std::string, double> wob("bitch!", 3.14);
    std::cout << wob.getBigger() << std::endl;
}

