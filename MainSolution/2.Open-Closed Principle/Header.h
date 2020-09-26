#ifndef _HEADER_H__
#define _HEADER_H__

#include <iostream>
#include <string>
#include <vector>

enum Color
{
	RED,
	GREEN,
	ORANGE
};

enum Size
{
	SMALL,
	MEDIUM,
	LARGE
};

struct Product
{
	std::string _name;
	Color _color;
	Size _size;
};


/**
* This is the wrong way to solve this problem
* 
*/
struct ProductFilter
{
	static std::vector<Product> BySize(const std::vector<Product>& input,Size size) {
		std::vector<Product> result;
		for (auto p:input)
		{
			if (p._size == size) {
				result.push_back(p);
			}
		}
		return result;
	}

	static std::vector<Product> ByColor(const std::vector<Product>& input, Color color) {
		std::vector<Product> result;
		for (auto p : input)
		{
			if (p._color == color) {
				result.push_back(p);
			}
		}
		return result;
	}

	static std::vector<Product> ByColorAndSize(const std::vector<Product>& input, Color color,Size size) {
		std::vector<Product> result;
		for (auto p : input)
		{
			if (p._color == color && p._size == size) {
				result.push_back(p);
			}
		}
		return result;
	}

};

/**
* this is the right way
*/
template<class T>
struct Specification
{
	virtual bool is_satisfied(T item) const = 0;
};

template<class T>
struct Filter
{
	virtual std::vector<T> filter(std::vector<T>& input,Specification<T>& spec) = 0;
};

struct GoodFilter:public Filter<Product>
{
	std::vector<Product> filter(std::vector<Product>& input,Specification<Product>& spec) override {
		std::vector<Product> result;
		for (auto p:input )
		{
			if (spec.is_satisfied(p)) {
				result.push_back(p);
			}
		}
		return result;
	}
};

struct ColorSpecification : public Specification<Product>
{
	Color _color;
	ColorSpecification(Color color):_color(color) {
	}
	bool is_satisfied(Product item) const override {
		return item._color == _color;
	}
};


struct ColorAndSizeSpecialization:public Specification<Product>
{
	Color _color;
	Size _size;

	ColorAndSizeSpecialization(Color color,Size size) 
		:_color(color),
		_size(size)
	{
	
	}

	bool is_satisfied(Product item) const override {
		return item._color == _color && item._size == _size;
	}

};

struct AndSpecification: public Specification<Product>
{

	AndSpecification(const Specification<Product>* const ref1,
					const Specification<Product>* const ref2)
			:_spec1(ref1),
			_spec2(ref2)
	{
	
	}

	bool is_satisfied(Product item) const override {
		return _spec1->is_satisfied(item) && _spec2->is_satisfied(item);
	}

	const Specification<Product>* _spec1{nullptr};
	const Specification<Product>* _spec2{nullptr};
};

#endif // !_HEADER_H__
