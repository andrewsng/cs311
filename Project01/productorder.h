// productorder.h
// Andrew Ng
// 2020-09-01
// CS 311 Fall 2020
// Header for class ProductOrder

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include <string>
#include <ostream>


class ProductOrder
{

public:

	ProductOrder()
	{
		setName("UNSPECIFIED");
		setNumber(0);
	}

	ProductOrder(const std::string& name, int inventory)
	{
		setName(name);
		setNumber(inventory);
	}

	~ProductOrder() = default;

	ProductOrder(const ProductOrder & other) = default;

	ProductOrder(ProductOrder && other) = default;

	ProductOrder & operator=(const ProductOrder & other) = default;

	ProductOrder & operator=(ProductOrder && other) = default;

public:

	std::string getName() const;

	int getNumber() const;

	void setName(const std::string & name);

	void setNumber(int inventory);

	bool empty() const;

	std::string toString() const;

public:

	bool operator==(const ProductOrder& other) const
	{
		return (name_ == other.getName() &&
			     inv_ == other.getNumber());
	}

	bool operator!=(const ProductOrder& other) const
	{
		return !(*this == other);
	}

	ProductOrder & operator++()
	{
		++inv_;
		return *this;
	}

	ProductOrder operator++(int dummy)
	{
		auto save = *this;
		++(*this);
		return save;
	}

	ProductOrder & operator--()
	{
		if (inv_ != 0)
			--inv_;
		return *this;
	}

	ProductOrder operator--(int dummy)
	{
		auto save = *this;
		if (inv_ != 0)
			--(*this);
		return save;
	}

private:

	std::string name_;
	int inv_;

};


std::ostream & operator<<(std::ostream & os,
	                      const ProductOrder & other);

#endif