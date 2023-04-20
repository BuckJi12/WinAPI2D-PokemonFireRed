#pragma once

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void AddObserver(IObserver* observer) = 0;
	virtual void RemoveObserver(IObserver* observer) = 0;
	virtual void Notify() = 0;
};

