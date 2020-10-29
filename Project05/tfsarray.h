// tfsarray.h
// VERSION 6
//
// Original author (v1-v5):
// Glenn G. Chappell
// Started: 2020-10-14
// Updated: 2020-10-21
//
// Completed by (v6):
// Andrew S. Ng
// Started: 2020-10-26
// Updated: 2020-10-29
//
// For CS 311 Fall 2020
// Header for class template TFSArray
// Frightfully smart array of client specified type

// History:
// - v1:
//   - Skeleton only: header & source files, #ifndef, #include, empty
//     class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.
// - v4:
//   - Revise class invariants to allow for _data being nullptr if _size
//     is zero.
//   - Write move ctor.
//   - Mark various functions as noexcept.
//   - Put definitions of copy & move functions, resize, insert, erase,
//     swap in source file.
// - v5:
//   - Add _capacity data member.
//   - Add constant DEFAULT_CAP and use it in setting the capacity in
//     default ctor/ctor from size.
// - v6:
//   - Move entire class to header to convert to class template for
//     client specified types.
//   - Write copy ctor, copy assn, move assn, resize, insert, erase,
//     and swap.
//   - Document exception-safety guarantees for functions just written.
//   - Document preconditions and exception-neutrality for all functions
//   - Document requirements on types for class template.

#ifndef FILE_TFSARRAY_H_INCLUDED
#define FILE_TFSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max, std::copy
#include <utility>
// For std::swap, std::ptrdiff_t


// *********************************************************************
// class template TFSArray - Class definition
// *********************************************************************


// class template TFSArray
// Frightfully Smart Array of client specified type.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//   0 <= _size <= _capacity.
//   _data points to an array of value_type, allocated with new [],
//    owned by *this, holding _capacity value_type values -- UNLESS
//    _capacity == 0, in which case _data may be nullptr.
// Requirements on Types:
//   T has a copy ctor.
//   T has a non-throwing dctor and non-throwing move operations.
template <typename T>
class TFSArray
{

// ***** TFSArray: types *****
public:

    // value_type: type of data items
    using value_type = T;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** TFSArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

// ***** TFSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee.
    // Exception-neutral.
    explicit TFSArray(size_type size=0)
        :_capacity(std::max(size, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(size),
         _data(_capacity == 0 ? nullptr : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee.
    // Exception-neutral.
    TFSArray(const TFSArray<value_type> & other)
        :_capacity(0),
         _size(0),
         _data(nullptr)
    {
        TFSArray<value_type> temp(other._capacity);
        temp._size = other.size();
        std::copy(other.begin(), other.end(), temp.begin());
        swap(temp);
    }

    // Move ctor
    // No-Throw Guarantee.
    // Exception-neutral.
    TFSArray(TFSArray<value_type> && other) noexcept
        :_capacity(other._capacity),
         _size(other._size),
         _data(other._data)
    {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment
    // Strong Guarantee.
    // Exception-neutral.
    TFSArray<value_type> & operator=(const TFSArray<value_type> & other)
    {
        TFSArray<value_type> copyOfOther(other);
        swap(copyOfOther);
        return *this;
    }

    // Move assignment
    // No-Throw Guarantee.
    // Exception-neutral.
    TFSArray<value_type> & operator=(TFSArray<value_type> && other) noexcept
    {
        swap(other);
        return *this;
    }

    // Dctor
    // No-Throw Guarantee.
    // Exception-neutral.
    ~TFSArray()
    {
        delete [] _data;
    }

// ***** TFSArray: general public operators *****
public:

    // operator[] - non-const & const
    // Returns a reference to the item at the index.
    // Pre:
    //   0 <= index < _size.
    // No-Throw Guarantee.
    // Exception-neutral.
    value_type & operator[](size_type index) noexcept
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const noexcept
    {
        return _data[index];
    }

// ***** TFSArray: general public functions *****
public:

    // size
    // Returns number of items in array.
    // No-Throw Guarantee.
    // Exception-neutral.
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // Returns bool for whether array is size zero.
    // No-Throw Guarantee.
    // Exception-neutral.
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // Returns iterator to first item.
    // No-Throw Guarantee.
    // Exception-neutral.
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // Returns iterator to one past last item.
    // No-Throw Guarantee.
    // Exception-neutral.
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // Resizes array, maintaining all prev data.
    // Reallocates and copies array when necessary.
    // Pre:
    //   0 <= newsize.
    // Strong Guarantee.
    // Exception-neutral.
    void resize(size_type newsize)
    {
        if (newsize <= _capacity)
            _size = newsize;
        else
        {
            size_type newCapacity = std::max(size_type(2) * _capacity, newsize);
            TFSArray<value_type> temp(newCapacity);
            temp._size = newsize;
            std::copy(begin(), end(), temp.begin());
            swap(temp);
        }
    }

    // insert
    // Inserts given item before the item referenced by the iterator.
    // Returns iterator to the inserted item.
    // Pre:
    //   begin() <= pos <= end().
    // Exception-neutral.
    iterator insert(iterator pos,
                    const value_type & item)
    {
        std::ptrdiff_t index = pos - begin();
        resize(size() + 1);
        pos = begin() + index;
        std::rotate(pos, end() - 1, end());
        *pos = item;
        return pos;
    }

    // erase
    // Removes the item referenced by the iterator.
    // Returns iterator to item after the removed item,
    //   or end() if the last item was removed.
    // Pre:
    //   begin() <= pos < end().
    // Exception-neutral.
    iterator erase(iterator pos)
    {
        std::rotate(pos, pos + 1, end());
        resize(size() - 1);
        return pos;
    }

    // push_back
    // Adds given item to the end of the array.
    // Exception-neutral.
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // Removes the last item from the array.
    // Exception-neutral.
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // Swaps the values of *this and another array.
    // No-Throw Guarantee.
    // Exception-neutral.
    void swap(TFSArray<value_type> & other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }

// ***** TFSArray: data members *****
private:

    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class TFSArray


#endif  //#ifndef FILE_TFSARRAY_H_INCLUDED

