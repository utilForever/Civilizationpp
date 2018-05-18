#include <HexMap.h>
#include <HexTile.h>

#include <gtest/gtest.h>

using namespace Civilizationpp;

class HexMapTest : public ::testing::Test
{
protected:
    HexMap hexMap{GameSettings{3, 3}};
};

TEST_F(HexMapTest, HexMapShouldAlwaysHaveOrigin) 
{
    HexTile* origin = hexMap.GetTile(0, 0);
    ASSERT_NE(origin, nullptr);
}

TEST_F(HexMapTest, HexMapShouldReturnNullPtrForInvalidCoordinates)
{
    HexTile* invalid = hexMap.GetTile(-100, -100);
    ASSERT_EQ(invalid, nullptr);
}

TEST_F(HexMapTest, HexMapShouldGenerateDefaultMapOnConstruction)
{
    for (int r = -2; r <= 2; ++r)
    {
        for (int q = -2; q <= 2; ++q)
        {
            if (r == -2 || r == 2)
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

TEST_F(HexMapTest, HexMapShouldSupportColumnWiseWraparound)
{
    ASSERT_NE(hexMap.GetTile(-1, -2), nullptr);
    ASSERT_NE(hexMap.GetTile( 0, -2), nullptr);
    ASSERT_NE(hexMap.GetTile(+1, -2), nullptr);
    ASSERT_NE(hexMap.GetTile(-1, +2), nullptr);
    ASSERT_NE(hexMap.GetTile( 0, +2), nullptr);
    ASSERT_NE(hexMap.GetTile( 1, +2), nullptr);
}

TEST_F(HexMapTest, HexMapShouldNotSupportRowWiseWraparound)
{
    ASSERT_EQ(hexMap.GetTile(-2, -1), nullptr);
    ASSERT_EQ(hexMap.GetTile(-2,  0), nullptr);
    ASSERT_EQ(hexMap.GetTile(-2, +1), nullptr);
    ASSERT_EQ(hexMap.GetTile(+2, -2), nullptr);
    ASSERT_EQ(hexMap.GetTile(+2, -1), nullptr);
    ASSERT_EQ(hexMap.GetTile(+2,  0), nullptr);
    ASSERT_EQ(hexMap.GetTile(+2, +1), nullptr);
}

TEST_F(HexMapTest, HexMapShouldReturnVectorOfNonNullptrAdjacentTilesOnRequest)
{
    std::vector<HexTile*> adjacenciesToOrigin = hexMap.GetAdjacencies(0, 0);
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile(-1,  0)), adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile(-1,  1)), adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 0,  1)), adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 1,  0)), adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 1, -1)), adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(),
        adjacenciesToOrigin.end(), hexMap.GetTile( 0, -1)), adjacenciesToOrigin.end());
    ASSERT_EQ(adjacenciesToOrigin.size(), (size_t)6);

    std::vector<HexTile*> adjacenciesToEdge = hexMap.GetAdjacencies(-1, -1);
    ASSERT_NE(std::find(adjacenciesToEdge.begin(),
		adjacenciesToEdge.end(), hexMap.GetTile(-1, -2)), adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(),
		adjacenciesToEdge.end(), hexMap.GetTile( 0, -2)), adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(),
		adjacenciesToEdge.end(), hexMap.GetTile( 0, -1)), adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(),
		adjacenciesToEdge.end(), hexMap.GetTile(-1,  0)), adjacenciesToEdge.end());
    ASSERT_EQ(adjacenciesToEdge.size(), (size_t)4);
}