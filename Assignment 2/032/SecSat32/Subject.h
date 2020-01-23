#pragma once

#include <list>

class IObserver;

/// Base class for classes who wish to notify other objects that their state has changed.
class Subject
{
public:
   virtual ~Subject()
   {
   }

   /// Adds the observer to the list of objects that will be notified when state changes.
   void RegisterObserver(IObserver* const observer);

   /// Remove the observer from the subscription list.
   void RemoveObserver(IObserver* observer);

protected:
   void NotifyObservers() const;

private:
   std::list<IObserver*> m_observers;
};
