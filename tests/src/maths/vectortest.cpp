#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Vector")
{
    SECTION("vec2")
    {
        vec2 vecA;
        vec2 vecB{ 3.2f, 7.1f };

        SECTION("vec2 is properly default-initialized")
        {
            REQUIRE(vecA.x == 0.f);
            REQUIRE(vecA.y == 0.f);
        }

        SECTION("vec2 is properly initialized")
        {
            REQUIRE(vecB.x == 3.2f);
            REQUIRE(vecB.y == 7.1f);
        }

        SECTION("vec2 == operator")
        {
            vec2 vecC{ 3.2f, 7.1f };
            REQUIRE(vecB == vecC);
        }

        SECTION("vec2 != operator")
        {
            REQUIRE(vecA != vecB);
        }
    }
}