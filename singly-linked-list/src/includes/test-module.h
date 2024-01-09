#ifndef __TEST_MODULE_H
#define __TEST_MODULE_H

#include <iostream>
#include "singly-linked-list.h"

class TestModule
{
private:
    Slist<int> tl;
public:
    TestModule();
    void test(std::size_t add_lim=20, std::size_t remove_lim=10);
};

#endif