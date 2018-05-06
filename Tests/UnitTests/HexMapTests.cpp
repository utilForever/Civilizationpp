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
    for (int r = -2; r <= 2; ++r)
    {
        for (int q = -2; q <= 2; ++q)
        {
            if ((r == -2 || r == 2) ||
                (q == -2 || q == 2))
            {
                ASSERT_EQ(hexMap.get(r, q), nullptr);
            }
            else
            {
                ASSERT_NE(hexMap.get(r, q), nullptr);    
            }
        }
    }
}

TEST(HexMapTest, HexMapShouldReturnVectorOfAdjacentTilesOnRequest)
{
    HexMap hexMap{};
    std::vector<Hex*> adjacenciesToOrigin = hexMap.getAdjacencies(0, 0);
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get(-1,  0)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get(-1,  1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get( 0,  1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get( 1,  0)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get( 1, -1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.get( 0, -1)) != adjacenciesToOrigin.end());
}