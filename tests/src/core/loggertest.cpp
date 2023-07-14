#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Logger")
{
    LUNAR_LOG_TRACE("This is a trace");
    LUNAR_LOG_INFO("This is an info");
    LUNAR_LOG_PROFILE("This is a profiling info");
    LUNAR_LOG_WARN("This is a warning");
    LUNAR_LOG_ERROR("This is an error");
    LUNAR_LOG_FATAL("This is a fatal error");
}