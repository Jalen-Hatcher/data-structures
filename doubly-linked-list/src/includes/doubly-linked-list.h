#ifndef __DLIST_H
#define __DLIST_H

#include <optional>
#include <initializer_list>

template<typename T>
struct Node
{
    T data{};
    Node<T> *prev{nullptr}, *next{nullptr};
};

template<typename T>
class Dlist
{
private:
    // dummy nodes/sentinels
    Node<T> *header, *trailer;
protected:
    // Local utilities
    void add(Node<T>*, const T&);
    void remove(Node<T>*);
public:
    // Constructors
    Dlist();
    ~Dlist();

    // Observers
    inline bool is_empty(void) const noexcept;
    std::optional<const T> front(void) const;
    std::optional<const T> back(void) const;

    // Mutators
    void add_front(const T&);
    void add_back(const T&);
    void remove_front(void);
    void remove_back(void);
};

template<typename T>
Dlist<T>::Dlist()
{
    header = new Node<T>;
    trailer = new Node<T>;
    header->next = trailer;
    trailer->prev = header;
}

template<typename T>
Dlist<T>::~Dlist()
{
    while (!is_empty())
        remove_front();
    delete header; 
    delete trailer;
}

template<typename T>
inline bool Dlist<T>::is_empty(void) const noexcept
{ return (header->next == trailer); }

template<typename T>
std::optional<const T> Dlist<T>::front(void) const 
{
    return is_empty() ?
        std::nullopt : std::optional<const T>(header->next->data);
}

template<typename T>
std::optional<const T> Dlist<T>::back(void) const
{
    return is_empty() ?
        std::nullopt : std::optional<const T>(trailer->prev->data);
} 

template<typename T>
void Dlist<T>::add(Node<T> *v, const T& elem)
{
    // Allocate new node for elem
    Node<T> *new_node = new Node<T>; 
    new_node->data = elem;

    new_node->next = v; // Link new_node between v
    new_node->prev = v->prev; // Link v->prev
    v->prev->next = new_node;
    v->prev = new_node;
}

template<typename T>
void Dlist<T>::add_front(const T& elem)
{ add(header->next, elem); }

template<typename T>
void Dlist<T>::add_back(const T& elem)
{ add(trailer, elem); }

template<typename T>
void Dlist<T>::remove(Node<T> *v)
{
    Node<T> *u = v->prev;   // Remove v's predecessor/successor                       //
    Node<T> *w = v->next;   // Unlink v

    u->next = w;
    w->prev = u;

    delete v;
}

template<typename T>
void Dlist<T>::remove_front()
{ remove(header->next); }

template<typename T>
void Dlist<T>::remove_back()
{ remove(trailer->prev); }
#endif