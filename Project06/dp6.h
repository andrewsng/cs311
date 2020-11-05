// dp6.h
// Andrew S. Ng
// Started: 2020-11-05
// Updated: 2020-11-05
//
// For CS 311 Fall 2020
// Header for Project 6 Templates

#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"  // For class template LLNode2

#include <memory>     // For std::unique_ptr
#include <utility>    // For std::pair, std::swap, std::move
#include <cstddef>    // For std::size_t
#include <functional> // For std::function


template <typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head)
{
    std::unique_ptr<LLNode2<ValType>> newHead;
    while (head)
    {
        newHead.swap(head->_next);
        newHead.swap(head);
    }
    head = std::move(newHead);
}


template <typename KeyType, typename ValType>
class LLMap
{

public:

    using key_type = KeyType;

    using value_type = ValType;

    using pair_type = std::pair<key_type, value_type>;

    using size_type = std::size_t;

    using iterator = value_type *;
    using const_iterator = const value_type *;

public:

    LLMap() = default;

    ~LLMap() = default;

    LLMap(const LLMap<key_type, value_type> & other) = delete;
    LLMap(LLMap<key_type, value_type> && other) = delete;
    LLMap<key_type, value_type> & operator=(const LLMap<key_type, value_type> & other) = delete;
    LLMap<key_type, value_type> & operator=(LLMap<key_type, value_type> && other) = delete;

public:

    size_type size() const
    {
        return ::size(_dataset);  // Refer to global function
    }

    bool empty() const
    {
        return size() == 0;
    }

    iterator find(const key_type & key)
    {
        for (auto p = _dataset.get(); p != nullptr; p = p->_next.get())
        {
            if (key == p->_data.first)
                return &(p->_data.second);
        }
        return nullptr;
    }
    const_iterator find(const key_type & key) const
    {
        for (auto p = _dataset.get(); p != nullptr; p = p->_next.get())
        {
            if (key == p->_data.first)
                return &(p->_data.second);
        }
        return nullptr;
    }

    void insert(const key_type & key, const value_type & value)
    {
        auto p = find(key);
        if (p != nullptr)
            *p = value;
        else
            push_front(_dataset, std::make_pair(key, value));
    }

    void erase(const key_type & key)
    {
        if (key == _dataset->_data.first)
        {
            pop_front(_dataset);
            return;
        }

        auto p = _dataset.get();
        while (p != nullptr)
        {
            if (key == p->_next->_data.first)
            {
                p->_next = std::move(p->_next->_next);
                return;
            }
            p = p->_next.get();
        }
    }

    void traverse(const std::function<void(key_type, value_type)> & f)
    {
        auto p = _dataset.get();
        while (p != nullptr)
        {
            f(p->_data.first, p->_data.second);
            p = p->_next.get();
        }
    }    

private:

    std::unique_ptr<LLNode2<pair_type>> _dataset;

};


#endif  // #ifndef FILE_DP6_H_INCLUDED

