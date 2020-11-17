// treesort.h  
//
// SKELETON BY
// Glenn G. Chappell
// 2020-11-09
//
// IMPLEMENTED BY
// Andrew S. Ng
// Started: 2020-11-15
// Updated: 2020-11-16
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


/////////////////////////////////////////////////////////////////////
//    struct BSTNode - Struct definition                           //
/////////////////////////////////////////////////////////////////////


// struct template BSTNode
// Binary search tree node of client-specified value type.
// Invariants:
//   _left and _right point to BSTNode subtrees, or are empty.
//   _left->_data <= _data <= _right->_data.
// Requirements on Types:
//   ValType has op<, a copy ctor, and a non-throwing dctor.
template <typename ValType>
struct BSTNode
{

    ValType                  _data;   // Data for this node
    std::unique_ptr<BSTNode> _left;   // Ptr to L subtree, or empty
    std::unique_ptr<BSTNode> _right;  // Ptr to R subtree, or empty

    // 1-param ctor
    // _data is set to data.
    // _left and _right are empty.
    // No-Throw Guarantee.
    explicit BSTNode(const ValType & data)
        :_data(data)
    {}

    // dctor defaulted
    // No-Throw Guarantee.
    ~BSTNode() = default;

    // No default ctor, copy/move operations
    BSTNode() = delete;
    BSTNode(const BSTNode & other) = delete;
    BSTNode & operator=(const BSTNode & other) = delete;
    BSTNode(BSTNode && other) = delete;
    BSTNode & operator=(BSTNode && other) = delete;

};  // End struct BSTNode


/////////////////////////////////////////////////////////////////////
//    struct BSTNode - Associated global functions                 //
/////////////////////////////////////////////////////////////////////


// insert
// Inserts item into binary search tree.
// Requirements on Types:
//   ValType has op<, a copy ctor, and a non-throwing dctor.
// Strong Guarantee.
// Exception Neutral.
template <typename ValType>
void insert(std::unique_ptr<BSTNode<ValType>> & head,
            const ValType & item)
{
    if (!head)
    {
        head = std::make_unique<BSTNode<ValType>>(item);
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
//   iter points to a valid location for writing data to.
// Requirements on Types:
//   ValType has op<, a copy ctor, and a non-throwing dctor.
// No-Throw Guarantee.
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


/////////////////////////////////////////////////////////////////////
//    Treesort - Algorithm definition                              //
/////////////////////////////////////////////////////////////////////


// treesort
// Sort a given range using Treesort.
// Pre:
//   [first, last) is a valid range.
// Requirements on Types:
//   FDIter is a forward iterator type.
//   Value of FDIter has op<, a copy ctor, and a non-throwing dctor.
// Strong Guarantee.
// Exception Neutral.
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

