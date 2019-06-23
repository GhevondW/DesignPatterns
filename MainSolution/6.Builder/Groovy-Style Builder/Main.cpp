#include <string>
#include <vector>
#include <iostream>

class Builder;
typedef const std::string& const_str_ref;

class Tag
{
	typedef std::vector<std::pair<std::string, std::string>> Attributes;
protected:
	Tag()
		:_name(),
		_text(),
		_children(),
		_attributes()
	{}
	Tag(const_str_ref name, const_str_ref text)
		:_name(name),
		_text(text)
	{}
	Tag(const_str_ref name, const std::vector<Tag>& children)
		:_name(name),
		_children(children)
	{}
	

public:

	~Tag() {};

	const std::string& get_name() const{
		return _name;
	}

	const std::string& get_text() const {
		return _text;
	}

	void set_name(const std::string& name){
		_name = name;
	}

	void set_text(const std::string& text) {
		_text = text;
	}

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		os << "<" << tag._name;

		for (const auto& att : tag._attributes)
			os << " " << att.first << "=\"" << att.second << "\"";

		if (tag._children.size() == 0 && tag._text.length() == 0)
		{
			os << "/>" << std::endl;
		}
		else
		{
			os << ">" << std::endl;

			if (tag._text.length())
				os << tag._text << std::endl;

			for (const auto& child : tag._children)
				os << child;

			os << "</" << tag._name << ">" << std::endl;
		}

		return os;
	}

private:

	std::vector<Tag>& get_children() {
		return _children;
	}

	Attributes& get_attributes() {
		return _attributes;
	}

protected:
	std::string _name;
	std::string _text;
	std::vector<Tag> _children;
	Attributes _attributes;
};


class P:public Tag
{
public:
	P(const_str_ref _text) 
		:Tag("P",_text)
	{}
	P(std::initializer_list<Tag> children)
		:Tag("P",children)
	{}
	~P() {};
};

class Img :public Tag
{
public:
	Img(const_str_ref _url)
		:Tag("Img","")
	{
		_attributes.emplace_back(std::make_pair("url",_url));
	}
	~Img() {};
};

int main() {

	std::cout <<
		P{
			Img
				{
					"http:ghevond.com"
				},
			P	{
					P{"Fis"},
					P{"Fis1"},
					P{"Fis"},
					P{"Fis3"}
				}
		}
	<< std::endl;

	std::cin.get();
	return 0;
}