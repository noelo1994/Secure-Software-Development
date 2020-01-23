#pragma once

#include <thread>
#include <chrono>
#include <atomic>

/// Performs the supplied function at a given interval.
class Timer
{
public:
   ~Timer();

   /// Starts the timer performing its function every interval.
   void Start(const std::chrono::milliseconds& interval);

   /// Stops the timer from performing the function.
   void Stop();

   void SetOnElapsed(const std::function<void(void)>& function) { m_onElapsed = function; }

private:
   std::atomic_bool m_isRunning = false;
   std::unique_ptr<std::thread> m_thread = nullptr;
   std::function<void(void)> m_onElapsed = nullptr;
};
