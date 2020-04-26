#ifndef _DATA_STREAM_H_
#define _DATA_STREAM_H_

#include <string>

class IStringReader
{
public:
	virtual std::string Read() = 0;
};

class IStringWriter
{
public:
	virtual void Write(const std::string& data) = 0;
};

class StringReader: public IStringReader
{
public:
	StringReader(const std::string& path):_path(path)  {}
	~StringReader() {}

	std::string Read() override {
		return "[" + _path + "]";
	}

private:
	std::string _path;
};

class ReadingDecorator: public IStringReader
{
public:
	ReadingDecorator(IStringReader* pnext = nullptr)
		:_pNext(pnext)
	{}
	virtual ~ReadingDecorator() {
		if (_pNext != nullptr) {
			delete _pNext;
			_pNext = nullptr;
		}
	}

	std::string Read() override {
		if (_pNext != nullptr)
		{
			return _pNext->Read();
		}
		throw "invalid operation";
	}

private:
	IStringReader* _pNext{nullptr};
};

class EncryptionDecorator: public ReadingDecorator
{
public:
	EncryptionDecorator(IStringReader* pnext = nullptr)
		:ReadingDecorator(pnext)
	{}
	~EncryptionDecorator() {}

	std::string Read() override {
		std::string data = ReadingDecorator::Read();
		std::string res = "(" + data + ")";
		return res;
	}

private:

};

class OtherDecorator : public ReadingDecorator
{
public:
	OtherDecorator(IStringReader* pnext = nullptr)
		:ReadingDecorator(pnext)
	{}
	~OtherDecorator() {}

	std::string Read() override {
		std::string data = ReadingDecorator::Read();
		std::string res = "{" + data + "}";
		return res;
	}

private:

};


#endif // !_UI_WIDGET_H_

