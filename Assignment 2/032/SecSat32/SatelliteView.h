#pragma once

#include "ISatelliteView.h"
#include "DialogView.h"

/// A Win32 implementation of ISatelliteView.
class SatelliteView : public ISatelliteView, public DialogView
{
public:
   SatelliteView();
   bool Process() const override { return DialogView::Process(); }
   void SetSatelliteTemperatureReading(const SecureDouble& newReading) override;
   void SetSolarRadiationReading(const SecureDouble& newReading) override;
   void SetGravityAnomalyReading(const SecureDouble& newReading) override;
   void ShowTemperatureWarning() const override;
   void HideTemperatureWarning() const override;
   void IndicateLostConnection() const override;
   void IndicateATCSPermissionDenied() const override;
   void IndicateSelfDestructPermissionDenied() const override;
   void IndicateSettingsPermissionDenied() const override;
   SatelliteViewUserRequestedAction GetUserRequestedAction() const override { return m_userRequestedAction; }

private:
   BOOL ProcessDialogMessages(HWND hi, const UINT message, const WPARAM wParam);
   void HandleButtonPresses(const WORD buttonID);
   static BOOL WINAPI DlgProc(HWND dialogHandle, UINT message, WPARAM wParam, LPARAM lParam);
   static std::string ToDisplayString(const SecureDouble& value);

   SatelliteViewUserRequestedAction m_userRequestedAction;
};
