#include "framework.h"
#include "CSubject.h"

CSubject::CSubject()
{
}

CSubject::~CSubject()
{
}

void CSubject::AddObserver(IObserver* observer)
{
	m_listObservers.push_back(observer);
}

void CSubject::RemoveObserver(IObserver* observer)
{
	m_listObservers.remove(observer);
}

void CSubject::Notify()
{
	auto iter = m_listObservers.begin();
	while (iter != m_listObservers.end())
	{
		(*iter)->ValueUpdate();
	}
}
