// productorder.cpp
// Andrew Ng
// 2020-09-01
// CS 311 Fall 2020
// Source for class ProductOrder

#include "productorder.h"


std::string ProductOrder::getName() const
{
	return name_;
}


int ProductOrder::getNumber() const
{
	return inv_;
}


void ProductOrder::setName(const std::string & name) 
{
	name_ = name;
}


void ProductOrder::setNumber(int inventory)
{
	inv_ = inventory;
}


bool ProductOrder::empty() const
{
	return inv_ == 0;
}


std::string ProductOrder::toString() const
{
	return name_ + " (" + std::to_string(inv_) + ")";
}


std::ostream & operator<<(std::ostream & os,
	                      const ProductOrder & other)
{
	os << other.toString();
	return os;
}
