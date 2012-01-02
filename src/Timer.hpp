#ifndef TIMER_H
#define TIMER_H

#include "Types.hpp"

#include <map>
#include <ctime>

#define TIMER_FUNC() TIMER(__PRETTY_FUNCTION__)
#define TIMER(name) Timer t(name)

class Timer {
    
public:
    Timer(rcString inName);
    ~Timer();

    static String GetReport(int precision = 2);

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
