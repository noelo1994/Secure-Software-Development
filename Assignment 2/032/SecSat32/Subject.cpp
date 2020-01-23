#include "Subject.h"
#include "IObserver.h"

void Subject::RegisterObserver(IObserver* const observer)
{
   m_observers.push_back(observer);
}

void Subject::RemoveObserver(IObserver* observer)
{
   auto iterator = find(m_observers.begin(), m_observers.end(), observer);

   if (iterator != m_observers.end())
   {
      *iterator = nullptr;
      m_observers.remove(observer);
   }
}

void Subject::NotifyObservers() const
{
   for (auto observer : m_observers)
   {
      observer->Update(this);
   }
}
