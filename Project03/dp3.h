// dp3.h
// Skeleton by Glenn G. Chappell
// 2020-09-17
// Functions by Andrew S. Ng
// Started: 2020-09-21
// Updated: 2020-09-23
//
// For CS 311 Fall 2020
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>   // For std::is_sorted


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    while (head != nullptr) {
        if (index == 0) {
            return head->_data;
        }
        head = head->_next;
        --index;
    }
    throw std::out_of_range(
        "Index is out of range of the linked list nodes");
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    return std::is_sorted(first, last);
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  // #ifndef FILE_DP3_H_INCLUDED

