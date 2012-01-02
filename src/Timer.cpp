#include "Timer.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

std::vector<String>      Timer::sTasks;
std::map<String, Uint32> Timer::sTaskCounters;
std::map<String, double> Timer::sSumTimings;
std::map<String, double> Timer::sMinTimings;
std::map<String, double> Timer::sMaxTimings;

Timer::Timer(rcString inName): 
  mIsInitialized(true),
  mTaskName(inName)
{
  if (std::find(sTasks.begin(), sTasks.end(), inName) == sTasks.end())
  {
    sTasks.push_back(inName);
    sTaskCounters[inName] = 0;
    sSumTimings[inName]   = 0.0;
    sMaxTimings[inName]   = 0.0;
    sMinTimings[inName]   = std::numeric_limits<double>::max();
  }
  time(&mStartTime);
}

Timer::~Timer() {
  time(&mEndTime);

  if (!mIsInitialized)
    return;

  sTaskCounters[mTaskName]++;
  double diff_time = difftime(mEndTime, mStartTime);
  sSumTimings[mTaskName] += diff_time;
  sMinTimings[mTaskName] = std::min<double>(sMinTimings[mTaskName], diff_time);
  sMaxTimings[mTaskName] = std::max<double>(sMaxTimings[mTaskName], diff_time);
}

String Timer::GetReport(int precision)
{
  std::stringstream report;
  report << "Name\tMin\tMax\tAvg\tSum\tCalls" << std::endl << std::endl;
  
  for (int i = 0, n = sTasks.size(); i < n; i++)
  {
    if (sTaskCounters[sTasks[i]] == 0)
      continue;

    report << sTasks[i] << "\t";
    report << std::setiosflags(std::ios::fixed)
           << std::setprecision(precision)
           << sMinTimings[sTasks[i]]
           << "\t";
    report << std::setiosflags(std::ios::fixed)
           << std::setprecision(precision)
           << sMaxTimings[sTasks[i]]
           << "\t";
    report << std::setiosflags(std::ios::fixed)
           << std::setprecision(precision)
           << (sSumTimings[sTasks[i]] / sTaskCounters[sTasks[i]])
           << "\t";
    report << std::setiosflags(std::ios::fixed)
           << std::setprecision(precision)
           << sSumTimings[sTasks[i]]
           << "\t";
    report << sTaskCounters[sTasks[i]]
           << std::endl;
  }

  report << std::endl << "Timings are in seconds" << std::endl;
  return report.str();
}
