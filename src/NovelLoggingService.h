// Copyright © Matt Jones and Contributors. Licensed under the MIT License (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_NOVELLOGGINGSERVICE_H
#define NOVELRT_NOVELLOGGINGSERVICE_H

#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace NovelRT {
enum LogLevel {
  TRACE = SPDLOG_LEVEL_TRACE,
  DEBUG = SPDLOG_LEVEL_DEBUG,
  INFO = SPDLOG_LEVEL_INFO,
  WARN = SPDLOG_LEVEL_WARN,
  ERR = SPDLOG_LEVEL_ERROR,
  CRITICAL = SPDLOG_LEVEL_CRITICAL,
  OFF = SPDLOG_LEVEL_OFF
};

class NovelLoggingService {
public:
  void log(std::string message);
  void logCritical(std::string errorMessage);
  void logError(std::string errorMessage);
  void logDebug(std::string debugMessage);
  void logWarning(std::string warningMessage);
  void setLogLevel();
};
}

#endif