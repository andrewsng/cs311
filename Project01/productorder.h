// productorder.h
// Andrew Ng
// Started: 2020-09-01
// Updated: 2020-09-08
//
// CS 311 Fall 2020
// Header for class ProductOrder
// Product order: name and count

#ifndef FILE_PRODUCTORDER_H_INCLUDED
#define FILE_PRODUCTORDER_H_INCLUDED

#include <string>	// For std::string
#include <ostream>	// For std::ostream


/////////////////////////////////////////////////
//    class ProductOrder - Class definition    //
/////////////////////////////////////////////////


// class ProductOrder
// Product order: name and count
// invariants:
//   0 <= count_
class ProductOrder
{

// ---- ProductOrder: ctors, dctor, copy, move ----
public:

	// Default ctor
	// Sets name to "UNSPECIFIED".
	// Sets count to 0.
	ProductOrder()
	{
		setName("UNSPECIFIED");
		setNumber(0);
	}

	// Ctor from name and inventory
	// Sets name to given string.
	// Sets count to given int.
	// Pre:
	//   0 <= inventory
	ProductOrder(const std::string & name, int inventory)
	{
		setName(name);
		setNumber(inventory);
	}

	// Big 5: automatically generated functions
	~ProductOrder() = default;
	ProductOrder(const ProductOrder & other) = default;
	ProductOrder(ProductOrder && other) = default;
	ProductOrder & operator=(const ProductOrder & other) = default;
	ProductOrder & operator=(ProductOrder && other) = default;

// ---- ProductOrder: general public functions ----
public:

	// getName
	// Return name
	std::string getName() const;

	// getNumber
	// Return count
	int getNumber() const;

	// setName
	// Sets name to given string.
	void setName(const std::string & name);

	// setNumber
	// Sets count to given int.
	// Pre:
	//   0 <= inventory
	void setNumber(int inventory);

	// Returns True if count == 0,
	// else returns False.
	bool empty() const;

	// Returns string representation of data:
	//   Product name with count in parentheses.
	//   "Name (Count)"
	std::string toString() const;

// ---- ProductOrder: general public operators ----
public:

	// op++ (pre)
	// Adds 1 to count
	ProductOrder & operator++()
	{
		++count_;
		return *this;
	}

	// op++ (post)
	// Adds 1 to count
	ProductOrder operator++([[maybe_unused]] int dummy)
	{
		auto save = *this;
		++(*this);
		return save;
	}

	// op-- (pre)
	// Subtracts 1 from count if count is not 0
	ProductOrder & operator--()
	{
		if (count_ != 0)
			--count_;
		return *this;
	}

	// op-- (post)
	// Subtracts 1 from count if count is not 0
	ProductOrder operator--([[maybe_unused]] int dummy)
	{
		auto save = *this;
		if (count_ != 0)
			--(*this);
		return save;
	}

// ---- ProductOrder: data members ----
private:

	std::string name_;	// Product name
	int count_;			// Order count (0 or greater)

};	// End class ProductOrder


/////////////////////////////////////////////////////////////
//    class ProductOrder - Global operator declarations    //
/////////////////////////////////////////////////////////////


// op== (ProductOrder, ProductOrder)
// Returns True if both the names and counts are equal
bool operator==(const ProductOrder & lhs,
	            const ProductOrder & rhs);


// op!= (ProductOrder, ProductOrder)
// Returns True if ProductOrders are not equal
bool operator!=(const ProductOrder & lhs,
	            const ProductOrder & rhs);


// op<< (ostream, ProductOrder)
// Prints string representation of data
// given by ProductOrder::toString member function
std::ostream & operator<<(std::ostream & os,
	                      const ProductOrder & rhs);

#endif  // #ifndef FILE_PRODUCTORDER_H_INCLUDED