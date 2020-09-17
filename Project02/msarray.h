// msarray.h
// Andrew S. Ng
// Started: 2020-09-14
// Updated: 2020-09-17
//
// CS 311 Fall 2020
// Header for class template MSArray
// RAII class holding array of generic type and its size

#ifndef FILE_MSARRAY_H_INCLUDED
#define FILE_MSARRAY_H_INCLUDED

#include <cstddef>    // for std::size_t
#include <algorithm>  // for generic algorithms
#include <utility>    // std::swap


/////////////////////////////////////////////////////
//    class template MSArray - Class definition    //
/////////////////////////////////////////////////////


// class template MSArray
// RAII class holding array of generic type and its size
// Invariants:
//   _arrayptr points to memory allocated by new[], owned by *this,
//     and with enough space for _size value_type objects.
//   _size >= 0
// Requirements on Types:
//   T must have a copy ctor.
template <typename T>
class MSArray
{

// ---- MSArray: public member types ----
public:

    using size_type = std::size_t;  // Unsigned type for
                                    // array size and indices.
    using value_type = T;           // Type of items in container.

// ---- MSArray: ctors, dctors, op= ----
public:

    // Default ctor
    // Allocates array of size 8.
    // All items default-constructed.
    MSArray()
        :_arrayptr(new value_type[8]),
         _size(8)
    {}

    // Ctor from size
    // Allocates array of given size.
    // All items default-constructed.
    // Not an implicit type conversion.
    // Pre:
    //   size >= 0
    explicit MSArray(size_type size)
        :_arrayptr(new value_type[size]),
         _size(size)
    {}

    // Ctor from size and value
    // Allocates array of given size.
    // All items filled with given value.
    // Pre:
    //   size >= 0
    MSArray(size_type size,
            const value_type & value)
        :_arrayptr(new value_type[size]),
         _size(size)
    {
        std::fill(begin(), end(), value);
    }

    // BIG 5: ALL DEFINED

    // Dctor
    // Deallocates array
    ~MSArray()
    {
        delete [] _arrayptr;
    }

    // Copy ctor
    MSArray(const MSArray<value_type> & other)
        :_arrayptr(new value_type[other.size()]),
         _size(other.size())
    {
        std::copy(other.begin(), other.end(), begin());
    }

    // Move ctor
    MSArray(MSArray<value_type> && other) noexcept
        :_arrayptr(other._arrayptr),
         _size(other.size())
    {
        other._arrayptr = nullptr;
    }

    // Copy assignment
    MSArray<value_type> & operator=(const MSArray<value_type> & rhs)
    {
        MSArray<value_type> copy(rhs);
        swap(copy);
        return *this;
    }
    
    // Move assignment
    MSArray<value_type> & operator=(MSArray<value_type> && rhs) noexcept
    {
        swap(rhs);
        return *this;
    }

// ---- MSArray: general public functions ----
public:

    // size
    // Returns number of items in array.
    size_type size() const
    {
        return _size;
    }

    // begin - non-const & const
    // Returns address of item 0 in array.
    value_type * begin()
    {
        return _arrayptr;
    }
    const value_type * begin() const
    {
        return _arrayptr;
    }

    // end - non-const & const
    // Returns address of item one-past
    // the end of the array.
    value_type * end()
    {
        return begin() + size();
    }
    const value_type * end() const
    {
        return begin() + size();
    }

// ---- MSArray: general public operators ----
public:

    // op[] - non-const & const
    // Returns a reference to the item at the index.
    // Pre:
    //   0 <= index < _size
    value_type & operator[](size_type index)
    {
        return _arrayptr[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _arrayptr[index];
    }

// ---- MSArray: general private functions ----
private:

    // swap
    // Swaps values of this object and other object.
    void swap(MSArray<value_type> & other) noexcept
    {
        std::swap(_arrayptr, other._arrayptr);
        std::swap(_size, other._size);
    }

// ---- MSArray: data members ----
private:

    value_type * _arrayptr;  // Pointer to dynamic array

    size_type _size;         // Size of array (num. of items)

};  // End class template MSArray


////////////////////////////////////////////////////////////////
//    class template MSArray - Global operator definitions    //
////////////////////////////////////////////////////////////////


// op== (MSArray<T>, MSArray<T>)
// Returns true if sizes are equal,
// and all items are equal.
// Requirements on Types:
//   T has a public op==.
template <typename T>
bool operator==(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    if (lhs.size() == rhs.size()) {
        return std::equal(lhs.begin(),
                          lhs.end(),
                          rhs.begin());
    }
    return false;
}


// op!= (MSArray<T>, MSArray<T>)
// Returns true if both MSArray<T>
// are not equal
// Requirements on Types:
//   T has a public op==.
template <typename T>
bool operator!=(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    return !(lhs == rhs);
}


// op< (MSArray<T>, MSArray<T>)
// Returns true if lhs is
// lexicographically less than rhs
// Requirements on Types:
//   T has a public op<.
template <typename T>
bool operator<(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    return std::lexicographical_compare(lhs.begin(),
                                        lhs.end(),
                                        rhs.begin(),
                                        rhs.end());
}


// op> (MSArray<T>, MSArray<T>)
// Returns true if rhs is less than lhs
// Requirements on Types:
//   T has a public op<.
template <typename T>
bool operator>(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    return rhs < lhs;
}


// op<= (MSArray<T>, MSArray<T>)
// Returns true if rhs is not less than lhs
// Requirements on Types:
//   T has a public op<.
template <typename T>
bool operator<=(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    return !(rhs < lhs);
}


// op>= (MSArray<T>, MSArray<T>)
// Returns true if lhs is not less than rhs
// Requirements on Types:
//   T has a public op<.
template <typename T>
bool operator>=(const MSArray<T> & lhs,
                const MSArray<T> & rhs)
{
    return !(lhs < rhs);
}

#endif // #ifndef FILE_MSARRAY_H_INCLUDED