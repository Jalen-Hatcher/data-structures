#ifndef __QUEUE_H
#define __QUEUE_H

#include "../../../circular-list/src/includes/c-list.h"

template<typename T>
class Queue
{
private:
    Clist<T> c; // Utilizes circular-list as base data structure
public:
    // Constructors/Destructors
    Queue();
    Queue(const std::initializer_list<T>&);
    ~Queue();

    // Observers
    std::size_t size(void) const noexcept;
    bool is_empty(void) const noexcept;
    auto front(void) const;

    // Mutators
    void enqueue(const T&);
    void dequeue(void);
    void for_each(void(*)(T&));
};

template<typename T>
Queue<T>::Queue(): c()
{}

template<typename T>
Queue<T>::Queue(const std::initializer_list<T>& init_list)
{
    for (const T& elem : init_list)
    {
        c.add(elem);
        c.advance();
    }
}

template<typename T>
Queue<T>::~Queue()
{
    while (!is_empty())
        dequeue();
}

template<typename T>
std::size_t Queue<T>::size(void) const noexcept
{ return c.size(); }

template<typename T>
bool Queue<T>::is_empty(void) const noexcept
{ return c.size() == 0; }

template<typename T>
auto Queue<T>::front(void) const
{ return c.first(); }

template<typename T>
void Queue<T>::enqueue(const T& e)
{
    c.add(e);
    c.advance();
}

template<typename T>
void Queue<T>::dequeue(void)
{
    if (is_empty())
        throw ("Dequeue on empty queue!");
    c.remove();
}

template<typename T>
void Queue<T>::for_each(void(*f)(T&))
{ c.for_each(f); }
#endif