#ifndef _JURNAL_H_
#define _JURNAL_H_

#include <string>
#include <vector>

class Jurnal
{
public:
	Jurnal(std::string name)
		:_name(std::move(name))
	{}
	~Jurnal() {}

public:

	void Add(std::string data) 
	{
		_content.push_back(std::move(data));
	}

	const std::vector<std::string>& GetData() const
	{
		return _content;
	}

	/* wrong functionality for this class
	void Print()
	{
		...
	}
	*/

private:
	std::string _name;
	std::vector<std::string> _content;
};

#endif // !_JURNAL_H_

