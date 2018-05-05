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
    Hex* invalid = hexMap.get(-100, -100);
    ASSERT_EQ(invalid, nullptr);
}

TEST(HexMapTest, HexMapShouldGenerateDefaultMapOnConstruction)
{
    HexMap hexMap{};
    // Basic maps are in shape of parrallelogram of 9 tiles
    // Also, tiles are indexed using axial coordinates, where
    // center tile, i.e. (3, 3) tile in offset coordinates, is
    // origin (0, 0). Generating mechanism should be seperated
    // into seperate class.
    
    // Also, there is assumption that all tile is connected 
    // through some path, i.e., there are no "gaps", "empty
    // spaces", or "jump" between any two tile.

    for (int row = -2; row <= 2; ++row)
    {
        for (int col = -2; col <= 2; ++col)
        {
            if ((row == -2 || row == 2) ||
                (col == -2 || col == 2))
            {
                ASSERT_EQ(hexMap.get(row, col), nullptr);
            }
            else
            {
                ASSERT_NE(hexMap.get(row, col), nullptr);    
            }
        }
    }
}