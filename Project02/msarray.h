// msarray.h
// Andrew Ng
// 2020-09-14
//
// CS 311 Fall 2020
// Header for class template MSArray
// Moderately Smart Array:
//   fixed-size array of generic type

#ifndef FILE_MSARRAY_H_INCLUDED
#define FILE_MSARRAY_H_INCLUDED

#include <cstddef>    
#include <algorithm>  
#include <utility>    


template <typename ValType>
class MSArray
{

public:

    using size_type = std::size_t;

    using value_type = ValType;

public:

    MSArray()
        :_arrayptr(new value_type[8]),
         _size(8)
    {}

    explicit MSArray(size_type size)
        :_arrayptr(new value_type[size]),
         _size(size)
    {}

    MSArray(size_type size,
            const value_type & value)
        :_arrayptr(new value_type[size]),
         _size(size)
    {
        std::fill(begin(), end(), value);
    }

    ~MSArray() noexcept
    {
        delete [] _arrayptr;
    }

    MSArray(const MSArray<value_type> & other)
        :_arrayptr(new value_type[other.size()]),
         _size(other.size())
    {
        std::copy(other.begin(), other.end(), begin());
    }

    MSArray(MSArray<value_type> && other) noexcept
        :_arrayptr(other._arrayptr),
         _size(other.size())
    {
        other._arrayptr = nullptr;
    }

    MSArray<value_type> & operator=(const MSArray<value_type> & rhs)
    {
        MSArray<value_type> copy(rhs);
        swap(copy);
        return *this;
    }
    
    MSArray<value_type> & operator=(MSArray<value_type> && rhs) noexcept
    {
        swap(rhs);
        return *this;
    }

public:

    size_type size() const
    {
        return _size;
    }

    value_type * begin()
    {
        return _arrayptr;
    }

    const value_type * begin() const
    {
        return _arrayptr;
    }

    value_type * end()
    {
        return begin() + size();
    }

    const value_type * end() const
    {
        return begin() + size();
    }

public:

    value_type & operator[](size_type index)
    {
        return _arrayptr[index];
    }

    const value_type & operator[](size_type index) const
    {
        return _arrayptr[index];
    }

private:

    void swap(MSArray<value_type> & other) noexcept
    {
        std::swap(_arrayptr, other._arrayptr);
        std::swap(_size, other._size);
    }

private:

    value_type * _arrayptr;

    size_type _size;

};


template <typename ValType>
bool operator==(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    if (lhs.size() == rhs.size()) {
        return std::equal(lhs.begin(),
                          lhs.end(),
                          rhs.begin());
    }
    return false;
}


template <typename ValType>
bool operator!=(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    return !(lhs == rhs);
}


template <typename ValType>
bool operator<(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    return std::lexicographical_compare(lhs.begin(),
                                        lhs.end(),
                                        rhs.begin(),
                                        rhs.end());
}


template <typename ValType>
bool operator>(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    return rhs < lhs;
}


template <typename ValType>
bool operator<=(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    return !(rhs < lhs);
}


template <typename ValType>
bool operator>=(const MSArray<ValType> & lhs,
                const MSArray<ValType> & rhs)
{
    return !(lhs < rhs);
}


#endif // FILE_MSARRAY_H_INCLUDED