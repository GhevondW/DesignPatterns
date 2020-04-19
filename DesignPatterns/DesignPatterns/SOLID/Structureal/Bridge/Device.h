#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <iostream>

class IDevice
{
public:
	virtual void VolumeUp() = 0;
	virtual void VolumeDown() = 0;
	virtual void ChannelUp() = 0;
	virtual void ChannelDown() = 0;

	virtual ~IDevice() {}
};

class TV : public IDevice
{
public:
	TV()
	{ 
		std::cout << "TV ctor" << std::endl;
	}
	~TV() { std::cout << "TV dtor" << std::endl; }

	void VolumeUp()
	{
		std::cout << "TV V_UP" << std::endl;
	}
	void VolumeDown()
	{
		std::cout << "TV V_DOWN" << std::endl;
	}
	void ChannelUp()
	{
		std::cout << "TV C_UP" << std::endl;
	}
	void ChannelDown()
	{
		std::cout << "TV C_DOWN" << std::endl;
	}

private:

};

class Radio : public IDevice
{
public:
	Radio()
	{
		std::cout << "Radio ctor" << std::endl;
	}
	~Radio() { std::cout << "Radio dtor" << std::endl; }

	void VolumeUp()
	{
		std::cout << "Radio V_UP" << std::endl;
	}
	void VolumeDown()
	{
		std::cout << "Radio V_DOWN" << std::endl;
	}
	void ChannelUp()
	{
		std::cout << "Radio C_UP" << std::endl;
	}
	void ChannelDown()
	{
		std::cout << "Radio C_DOWN" << std::endl;
	}

private:

};

enum class DeviceType
{
	TV,
	RADIO
};

class Remote
{
public:
	Remote(DeviceType type = DeviceType::TV) 
		:_enDeviceType(type)
	{
		if (type == DeviceType::TV) {
			_pDevice = new TV();
		}
		else {
			_pDevice = new Radio();
		}
	}
	~Remote() {
		if (_pDevice != nullptr) {
			delete _pDevice;
			_pDevice = nullptr;
		}
	}

	void ChangeDevice() {
		delete _pDevice;
		if (_enDeviceType == DeviceType::TV) {
			_enDeviceType = DeviceType::RADIO;
			_pDevice = new Radio();
			return;
		}
		_enDeviceType = DeviceType::RADIO;
		_pDevice = new TV();
	}

	void VolumeUp()
	{
		_pDevice->VolumeUp();
	}
	void VolumeDown()
	{
		_pDevice->VolumeDown();
	}
	void ChannelUp()
	{
		_pDevice->ChannelUp();
	}
	void ChannelDown()
	{
		_pDevice->ChannelDown();
	}

private:
	IDevice* _pDevice{nullptr};
	DeviceType _enDeviceType;
};


#endif // !_DEVICE_H_

