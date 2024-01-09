#include "test-module.h"
#include <iostream>

TestModule::TestModule(): tq()
{}

void TestModule::test(std::size_t enqueue_lim, std::size_t dequeue_lim)
{
    std::cout << "! Test Initialization !\n";
    std::cout << "\tis_empty(): " << tq.is_empty() << '\n';
    std::cout << "\tsize(): " << tq.size() << '\n';

    std::cout << "Populating Queue...\n\t";
    for (unsigned i = 1; i <= enqueue_lim; ++i)
        tq.enqueue(i);
    tq.for_each([](int& elem) { std::cout << elem << ' '; });
    std::cout << "\n\t" << "is_empty(): " << tq.is_empty() << '\n';
    std::cout << "\tsize(): " << tq.size() << '\n';
    std::cout << "\tfront(): " << tq.front().value_or(-1) << '\n';

    std::cout << "Dequeuing " << dequeue_lim << " elements\n";
    for (unsigned i = 1; i <= dequeue_lim; ++i)
        tq.dequeue();
    std::cout << "\t" << "is_empty(): " << tq.is_empty() << '\n';
    std::cout << "\tsize(): " << tq.size() << '\n';
    std::cout << "\tfront(): " << tq.front().value_or(-1) << '\n';

    std::cout << "Calling destructor...\n";
    tq.~Queue();
    std::cout << "\t" << "is_empty(): " << tq.is_empty() << '\n';
    std::cout << "\tsize(): " << tq.size() << '\n';
    std::cout << "\tfront(): " << tq.front().value_or(-1) << '\n';

    std::cout << "Test Module complete!\n";
}