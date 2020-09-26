#ifndef _JURNAL_PRINTER_H_
#define _JURNAL_PRINTER_H_

#include "Jurnal.h"
#include <iostream>

class JurnalPrinter
{
public:
	JurnalPrinter(const Jurnal* const ref = nullptr)
	{
		jurnal = ref;
	}

	~JurnalPrinter()
	{

	}

public:

	void Print() const
	{
		auto& data = jurnal->GetData();
		for (int i = 0; i < data.size(); i++)
		{
			std::cout << data[i] << std::endl;
		}
	}

private:
	const Jurnal* jurnal = nullptr;
};

#endif // !_JURNAL_PRINTER_H_
