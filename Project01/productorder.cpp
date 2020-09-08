// productorder.cpp
// Andrew Ng
// Started: 2020-09-01
// Updated: 2020-09-08
//
// CS 311 Fall 2020
// Source for class ProductOrder
// Product order: name and count

#include "productorder.h"	// For class ProductOrder


////////////////////////////////////////////////////////////////
//    class ProductOrder - Definitions of member functions    //
////////////////////////////////////////////////////////////////


// ProductOrder::getName
// (See header.)
std::string ProductOrder::getName() const
{
	return name_;
}


// ProductOrder::getNumber
// (See header.)
int ProductOrder::getNumber() const
{
	return count_;
}


// ProductOrder::setName
// (See header.)
void ProductOrder::setName(const std::string & name) 
{
	name_ = name;
}


// ProductOrder::setNumber
// (See header.)
void ProductOrder::setNumber(int inventory)
{
	count_ = inventory;
}


// ProductOrder::empty
// (See header.)
bool ProductOrder::empty() const
{
	return count_ == 0;
}


// ProductOrder::toString
// (See header.)
std::string ProductOrder::toString() const
{
	return name_ + " (" + std::to_string(count_) + ")";
}


////////////////////////////////////////////////////////////
//    class ProductOrder - Global operator definitions    //
////////////////////////////////////////////////////////////


// op== (ProductOrder, ProductOrder)
// (See header.)
bool operator==(const ProductOrder & lhs,
	            const ProductOrder & rhs)
{
	return (lhs.getName() == rhs.getName() &&
		  lhs.getNumber() == rhs.getNumber());
}


// op!= (ProductOrder, ProductOrder)
// (See header.)
bool operator!=(const ProductOrder & lhs,
	            const ProductOrder & rhs)
{
	return !(lhs == rhs);
}


// op<< (ostream, ProductOrder)
// (See header.)
std::ostream & operator<<(std::ostream & os,
	                      const ProductOrder & rhs)
{
	os << rhs.toString();
	return os;
}
