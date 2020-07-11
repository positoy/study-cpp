#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
// #include <functional>

std::mutex mu;

void test_mutex(int tid) {
    while (true) {
        mu.lock();
        std::cout << "thread " << tid << std::endl;
        mu.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void test_lockguard(int tid) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> guard(mu);
        std::cout << "thread " << tid << std::endl;
    }
}

void test_uniquelock(int tid) {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> ulock(mu);
        std::cout << "thread " << tid << std::endl;
        ulock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ulock.lock();
        std::cout << "thread " << tid << "-1" << std::endl;
    }
}

int main()
{
    std::vector<std::thread> thread_vector;

    thread_vector.push_back(std::thread(test_mutex, 0));
    thread_vector.push_back(std::thread(test_lockguard, 1));
    thread_vector.push_back(std::thread(test_uniquelock, 2));

    for (auto &t : thread_vector)
        t.join();
}