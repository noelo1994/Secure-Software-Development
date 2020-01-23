#pragma once

class User;

/// Stores the state of the Active Thermal Control System.
class ActiveThermalControlSystem 
{
public:

   bool GetIsActive() const { return m_isActive; }

   /// Sets the state of the ATCS. Throws if the user has inadequate access. 
   void SetIsActive(const bool isActive, const User& user);

private:
   bool m_isActive = true;
};
