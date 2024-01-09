#ifndef __TEST_MODULE_H
#define __TEST_MODULE_H

#include "c-list.h"
#include <initializer_list>

class TestModule
{
private:
    Clist<int> tl;
public:
    TestModule();
    TestModule(const std::initializer_list<int>&);
    void test(size_t);
};
#endif