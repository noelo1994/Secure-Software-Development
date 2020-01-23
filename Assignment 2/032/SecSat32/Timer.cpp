#include "Timer.h"

Timer::~Timer()
{
   Stop();
}

void Timer::Start(const std::chrono::milliseconds& interval)
{
   m_isRunning = true;

   m_thread= std::make_unique<std::thread>([=]()
   {
      while (m_isRunning)
      {
         std::this_thread::sleep_for(interval);

         if (m_onElapsed)
         {
            m_onElapsed();
         }
      }
   });
}

void Timer::Stop()
{
   if (m_isRunning)
   {
      m_thread->detach();
      m_isRunning = false;
   }
}
