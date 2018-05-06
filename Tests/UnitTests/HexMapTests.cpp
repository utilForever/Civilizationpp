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