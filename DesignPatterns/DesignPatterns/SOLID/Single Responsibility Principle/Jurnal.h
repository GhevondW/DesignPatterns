#ifndef _JURNAL_H_
#define _JURNAL_H_

#include <string>
#include <vector>

class Jurnal
{
public:
	Jurnal(const std::string& name)
		:_name(name)
	{}
	~Jurnal() {}

public:

	void Add(const std::string& data) 
	{
		_content.push_back(data);
	}

	const std::vector<std::string>& GetData() const
	{
		return _content;
	}

private:
	std::string _name;
	std::vector<std::string> _content;
};

#endif // !_JURNAL_H_

