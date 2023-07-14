#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Window")
{
    lunar::Window window;
    window.Init({.Width = 640, .Height = 480, .Title = "WindowTest" });

    SECTION("WindowProperties are properly used") 
    {
        const ivec2 size = window.GetSize();
        REQUIRE(size.x == 640);
        REQUIRE(size.y == 480);
        REQUIRE(strcmp(window.GetTitle(), "WindowTest") == 0);
    }
}