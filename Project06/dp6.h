// dp6.h
// Andrew S. Ng
// Started: 2020-11-04
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


// reverseList
// Reverses the items in a given linked list.
// Requirements on Types:
//   None.
// No-Throw Guarantee
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


// class template LLMap
// Associative dataset of client-specified key and value types.
// Invariants:
//   _dataset is empty or points to an LLNode2 of key-value pairs.
//   No two pairs have the same keys (equal by op==).
// Requirements on Types:
//   KeyType and ValType have a copy ctor and a non-throwing dctor.
//   KeyType has the equality operator (==).
template <typename KeyType, typename ValType>
class LLMap
{

// ---- LLMap: public member types ----
public:

    using key_type = KeyType;

    using value_type = ValType;

    using pair_type = std::pair<key_type, value_type>;

    using size_type = std::size_t;

// ---- LLMap: ctors, dctors, op= ----
public:

    // Default ctor
    // No-Throw Guarantee
    LLMap() = default;

    // Dctor
    // No-Throw Guarantee
    ~LLMap() = default;

    // No copy/move operations
    LLMap(const LLMap<key_type, value_type> & other) = delete;
    LLMap(LLMap<key_type, value_type> && other) = delete;
    LLMap<key_type, value_type> & operator=(const LLMap<key_type, value_type> & other) = delete;
    LLMap<key_type, value_type> & operator=(LLMap<key_type, value_type> && other) = delete;

// ---- LLMap: general public functions ----
public:

    // size
    // Returns number of key-value pairs in dataset.
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return ::size(_dataset);  // Refer to global scope
    }

    // empty
    // Returns true when dataset has no key-value pairs.
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // find - non-const & const
    // Searches for given key within the dataset.
    // If found, returns pointer to associated value,
    //   otherwise returns nullptr.
    // No-Throw Guarantee
    value_type * find(const key_type & key) noexcept
    {
        auto p = _dataset.get();
        while (p != nullptr)
        {
            if (key == p->_data.first)
                return &(p->_data.second);
            p = p->_next.get();
        }
        return nullptr;
    }
    const value_type * find(const key_type & key) const noexcept
    {
        auto p = _dataset.get();
        while (p != nullptr)
        {
            if (key == p->_data.first)
                return &(p->_data.second);
            p = p->_next.get();
        }
        return nullptr;
    }

    // insert
    // Inserts key-value pair into dataset if key does not already
    //   exist, otherwise replaces existing pair.
    // Strong Guarantee
    // Exception Neutral
    void insert(const key_type & key, const value_type & value)
    {
        auto p = find(key);
        if (p != nullptr)
            *p = value;
        else
            push_front(_dataset, std::make_pair(key, value));
    }

    // erase
    // If key exists in the dataset, the key-value pair is removed.
    // No-Throw Guarantee
    void erase(const key_type & key) noexcept
    {
        // Empty case
        if (empty())
            return;

        // Check first pair
        if (key == _dataset->_data.first)
        {
            pop_front(_dataset);
            return;
        }

        // Iterate: if next pair matches key, replace next pair
        //   with whatever it's pointing to.
        auto p = _dataset.get();
        while (p->_next)
        {
            auto & np = p->_next;
            if (key == np->_data.first)
            {
                auto temp = std::move(np->_next);
                np = std::move(temp);
                return;
            }
            p = np.get();
        }
    }

    // traverse
    // Passed function is called on each key-value pair in dataset.
    // Pre:
    //   Function f has two parameters: (key type, value type).
    //   Function f returns nothing.
    // Strong Guarantee
    // Exception Neutral
    void traverse(const std::function<void(key_type, value_type)> & f) const
    {
        auto p = _dataset.get();
        while (p != nullptr)
        {
            f(p->_data.first, p->_data.second);
            p = p->_next.get();
        }
    }    

// ---- LLMap: data members ----
private:

    // Associative dataset
    std::unique_ptr<LLNode2<pair_type>> _dataset;

};  // End class LLMap


#endif  // #ifndef FILE_DP6_H_INCLUDED

