/* STL
 *
 * 1. TEMPLATE
 * 2. CONTAINER
 * 3. ALGORITHMS
 *
 * BASED ON GENERIC PROGRAMMING PHILOSOPHY
 */

/*
    1. Container
        * Sequence Container
            vector  : fast insertion and deletion at the end / slow at the center
            deque   : fast at the each end / slow at center
            list    : linear access / same insertion, deletion speed at any point of the set
        * Sorted Associative Container
            set         : unduplicated key with value, fast for searching key
            multiset    : set allowing duplicated keys
            map         : set providing fast value search with given key
            multimap    : map allowing duplicated keys

    2. Iterator
            input           : not for following ; *it = 10 (x)
            output          : not for following ; k = *it (x)
            forward         : include all operation of input and output iterator.
                              but moves only in one direction   ; ++it
            bidirectional   : same as forward but goes bidirectional ; ++it, --it
            random access   : same as bidirectional but same time consumed for random access

    3. Algorithms
            Nonmutating sequence algorithms
            Mutating sequence algorithms
            Sorting related algorithms

    4. 함수자
        0개 이상의 인자를 받아서 알고리즘의 기본동작을 변형시켜줌

    # Pros
            - generic programming
            - good speed
            - standard
    # Cons
            - large source code
            - low readability
            - difficult exception handling
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>

void test_vector();
void test_deque();
void test_list();

int main()
{
    // vector - exponential하게 공간을 추가할당 하기 때문에 재배치가 적다
//    test_vector();

    // deque - 동일한 크기의 chunk로 추가할당 하므로 vector보다 재배치가 많다.
    //           하지만 vector와 달리 front에서 접근이 가능하다.
    test_deque();

    // list - 삽입,삭제에 용이. access에 n에 비례하여 비용이 발생한다.
    //test_list();

}

void test_vector()
{
    std::vector<int> v;

    // ACCESS - [], push_back, front, at, back
    //v[0]      [] operator don't assign space automatically, could occur a error (or not)
    for (int i=0; i<5; i++)
        v.push_back(i*10);
    std::cout << v[3] << ' ' << v.front() << ' ' << v.back() << ' ' << v.at(2) << std::endl;

    // CONTAINER - size, resize, reserve, shrink_to_fit, max_size, empty
    v.resize(10, 99);   // 10 vectors will be assigned, with value of 99 unless it is already assigned
    v.reserve(20);      // size is still 10, but 10 extra spaces will be reserved 
    v.shrink_to_fit();  // capacity wil be shrinked to the size (c++11 support)

    // modify
    v.push_back(0);
    v.push_back(0);                 // 0 0
    v.erase(--v.end());             // 0
    v.insert(v.end(), 10000);       // 0 10000
    v.insert(v.end(), 2, 20000);    // 0 10000 20000 20000
    v.pop_back();                   // 0 10000 20000

    // ITERATOR - begin, end, rbegin, rend
    for (std::vector<int>::iterator it=v.begin(); it<v.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void test_deque()
{
    std::deque<int> dv;  // dv(10);

    // <front> ------------- pipe ------------- <back>
    for (int i=0; i<10; i++) {
        if (i%2) dv.push_front(i);
        else     dv.push_back(i);
    }

    // ACCESS - [], front, at, back

    // CONTAINER - size, max_size, resize, capacity, empty, shrink_to_fit (no reserve)
    
    // modify - push_back, pop_back, push_front, pop_front, insert, erase, swap, clear (push,pop at the front)
    // ITERATOR
    for (std::deque<int>::reverse_iterator it=dv.rbegin(); it<dv.rend(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;

    while (!dv.empty()) {
        std::cout << dv.front() << ' ';
        dv.pop_front();
    }
    std::cout << std::endl << "size:" << dv.size() << std::endl;
}

void test_list()
{
    std::list<char> li;

    for (char input='a'; input<='z'; input++)
        li.push_front(input);
    li.push_front('x');

    for (std::list<char>::reverse_iterator rit = li.rbegin(); rit!=li.rend(); rit++)
        std::cout << *rit << ' ';
    std::cout << std::endl;

    // 정렬
    li.sort();
    for (std::list<char>::reverse_iterator rit = li.rbegin(); rit!=li.rend(); rit++)
        std::cout << *rit << ' ';
    std::cout << std::endl;

    // 중복제거
    li.unique();
    for (std::list<char>::reverse_iterator rit = li.rbegin(); rit!=li.rend(); rit++)
        std::cout << *rit << ' ';
    std::cout << std::endl;

    // 순서뒤집기
    li.reverse();
    for (std::list<char>::reverse_iterator rit = li.rbegin(); rit!=li.rend(); rit++)
        std::cout << *rit << ' ';
    std::cout << std::endl;


    // 리스트 삽입하기
    std::list<char> newli(li);
    for (std::list<char>::iterator it=li.begin(); it!=li.end(); it++) {
        if (*it != 'h') continue;
        li.splice(it, newli);
        break;
    }
    for (std::list<char>::iterator it=li.begin(); it!=li.end(); it++) {
        std::cout << *it << ' ';
    }


    // ACCESS - front, back

    // CONTAINER - size, max_size, empty
    
    // modify - push_back, pop_back, push_front, pop_front, insert, erase, swap, clear 

    // OPERATION - splice, remove, remove_if, unique, merge, sort, reverse 
}

