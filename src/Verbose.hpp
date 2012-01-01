#ifndef VERBOSE_HDR
#define VERBOSE_HDR

#include "Types.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class Verbose
{
public:
  enum Output {
    SCREEN = (1 << 0),
    LOG    = (1 << 1)
  };

  enum Level {
    DBG = (1 << 0), // DEBUG
    NTC = (1 << 1), // NOTICE
    WRN = (1 << 2), // WARNING
    ERR = (1 << 3), // ERROR
    FTL = (1 << 4)  // FATAL
  };

  Verbose();
  ~Verbose();

  static Verbose* Instance();
  static void SetVerbosity(Level inLevel);

  Verbose& Print(rcString inMsg, Level inLevel=NTC);

private:
  enum Style {
    REGULAR = 0,
    BOLD    = 1
  };

  enum Color {
    BLACK   = 30,
    RED     = 31,
    GREEN   = 32,
    YELLOW  = 33,
    BLUE    = 34,
    MAGENTA = 35,
    CYAN    = 36,
    WHITE   = 37
  };

  static Verbose                *sInstance;
  static Uint32                  sMinLevel;
  static Uint32                  sOutput;
  static std::map<Level, String> sLevels;
  static std::ofstream           sStream;

  bool mIsStartOfLine;
  bool mShouldUseColor;

  String Prefix(Level inLevel);
  String Colorize(rcString inMsg, Level inLevel);
  bool ShouldUseColor();
};


#define Debug(MSG)                                    \
do {                                                  \
  std::stringstream ss;                               \
  ss << MSG;                                          \
  Verbose::Instance()->Print(ss.str(), Verbose::DBG); \
} while(0)

#define Notice(MSG)                                   \
do {                                                  \
  std::stringstream ss;                               \
  ss << MSG;                                          \
  Verbose::Instance()->Print(ss.str(), Verbose::NTC); \
} while(0)

#define Warning(MSG)                                  \
do {                                                  \
  std::stringstream ss;                               \
  ss << MSG;                                          \
  Verbose::Instance()->Print(ss.str(), Verbose::WRN); \
} while(0)

#define Error(MSG)                                    \
do {                                                  \
  std::stringstream ss;                               \
  ss << MSG;                                          \
  Verbose::Instance()->Print(ss.str(), Verbose::ERR); \
} while(0)

#define Fatal(MSG)                                    \
do {                                                  \
  std::stringstream ss;                               \
  ss << MSG;                                          \
  Verbose::Instance()->Print(ss.str(), Verbose::FTL); \
} while(0)

#define DebugLine(MSG) Debug(MSG << std::endl)
#define NoticeLine(MSG) Notice(MSG << std::endl)
#define WarningLine(MSG) Warning(MSG << std::endl)
#define ErrorLine(MSG) Error(MSG << std::endl)
#define FatalLine(MSG) Fatal(MSG << std::endl)

#endif // VERBOSE_HDR
