#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>

template <typename T>
class List
{
    template <typename U> class Node;

public:
    List()
    {
        std::cout << "List created" << std::endl;
    }

    List(const List<T> &list)
    {
        _head = std::move(list._head);
    }

    List(List<T> &&list)
    {
        _head = std::move(list._head);
    }

    ~List()
    {
        std::cout << "List destroyed" << std::endl;
    }

    Node<T>* head()
    {
        return *_head;
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
        _head = std::move(node);
    }

    void remove(Node<T> *node)
    {
        if(node->_prev != nullptr) node->_prev->_next = std::move(node->_next);
        else _head = std::move(node->_next);

        if(node->_next != nullptr) node->_next->_prev = node->_prev;
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
    std::unique_ptr<Node<T>> _head = nullptr;
};

template <typename T>
template <typename U>
class List<T>::Node
{
    friend class List;

public:
    Node(const T &t) : _key(t)
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
