#include "SecurityExceptionController.h"
#include "DialogView.h"

SecurityExceptionController::SecurityExceptionController(std::unique_ptr<DialogView> view) : m_view(move(view))
{
}

void SecurityExceptionController::ProcessView() const
{
   while (m_view->Process())
   {
   }
}
