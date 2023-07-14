#include <catch2/catch_test_macros.hpp>
#include <lunar.h>

TEST_CASE("Vector")
{
    {
        ivec2 vecA;
        ivec2 vecB{ 3, 7 };
        ivec2 vecC{ 3, 7 };
        SECTION("ivec2 is properly initialized")
        {
            REQUIRE(vecA.x == 0);
            REQUIRE(vecA.y == 0);
            REQUIRE(vecB.x == 3);
            REQUIRE(vecB.y == 7);
        }

        SECTION("ivec2 array accessor")
        {
            REQUIRE(vecC[0] == 3);
            REQUIRE(vecC[1] == 7);
        }

        SECTION("ivec2 == operator")
        {
            REQUIRE(vecB == vecC);
        }

        SECTION("ivec2 != operator")
        {
            REQUIRE(vecA != vecB);
        }
    }

    {
        vec2 vecA;
        vec2 vecB{ 3.f, 7.f };
        vec2 vecC{ 3.f, 7.f };
        SECTION("vec2 is properly initialized")
        {
            REQUIRE(vecA.x == 0.f);
            REQUIRE(vecA.y == 0.f);
            REQUIRE(vecB.x == 3.f);
            REQUIRE(vecB.y == 7.f);
        }

        SECTION("vec2 array accessor")
        {
            REQUIRE(vecC[0] == 3.f);
            REQUIRE(vecC[1] == 7.f);
        }

        SECTION("vec2 == operator")
        {
            REQUIRE(vecB == vecC);
        }

        SECTION("vec2 != operator")
        {
            REQUIRE(vecA != vecB);
        }
    }
}