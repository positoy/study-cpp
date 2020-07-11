#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() : data{0} {}
    
    void setData(int _data) { data = _data; }
    int getData() { return data; }

    void print() {
        std::cout << data << std::endl;
    }

private:
    int data;
};

void test_unique_ptr()
{
    std::unique_ptr<MyClass> ptr1(new MyClass()), ptr2;
    ptr1->setData(30);
    ptr1->print();
    std::cout << "ptr1 pointer address : " << ptr1.get() << std::endl;
    std::cout << "ptr2 pointer address : " << ptr2.get() << std::endl;

    ptr2 = std::move(ptr1);
    std::cout << "ptr1 pointer address : " << ptr1.get() << std::endl;
    std::cout << "ptr2 pointer address : " << ptr2.get() << std::endl;

    ptr2.reset();
    std::cout << "ptr1 pointer address : " << ptr1.get() << std::endl;
    std::cout << "ptr2 pointer address : " << ptr2.get() << std::endl;

    ptr2 = std::make_unique<MyClass>();
    std::cout << "ptr1 pointer address : " << ptr1.get() << std::endl;
    std::cout << "ptr2 pointer address : " << ptr2.get() << std::endl;
}

void test_shared_ptr()
{
    std::shared_ptr<MyClass> sptr1 = std::make_shared<MyClass>();
    std::cout << "sptr1 counter : " << sptr1.use_count() << std::endl;
    
    std::shared_ptr<MyClass> sptr2 = sptr1;
    std::cout << "sptr1 counter : " << sptr1.use_count() << std::endl;
    std::cout << "sptr2 counter : " << sptr2.use_count() << std::endl;

    std::shared_ptr<MyClass> sptr3 = std::move(sptr1);
    std::cout << "sptr1 counter : " << sptr1.use_count() << std::endl;
    std::cout << "sptr2 counter : " << sptr2.use_count() << std::endl;
    std::cout << "sptr3 counter : " << sptr3.use_count() << std::endl;
}

int main()
{
    test_unique_ptr();
    test_shared_ptr();
}