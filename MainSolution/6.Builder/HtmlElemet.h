#ifndef _HTML_ELEMENT_H__
#define _HTML_ELEMENT_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

struct HtmlBuilder;

class HtmlElement
{
	friend class HtmlBuilder;
public:
	HtmlElement() {}
	HtmlElement(const std::string& name, const std::string& text)
		: _name(name),
		_text(text)
	{
	}

	std::string str(int indent = 0) const
	{
		std::ostringstream oss;
		std::string i(indent_size*indent, ' ');
		oss << i << "<" << _name << ">" << std::endl;
		if (_text.size() > 0)
			oss << std::string(indent_size*(indent + 1), ' ') << _text << std::endl;

		for (const auto& e : _elements)
			oss << e.str(indent + 1);

		oss << i << "</" << _name << ">" << std::endl;
		return oss.str();
	}

public:

	const std::string& get_name() const{
		return _name;
	}

	void set_name(const std::string& name) {
		_name = name;
	}

	const std::string& get_text() const{
		return _text;
	}

	void set_text(const std::string& text) {
		_text = text;
	}

private:

	std::vector<HtmlElement>& get_elements(){
		return _elements;
	}

public:

	static HtmlBuilder* init(const std::string& root_name);

private:

	std::string _name;
	std::string _text;
	std::vector<HtmlElement> _elements;
	const size_t indent_size = 2;
};

class HtmlBuilder
{
	friend class HtmlElement;
private:
	HtmlBuilder(const std::string& root_name)
	{
		_root.set_name(root_name);
		_root.set_text("");
	}
public:

	const std::string str() {
		return _root.str();
	}

	HtmlBuilder* add_child(const std::string& child_name, const std::string& child_text) {
		_root.get_elements().push_back({ child_name,child_text });
		return this;
	}

	HtmlElement build() const{
		return std::move(_root);
	}

private:
	HtmlElement _root;
};

HtmlBuilder* HtmlElement::init(const std::string& root_name) {
	return new HtmlBuilder(root_name);
}

#endif // !_HTML_ELEMENT_H__
