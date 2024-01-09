#ifndef __TEST_MODULE_H
#define __TEST_MODULE_H

#include "queue.h"

class TestModule
{
private:
     Queue<int> tq;
public:
    TestModule();
    void test(std::size_t enqueue_lim=20, std::size_t dequeue_lim=10);
};

#endif