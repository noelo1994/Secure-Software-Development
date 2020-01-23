#pragma once

class Subject;

/// Interface for a class that wants to register itself as an observer of a subject.
class IObserver
{
public:
   virtual ~IObserver()
   {
   }

   virtual void Update(const Subject* const subject) = 0;  
};
