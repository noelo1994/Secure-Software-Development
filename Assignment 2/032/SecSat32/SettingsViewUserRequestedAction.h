#pragma once

/// The possible requests that a user can make when using an ISettingsView.
enum class SettingsViewUserRequestedAction
{
   None,
   ViewUsers,
   ChangeUserRole,
   ChangeLoggerConfiguration,
};