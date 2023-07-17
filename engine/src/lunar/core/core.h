#pragma once

#include <cstdint>

#define DEV_BUILD

#ifdef NDEBUG
#define LUNAR_RELEASE
#else
#define LUNAR_DEBUG
#endif

#ifdef DEV_BUILD
#define LUNAR_DEV
#define LUNAR_DEV_ONLY(...) __VA_ARGS__
#else
#define LUNAR_FASTLOAD
#define LUNAR_DEV_ONLY(...)
#endif

using i32 = int32_t;
using u32 = uint32_t;