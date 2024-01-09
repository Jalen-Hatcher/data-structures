#include "test-module.h"
#include <iostream>

TestModule::TestModule(): tl() {}


void TestModule::test(const std::size_t add_lim, const std::size_t remove_lim)
{
    std::cout << "! Test Initialization !\n";
    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';

    std::cout << "Populating front of list...\n";
    for (unsigned i = 1; i <= add_lim; ++i)
        tl.add_front(i);
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tback(): " << tl.back().value_or(-1) << '\n';

    std::cout << "Adding " << remove_lim << " elements to back of list\n";
    for (unsigned i = (add_lim + 1); i <= (add_lim + remove_lim); i++)
        tl.add_back(i);
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tback(): " << tl.back().value_or(-1) << '\n';

    std::cout << "Removing " << remove_lim << " elements from front of list\n";
    for (unsigned i = 1; i <= remove_lim; ++i)
        tl.remove_front();
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tback(): " << tl.back().value_or(-1) << '\n';

    std::cout << "Removing " << remove_lim << " elements from back of list\n";
    for (unsigned i = 1; i <= remove_lim; ++i)
        tl.remove_back();
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tback(): " << tl.back().value_or(-1) << '\n';

    
    std::cout << "calling destructor...\n";
    tl.~Dlist();

    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';
    std::cout << "\tfront(): " << tl.front().value_or(-1) << '\n';
    std::cout << "\tback(): " << tl.back().value_or(-1) << '\n';
}