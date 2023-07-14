#pragma once

#include <cstdint>

#ifdef NDEBUG
#define LUNAR_RELEASE
#else
#define LUNAR_DEBUG
#endif

using i32 = int32_t;
using u32 = uint32_t;