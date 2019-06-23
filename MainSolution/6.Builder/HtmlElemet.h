#ifndef _HTML_ELEMENT_H__
#define _HTML_ELEMENT_H__

#include <vector>
#include <sstream>

class HtmlBuilder;

class HtmlElement
{
public:
	HtmlElement(const std::string& name, const std::string& text)
		:_name(name),
		_text(text)
	{}
	HtmlElement(const HtmlElement& other) = default;
	
	~HtmlElement() {}

public:

	const std::string& get_tag() const {
		return _name;
	}

	const std::string get_text()const {
		return _text;
	}

	std::vector<HtmlElement>& get_inner_elements() {
		return _innerElements;
	}

public:

	std::string str(int indent = 0) const {
		std::ostringstream oss;
		std::string i(INDENT_SIZE*indent, ' ');
		oss << i << "<" << _name << ">" << std::endl;
		if (_text.size() > 0)
			oss << std::string(INDENT_SIZE*(indent + 1), ' ') << _text << std::endl;

		for (const auto& e : _innerElements)
			oss << e.str(indent + 1);

		oss << i << "</" << _name << ">" << std::endl;
		return oss.str();
	}

	HtmlBuilder build(const std::string& root_name) {
		return HtmlBuilder(root_name);
	}

public:
	const int INDENT_SIZE = 2;
private:
	std::string _name;
	std::string _text;
	std::vector<HtmlElement> _innerElements;
};

class HtmlBuilder
{
public:
	HtmlBuilder(const HtmlElement& root)
		:_root(root)
	{}
	HtmlBuilder(const std::string& root_name)
		:_root(root_name,"")
	{}
	~HtmlBuilder(){}

private:
	HtmlElement _root;
};


#endif // !_HTML_ELEMENT_H__
