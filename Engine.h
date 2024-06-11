#pragma once
class UEngine
{
public:
	virtual ~UEngine();

	static UEngine* GetInstance();
	static UEngine* AddressEngine;

protected:
	UEngine();

};

