#ifndef TIMER_H
#define TIMER_H

#include "Types.hpp"

#include <map>
#include <ctime>

#define PROFILE_FUNCTION() PROFILE(__PRETTY_FUNCTION__)

#ifdef ENABLE_PROFILING
#define PROFILE(name) Timer t(name)
#else
#define PROFILE(name)
#endif

class Timer {
    
public:
  Timer(rcString inName);
  ~Timer();

  static String GetReport(int inPrecision = 2);
  static String SpacePadding(rcString inString, int inSpaces);

private:
  static std::vector<String> sTasks;
  static std::map<String, Uint32> sTaskCounters;
  static std::map<String, double> sSumTimings;
  static std::map<String, double> sMinTimings;
  static std::map<String, double> sMaxTimings;

  bool mIsInitialized;
  time_t mStartTime;
  time_t mEndTime;
  cString mTaskName;
};

#endif
