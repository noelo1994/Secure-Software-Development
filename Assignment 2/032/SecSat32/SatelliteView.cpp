#include <string>
#include "SatelliteView.h"
#include "resource.h"
#include <sstream>
#include <iomanip>
#include "SecureDouble.h"
#include "SecureString.h"
#include "SatelliteViewUserRequestedAction.h"

SatelliteView::SatelliteView() : 
DialogView(CreateDialogParam(GetModuleHandle(nullptr), MAKEINTRESOURCE(dialogSatellite),
   nullptr, DlgProc, reinterpret_cast<LPARAM>(this))),
m_userRequestedAction(SatelliteViewUserRequestedAction::None)
{
   ShowWindow(m_dialogHandle, SW_SHOW);
}

void SatelliteView::SetSatelliteTemperatureReading(const SecureDouble& newReading)
{
   SetDlgItemText(m_dialogHandle, textControlSatelliteTemperatureReading, ToDisplayString(newReading).c_str());
}

void SatelliteView::SetSolarRadiationReading(const SecureDouble& newReading)
{
   SetDlgItemText(m_dialogHandle, textControlSolarRadiationReading, ToDisplayString(newReading).c_str());
}

void SatelliteView::SetGravityAnomalyReading(const SecureDouble& newReading)
{
   SetDlgItemText(m_dialogHandle, textControlGravityAnomalyReading, ToDisplayString(newReading).c_str());
}

void SatelliteView::ShowTemperatureWarning() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, pictureBoxWarning), SW_SHOW);
}

void SatelliteView::HideTemperatureWarning() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, pictureBoxWarning), SW_HIDE);
}

void SatelliteView::IndicateLostConnection() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, pictureBoxSatellite), SW_HIDE);
   ShowWindow(GetDlgItem(m_dialogHandle, textNoConnection), SW_SHOW);
   HideTemperatureWarning();
   const char* const unavailableDataString = "---";
   SetDlgItemText(m_dialogHandle, textControlSatelliteTemperatureReading, unavailableDataString);
   SetDlgItemText(m_dialogHandle, textControlGravityAnomalyReading, unavailableDataString);
   SetDlgItemText(m_dialogHandle, textControlSolarRadiationReading, unavailableDataString);
   HWND checkBoxHandle = GetDlgItem(m_dialogHandle, checkBoxATCS);
   PostMessage(checkBoxHandle, BM_SETCHECK, BST_UNCHECKED, 0);
}

void SatelliteView::IndicateATCSPermissionDenied() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, textATCSPermissionDenied), SW_SHOW);
   HWND aTCSCheckBoxHandle = GetDlgItem(m_dialogHandle, checkBoxATCS);
   PostMessage(aTCSCheckBoxHandle, BM_SETCHECK, BST_CHECKED, 0);
   EnableWindow(aTCSCheckBoxHandle, false);
}

void SatelliteView::IndicateSelfDestructPermissionDenied() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, textSelfDestructPermissionDenied), SW_SHOW);
   HWND selfDestructButtonHandle = GetDlgItem(m_dialogHandle, buttonSelfDestruct);
   EnableWindow(selfDestructButtonHandle, false);
}

void SatelliteView::IndicateSettingsPermissionDenied() const
{
   ShowWindow(GetDlgItem(m_dialogHandle, textSettingsPermissionDenied), SW_SHOW);
   HWND settingsButtonHandle = GetDlgItem(m_dialogHandle, buttonSettings);
   EnableWindow(settingsButtonHandle, false);
}

BOOL WINAPI SatelliteView::DlgProc(HWND dialogHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
   SatelliteView* instance = nullptr;

   if (message == WM_INITDIALOG)
   {
      // Get the instance pointer given at creation of the dialog, and store it in DWLP_USER
      instance = reinterpret_cast<SatelliteView*>(lParam);                   
      SetWindowLongPtr(dialogHandle, DWLP_USER, reinterpret_cast<LONG_PTR>(instance));
   }
   else
   {
      // Retrieve the instance pointer stored when the WM_INITDIALOG message was received
      instance = reinterpret_cast<SatelliteView*>(GetWindowLongPtr(dialogHandle, DWLP_USER));
   }

   if (instance)
   {
      // Call the instance specific message handler
      return instance->ProcessDialogMessages(dialogHandle, message, wParam);
   }

   // The instance pointer has not been assigned yet
   return FALSE;
}

BOOL SatelliteView::ProcessDialogMessages(const HWND dialogHandle, const UINT message, const WPARAM wParam)
{
   switch (message)
   {
      case WM_INITDIALOG:
         {
            // The class member handle has not been set at the time of this message, so the one passed in is used
            HWND aTCSCheckBoxHandle = GetDlgItem(dialogHandle, checkBoxATCS);
            PostMessage(aTCSCheckBoxHandle, BM_SETCHECK, BST_CHECKED, 0);
            return TRUE;
         }

         case WM_CTLCOLORDLG:
         {
            return reinterpret_cast<BOOL>(GetStockObject(BLACK_BRUSH));
         }

         case WM_CTLCOLORSTATIC:
         {
            HDC hDCStatic = reinterpret_cast<HDC>(wParam);
            SetTextColor(hDCStatic, RGB(255, 255, 255));
            SetBkColor(hDCStatic, BLACK_BRUSH);
            return reinterpret_cast<BOOL>(GetStockObject(BLACK_BRUSH));
         }

         case WM_COMMAND:
         {
            HandleButtonPresses(LOWORD(wParam));
            return TRUE;
         }

         case WM_CLOSE:
         {
            DestroyWindow(m_dialogHandle);
            return TRUE;
         }

         case WM_DESTROY:
         {
            PostQuitMessage(0);
            return TRUE;
         }

         default:
         {
            return FALSE;
         }
   }
}

void SatelliteView::HandleButtonPresses(const WORD buttonID)
{
   switch (buttonID)
   {
      case checkBoxATCS:
      {
         m_userRequestedAction = SatelliteViewUserRequestedAction::ToggleActiveThermalControlSystem;
         NotifyObservers();
         break;
      }

      case buttonSelfDestruct:
      {
         m_userRequestedAction = SatelliteViewUserRequestedAction::SelfDestruct;
         NotifyObservers();
         break;
      }

      case buttonSettings:
      {
         m_userRequestedAction = SatelliteViewUserRequestedAction::OpenSettingsManager;
         NotifyObservers();
         break;
      }

      default:
      {
         break;
      }
   }
}

std::string SatelliteView::ToDisplayString(const SecureDouble& value)
{
   std::ostringstream stringStream;
   stringStream << std::fixed << std::setprecision(2) << value.GetValue();
   return stringStream.str();
}
