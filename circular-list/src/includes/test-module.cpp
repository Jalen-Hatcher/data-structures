#include "test-module.h"
#include <iostream>

TestModule::TestModule(): tl() {}

TestModule::TestModule(const std::initializer_list<int>& init_list): tl{init_list} {};

void TestModule::test(size_t lim)
{
    std::cout << "! Test Initialization !\n";
    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';
    std::cout << "\tis_full(): " << tl.is_full() << '\n';

    std::cout << "Populating list...\n\t";
    for (unsigned i = 1; i <= lim; ++i)
        tl.add(i);
    tl.for_each([](int& elem) {std::cout << elem << ' '; });
    std::cout << '\n';
    

    std::cout << "\tfirst(): " << tl.first().value_or(-1) << '\n';
    std::cout << "\tlast(): " << tl.last().value_or(-1) << '\n';

    std::cout << "calling advance()...\n";
    tl.advance();

    std::cout << "\tfirst(): " << tl.first().value_or(-1) << '\n';
    std::cout << "\tlast(): " << tl.last().value_or(-1) << '\n';

    std::cout << "calling make_empty()...\n";
    tl.make_empty();

    std::cout << "\tis_empty(): " << tl.is_empty() << '\n';
    std::cout << "\tis_full(): " << tl.is_full() << '\n';
}