#if 0
#include <iostream>
#include "DataStream.h"

int main(){

	std::cout << "---Hello Decorator---" << std::endl;

	StringReader* stringReader = new StringReader("C://Files//Files");
	
	ReadingDecorator* decorate = new ReadingDecorator
	{
		new EncryptionDecorator
		{
			new EncryptionDecorator
			{
				new OtherDecorator
				{
					new EncryptionDecorator
					{
						new OtherDecorator
						{
							stringReader
						}
					}
				}
			}
		}
	};

	delete stringReader;
	return 0;
}
#endif