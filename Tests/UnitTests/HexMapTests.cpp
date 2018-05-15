#include <gtest/gtest.h>
#include <HexMap.h>
#include <HexTile.h>

using namespace Civilizationpp;

class HexMapTest : public ::testing::Test
{
protected:
    HexMap hexMap{GameSettings{3, 3}};
};

TEST_F(HexMapTest, HexMapShouldAlwaysHaveOrigin) 
{
    Hex* origin = hexMap.GetTile(0, 0);
    ASSERT_NE(origin, nullptr);
}

TEST_F(HexMapTest, HexMapShouldReturnNullPtrForInvalidCoordinates)
{
    Hex* invalid = hexMap.GetTile(-100, -100);
    ASSERT_EQ(invalid, nullptr);
}

TEST_F(HexMapTest, HexMapShouldGenerateDefaultMapOnConstruction)
{
    for (int r = -2; r <= 2; ++r)
    {
        for (int q = -2; q <= 2; ++q)
        {
            if ((r == -2 || r == 2) ||
                (q == -2 || q == 2))
            {
                ASSERT_EQ(hexMap.GetTile(r, q), nullptr);
            }
            else
            {
                ASSERT_NE(hexMap.GetTile(r, q), nullptr);    
            }
        }
    }
}

TEST_F(HexMapTest, HexMapShouldReturnVectorOfAdjacentTilesOnRequest)
{
    std::vector<Hex*> adjacenciesToOrigin = hexMap.GetAdjacencies(0, 0);
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile(-1,  0)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile(-1,  1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 0,  1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 1,  0)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 1, -1)) != adjacenciesToOrigin.end());
    ASSERT_TRUE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 0, -1)) != adjacenciesToOrigin.end());
}