#ifndef __SLIST_H
#define __SLIST_H

#include <optional>
#include <initializer_list>

template<typename T>
struct Node
{
    T data{};
    Node<T> *next{nullptr};
};

template<typename T>
class Slist
{
private:
    Node<T> *head, *iterator;
    std::size_t n{0};
public:
    // Constructors/Destructors
    Slist();
    Slist(const std::initializer_list<T>&);
    ~Slist();

    // Observers
    inline std::size_t size(void) const noexcept;
    inline bool is_empty(void) const noexcept;
    std::optional<const T> front(void) const;

    // Mutators
    void add_front(const T&);
    void remove_front(void);

    // Aux
    void for_each(void(*)(T&));
};

template<typename T>
Slist<T>::Slist(): head{nullptr}, iterator{nullptr}
{}

template<typename T>
Slist<T>::Slist(const std::initializer_list<T>& init_list)
{
    for (const T& elem: init_list)
        add_front(elem);
}

template<typename T>
Slist<T>::~Slist()
{ 
    while (head != nullptr)
        remove_front();
}

template<typename T>
inline std::size_t Slist<T>::size(void) const noexcept
{ return n; }

template<typename T>
inline bool Slist<T>::is_empty(void) const noexcept
{ return head == nullptr; }

template<typename T>
std::optional<const T> Slist<T>::front(void) const
{
    return head == nullptr ?
        std::nullopt : std::optional<const T>(head->data);
}

template<typename T>
void Slist<T>::add_front(const T& elem)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = elem;
    new_node->next = head;
    head = new_node;
    ++n;
}

template<typename T>
void Slist<T>::remove_front(void)
{
    if (head == nullptr)
        return;

    Node<T> *old = head;
    head = old->next;
    delete old;
    --n;
}

template<typename T>
void Slist<T>::for_each(void(*f)(T&))
{
    if (head == nullptr)
        return;

    iterator = head;
    while (iterator != nullptr)
    {
        f(iterator->data);
        iterator = iterator->next;
    }
}
#endif

