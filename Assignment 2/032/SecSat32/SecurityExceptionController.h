#pragma once

#include <memory>

class DialogView;

/// Controls the SecurityExceptionView.
class SecurityExceptionController
{
public:
   explicit SecurityExceptionController(std::unique_ptr<DialogView> view);

   /// Instructs the view to do whatever it is that the view does.
   void ProcessView() const;

private:
  const std::unique_ptr<DialogView> m_view;
};
