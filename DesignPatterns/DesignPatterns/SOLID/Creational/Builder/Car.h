#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>

enum class CarClass
{
	RS5,
	RS6,
	RS7,
	S8,
	DEF
};

enum class Color
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	WHITE,
	COSTOM
};

enum class Stage {

	STAGE0,
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4
};

class Car;

class IBuilder {
public:

	virtual IBuilder& SetClass(const CarClass cl) = 0;
	virtual IBuilder& SetColor(const Color color) = 0;
	virtual IBuilder& SetStage(const Stage stage) = 0;
	virtual IBuilder& SetDoorsCount(const int count) = 0;
	virtual IBuilder& SetHp(const int val) = 0;
	virtual IBuilder& SetNm(const int val) = 0;
	virtual IBuilder& SetGPS(const bool val) = 0;
	virtual IBuilder& SetChip(const bool val) = 0;
	virtual IBuilder& SetAI(const bool val) = 0;
	virtual Car* Build() = 0;
};

class CarBuilder : public IBuilder
{
	friend class Car;
private:
	CarBuilder();
public:
	~CarBuilder();
public:
	IBuilder& SetClass(const CarClass cl) override;
	IBuilder& SetColor(const Color color) override;
	IBuilder& SetStage(const Stage stage) override;
	IBuilder& SetDoorsCount(const int count) override;
	IBuilder& SetHp(const int val) override;
	IBuilder& SetNm(const int val) override;
	IBuilder& SetGPS(const bool val) override;
	IBuilder& SetChip(const bool val) override;
	IBuilder& SetAI(const bool val) override;
	Car* Build() override;

private:
	Car* _pCar{ nullptr };
};

class Car
{
	friend class CarBuilder;
public:
	~Car() {
		std::cout << "Car Dtor" << std::endl;
	}

	static CarBuilder Make()
	{
		return CarBuilder{};
	}

private:

	Car()
		:_eClass(CarClass::DEF),
		_eColor(Color::BLACK),
		_eStage(Stage::STAGE0),
		_iDoors(4),
		_iHp(0),
		_iNm(0),
		_bGPS(false),
		_bChip(false),
		_bAudiAI(false)
	{
		std::cout << "Car Ctor" << std::endl;
	}

	

public:

	CarClass GetClass() const { return _eClass; }
	Color GetColor() const { return _eColor; }
	Stage GetStage() const { return _eStage; }
	int GetDoorsCount() const { return _iDoors; }
	int GetHp() const { return _iHp; }
	int GetNm() const { return _iNm; }
	bool HasGPS() const { return _bGPS; }
	bool HasChip() const { return _bChip; }
	bool HasAI() const { return _bAudiAI; }


private:
	CarClass _eClass;
	Color _eColor;
	Stage _eStage;
	int _iDoors;
	int _iHp;
	int _iNm;
	bool _bGPS;
	bool _bChip;
	bool _bAudiAI;
};




#endif // !_CAR_H_

