
#include <iostream>
#include "Device.h"

int main() {
	std::cout << "---Bridge---" << std::endl;

	Remote* remote = new Remote(DeviceType::RADIO);

	remote->VolumeUp();
	remote->VolumeDown();
	remote->ChannelUp();
	remote->ChannelDown();

	remote->ChangeDevice();

	remote->VolumeUp();
	remote->VolumeDown();
	remote->ChannelUp();
	remote->ChannelDown();

	delete remote;
	return 0;
}