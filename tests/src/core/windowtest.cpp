#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Window")
{
    lunar::Window window;
    constexpr i32 width = 640;
    constexpr i32 height = 640;

    window.Init({ .Width = width, .Height = height, .Title = "WindowTest" });

    SECTION("WindowProperties are properly used")
    {
        REQUIRE(window.GetSize() == ivec2(width, height));
        REQUIRE(strcmp(window.GetTitle(), "WindowTest") == 0);
    }

    window.Destroy();

    SECTION("Window is properly destroyed")
    {
        REQUIRE(window.GetNativeWindow() == nullptr);
    }
}