#pragma once

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void ValueUpdate() = 0;
};