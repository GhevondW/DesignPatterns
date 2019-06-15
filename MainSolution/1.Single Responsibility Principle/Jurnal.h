#ifndef _JURNAL_H__
#define _JURNAL_H__

#include <iostream>
#include <string>
#include <vector>

/**
* each class has to have only his functionality
* in this example, I have shown that idea
*/

class Jurnal
{
public:
	Jurnal(const std::string& title) 
		:_title(title){}
	~Jurnal() {
	
	}

public:

	void add_entry(const std::string& new_entry) {
		_entries.push_back(new_entry);
	}

	/**
	* this is the wrong use case
	* because the print function does not belong to Jurnal class
	* void print() const{
	*	  std::cout << _title << std::endl;
	*	  for (auto e:_entries)
	*	  {
	*		  std::cout << e << std::endl;
	*	  }
	*}
	*/

public:

	const std::vector<std::string> get_entries() const{
		return this->_entries;
	}

	int get_entries_count() const{
		return _entries.size();
	}

	const std::string get_title() const{
		return _title;
	}

private:
	const std::string _title;
	std::vector<std::string> _entries;
};


class JurnalsManager
{
public:

	static void print(const Jurnal& jurnal){
		std::cout << jurnal.get_title() << std::endl;
		for(auto e:jurnal.get_entries())
		{
			std::cout << e << std::endl;
		}
	}

};

#endif // !_JURNAL_H__


