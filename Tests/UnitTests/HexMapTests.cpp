#include <gtest/gtest.h>
#include <HexMap.h>
#include <HexTile.h>

TEST(HexMapTest, HexMapShouldAlwaysHaveOrigin) 
{
    HexMap hexMap{};
    // There are assumptions that get will return
    // nullptr if given coordinates are invalid,
    // which must be clarified by other test.
    Hex* origin = hexMap.get(0, 0);
    ASSERT_NE(origin, nullptr);
}