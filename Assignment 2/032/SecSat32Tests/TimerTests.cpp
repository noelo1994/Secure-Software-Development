#include "CppUnitTest.h"
#include "Timer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SecureSatellite32Tests
{		
	TEST_CLASS(TimerTests)
	{
	public:	
		TEST_METHOD(Timer_GivenOnElapsedHasNotBeenSet_WhenStart_ThenDoesNotCauseError)
		{
         Timer timer;

         // Failing test results in test execution engine error
         timer.Start(std::chrono::milliseconds(0));
         timer.Stop();
		}

      TEST_METHOD(Timer_GivenTimerIsRunning_WhenDestructed_ThenDoesNotCauseError)
      {
         Timer timer;
      
         timer.Start(std::chrono::milliseconds(0));

         // Failing test results in test execution engine error
      }

      TEST_METHOD(Timer_GivenOnElapsedHasBeenSet_WhenTimerElapsed_ThenOnElapsedFunctionIsRun)
      {
         const auto originalValue = 0;
         auto value = originalValue;
         Timer timer;

         timer.SetOnElapsed([&]()
         {
            ++value;
         });

         timer.Start(std::chrono::milliseconds(1));
         std::this_thread::sleep_for(std::chrono::milliseconds(2));

         Assert::IsTrue(value > originalValue);
      }
	};
}