// treesort.h  
//
// SKELETON BY
// Glenn G. Chappell
// 2020-11-09
//
// IMPLEMENTED BY
// Andrew S. Ng
// Started: 2020-11-15
// Updated: 2020-11-15
//
// For CS 311 Fall 2020
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <memory>
// For std::unique_ptr
#include <utility>
// For std::move


// struct template BSTNode
// Binary search tree node of client-specified value type.
// Invariants:
//     ???
// Requirements on Types:
//     ???
template <typename ValType>
struct BSTNode
{
    ValType _data;
    std::unique_ptr<BSTNode> _left;
    std::unique_ptr<BSTNode> _right;

    explicit BSTNode(const ValType & data)
        :_data(data)
    {}
};


// insert
// Inserts item into binary search tree.
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template <typename ValType>
void insert(std::unique_ptr<BSTNode<ValType>> & head,
            const ValType & item)
{
    if (!head)
    {
        auto tmp = std::make_unique<BSTNode<ValType>>(item);
        head = std::move(tmp);
        return;
    }

    if (item < head->_data)
    {
        insert(head->_left, item);
        return;
    }

    insert(head->_right, item);
}


// traverse
// Writes binary search tree data to location by inorder traversal.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template <typename ValType, typename FDIter>
void traverse(const std::unique_ptr<BSTNode<ValType>> & ptr,
              FDIter & iter)
{
    if (!ptr)
        return;

    traverse(ptr->_left, iter);
    *iter++ = ptr->_data;
    traverse(ptr->_right, iter);
}              


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template <typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // Populate binary search tree with values
    std::unique_ptr<BSTNode<Value>> BSTree;
    for (FDIter it = first; it != last; ++it)
    {
        insert(BSTree, *it);
    }

    // Copy data back by inorder traversal
    traverse(BSTree, first);
}


#endif  //#ifndef FILE_TREESORT_H_INCLUDED

