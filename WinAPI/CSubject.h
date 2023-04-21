#pragma once

class CSubject : public ISubject
{
public:
	CSubject();
	virtual ~CSubject();

private:
	list<IObserver*> m_listObservers;

public:
	void AddObserver(IObserver* observer) override;
	void RemoveObserver(IObserver* observer) override;
	void Notify() override;
};

