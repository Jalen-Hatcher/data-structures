#ifndef __CLIST_H
#define __CLIST_H

#include <iostream>
#include <optional>
#include <string>
#include <initializer_list>

template<typename T>
struct Node
{
    T data{};
    Node<T> *next{nullptr};
};

template<typename T>
class Clist
{
private:
    Node<T> *cursor, *iterator;
    std::size_t n{0};
public:
    //Constructors/destructors
    Clist();
    Clist(const std::initializer_list<T>&);
    ~Clist();

    //Observer member functions
    inline bool is_empty(void) const noexcept;
    bool is_full(void) const;
    std::optional<const T> first(void) const; //return element after the cursor
    std::optional<const T> last(void) const; //return element at the cursor
    inline std::size_t size(void) const noexcept;

    //Mutator member functions
    void advance(); //advance cursor one node
    void add(const T&);
    void remove(void);
    void make_empty(void);

    //aux
    void for_each(void(*)(T&));
};

template<typename T>
Clist<T>::Clist(): cursor{nullptr}, iterator{nullptr} {}

template<typename T>
Clist<T>::Clist(const std::initializer_list<T>& init_list)
{
    for (const T& itr: init_list)
        add(itr);
}

template<typename T>
Clist<T>::~Clist()
{
    while (cursor != nullptr) 
        remove();
}

template<typename T>
inline bool Clist<T>::is_empty(void) const noexcept
{
    return cursor == nullptr;
}

template<typename T>
bool Clist<T>::is_full(void) const
{
    try
    {
        Clist<T> *nl = new Clist<T>();
        delete nl;
        return false;
    }
    catch(const std::bad_alloc& e)
    {
        return true;
    }  
}

template<typename T>
std::optional<const T> Clist<T>::first(void) const
{
    return cursor == nullptr ?
        std::nullopt : std::optional<const T>(cursor->next->data);
}

template<typename T>
std::optional<const T> Clist<T>::last(void) const
{
    return cursor == nullptr ?
        std::nullopt : std::optional<const T>(cursor->data);
}

template<typename T>
std::size_t Clist<T>::size(void) const noexcept 
{
    return n;
}

template<typename T>
void Clist<T>::advance()
{
    if (n == 0)
        return;

    cursor = cursor->next;
}

template<typename T>
void Clist<T>::add(const T& item)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = item;

    if (cursor == nullptr)
    {
        new_node->next = new_node;
        cursor = new_node;
        ++n;
        return;
    }

    new_node->next = cursor->next;
    cursor->next = new_node;
    ++n;
}

template<typename T>
void Clist<T>::remove(void)
{
    if (cursor == nullptr) //Empty List?
        return;

    Node<T> *old = cursor->next;

    if (cursor == old)  //If self-referential, cursor now NULL
        cursor = nullptr;
    else
        cursor->next = old->next;

    delete old;
    --n; 
}

template<typename T>
void Clist<T>::make_empty(void)
{
    while (cursor != nullptr)
        remove();
}

template<typename T>
void Clist<T>::for_each(void(*f)(T&))
{
    if (cursor == nullptr)
        return;

    iterator = cursor;
    do
    {
        f(iterator->data);
        iterator = iterator->next;
    } while (iterator != cursor);

    iterator = nullptr;
}
#endif