#include <catch2/catch_test_macros.hpp>
#include <lunar.h>
#include <platforms/sdl/sdlwindow.h>

TEST_CASE("Window")
{
    lunar::SDLWindow window;
    constexpr i32 width = 1280;
    constexpr i32 height = 720;

    window.Init({ .Width = width, .Height = height, .Title = "WindowTest" });

    SECTION("WindowProperties are properly used")
    {
        REQUIRE(window.GetSize() == ivec2(width, height));
    }

    window.Destroy();

    SECTION("Window is properly destroyed")
    {
        REQUIRE(window.GetNativeWindow() == nullptr);
    }
}