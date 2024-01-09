#ifndef __TEST_MODULE_H
#define __TEST_MODULE_H

#include <iostream>
#include "doubly-linked-list.h"

class TestModule
{
private:
    Dlist<int> tl;
public:
    TestModule();
    void test(const std::size_t add_lim=1000, const std::size_t remove_lim=450);
};

#endif