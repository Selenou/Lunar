#pragma once

#include "core.h"
#include "logger.h"

#ifdef LUNAR_DEBUG
#define LUNAR_ASSERTIONS_ENABLED
#endif

#ifdef LUNAR_ASSERTIONS_ENABLED
#define LUNAR_ASSERT(expr, ...) if(!(expr)) { LUNAR_LOG_FATAL(__VA_ARGS__); __builtin_trap(); }
#define LUNAR_SOFTASSERT(expr, ...) if(!(expr)) { LUNAR_LOG_ERROR(__VA_ARGS__); __debugbreak(); }
#else
#define LUNAR_ASSERT(expr, ...)
#define LUNAR_SOFTASSERT(expr, ...)
#endif