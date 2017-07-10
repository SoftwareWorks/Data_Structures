#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>

template <typename T>
class List
{
    template <typename> class Node;

public:
    List() : _head(nullptr), _tail(nullptr)
    {
        std::cout << "List created" << std::endl;
    }

    List(const List<T> &list)
    {
        _head = std::move(list._head);
        _tail = list._tail;
    }

    List(List<T> &&list)
    {
        _head = std::move(list._head);
        _tail = std::move(list._tail);
    }

    ~List()
    {
        std::cout << "List destroyed" << std::endl;
    }

    Node<T>* head()
    {
        return _head.get();
    }

    Node<T>* tail()
    {
        return _tail;
    }

    Node<T>* search(const T &t)
    {
        auto node = _head.get();
        while(node != nullptr && node->_key != t)
        {
            node = node->_next.get();
        }

        return node;
    }

    void insert(const T &t)
    {
        auto node = std::make_unique<Node<T>>(t);
        if(_head != nullptr) _head->_prev = node.get();
        node->_next = std::move(_head);
        node->_prev = nullptr;

        if(_tail == nullptr) _tail = node.get();
        _head = std::move(node);
    }

    void insertBefore(Node<T> *n, const T &t)
    {
        auto node = std::make_unique<Node<T>>(t);

        if(n->_prev == nullptr) //when n is list's head
        {
            node->_next = std::move(_head);
            node->_prev = nullptr;

            _head = std::move(node);
        }
        else
        {
            node->_next = std::move(n->_prev->_next);
            node->_prev = n->_prev;

            n->_prev->_next = std::move(node);
            n->_prev = node.get();
        }
    }

    void remove(Node<T> *node)
    {
        if(node == _tail) _tail = node->_prev;

        if(node->_next != nullptr) node->_next->_prev = node->_prev;

        if(node->_prev != nullptr) node->_prev->_next = std::move(node->_next);
        else _head = std::move(node->_next);
    }

    List<T>& operator=(const List<T> &list)
    {
        _head = std::move(list._head);
        return *this;
    }

    List<T>& operator=(List<T> &&list)
    {
        _head = std::move(list._head);
        return *this;
    }

private:
    std::unique_ptr<Node<T>> _head;
    Node<T> *_tail;
};

template <typename T>
template <typename>
class List<T>::Node
{
    friend class List;

public:
    Node(const T &t) : _next(nullptr), _prev(nullptr), _key(t)
    {
        std::cout << "Node " << _key << " created" << std::endl;
    }

    ~Node()
    {
        std::cout << "Node " << _key << " destroyed" << std::endl;
    }

    T& key()
    {
        return _key;
    }

private:
    std::unique_ptr<Node> _next;
    Node *_prev;

    T _key;
};

#endif // LIST_H
