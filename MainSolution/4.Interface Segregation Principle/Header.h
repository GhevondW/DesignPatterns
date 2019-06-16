#ifndef _HEADER_H__
#define	 _HEADER_H__

#include <iostream>
#include <string>

struct Document
{
	std::string _text;
};

/**
* This is bas usecase
*/
//struct IMachine
//{
//	virtual void print(Document& doc) = 0;
//	virtual void scan(Document& doc) = 0;
//	virtual void fax(Document& doc) = 0;
//};
//
//struct Machine:IMachine
//{
//	void print(Document& doc) override {
//		 //ok for all functionality
//	}
//	void scan(Document& doc) override {
//		//ok for all functionality
//	}
//	void fax(Document& doc) override {
//		//ok for all functionality
//	}
//};
//
////but what if
//struct Printer:IMachine
//{
//	void print(Document& doc) override {
//		//ok
//	}
//	void scan(Document& doc) override {
//		//is not good
//	}
//	void fax(Document& doc) override {
//		//is not good
//	}
//};

/**
* This is the right way to solve this problem
*/

struct IPrinter
{
	virtual void print(Document& doc) = 0;
};

struct IScanner
{
	virtual void scan(Document& doc) = 0;
};

struct IFax
{
	virtual void fax(Document& doc) = 0;
};

struct Scanner:IScanner
{
	void scan(Document& doc) override {
		//Ok
	}
};

struct Printer :IPrinter
{
	void print(Document& doc) override {
		//Ok
	}
};

struct IMachine:IScanner,IPrinter
{};

struct Machine:IMachine
{
	IScanner& _scanner;
	IPrinter& _printer;

	Machine(IScanner& scanner,IPrinter& printer) 
		:_scanner(scanner),
		_printer(printer)
	{
	
	}

	void scan(Document& doc) override {
		_scanner.scan(doc);
	}
	void print(Document& doc) override {
		_printer.print(doc);
	}
};

#endif // !_HEADER_H__
