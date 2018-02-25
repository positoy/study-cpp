#include <iostream>
#include <set>
#include <map>

#include <cstdlib>

void test_set();
void test_map();

int main()
{
    // 1. set - 데이터를 키로 사용하여 중복이 없다 (고유한 key 집합을 만들 수 있음)
    //          항상 데이터가 정렬된다.
    //test_set();

    test_map();
}

void test_set()
{
    std::set<int> st;

    // iterator - lower_bound, upper_bound
    srand((unsigned int)time(NULL));
    for (int i=0; i<10; i++) st.insert(rand()%10);

    for (std::set<int>::iterator it=st.begin(); it!=st.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;

    char message[] = "ABASDFWFADFASWEASGAFQWFSDF";
    std::set<char> helloset(&message[0], &message[20]);
    for (std::set<char>::iterator it=helloset.begin(); it!=helloset.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    
    // container - empty, size, max_size
    
    // access,modify - insert, erase, find, count (count는 일치하는 갯수 리턴이지만 set에서는 0, 1 만 리턴)
    helloset.erase(helloset.find('F'));
    for (std::set<char>::iterator it=helloset.begin(); it!=helloset.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;

    for (char ptrc='A'; ptrc<='Z'; ptrc++)
    if (helloset.count(ptrc) != 0)
        std::cout << ptrc << " is a member of the set." << helloset.count(ptrc) << " times." << std::endl;
    else
        std::cout << ptrc << " is not a member of the set." << std::endl;
}

void test_map()
{
    std::map<std::string,std::string> cmap;
    
    // CONTAINER - empty, size, max_size, upper_bound, 
    cmap["hello"] = "world!";
    cmap["world"] = "hello!";

    std::cout << cmap["world"] << ' ' << cmap.at("hello") << std::endl;
    
    
    
    // ITERATOR - lower_bound, upper_bound, find, count, equal_range
    
    // ACCESS, MODIFY - at, [], insert, erase, swap, clear
    


}

