#include "test-module.h"
#include <iostream>

TestModule::TestModule(): tl() {}

void TestModule::test(std::size_t add_lim, std::size_t remove_lim)
{
    if (remove_lim > add_lim)
    {
        std::cout << "Remove limit exceeds add limit\n";
        return;
    }

    std::cout << "! Test Initialization !\n";
    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';

    std::cout << "Populating list...\n\t";
    for (unsigned i = 1; i <= add_lim; ++i)
        tl.add_front(i);
    tl.for_each([](int& elem) { std::cout << elem << ' '; });
    std::cout << '\n';

    
    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tsize(): " << tl.size() << '\n';

    std::cout << "Removing" << remove_lim << " items from list...\n";
    for (unsigned i = 1; i <= remove_lim; ++i)
        tl.remove_front();

    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tsize(): " << tl.size() << '\n';

    std::cout << "Test Module complete!\n";
}