// productorder.cpp
// Andrew Ng
// 2020-09-01
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
	return inv_;
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
	inv_ = inventory;
}


// ProductOrder::empty
// (See header.)
bool ProductOrder::empty() const
{
	return inv_ == 0;
}


// ProductOrder::toString
// (See header.)
std::string ProductOrder::toString() const
{
	return name_ + " (" + std::to_string(inv_) + ")";
}


////////////////////////////////////////////////////////////
//    class ProductOrder - Global operator definitions    //
////////////////////////////////////////////////////////////


// operator<< (ostream, ProductOrder)
// (See header.)
std::ostream & operator<<(std::ostream & os,
	                      const ProductOrder & other)
{
	os << other.toString();
	return os;
}
