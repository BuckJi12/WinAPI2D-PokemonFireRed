#pragma once

class IObject
{
public:
	virtual ~IObject() {};
	virtual void AddObserver() = 0;
	virtual void RemoveObserver() = 0;
	virtual void Notify() = 0;
};

