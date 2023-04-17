#pragma once

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void AddObserver() = 0;
	virtual void RemoveObserver() = 0;
	virtual void Notify() = 0;
};

