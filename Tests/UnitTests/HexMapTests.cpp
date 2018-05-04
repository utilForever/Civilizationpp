#include <gtest/gtest.h>
#include <HexMap.h>
#include <HexTile.h>

TEST(HexMapTest, HexMapShouldAlwaysHaveOrigin) 
{
    HexMap hexMap{};
    Hex* origin = hexMap.get(0, 0);
    ASSERT_NE(origin, nullptr);
}

TEST(HexMapTest, HexMapShouldReturnNullPtrForInvalidCoordinates)
{
    HexMap hexMap{};
    // There are assumptions that the default generator
    // will be at least smaller that the 200x200, which
    // must be clarified by other test.
    Hex* invalid = hexMap.get(-100, -100);
    ASSERT_EQ(invalid, nullptr);
}