#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>

template <typename T>
class List
{
    template <typename> class Node;

public:
    List() : _head(nullptr)
    {
        std::cout << "List created" << std::endl;
    }

    List(const List &list)
    {
        _head = std::move(list._head);
    }

    List(List &&list)
    {
        _head = std::move(list._head);
    }

    ~List()
    {
        std::cout << "List destroyed" << std::endl;
    }

    Node<T>* search(const T &t)
    {
        auto node = _head.get();
        while(node != nullptr && node->_key != t) node = node->_next.get();

        return node;
    }

    void insert(const T &t)
    {
        auto node = std::make_unique<Node<T>>(t);
        node->_next = std::move(_head);
        _head = std::move(node);
    }

    void remove(Node<T> *n)
    {
        if(n == _head.get()) _head = std::move(n->_next);
        else
        {
            auto prev = _head.get();
            while(prev->_next.get() != n && prev != nullptr) prev = prev->_next.get();

            if(prev != nullptr) prev->_next = std::move(n->_next);
        }
    }

    Node<T>* head()
    {
        return _head.get();
    }

    List<T>& operator=(const List<T> &list);
    List<T>& operator=(List<T> &&list);

private:
    std::unique_ptr<Node<T>> _head;
};

template <typename T>
template <typename>
class List<T>::Node
{
    friend class List;

public:
    Node(const T &key) : _next(nullptr), _key(key)
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
    std::unique_ptr<Node<T>> _next;
    T _key;
};

#endif // LIST_H
