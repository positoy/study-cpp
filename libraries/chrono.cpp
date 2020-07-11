#include <iostream>
#include <chrono>

// duration, time_point, clock
int main()
{
    // duration
    std::chrono::seconds sec(1);
    std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(sec);
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(msec);
    std::chrono::nanoseconds nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(usec);

    std::cout << sec.count() << " seconds" << std::endl
        << msec.count() << " milliseconds" << std::endl
        << usec.count() << " microseconds" << std::endl
        << nsec.count() << " nanoseconds" << std::endl;

    std::chrono::duration<double, std::ratio<1,1>> dsec(std::chrono::milliseconds(3829));
    std::cout << dsec.count() << " seconds with double representation" << std::endl;

    std::cout << std::endl << std::endl;

    // time_point & system_clock
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();
    for (int i=0; i<2000000000; i++) int k = 1.23 * 3.87;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double, std::ratio<1,1>> spent = end - start;
    std::cout << spent.count() << " seconds passed" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(spent).count() << " milliseconds passed" << std::endl;
}