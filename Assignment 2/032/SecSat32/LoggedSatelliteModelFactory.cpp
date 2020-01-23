#include "LoggedSatelliteModelFactory.h"
#include "SatelliteModel.h"
#include "AccessLevel.h"
#include "ResourceType.h"
#include "PermissionChecker.h"
#include "User.h"
#include "LoggerType.h"
#include "LogFormatType.h"

SatelliteModelLogger LoggedSatelliteModelFactory::m_logger(LoggerType::Text, LogFormatType::Plain);

std::unique_ptr<SatelliteModel> LoggedSatelliteModelFactory::CreateLoggedSatelliteModel() const
{
   auto satelliteModel = std::make_unique<SatelliteModel>();
   m_logger.SetModel(satelliteModel.get());
   satelliteModel->RegisterObserver(&m_logger);
   return satelliteModel;
}

void LoggedSatelliteModelFactory::ChangeLoggerType(const LoggerType newLoggerType, const LogFormatType newLogFormatType, const User& user)
{
   PermissionChecker permissionChecker;

   if (permissionChecker.CheckPermission(ResourceType::Settings, user.GetRole(), AccessLevel::Full))
   {
      m_logger.SetLogger(newLoggerType, newLogFormatType);
   }
   else
   {
      throw SecurityException("Unauthorised access to system settings.");
   }
}
